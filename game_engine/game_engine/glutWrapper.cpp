#include "glutWrapper.h"



	static void display(void) {
    u->redrawGL();
	}
	static void reshape(int w,int h) {
	u->resizeGL(w,h);
	}
	static void visible(int st) {
	u->visible(st);
	}
	static void idle(void) {
	u->idle();
	}

glutWrapper::glutWrapper(void)
{
}


glutWrapper::~glutWrapper(void)
{
}
