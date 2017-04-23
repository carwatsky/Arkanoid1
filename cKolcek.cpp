#include "cKlocek.h"

cKlocek::cKlocek()
{
	punktacja = (rand() % 5) + 1;
	odpornosc = (rand() % 2) + 1;
}
/*******************/
cKlocek::cKlocek(float _R, float _G, float _B, int _p, int _o){
	R = _R;
	G = _G;
	B = _B;
	punktacja = _p;
	odpornosc = _o;
}
/********************/
void cKlocek::odbicie(float alpha){
	odpornosc--;
	if (odpornosc <= 0)
		widoczny = false;
}
/**********************/
int cKlocek::punkty()
{
	if (!widoczny) return 0;
	else return punktacja;
}