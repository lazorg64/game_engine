#pragma once
#include <iostream>
#include "glut.hpp"
#include "gl_camera.h"
using namespace std;


class MyWindow: public Window {
public:

	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	gl_camera * my_cam;

	int curs_posx;
	int curs_posy;
	int curs_posz;
	AUX_RGBImageRec * texture;
	GLuint	textures[2];
	MyWindow(const char* title);

	void displayFunc();
	void keyboardFunc(unsigned char key, int x, int y);
	void drawAxis();
	void drawCurs();
	void initGL();
	void drawBackground();
	void reshapeFunc(int W, int H);
	void mouseFunc(int button,int state,int x,int y);
};

