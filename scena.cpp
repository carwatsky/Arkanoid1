#include "scena.h"
#include "cKlocek.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cScena scena;
int current = -1;
/***************/
void przerysuj()
{
	scena.rysuj();
}
cScena::cScena(){
	aktywny = -1;
}
void klawisz(unsigned char znak, int x, int y)
{
	scena.klawiatura(znak, x, y);
}
/*******************/

void cScena::mysz_aktywnie(int x1, int y1)
{
	figury[5]->ustaw_pozycje((double)x1 / 600 * 2.0  -2.0, -.8);
	figury[6]->ustaw_pozycje((double)x1 / 600 * 2.0 - 2.0, -.8);
}
void mysz_aktywna( int x, int y)
{
	scena.mysz_aktywnie(x, y);
}

void idle()
{

	scena.aktualizuj();
	glutPostRedisplay();
	Sleep(1);
}

void cScena::klawiatura(unsigned char key, int mouse_x, int mouse_y)
{
	switch (key)
	{

	case'd':
	{
		figury[5]->przesun(.15, 0);
		figury[6]->przesun(.15, 0);
		break;
	}

	case'a':
	{
		figury[5]->przesun(-.15, 0);
		figury[6]->przesun(-.15, 0);
		break;
	}

	


	default:
		break;
	}



}
void cScena::aktualizuj()
{
	int czas = GetTickCount(); //zwraca czas w [ms]
	for (int i = 0; i< figury.size() - 1; i++)
		figury[i]->Aktualizuj(czas); //obliczanie nowych polozen
									 //wykrywanie kolizji
	for (int i = 0; i< figury.size() - 1; i++)
		for (int j = i + 1; j<figury.size() - 1; j++)
			if (figury[0]->Kolizja(*figury[j])) //znajduje kolizje
			{
				
				
			}
}
/*******************/
void cScena::rysuj(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f = figury.begin(); f != figury.end(); f++)
	{
		(*f)->rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}
/***************************************/
void cScena::init()
{

	cKolo *pil = new cKolo(0.045);
	pil->setPredkosc(0.001,60);
	pil->przesun(0, 0);
	pil->ustaw_kolor(1, 0.3, 0);
	figury.push_back(pil);
	current = figury.size() - 1;

	
	
	
	cProstokat *gora = new cProstokat(0.1,100);
	
	gora->przesun(0, .9);
	figury.push_back(gora);


	cProstokat *left = new cProstokat(100, 0.2);
	left->przesun(-0.9, 0);
	figury.push_back(left);

	cProstokat *right = new cProstokat(100, 0.2);
	right->przesun(0.9, 0);
	figury.push_back(right);

	cProstokat *right_1 = new cProstokat(100, 0.2);
	right_1->przesun(0.9, 0);
	figury.push_back(right_1);

	cProstokat *paletka = new cProstokat(.07, 0.3);
	paletka->przesun(0, -.9);
	paletka->ustaw_kolor(0, 0, 0.9);
	figury.push_back(paletka);

	cProstokat *paletka1 = new cProstokat(.07, 0.3);
	paletka1->przesun(0, -.9);
	paletka1->ustaw_kolor(0, 0, 0.9);
	figury.push_back(paletka1);


	cKlocek *klocek1 = new cKlocek;
	klocek1->ustaw_kolor(0, 0.88, 0);
	klocek1->przesun(-.6, .7);
	figury.push_back(klocek1);


	

}
/****************************************/
void cScena::inicjuj()
{
	glutInitWindowPosition(150, 50);
	glutInitWindowSize(900, 600);
	glutIdleFunc(idle);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);// | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Prostokaty");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutKeyboardFunc(::klawisz);
	glutDisplayFunc(::przerysuj);
//	glutMouseFunc(::mysz);
	glutPassiveMotionFunc(::mysz_aktywna);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -.1, .1);
	init();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************/