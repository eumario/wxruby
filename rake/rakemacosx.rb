# rakemacosx.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project


#############################
# platform-dependent settings


use_wx_config
$wx_version = "2.5.3"

$cpp = "g++"
$ld = "g++"
#$ld = "/usr/bin/libtool"
$swig_options += " -D__WXMAC__ "

=begin
    CONFIG['CC'] = "g++"
    CONFIG['LDSHARED'].gsub!("cc","g++")
    if (!$DEBUG)
      CONFIG['CFLAGS'].gsub!("-g","")
    else
      CONFIG['CFLAGS'].gsub!("-Os","-O0")
    end

    $CFLAGS += " `wx-config --cxxflags` "
    $CPPFLAGS += ' -x objective-c++ '
    $LDFLAGS += " `wx-config --libs` -framework Carbon "
=end

$ruby_cppflags.gsub!(/-g/,"")
$wx_libs = $wx_libs.chomp.gsub(/-framework Cocoa/,"").gsub(/-framework WebKit/,"") + " -lobjc "

$extra_cppflags = '-x objective-c++'
$extra_ldflags = "-dynamic -bundle -flat_namespace -undefined suppress"
#$extra_ldflags = " -lgcc -lstdc++ -dynamic -flat_namespace -undefined suppress -read_only_relocs suppress -install_name /Library/Frameworks/wxruby.framework/wxruby -current_version 0.5 -compatibility_version 0.5"

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
    <string>0.5.0</string>
    <key>CFBundleSignature</key>
    <string>????</string>
    <key>CFBundleName</key>
    <string>wxruby</string>
    <key>CFBundleVersion</key>
    <string>050</string>
    <key>CFBundleGetInfoString</key>
    <string>wxruby 0.5.0 (c) 2004 Kevin Smith, Nicreations</string>
    <key>CFBundleLongVersionString</key>
    <string>0.5.0, (c) 2004 Kevin Smith, Nicreations</string>
    <key>NSHumanReadableCopyright</key>
    <string>Copyright 2004 Kevin Smith, Nicreations</string>
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
