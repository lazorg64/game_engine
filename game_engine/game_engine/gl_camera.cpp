#include "gl_camera.h"


gl_camera::gl_camera(float camx,float camy, float camz,float tox,float toy,float toz)
{
	up_vector_x=0;
	up_vector_y=0;
	up_vector_z=1;

	rotx=0;
	roty=0;
	rotz=0;

	camera_pos_x=camx;
	camera_pos_y=camy;
	camera_pos_z=camz;

	target_pos_x=tox;
	target_pos_y=toy;
	target_pos_z=toz;

	update();
	
}

void gl_camera::update()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(50.0, 1.0, 3.0, 1000.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 

	float tempx,tempy;
	tempx=target_pos_x+(camera_pos_x-target_pos_x)*cos(rotz)-(camera_pos_y-target_pos_y)*sin(rotz);
	//Xp + (X-Xp)*cos(dPhi) - (Y-Yp)*sin(dPhi);
	tempy=target_pos_y+(camera_pos_y-target_pos_y)*cos(rotz)+(camera_pos_x-target_pos_x)*sin(rotz);
	//Yp + (Y-Yp)*cos(dPhi) + (X-Xp)*sin(dPhi);
	camera_pos_x=tempx;
	camera_pos_y=tempy;

	rotz=0;

	gluLookAt(camera_pos_x, camera_pos_y, camera_pos_z,
		target_pos_x, target_pos_y, target_pos_z,
		up_vector_x, up_vector_y, up_vector_z);
}

gl_camera::~gl_camera(void)
{
}

void gl_camera::setpos(float x,float y,float z)
{
	update();
	camera_pos_x=x;
	camera_pos_y=y;
	camera_pos_z=z;
	update();
}

void gl_camera::settarget(float x,float y,float z)
{
	update();
	target_pos_x=x;
	target_pos_y=y;
	target_pos_z=z;
	update();
}

void gl_camera::rotate(float anglex,float angley,float anglez)
{
	update();
	rotx+=anglex;
	roty+=angley;
	rotz+=anglez;
	
	update();
}