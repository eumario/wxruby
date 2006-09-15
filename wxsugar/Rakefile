require 'rake/packagetask'

if ENV['VERSION']
  WXSUGAR_VERSION = ENV['VERSION']
else
  raise "Cannot build a package or gem without a version number\n" +
        "Please specify like VERSION=1.2.2"
end

          

desc "Make a WxSugar gem"
task :gem do
  wxsugar_gemspec = Gem::Specification.new do | s |
    # BASICS
    s.name = 'wx_sugar'
    s.version = WXSUGAR_VERSION
    s.summary = "Syntax extensions for WxRuby."
    s.description = <<-EOF
      Ruby-ifies the ruby API for WxRuby.
    EOF

    # CONTACT
    s.author = "Alex Fenton"
    s.email = "alex@pressure.to"
    s.homepage = "http://www.pressure.to/qda/"
    s.rubyforge_project = "weft-qda"

    # REQUIREMENTS
    s.required_ruby_version = '>= 1.8.1'  

    s.files = FileList[ 'lib/wx_sugar/*.rb' ].to_a

    # LIBRARIES
    s.require_path = 'lib'
    s.has_rdoc = true
  end
  Gem.manage_gems
  Gem::Builder.new(wxsugar_gemspec).build
end

# TODO - version shouldn't be hardcoded - load from rake-created file instead
Rake::PackageTask.new('wx_sugar', WXSUGAR_VERSION) do | p_task |
  p_task.need_tar_gz = true
  pkg_files = p_task.package_files
  pkg_files.include('Rakefile')
  pkg_files.include('lib/**/*.rb')
  pkg_files.include('samples/**/*')
end
