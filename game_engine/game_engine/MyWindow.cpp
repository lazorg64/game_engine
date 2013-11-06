#pragma once
#include "MyWindow.h"


MyWindow::MyWindow(const char* title) : Window(title, 900, 900)
{
	WINDOW_WIDTH = 900;
	WINDOW_HEIGHT = 900;

	curs_posx=0;
	curs_posy=0;
	curs_posz=0;

	my_cam = new gl_camera(3,3,3,0,0,0);


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
	case 'q':
		my_cam->rotate(0,0,3.14/100);
		break;
	case 'e':
		my_cam->rotate(0,0,-3.14/100);
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
	
	texture = auxDIBImageLoadA("6.bmp");
	cout << texture->sizeX<<endl<<texture->sizeY<<endl;
	glGenTextures(1, &textures[0]);

	glBindTexture(GL_TEXTURE_2D,textures[0]);

	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, texture->sizeX, texture->sizeY,0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);




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

	

	glEnable(GL_TEXTURE_2D);



	drawCurs();
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
	my_cam->update();
	glDepthFunc(GL_LESS);
	
	drawBackground();
	
	glDepthRange(0,1000);
	drawAxis();
	drawCurs();
	swapBuffers();
	glFlush();
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

void MyWindow::drawBackground()
{
	//gluLookAt(0,0,0,0,0,0,0,0,0);
	glEnable(GL_TEXTURE_2D);


	//glDepthRange(1,0.5);

	glBegin(GL_QUADS);

	float size = 50;
	glColor4d(1,1,1,1);

	

	glTexCoord2d(0.25,0);
	glVertex3d(-size,+size,-size);
	glTexCoord2d(0.25,(double)1/3);
	glVertex3d(+size,+size,-size);
	glTexCoord2d(0.5,(double)1/3);
	glVertex3d(+size,-size,-size);
	glTexCoord2d(0.5,0);
	glVertex3d(-size,-size,-size);

	glTexCoord2d(0.25,1);
	glVertex3d(-size,+size,+size);
	glTexCoord2d(0.25,(double)2/3);
	glVertex3d(+size,+size,+size);
	glTexCoord2d(0.5,(double)2/3);
	glVertex3d(+size,-size,+size);
	glTexCoord2d(0.5,1);
	glVertex3d(-size,-size,+size);

	glTexCoord2d(0,(double)1/3);
	glVertex3d(-size,size,-size);
	glTexCoord2d(0.25,(double)1/3);
	glVertex3d(+size,size,-size);
	glTexCoord2d(0.25,(double)2/3);
	glVertex3d(+size,size,+size);
	glTexCoord2d(0,(double)2/3);
	glVertex3d(-size,size,+size);

	glTexCoord2d(0.75,(double)1/3);
	glVertex3d(-size,-size,-size);
	glTexCoord2d(0.5,(double)1/3);
	glVertex3d(+size,-size,-size);
	glTexCoord2d(0.5,(double)2/3);
	glVertex3d(+size,-size,+size);
	glTexCoord2d(0.75,(double)2/3);
	glVertex3d(-size,-size,+size);


	glTexCoord2d(0.75,(double)1/3);
	glVertex3d(-size,-size,-size);
	glTexCoord2d(1,(double)1/3);
	glVertex3d(-size,+size,-size);
	glTexCoord2d(1,(double)2/3);
	glVertex3d(-size,+size,+size);
	glTexCoord2d(0.75,(double)2/3);
	glVertex3d(-size,-size,+size);

	glTexCoord2d(0.5,(double)1/3);
	glVertex3d(+size,-size,-size);
	glTexCoord2d(0.25,(double)1/3);
	glVertex3d(+size,+size,-size);
	glTexCoord2d(0.25,(double)2/3);
	glVertex3d(+size,+size,+size);
	glTexCoord2d(0.5,(double)2/3);
	glVertex3d(+size,-size,+size);



	glEnd();

	glDisable(GL_TEXTURE_2D);
	// glDisable(GL_TEXTURE_2D);
}

void MyWindow::drawCurs()
{
	glBegin(GL_QUADS);
	glColor4d(0.3,0.5,0.1,0.3);
	float posx = curs_posx/(float)2,posy=curs_posy/(float)2,posz=curs_posz/(float)2;
	my_cam->settarget(posx,posy,posz);
	//my_cam->setpos(posx-10,posy,posz+10);
	//my_cam->update();

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
