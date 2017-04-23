#ifndef _CFIGURA_H
#define _CFIGURA_H

#include <iostream>
#include <string>
#include <cmath>
#include "fizyka.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

using namespace std;

class cFigura : public CFizyka
{
protected:
	float alpha;
	float R, G, B;
public:
	cFigura();
	virtual void rysuj() = 0;
	void przesun(float dx, float dy);
	void obroc(float dalpha);
	void ustaw_kolor(float r, float g, float b);
	void ustaw_pozycje(double x1, double y1);

};
#endif