tvgui:
	g++ main.cc -o tvgui -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
clean:
	rm tvgui
