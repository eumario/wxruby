require 'rubygems'
require 'rake/packagetask'

# This file adds support for five new Rake targets
# Two important ones:
# :gem     - build a binary wxruby gem for current platform
# :package - build a platfrom-neutral source tarball

# Three less important ones:
# :gem_mswin - build a binary gem for Win32 (-i686)
# :gem_osx   - build a binary gem for OS X (-ppc)
# :gem_linux - build a binary gem for Linux (-i686)

$base_gemspec = Gem::Specification.new do | spec |
  spec.name = 'wxruby2-preview'
  spec.version = '0.0.34'

  spec.require_path = 'lib'
  spec.summary  = 'Ruby interface to the wxWidgets GUI library'
  spec.author   = 'wxRuby development team'
  spec.homepage = 'http://wxruby.org/'
  spec.email    = 'support@wxruby.org'

  spec.rubyforge_project = 'wxruby'
  spec.description = <<-DESC
  wxRuby allows the creation of graphical user interface (GUI)
  applications via the wxWidgets library. wxRuby provides native-style
  GUI windows, dialogs and controls on platforms including Windows, OS X
  and Linux.
  DESC

  spec.autorequire  = 'wx'
  spec.require_path = 'lib'
  # Platform specific binaries are added in later
  spec.files        = [ 'lib/wx.rb' ] +
                      FileList[ 'samples/**/*' ].to_a

  spec.has_rdoc = false
end

GEM_PLATFORMS = { 'mswin' => [ Gem::Platform::WIN32,  '.so' ],
                  'osx'   => [ Gem::Platform::DARWIN, '.bundle' ],
                  'linux' => [ Gem::Platform::LINUX_586, '.so' ] }


def create_release_tasks
  create_gem_tasks
  create_package_tasks
end

# creates 'gem', 'gem_osx', 'gem_linux' and 'gem_mswin' tasks
def create_gem_tasks
  # basic binary gem task for current platform
  desc "Build a binary RubyGem for the current platform"
  task :gem => [ :default ]do 
    this_gemspec = $base_gemspec.dup()    
    this_gemspec.instance_eval do 
      self.platform = Gem::Platform::CURRENT
      self.files += [ $target_lib ]
    end
    Gem::manage_gems()
    Gem::Builder.new(this_gemspec).build
    # tidy up the gem file name if on OS X, remove Xcode version
    if this_gemspec.full_name =~ /darwin[\d.]+$/
      mv this_gemspec.full_name + '.gem',
         this_gemspec.full_name.sub(/darwin[\d.]+$/, 'darwin') + '.gem'
    end
  end

  # named platform binary gem tasks to allow cross-building
  GEM_PLATFORMS.each do | platform, details |
    gem_platform, ext = details
    gem_task = "gem_#{platform}".intern
    task gem_task do
      this_gemspec = $base_gemspec.dup()      
      this_gemspec.instance_eval do 
        self.platform = gem_platform
        self.files += [ File.join($dest_dir, "wxruby2#{ext}") ]
      end
      Gem::manage_gems()
      Gem::Builder.new(this_gemspec).build
    end
  end
end

def create_package_tasks
  Rake::PackageTask.new('wxruby', '1.9.0') do | p_task |
    p_task.need_tar_gz = true
    pkg_files = p_task.package_files
    pkg_files.include('README', 'LICENSE', 'ChangeLog', 'rakefile')
    pkg_files.include('lib/**/*.rb')
    pkg_files.include('swig/**/*')
    pkg_files.include('tests/**/*')
    pkg_files.include('rake/**/*')
    pkg_files.include('samples/**/*')
  end
end
