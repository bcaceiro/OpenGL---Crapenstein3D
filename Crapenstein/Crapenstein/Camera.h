#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "OpenGLIncludes.h"
#include "collidingObject.h"
/*
Generic camera class by Nghia Ho
*/

class Camera
{
public:
	Camera() { Init(); }
	~Camera(){}

	void Init();
	void Refresh();
	void SetPos(float x, float y, float z);
    void GetPos(float &x, float &y, float &z);
    void GetDirectionVector(float &x, float &y, float &z);
	void SetYaw(float angle);
	void SetPitch(float angle);

	// Navigation
	void Move(float incr);
	void Strafe(float incr);
	void Fly(float incr);
	void RotateYaw(float angle);
	void RotatePitch(float angle);
    void setObject(CollidingObject* obj);
    float m_x, m_y, m_z;   // Position
private:
    CollidingObject* obj;
    float m_lx, m_ly, m_lz; // Direction vector of where we are looking at
	float m_yaw, m_pitch; // Various rotation angles
	float m_strafe_lx, m_strafe_lz; // Always 90 degree to direction vector
};

#endif
