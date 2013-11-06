#pragma once
#include "glut.hpp"

class gl_camera
{
	float camera_pos_x;
	float camera_pos_y;
	float camera_pos_z;

	float target_pos_x;
	float target_pos_y;
	float target_pos_z;

	float up_vector_x;
	float up_vector_y;
	float up_vector_z;
	float rotx;
	float roty;
	float rotz;
public:
	gl_camera(float camx,float camy, float camz,float tox,float toy,float toz);
	void setpos(float x,float y,float z);
	void settarget(float x,float y,float z);
	void rotate(float anglex,float angley,float anglez);
	void update();
	~gl_camera(void);
};

