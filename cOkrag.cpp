#include "cOkrag.h"

cKolo::cKolo()
{
	r = 0.1;
}

cKolo::cKolo(float _r)
{
	r = _r;
	setGeometria(x, y, -r, -r,  r,  r);
}
/************************/
void cKolo::rysuj(){
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (float kat = 0; kat<360; kat += 10)
	{
		GLfloat x, y;
		x = r*cos(kat / 180 * 3.14);
		y = r*sin(kat / 180 * 3.14);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
}
