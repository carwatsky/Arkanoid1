#ifndef _SCENA_H
#define _SCENA_H

#include <vector>
#include "cFigura.h"
#include "cProstokat.h"
#include "cOkrag.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

class cScena{
protected:
	int aktywny;
	vector<cFigura*> figury;
	
	int punkty;
public:
	cScena();
	void rysuj();
	void inicjuj();
	void aktualizuj();
	void init();
	void mysz_aktywnie(int x1, int y1);
	void klawiatura(unsigned char key, int mouse_x, int mouse_y);
};
extern cScena scena;

#endif