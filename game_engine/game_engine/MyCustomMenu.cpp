#include "MyCustomMenu.h"



 MyCustomMenu(glut::Window& w) : glut::Menu(w) {
   addEntry("Hello", 1);
   addEntry("World", 2);
   attach(GLUT_RIGHT_BUTTON);
 }
	
void MyCustomMenu::selected(int value)
{

}