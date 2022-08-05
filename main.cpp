#include <iostream>
#include <GL/glut.h> 
#include <windows.h>
#include <time.h>

#define XLIM 1280
#define YLIM 640

using namespace std;
void pantalla(){
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}
int main (int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(XLIM,YLIM);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Game Of Life");
	glutDisplayFunc(pantalla);
	glutMainLoop();
	return 0;
}
