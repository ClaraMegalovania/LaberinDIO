#pragma once
#include <cmath>
#include <GL/glut.h>
#include "vector3d.h"
#include <iostream>

//#define M_PI 3.14159
const double M_PI = 3.14159;

inline double rot2rad(double  a) { return a / 180 * M_PI; }

using namespace std;

class Camara {
	Vector3D pos;
	Vector3D rot;
public:
	Camara();
	Camara(double x, double y, double z) :pos(Vector3D(x, y, z)) {}
	virtual ~Camara();
	inline Vector3D getPos() const { return pos; }
	inline void setPos(Vector3D pos) { this->pos = pos; }
	inline Vector3D getRot() const { return rot; }
	inline void setRot(Vector3D rot) { this->rot = rot; }
	void render() {
		glTranslatef(-this->getPos().getX(), -this->getPos().getY(), -this->getPos().getZ());
		glRotatef(getRot().getX(), 1, 0, 0);
		glRotatef(getRot().getY(), 0, 1, 0);
		glRotatef(getRot().getZ(), 0, 0, 1);
	}
};

class CamaraFPS : public Camara {
public:
	CamaraFPS(double x = 0, double y = 1.85, double z = 0) :Camara(x, y, z) {}

	void update(double dt)
	{
		double ry = rot2rad(getRot().getY()); //ROTACION
		Vector3D dir = { -sin(ry) , 0 , cos(ry) }; //MOVIMIENTO DIRECCION
		setPos(getPos() - dir * dt);

		
	}

	void render() {
		glRotatef(getRot().getX(), 1, 0, 0);
		glRotatef(getRot().getY(), 0, 1, 0);
		glRotatef(getRot().getZ(), 0, 0, 1);
		glTranslatef(-getPos().getX(), -getPos().getY(), -getPos().getZ());
	}
};



