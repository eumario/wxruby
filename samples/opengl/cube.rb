#!/usr/bin/env ruby

begin
 require 'wx'
 require 'gl'
 require 'glu'
rescue LoadError => e
 begin
   require 'rubygems'
   require 'wx'
   require 'gl'
   require 'glu'
 rescue
   raise e
 end
end

include Gl
include Glu

class CubeFrame < Wx::Frame
 def initialize(title)
   super(nil, :title => title, :size => [ 400, 300 ])
   attrib = [Wx::GL_RGBA, Wx::GL_DOUBLEBUFFER, Wx::GL_DEPTH_SIZE, 24]
   @canvas = Wx::GLCanvas.new(self, -1, [-1, -1], [-1, -1],
                              Wx::FULL_REPAINT_ON_RESIZE, 'GLCanvas', attrib)
   @canvas.evt_paint { @canvas.paint { render } }
   @canvas.evt_key_down {|evt| on_key_down(evt.get_key_code) }
   @rotate = [0.0, 0.0, 0.0]
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
   sz = @canvas.get_size
   w = sz.get_width
   h = sz.get_height
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
     glColor3d(1.0, 1.0, 1.0)
     glVertex3d(-1.0, 1.0, 1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d(-1.0,-1.0,-1.0)
     #right
     glColor3d(0.0, 1.0, 1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d( 1.0, 1.0,-1.0)
     #up
     glColor3d(0.0, 0.0, 1.0)
     glVertex3d(-1.0, 1.0, 1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d( 1.0, 1.0, 1.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     #down
     glColor3d(1.0, 0.0, 0.0)
     glVertex3d(-1.0,-1.0,-1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     glVertex3d(-1.0, 1.0,-1.0)
     glVertex3d( 1.0, 1.0,-1.0)
     #front
     glColor3d(1.0, 1.0, 0.0)
     glVertex3d(-1.0,-1.0, 1.0)
     glVertex3d(-1.0,-1.0,-1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     glVertex3d( 1.0,-1.0, 1.0)
     glVertex3d(-1.0,-1.0,-1.0)
     glVertex3d( 1.0,-1.0,-1.0)
     #back
     glColor3d(0.0, 1.0, 0.0)
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
 frame.show
end