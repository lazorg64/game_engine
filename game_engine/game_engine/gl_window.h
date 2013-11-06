#pragma once

#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <gl\GLAux.h>



#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "glut32")



class gl_window
{
		
public:

    int WindowWidth, WindowHeight;

	void drawAxis(void);
	void initGL(void);
	void redrawGL(void);
	void resizeGL(int W, int H);
	void idle(void);
	void visible(int vis);
	void mouseHandler(int button,int state,int x,int y);
	gl_window(int argc,char** argv);
	~gl_window(void);
};

