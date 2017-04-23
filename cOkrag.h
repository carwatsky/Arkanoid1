#ifndef _COKRAG_H
#define _COKRAG_H

#include "cFigura.h"

class cKolo : public cFigura
{
protected:
	float r;
public:
	cKolo();
	cKolo(float _r);
	void rysuj();
};
#endif