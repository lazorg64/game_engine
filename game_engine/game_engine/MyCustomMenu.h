#pragma once
#include "glut.hpp"

class MyCustomMenu :
	public glut::Menu
{
public:
	MyCustomMenu(glut::Window& w);
	
void selected(int value);
};

