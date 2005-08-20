require 'wx'

#
# Basic Frame Class. This creates the dialog window
#
class SimpleFrame < Wx::Frame 

	FILE_DIALOG, FILE_ABOUT, FILE_QUIT = [0,Wx::ID_ABOUT,2]
	
	def initialize(parent)
		super(nil,-1,"Sample",Wx::Point.new(50,50),Wx::Size.new(300,300))

    $xml.load_frame_subclass(self,nil,'ID_FRAME')
    
		# Create a new menu
		bar = Wx::MenuBar.new
		menu = Wx::Menu.new
    menu.append(FILE_ABOUT,"About...")
    menu.append_separator
		menu.append(FILE_QUIT,"Quit")
		bar.append(menu,"File")
		
		set_menu_bar(bar)
		
		# Assign the menu events
    evt_menu(FILE_ABOUT) do
        Wx::message_box("wxRuby Listbook sample\nby Sean Long", "About Listbook", Wx::OK | Wx::ICON_INFORMATION, self)
    end    
		evt_menu(FILE_QUIT) do
			Wx::get_app.exit_main_loop()
		end
		evt_close() do
			Wx::get_app.exit_main_loop()
		end

    # Variables not in tabs
    @listbook = Wx::Window.find_window_by_id(Wx::xrcid('ID_LISTBOOK'),self)
    @text_output = Wx::Window.find_window_by_id(Wx::xrcid('ID_ORDER_TEXTCTRL'),self)
    
    # Variables for widgets in Pizza tab
    @pizza_size = Wx::Window.find_window_by_id(Wx::xrcid('ID_PIZZA_SIZE_CHOICE'),self)
    @pizza_crust = Wx::Window.find_window_by_id(Wx::xrcid('ID_PIZZA_CRUST_CHOICE'),self)
    @pizza_sauce = Wx::Window.find_window_by_id(Wx::xrcid('ID_PIZZA_SAUCE_CHOICE'),self)
    @pizza_cheese = Wx::Window.find_window_by_id(Wx::xrcid('ID_PIZZA_CHEESE_CHOICE'),self)
    @pizza_toppings = []
    3.times do |i|
      @pizza_toppings << Wx::Window.find_window_by_id(Wx::xrcid("ID_PIZZA_TOPPING_#{i+1}_CHOICE"),self)
    end

    # fill in toppings
    toppings = ['pepperoni','sausage','itallian sausage','olives','mushrooms','artichoke','extra cheese','']
    toppings.each do |top_name|
      @pizza_toppings.each do |top_obj|
        top_obj.append(top_name)
      end      
    end
    index = 0
    @pizza_toppings.each do |obj|
      obj.set_selection(index)
      index += 1
    end
    
    # Events for pizza tab
    evt_button(Wx::xrcid('ID_PIZZA_BUTTON')) do |event|
      #get selections and add to order
      order_string = @text_output.get_value
      if order_string != "" then order_string << "\n" end
      
      order_string << "One #{@pizza_size.get_string_selection} pizza with:\n"      
      order_string << @pizza_crust.get_string_selection + " crust" + "\n"
      order_string << @pizza_sauce.get_string_selection + " sauce" +"\n"
      order_string << @pizza_cheese.get_string_selection + " and" + "\n"
      @pizza_toppings.each { |obj| order_string << obj.get_string_selection + "\n" }

      @text_output.set_value(order_string)
    end
    

    # Variables for widgets in Drink tab
    @drink_size = Wx::Window.find_window_by_id(Wx::xrcid('ID_DRINK_SIZE_CHOICE'),self)
    @drink_type = Wx::Window.find_window_by_id(Wx::xrcid('ID_DRINK_TYPE_CHOICE'),self)
    
    # Events for drink tab
    evt_button(Wx::xrcid('ID_DRINK_BUTTON')) do |event|
      #get selections and add to order
      order_string = @text_output.get_value
      if order_string != "" then order_string << "\n" end
      
      order_string << "One #{@drink_size.get_string_selection} #{@drink_type.get_string_selection }.\n"      

      @text_output.set_value(order_string)
    end    
    
    # Variables for widgets in Ice Cream tab
    @ice_cream_size = Wx::Window.find_window_by_id(Wx::xrcid('ID_ICE_CREAM_SIZE_CHOICE'),self)
    @ice_cream_type = Wx::Window.find_window_by_id(Wx::xrcid('ID_ICE_CREAM_TYPE_CHOICE'),self)
    @ice_cream_toppings = []
    4.times do |i|
      @ice_cream_toppings << Wx::Window.find_window_by_id(Wx::xrcid("ID_ICE_CREAM_TOPPING_#{i+1}_CHOICE"),self)
    end    

    toppings = ['','m&m\'s','chocolate chips','fudge','nuts','cherry','whip cream'] 
    toppings.each do |top_name|
      @ice_cream_toppings.each do |top_obj|
        top_obj.append(top_name)
      end      
    end    
    @ice_cream_toppings.each { |obj| obj.set_selection(0) } 
    
    # Events for ice cream tab
    evt_button(Wx::xrcid('ID_ICE_CREAM_BUTTON')) do |event|
      #get selections and add to order
      order_string = @text_output.get_value
      if order_string != "" then order_string << "\n" end
      
      order_string << "One #{@ice_cream_size.get_string_selection} #{@ice_cream_type.get_string_selection} ice cream:\n"      
      @ice_cream_toppings.each { |obj| order_string << obj.get_string_selection + "\n" }

      @text_output.set_value(order_string)
    end       
    
    evt_listbook_page_changed(Wx::xrcid('ID_LISTBOOK')) do |event|
      tab_number = event.get_selection
      order_string = @text_output.get_value
      order_string << "moved to tab = #{@listbook.get_page_text(tab_number)} \n"
      @text_output.set_value(order_string)
    end    
 
  end
	
end

#
# Application class.
#
class XrcApp < Wx::App

	def on_init
		#
		# Xrc dialogs can load images, so it's good to have
		# this line before loading a resource file
		#
		Wx::init_all_image_handlers()
	
		#
		# Create a resource handler
		#
		$xml = Wx::XmlResource.get();
		$xml.init_all_handlers();

		#
		# Load a resource file
		#
		$xml.load("listbook.xrc")	

		#
		# Show the main frame.
		#
		$main = SimpleFrame.new(self)
		$main.show(true)
    
	end

end
		
		
XrcApp.new().main_loop()
