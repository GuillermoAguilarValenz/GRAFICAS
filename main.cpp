#include <iostream>
#include <GL/glut.h> 
#include <windows.h>
#include <time.h>

#define XLIM 1280
#define YLIM 640

#define PROB 3
#define NX  (XLIM/PIXEL)
#define NY  (YLIM/PIXEL)

#define FRAMERATE 16
using namespace std;
int **mat1, **mat2;
int PIXEL=10;
int sobrevive(int x, int y){
	int i, j;
	int aux = 0;
	if(!x || !y || (x==NX-1) || (y== NY-1)){
		return 0;
	}
	else{
		for(i=x-1; i<=x+1; ++i){
			for(j=y-1; j<=y+1; ++j){
				aux+=mat1[i][j];		
			}
		}
		aux-=mat1[x][y];
		aux = (mat1[x][y]) ? ((aux == 2)||(aux == 3)) :(aux == 3);
		return aux;
	}
}
	void pantalla(){
		glClear(GL_COLOR_BUFFER_BIT);
		for(int i=0; i<NX; ++i){
			for(int j=0; j<NY; ++j){			
				glPointSize(PIXEL);
				glColor3f(mat1[i][j], mat1[i][j], mat1[i][j]);
				glBegin(GL_POINTS);
				glVertex2f(i*PIXEL+PIXEL/2.0, j*PIXEL+PIXEL/2.0);
				glEnd();
			}
		}
		for(int i=0; i<NX; ++i){
			for(int j=0; j<NY; ++j){
				mat2[i][j] = sobrevive(i, j);		
			}
		}
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
			void swap(){
				int **tmp;
				tmp  = mat1;
				mat1 = mat2;
				mat2 = tmp;
			}
				void timer(int){
					pantalla();
					swap();
					glutTimerFunc(FRAMERATE, timer, 0);
				}
					int main (int argc, char **argv) {
						cout<<"---------- JUEGO DE LA VIDA ------------"<<endl;
						cout<<"Define el tamaño de los pixeles (recomendado: 1<=pixel<=90): ";cin>>PIXEL;
						glutInit(&argc, argv);
						glutInitWindowSize(XLIM,YLIM);
						glutInitWindowPosition(10,10);
						glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
						glutCreateWindow("Game Of Life");
						inicio();
						glutDisplayFunc(pantalla);
						timer(0);
						glutMainLoop();
						return 0;
					}
					
					
