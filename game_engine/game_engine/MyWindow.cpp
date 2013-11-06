#pragma once
#include "MyWindow.h"


MyWindow::MyWindow(const char* title) : Window(title, 600, 600)
{
	WINDOW_WIDTH = 600;
	WINDOW_HEIGHT = 600;

	curs_posx=0;
	curs_posy=0;
	curs_posz=0;

	my_cam = new gl_camera(5,5,5,0,0,0);


	initGL();
}

void MyWindow::keyboardFunc(unsigned char key, int x, int y) {
	switch (key){
	case 'w':
		curs_posx++;
		break;
	case 's':
		curs_posx--;
		break;
	case 'a':
		curs_posy++;
		break;
	case 'd':
		curs_posy--;
		break;


	}

	cout << key << endl;
	this->postRedisplay();
}

void MyWindow::mouseFunc(int button,int state,int x,int y)
{

	this->postRedisplay();
	//exit(0);
}

void MyWindow::initGL()
{
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* Red diffuse light. */
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glClearDepth(200.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);




	glShadeModel(GL_SMOOTH);
	my_cam->update();
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

}

void MyWindow::reshapeFunc(int W, int H) {
	WINDOW_WIDTH = W;
	WINDOW_HEIGHT = H;
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

}

void MyWindow::displayFunc() {

	glClearColor(1.0f, 1.0f, 1.0f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	drawAxis();
	drawCurs();
	swapBuffers();
}

void MyWindow::drawAxis()
{
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor4f(1.00f, 0.00f, 0.00f, 1.0f);

	glVertex3f(1.5f,0.2,0.0);
	glVertex3f(1.5f,0.1,0.0);
	glVertex3f(1.55f,0.15,0.0);
	glVertex3f(1.45f,0.15,0.0);
	glVertex3f( 100.0f,  0.0f,  0.0f);
	glVertex3f(-100.0f,  0.0f,  0.0f);

	glColor4f(0.00f, 1.00f, 0.00f, 1.0f);

	glVertex3f( 0.0f,  100.0f,  0.0f);
	glVertex3f( 0.0f, -100.0f,  0.0f);
	glVertex3f(0.2,1.5f,0.0);
	glVertex3f(0.1,1.5f,0.0);
	glVertex3f(0.15,1.55f,0.0);
	glVertex3f(0.15,1.45f,0.0);

	glColor4f(0.00f, 0.00f, 1.00f, 1.0f);

	glVertex3f( 0.0f,  0.0f,  100.0f);
	glVertex3f( 0.0f,  0.0f, -100.0f);

	glEnd();
}


void MyWindow::drawCurs()
{
	glBegin(GL_QUADS);
	glColor4d(0.3,0.5,0.1,0.5);
	float posx = curs_posx/(float)2,posy=curs_posy/(float)2,posz=curs_posz/(float)2;


	glVertex3f(posx-0.26f,posy-0.26f,posz-0.26f);
	glVertex3f(posx-0.26f,posy-0.26f,posz-0.24f+0.5f);
	glVertex3f(posx-0.26f,posy-0.24f+0.5f,posz-0.24f+0.5f);
	glVertex3f(posx-0.26f,posy-0.24f+0.5f,posz-0.26f);

	glVertex3f(posx-0.26f,posy-0.26f,posz-0.26f);
	glVertex3f(posx-0.26f,posy-0.26f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.26f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.26f,posz-0.26f);

	glVertex3f(posx-0.26f,posy-0.24f+0.5f,posz-0.26f);
	glVertex3f(posx-0.26f,posy-0.24f+0.5f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.24f+0.5f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.24f+0.5f,posz-0.26f);

	glVertex3f(posx-0.24f+0.5f,posy-0.26f,posz-0.26f);
	glVertex3f(posx-0.24f+0.5f,posy-0.26f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.24f+0.5f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.24f+0.5f,posz-0.26f);

	glVertex3f(posx-0.26f,posy-0.24f+0.5f,posz-0.26f);
	glVertex3f(posx-0.24f+0.5f,posy-0.24f+0.5f,posz-0.26f);
	glVertex3f(posx-0.24f+0.5f,posy-0.26f,posz-0.26f);
	glVertex3f(posx-0.26f,posy-0.26f,posz-0.26f);

	glVertex3f(posx-0.26f,posy-0.26f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.26f,posz-0.24f+0.5f);
	glVertex3f(posx-0.24f+0.5f,posy-0.24f+0.5f,posz-0.24f+0.5f);
	glVertex3f(posx-0.26f,posy-0.24f+0.5f,posz-0.24f+0.5f);



	glEnd();
}
