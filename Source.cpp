#include <GL/freeglut.h>
#include <glm/glm.hpp>

#define WINDOW_WIDTH 640;
#define WINDOW_HEIGHT 480;
#define PI_F 3.14159265358979f;

GLint WindowWidth = WINDOW_WIDTH;
GLint WindowHeight = WINDOW_HEIGHT;

void displayPoligonoEquilatero() {
	int i; 
	//MINIMO 3
	int n_vertices = 100;
	int radio = 100;
	GLfloat twicePi = 2.0f * PI_F;
	int x = 0, y = 0; //centro del polygono

	glClearColor(0.7, 0.8, 0.6, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.3, 0.6, 0.7, 1);
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // vertice inicial
	for (i = 0; i <= n_vertices; i++) {
		GLfloat xi = x + (radio * cos(i * twicePi / n_vertices));
		GLfloat yi = y + (radio * sin(i * twicePi / n_vertices));
		glVertex2f(xi,yi);
	}
	glEnd();
	glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble x0 = (WindowWidth / 2);
	GLdouble y0 = (WindowHeight / 2);

	gluOrtho2D(-x0, x0, -y0, y0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);

	glutCreateWindow("Dibujar un circulo");
	glutDisplayFunc(displayPoligonoEquilatero);
	glutReshapeFunc(reshape);

	glutMainLoop();
	
	return EXIT_SUCCESS;
}