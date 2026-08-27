tvgui:
	g++ Main.cc App.cc App.h Button.h Theme.h Widget.h -o tvgui -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean:
	rm tvgui
