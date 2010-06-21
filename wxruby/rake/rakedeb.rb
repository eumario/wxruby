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
	$INFO[:author][:full_name] = ENV["WXRUBY_DEB_AUTHOR"]
	$INFO[:author][:email] = ENV["WXRUBY_DEB_EMAIL"]
	$INFO[:package_info][:base_version] = ENV["WXRUBY_VERSION"]
	$INFO[:package_info][:base_name] = "wxruby"
	if ENV["WXRUBY_DEB_VERSION"].nil?
		deb_ver = "-1"
	else
		deb_ver = ENV["WXRUBY_DEB_VERSION"]
	end
	$INFO[:package_info][:deb_version] = ENV["WXRUBY_VERSION"] + deb_ver
	if File.exists?("deb_helper/changelog")
		$INFO[:package_info][:changelog] = YAML::load_file("deb_helper/changelog")
	else
		$INFO[:package_info][:changelog] = [
			{:package=>"wxruby",:version=>"2.0.1-1",
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
	
	if ENV["WXRUBY_VERSION"].nil?
		puts "Failed to generate Debian package, please set WXRUBY_VERSION before executing this task."
		exit 1
	end
	
	gather_information
	if $INFO[:author].has_value? nil
		puts "Failed to generate Debian package, please set all WXRUBY_DEB* environment values before executing this task."
		puts "Required WXRUBY_DEB* Fields:"
		puts "\tWXRUBY_DEB_AUTHOR"
		puts "\tWXRUBY_DEB_EMAIL"
		puts "Optional WXRUBY_DEB* Fields:"
		puts "\tWXRUBY_DEB_VERSION"
		exit 1
	end
	
	build_dir = "deb_build/#{$INFO[:package_info][:base_name]}-#{$INFO[:package_info][:base_version]}"
	package_file = "#{$INFO[:package_info][:base_name]}-#{$INFO[:package_info][:base_version]}"
	deb_file = "#{$INFO[:package_info][:base_name]}_#{$INFO[:package_info][:deb_version]}_i386.deb"
	lib_dir = File.join build_dir, "lib"
	examples_dir = File.join build_dir, "data", "wxruby", "examples"
	docs_dir = File.join build_dir, "data", "wxruby", "docs"
	ext_dir = File.join build_dir, "ext"
	File.makedirs build_dir
	File.makedirs lib_dir
	File.makedirs docs_dir
	File.makedirs ext_dir
	File.copy_r("lib",build_dir)
	File.copy_r("samples",examples_dir)
	cdir = File.join(Dir.pwd,"lib","wxruby2.so")
	data = File.read("deb_helper/extconf.rb") % [cdir]
	File.open(File.join(ext_dir,"extconf.rb"),"w") {|fh| fh.print(data)}
	File.move(File.join(examples_dir,"SAMPLES-LICENSE.TXT"),docs_dir)
	File.copy("ChangeLog",docs_dir)
	File.copy("INSTALL",docs_dir)
	File.copy("LICENSE",docs_dir)
	File.copy("README",docs_dir)
	File.copy("deb_helper/setup.rb",build_dir)
	puts "Build directory structure created, compressing into Tar package..."
	cdir = Dir.pwd
	Dir.chdir("deb_build")
	`tar -czf #{package_file}.tar.gz #{package_file}`
	Dir.chdir(cdir)
	puts "Tar package created."
	puts "Creating debian folder structure..."
	puts "-----------------------<dh_make output>-----------------------"
	IO.popen("cd deb_build/#{package_file} && dh_make -s -e #{$INFO[:author][:email]} -f ../#{package_file}.tar.gz","r+") do |f|
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
	IO.popen("cd deb_build/#{package_file} && dpkg-buildpackage -rfakeroot") do |f|
		puts f.readlines
	end
	Dir.chdir(cdir)
	File.copy(File.join(".","deb_build",deb_file),".")
	`rm -rf deb_build`
	puts "Debian package created."
end
