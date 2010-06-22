require 'ftools'
require 'yaml'

$DEB_CONTROL = File.read("deb_helper/control")
$DEB_LICENSE = File.read("deb_helper/license")
$DEB_CHANGELOG_ENTRY = File.read("deb_helper/changelog_entry")
$DEB_RULES = File.read("deb_helper/rules")

def deb_timestamp(time = nil)
	if time.nil?
		Time.now.strftime("%a, %d %b %Y %H:%M:%S %z")
	else
		time = Time.parse(time)
		time.strftime("%a, %d %b %Y %H:%M:%S %z")
	end
end

def generate_changelog(entries)
	changelog = ""
	entries.each do |entry_hash|
		changelog << $DEB_CHANGELOG_ENTRY % [
			entry_hash[:package],
			entry_hash[:version],
			entry_hash[:distro],
			entry_hash[:message],
			entry_hash[:author],
			entry_hash[:author_email],
			deb_timestamp(entry_hash[:timestamp])
		]
		changelog << "\n"
	end
	File.open("debian/changelog","w") {|fh| fh.print(changelog)}
end

def generate_control(author_info)
	control = $DEB_CONTROL % [
		author_info[:full_name],
		author_info[:email]
	]
	File.open("debian/control","w") {|fh| fh.print(control)}
end

def generate_license(author_info)
	license = $DEB_LICENSE % [
		author_info[:full_name],
		author_info[:email],
		deb_timestamp()
	]
	File.open("debian/license","w") {|fh| fh.print(license)}
end

def generate_rules(package)
	rules = $DEB_RULES % [package]
	File.open("debian/rules","w") {|fh| fh.print(rules)}
	File.chmod(0755,"debian/rules")
end

$INFO = {}
def gather_information
	$INFO[:author] = {}
	$INFO[:package_info] = {}
	$INFO[:author][:full_name] = ENV["WXSUGAR_DEB_AUTHOR"]
	$INFO[:author][:email] = ENV["WXSUGAR_DEB_EMAIL"]
	$INFO[:package_info][:base_version] = ENV["WXSUGAR_VERSION"]
	$INFO[:package_info][:base_name] = "wxsugar"
	if ENV["WXSUGAR_DEB_VERSION"].nil?
		deb_ver = "-1"
	else
		deb_ver = ENV["WXSUGAR_DEB_VERSION"]
	end
	$INFO[:package_info][:deb_version] = ENV["WXSUGAR_VERSION"] + deb_ver
	if File.exists?("deb_helper/changelog")
		$INFO[:package_info][:changelog] = YAML::load_file("deb_helper/changelog")
	else
		$INFO[:package_info][:changelog] = [
			{:package=>"wxsugar",:version=>"0.1.22-1",
				:distro=>"lucid",:message=>"Initial Release.",
				:author=>$INFO[:author][:full_name],
				:author_email=>$INFO[:author][:email]}
		]
	end
end

class File
	class << self
		def copy_r(path,dest)
			`cp -r #{path} #{dest}`
		end
	end
end

desc "Creates a Debian Package for use with Apt installer"
task :package_deb do
	puts "Debian package generation started.  Gathering information..."
	unless File.exists? "/usr/bin/dh_make"
		puts "Failed to generate Debian package, required tool 'dh-make' not installed."
		puts "Please install this package via 'sudo apt-get install dh-make'"
		exit 1
	end
	
	unless File.exists? "/usr/share/ruby-pkg-tools/1/class/ruby-setup-rb.mk"
		puts "Failed to generate Debian package, required tool 'ruby-pkg-tools' not installed."
		puts "Please install this package via 'sudo apt-get install ruby-pkg-tools'"
		exit 1
	end
	
	unless File.exists? "/usr/share/cdbs/1/rules/debhelper.mk"
		puts "Failed to generate Debian package, required tool 'cdbs' not installed."
		puts "Please install this package via 'sudo apt-get install cdbs'"
		exit 1
	end
	
	if ENV["WXSUGAR_VERSION"].nil?
		puts "Failed to generate Debian package, please set WXSUGAR_VERSION before executing this task."
		exit 1
	end
	
	gather_information
	if $INFO[:author].has_value? nil
		puts "Failed to generate Debian package, please set all WXSUGAR_DEB* environment values before executing this task."
		puts "Required WXSUGAR_DEB* Fields:"
		puts "\tWXSUGAR_DEB_AUTHOR"
		puts "\tWXSUGAR_DEB_EMAIL"
		puts "Optional WXSUGAR_DEB* Fields:"
		puts "\tWXSUGAR_DEB_VERSION"
		exit 1
	end
	
	build_dir = "pkg/#{$INFO[:package_info][:base_name]}-#{$INFO[:package_info][:base_version]}"
	package_file = "#{$INFO[:package_info][:base_name]}-#{$INFO[:package_info][:base_version]}"
	deb_file = "#{$INFO[:package_info][:base_name]}_#{$INFO[:package_info][:deb_version]}_i386.deb"
	bin_dir = File.join build_dir, "bin"
	lib_dir = File.join build_dir, "lib"
	examples_dir = File.join build_dir, "data", "wxsugar", "examples"
	docs_dir = File.join build_dir, "data", "wxsugar", "docs"
	File.makedirs build_dir
	File.makedirs lib_dir
	File.makedirs docs_dir
	File.copy_r("bin",bin_dir)
	File.copy_r("lib",build_dir)
	File.copy_r("samples",examples_dir)
	File.copy("LICENCE.txt",docs_dir)
	File.copy("README.txt",docs_dir)
	File.copy("deb_helper/setup.rb",build_dir)
	puts "Build directory structure created, compressing into Tar package..."
	cdir = Dir.pwd
	Dir.chdir("pkg")
	`tar -czf #{package_file}.tar.gz #{package_file}`
	Dir.chdir(cdir)
	puts "Tar package created."
	puts "Creating debian folder structure..."
	puts "-----------------------<dh_make output>-----------------------"
	IO.popen("cd pkg/#{package_file} && dh_make -s -e #{$INFO[:author][:email]} -f ../#{package_file}.tar.gz","r+") do |f|
		f.puts
		puts f.readlines
	end
	puts "-----------------------<dh_make output>-----------------------"
	puts "Debian folder structure created.  Updating changelog, license, control and rules..."
	cdir = Dir.pwd
	Dir.chdir(build_dir)
	generate_control($INFO[:author])
	generate_license($INFO[:author])
	generate_rules($INFO[:package_info][:base_name])
	generate_changelog($INFO[:package_info][:changelog])
	Dir.chdir(cdir)
	puts "Updates complete, generating package...."
	IO.popen("cd pkg/#{package_file} && dpkg-buildpackage -rfakeroot") do |f|
		puts f.readlines
	end
	Dir.chdir(cdir)
	puts "Debian package created."
end
