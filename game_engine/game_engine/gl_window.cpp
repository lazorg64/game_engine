#include "gl_window.h"

void gl_window::redrawGL() 
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	drawAxis();
	glutSwapBuffers();
}

gl_window::gl_window(int argc,char** argv)
{
	WindowWidth = 1024;
	WindowHeight = 1024;

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Game");
	/*
	glutDisplayFunc(redrawGL);
	glutReshapeFunc(resizeGL);
    glutVisibilityFunc(visible);
    glutIdleFunc(idle);
	glutMouseFunc(mouseHandler);

	*/
    glutReshapeWindow(WindowWidth, WindowHeight);
	initGL();
	glutMainLoop();
}

void mouseHandler(int button,int state,int x,int y)
{

}

void gl_window::idle(void) {
    glutPostRedisplay();
}
 
void  gl_window::visible(int vis) {
    if (vis == GLUT_VISIBLE)
		glutIdleFunc(0);
    else
        glutIdleFunc(0);
}

void gl_window::resizeGL(int W, int H) {
	
	WindowWidth = W;
    WindowHeight = H;
    glViewport(0, 0, WindowWidth, WindowWidth);
	
}

void gl_window::initGL()
{	
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(50.0, 1.0, 3.0, 7.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	gluLookAt(0.0, 0.0, 5.0,/*|*/0.0, 0.0, 0.0,/*|*/0.0, 1.0, 0.0);     /* up is in positive Y direction */
    glEnable(GL_COLOR_MATERIAL);
  
}


void gl_window::drawAxis()
{
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    glVertex3f( 100.0f,  0.0f,  0.0f);
    glVertex3f(-100.0f,  0.0f,  0.0f);
    glColor4f(0.00f, 1.00f, 0.00f, 1.0f);
    glVertex3f( 0.0f,  100.0f,  0.0f);
    glVertex3f( 0.0f, -100.0f,  0.0f);
    glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
    glVertex3f( 0.0f,  0.0f,  100.0f);
    glVertex3f( 0.0f,  0.0f, -100.0f);
    glEnd();
}

gl_window::~gl_window(void)
{
}
