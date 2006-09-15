# Automatic loader for all the extensions to core Wx classes
Dir.glob( __FILE__.sub(/\.rb$/, File::SEPARATOR + '*.rb' ) ).each do | f |
  require 'wx_sugar/wx_classes/' + File.basename(f)
end
