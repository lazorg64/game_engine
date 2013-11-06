#include "gl_camera.h"


gl_camera::gl_camera(float camx,float camy, float camz,float tox,float toy,float toz)
{
	up_vector_x=0;
	up_vector_y=0;
	up_vector_z=1;

	camera_pos_x=camx;
	camera_pos_y=camy;
	camera_pos_z=camz;

	target_pos_x=tox;
	target_pos_y=toy;
	target_pos_z=toz;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(50.0, 1.0, 3.0, 1000.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	gluLookAt(camera_pos_x, camera_pos_y, camera_pos_z,
		target_pos_x, target_pos_y, target_pos_z,
		up_vector_x, up_vector_y, up_vector_z); 
}

void gl_camera::update()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(50.0, 1.0, 3.0, 1000.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	gluLookAt(camera_pos_x, camera_pos_y, camera_pos_z,
		target_pos_x, target_pos_y, target_pos_z,
		up_vector_x, up_vector_y, up_vector_z);
}

gl_camera::~gl_camera(void)
{
}
