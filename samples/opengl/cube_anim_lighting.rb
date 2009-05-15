#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

# OpenGL sample by Chauk-Mean Proum featuring an animated cube with lighting.
# OpenGL commands are structured following the Red Book :
# - init part (opengl_init)
# - resize part (opengl_resize)
# - render part (opengl_render)

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
    super(nil, :title => title)

    sizer = Wx::VBoxSizer.new

    attrib = [Wx::GL_RGBA, Wx::GL_DOUBLEBUFFER, Wx::GL_DEPTH_SIZE, 24]
   
    canvas_size = [ 600, 600 ]
    @canvas = Wx::GLCanvas.new(self, -1, [-1, -1], canvas_size,
      Wx::FULL_REPAINT_ON_RESIZE, 'GLCanvas', attrib)
                              
    @canvas.evt_paint { @canvas.paint { opengl_render } }
    @canvas.evt_size do |e|
      opengl_resize
      e.skip()
    end
   
    @canvas.evt_key_down {|evt| on_key_down(evt.get_key_code) }
    @rotate = [15.0, -30.0, 0.0]

    sizer.add_item @canvas, :proportion => 1, :flag => Wx::EXPAND

    text = Wx::StaticText.new(self, :label => "Up/Down keys : manual rotation - Left/Right keys : animation direction")
  
    sizer.add_item text
    self.sizer = sizer
    sizer.fit(self)
    self.show

    opengl_init()
    opengl_resize()
   
    # set the focus on the GL canvas for key press
    @canvas.set_focus

    # start the animation
    @animation_direction = -2.0
    timer = Wx::Timer.new(self)
    timer.start(25) # start the timer with a period of 25 ms
    evt_timer timer.id, :animate
    
    # Wx::Timer.every(25) do
      # animate
    # end

  end

  def animate
    @rotate[1] += @animation_direction
    opengl_render()
  end


  def on_key_down(key)
    case key
    when Wx::K_UP
      @rotate[0] -= 2.0
    when Wx::K_DOWN
      @rotate[0] += 2.0
    when Wx::K_LEFT
      @animation_direction = -2.0
    when Wx::K_RIGHT
      @animation_direction = 2.0
    end
    opengl_render()
  end


  def opengl_init
    # initialize the GL rendering
    @canvas.set_current

    mat_specular = [1.0, 1.0, 1.0, 1.0]
    mat_shininess = [90.0]
    
    light_ambient = [0.9, 0.9, 0.9, 1.0]
    light_position = [-1.0, 4.0, 7.0, 0.0]
    
    glLoadIdentity()
    
#    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular)
#    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess)
   
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_ambient)
    glLightfv(GL_LIGHT0, GL_POSITION, light_position)
    
    glColorMaterial(GL_FRONT, GL_DIFFUSE)
    
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glEnable(GL_COLOR_MATERIAL)
    
    glDepthFunc(GL_LEQUAL)
    glEnable(GL_DEPTH_TEST)
  end
 
  def opengl_resize
    @canvas.set_current
    sz = @canvas.size
    w = sz.width
    h = sz.height
    glViewport(0, 0, w, h)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(30.0, w.to_f/h.to_f, 1.0, 20.0)
    glMatrixMode(GL_MODELVIEW)
  end

  def opengl_render
    @canvas.set_current
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
   
    gluLookAt(0.0, 3.0, 8.0, # position
      0.0, 0.0, 0.0, # target
      0.0, 1.0, 0.0) # up direction
             
    glRotate(@rotate[0], 1.0, 0.0, 0.0)
    glRotate(@rotate[1], 0.0, 1.0, 0.0)
    glRotate(@rotate[2], 0.0, 0.0, 1.0)
   
    glBegin(GL_QUADS)
    
    #left
    glNormal3d(-1.0, 0.0, 0.0) # normal vector is required for proper lighting
    glColor3d(1.0, 1.0, 0.0) # yellow
    glVertex3d(-1.0,-1.0,-1.0)
    glVertex3d(-1.0, 1.0,-1.0)
    glVertex3d(-1.0, 1.0, 1.0)
    glVertex3d(-1.0,-1.0, 1.0)
    #right
    glNormal3d( 1.0, 0.0, 0.0)
    glColor3d(0.0, 1.0, 0.0) # green
    glVertex3d( 1.0,-1.0,-1.0)
    glVertex3d( 1.0, 1.0,-1.0)
    glVertex3d( 1.0, 1.0, 1.0)
    glVertex3d( 1.0,-1.0, 1.0)
    #up
    glNormal3d( 0.0, 1.0, 0.0)
    glColor3d(0.0, 0.0, 1.0) # blue
    glVertex3d(-1.0, 1.0,-1.0)
    glVertex3d( 1.0, 1.0,-1.0)
    glVertex3d( 1.0, 1.0, 1.0)
    glVertex3d(-1.0, 1.0, 1.0)
    #down
    glNormal3d( 0.0,-1.0, 0.0)
    glColor3d(0.0, 1.0, 1.0) # cyan
    glVertex3d(-1.0,-1.0,-1.0)
    glVertex3d( 1.0,-1.0,-1.0)
    glVertex3d( 1.0,-1.0, 1.0)
    glVertex3d(-1.0,-1.0, 1.0)
    #front
    glNormal3d( 0.0, 0.0, 1.0)
    glColor3d(1.0, 0.0, 0.0) # red
    glVertex3d(-1.0,-1.0, 1.0)
    glVertex3d(-1.0, 1.0, 1.0)
    glVertex3d( 1.0, 1.0, 1.0)
    glVertex3d( 1.0,-1.0, 1.0)
    #back
    glNormal3d( 0.0, 0.0,-1.0)
    glColor3d(1.0, 0.0, 1.0) # magenta
    glVertex3d(-1.0,-1.0,-1.0)
    glVertex3d(-1.0, 1.0,-1.0)
    glVertex3d( 1.0, 1.0,-1.0)
    glVertex3d( 1.0,-1.0,-1.0)
    glEnd()
    glFlush()
    @canvas.swap_buffers
  end
end

Wx::App.run do
  self.app_name = 'GLCanvas Cube'
  frame = CubeFrame.new("OpenGL Canvas wxRuby : Animation and Lighting")
end
