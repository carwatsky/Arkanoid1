#include "cFigura.h"
#include "cProstokat.h"
#include "scena.h"

cFigura::cFigura()
{
	x = 0;
	y = 0;
	R = 0; G = 0; B = 0;
	alpha = 0;
}

void cFigura::przesun(float dx, float dy){
	x += dx;
	y += dy;
}

void cFigura::obroc(float dalpha){
	alpha += dalpha;
}

void cFigura::ustaw_kolor(float r, float g, float b)
{
	R = r;
	G = g;
	B = b;
}

void cFigura::ustaw_pozycje(double x1, double y1)
{
	x = x1;
	y = y1;
}
