#include "MyWindow.h"

std::map<int, Window*> Window::wins;
std::map<int, Menu*> Menu::menus;

int main(int argc,char** argv)
{
	MyWindow w("Window 1");
	w.show();
	w.MainLoop();
	return 0;
}