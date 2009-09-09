#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'
require 'gl'
require 'glu'

include Gl
include Glu

class CubeFrame < Wx::Frame
 def initialize(title)
   super(nil, :title => title, :size => [ 600, 400 ])

   sizer = Wx::VBoxSizer.new

   attrib = [Wx::GL_RGBA, Wx::GL_DOUBLEBUFFER, Wx::GL_DEPTH_SIZE, 24]
   @canvas = Wx::GLCanvas.new(self, -1, [-1, -1], [-1, -1],
                              Wx::FULL_REPAINT_ON_RESIZE, "GLCanvas", attrib)
   sizer.add_item @canvas, :proportion => 1, :flag => Wx::EXPAND

   text = Wx::StaticText.new(self, :label => "Use Up/Down/Left/Right keys to rotate the cube")
   sizer.add_item text

   self.sizer = sizer
   self.show

   @canvas.set_focus
   @canvas.evt_key_down {|evt| on_key_down(evt.get_key_code) }

   @canvas.evt_paint { @canvas.paint { render } }
   @rotate = [30.0, 0.0, -30.0]

 end

 def on_key_down(key)
   case key
   when Wx::K_UP
     @rotate[0] -= 3.0
   when Wx::K_DOWN
     @rotate[0] += 3.0
   when Wx::K_LEFT
     @rotate[2] -= 3.0
   when Wx::K_RIGHT
     @rotate[2] += 3.0
   end
   render
 end

 def render
   @canvas.set_current
   sz = @canvas.size
   w = sz.width
   h = sz.height
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
   glEnable(GL_DEPTH_TEST)
   glViewport(0, 0, w, h)
   glMatrixMode(GL_PROJECTION)
   glLoadIdentity()
   gluPerspective(30.0, w.to_f/h.to_f, 0.1, 1000.0)
   glMatrixMode(GL_MODELVIEW)
   glLoadIdentity()
   gluLookAt(0.0, -10.0, 0.0,
             0.0, 0.0, 0.0,
             0.0, 0.0, 1.0)
   glRotate(@rotate[0], 1.0, 0.0, 0.0)
   glRotate(@rotate[1], 0.0, 1.0, 0.0)
   glRotate(@rotate[2], 0.0, 0.0, 1.0)
   glBegin(GL_TRIANGLES)
     #left
     glColor3d(1.0, 1.0, 0.0) # yellow
     glVertex3d(-1.0, 1.0, 1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d(-1.0,-1.0,-1.0)
     #right
     glColor3d(0.0, 1.0, 0.0) # green
     glVertex3d( 1.0,-1.0, 1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d( 1.0, 1.0,-1.0)
     #up
     glColor3d(0.0, 0.0, 1.0) # blue
     glVertex3d(-1.0, 1.0, 1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     #down
     glColor3d(0.0, 1.0, 1.0) # cyan
     glVertex3d(-1.0,-1.0,-1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d( 1.0, 1.0,-1.0)
     #front
     glColor3d(1.0, 0.0, 0.0) # red
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d(-1.0,-1.0,-1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     glVertex3d(-1.0,-1.0,-1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     #back
     glColor3d(1.0, 0.0, 1.0) # magenta
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0, 1.0,-1.0)
     glVertex3d(-1.0, 1.0, 1.0)
     glVertex3d(-1.0, 1.0, 1.0)
     glVertex3d( 1.0, 1.0,-1.0)
     glVertex3d(-1.0, 1.0,-1.0)
   glEnd()
   @canvas.swap_buffers
 end
end

Wx::App.run do
 self.app_name = 'GLCanvas Cube'
 frame = CubeFrame.new("OpenGL Canvas wxRuby App")
end
