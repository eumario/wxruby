# rakemacosx.rb
#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license


#############################
# platform-dependent settings


require './rake/rakeunixish'

$cpp = "g++"
$ld = "g++"

$wx_libs.chomp!
$wx_libs.gsub!(/-framework (Cocoa|WebKit)/, '')
$wx_libs << ' -framework Foundation -framework Appkit'

# Defaults to building a universal binary, set WXRUBY_OSX_NO_UNIVERSAL to true
# to build the default for the current computer
$osx_universal = true

if ENV['WXRUBY_OSX_NO_UNIVERSAL']
  $osx_universal = false
end

# Minimum system supported is 10.4.x, this is the minimum supported by
# wxWidgets as of 01/15/2008
$extra_cppflags = '-x objective-c++ -isysroot /Developer/SDKs/MacOSX10.4u.sdk -mmacosx-version-min=10.4'
# If release build, remove debugging info; if debug build, ensure
# debugging info and remove optimisations
if $release_build
  $ruby_cppflags.sub!(/-g/, '')
elsif $debug_build
  $extra_cppflags << ' -g'
  $ruby_cppflags.sub!(/-Os/, '')
end

$extra_ldflags = '-dynamic -bundle -flat_namespace -undefined suppress -isysroot /Developer/SDKs/MacOSX10.4u.sdk -mmacosx-version-min=10.4'

if $osx_universal
  $extra_cppflags << ' -arch ppc -arch i386'
  $extra_ldflags << ' -arch ppc -arch i386'
end

task :framework do
	build_framework
end

def build_framework()
	base = "#{$dest_dir}/wxruby.framework"
	if (File.exists?(base))
		`rm -fr #{base}`
	end
	#
	# Create the directories
	#
	Dir.mkdir(base);
	Dir.mkdir("#{base}/Versions")
	Dir.mkdir("#{base}/Versions/A")
	Dir.mkdir("#{base}/Versions/A/Resources")

	# 
	# Copy in the libraries
	#
	`cp #{$dest_dir}/wxruby #{base}/Versions/A/wxruby`
	create_info_plist(base)
	create_resources(base)
	#
	# Create the symlinks
	#
	File.symlink("Versions/A/wxruby","#{base}/wxruby")
	File.symlink("Versions/A/Resources","#{base}/Resources")
	File.symlink("Versions/A","#{base}/Current")
	
end

def create_info_plist(base)

	File.open("#{base}/Versions/A/Resources/Info.plist","w") do |fp|
		fp.puts <<INFOLIST
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>English</string>
    <key>CFBundleIdentifier</key>
    <string>org.wxwidgets.wxruby.framework</string>
    <key>CFBundlePackageType</key>
    <string>FMWK</string>
    <key>CFBundleShortVersionString</key>
    <string>2.0.0</string>
    <key>CFBundleSignature</key>
    <string>????</string>
    <key>CFBundleName</key>
    <string>wxruby</string>
    <key>CFBundleVersion</key>
    <string>2.0.0</string>
    <key>CFBundleGetInfoString</key>
    <string>wxruby 2.0.0 (c) 2006 Kevin Smith, Nicreations</string>
    <key>CFBundleLongVersionString</key>
    <string>2.0.0, (c) 2006 Kevin Smith, Nicreations</string>
    <key>NSHumanReadableCopyright</key>
    <string>Copyright 2006 Kevin Smith, Nicreations</string>
    <key>LSRequiresCarbon</key>
    <true/>
    </dict>
</plist>
INFOLIST

	end

end


def create_resources(base)
	cmd = `wx-config --rezflags`.strip
	`#{cmd} #{base}/Versions/A/Resources/wxruby.rsrc`
end

