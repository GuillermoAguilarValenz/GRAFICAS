#include <iostream>
#include <GL/glut.h> 
#include <windows.h>
#include <time.h>

#define XLIM 1280
#define YLIM 640
#define PIXEL 3
#define PROB 3
#define NX  (XLIM/PIXEL)
#define NY  (YLIM/PIXEL)
int **mat1, **mat2;
using namespace std;
void pantalla(){
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
	void inicio(){
		srand(time(NULL));
		mat1 = new int*[NX];
		mat2 = new int*[NX];
		for(int i=0; i<NX; ++i){
			mat1[i] = new int[NY];
			mat2[i] = new int[NY];
		}
		for(int i=0; i<NX; ++i){
			for(int j=0; j<NY; ++j){
				mat1[i][j] = PROB>(int)(rand()%10);
				mat2[i][j] = 0;
			}
		}
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0, XLIM, 0, YLIM);           //Establece el sistema de coordenadas.
		glClearColor(0.0, 0.0, 0.0, 0.0);   //Establece el color RGB de fondo.
	}
		int main (int argc, char **argv) {
			glutInit(&argc, argv);
			glutInitWindowSize(XLIM,YLIM);
			glutInitWindowPosition(10,10);
			glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
			glutCreateWindow("Game Of Life");
			inicio();
			glutDisplayFunc(pantalla);
			glutMainLoop();
			return 0;
		}
		
