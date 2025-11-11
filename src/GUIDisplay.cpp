#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <windows.h>
#include "GUIDisplay.h"


void display::MessageBoxi (){
	MessageBoxW(nullptr, L"Operation completed successfullyăâîșț.", L"Info", MB_OK | MB_ICONINFORMATION);
}


int FL::gui_window(){
	Fl_Window *window = new Fl_Window(340,180);
	Fl_Box *box = new Fl_Box(20,40,300,100,"Hello all");
	box -> box(FL_UP_BOX);
	box -> labelfont (FL_BOLD + FL_ITALIC);
	box -> labelsize (36);
	box -> labeltype (FL_SHADOW_LABEL);
	window -> end();
	window -> show();
	return Fl::run();
}


