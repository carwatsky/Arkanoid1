#ifndef _CKLOCEK_H
#define _CKLOCEK_H
#include "fizyka.h"
#include "scena.h"
#include "cProstokat.h"

class cKlocek : public cProstokat{
protected:
	int punktacja;
	int odpornosc;
public:
	cKlocek();
	cKlocek(float _R, float _G, float _B, int _p, int _o);
	void odbicie(float alpha);
	int punkty();
};



#endif