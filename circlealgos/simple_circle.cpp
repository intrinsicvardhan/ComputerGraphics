//simple circle using glut 
#include <GL/glut.h>
#include <cmath>
#include <iostream>
//compile it using g++ simple_circle.cpp -lGL -lGLU -lglut -lstdc++ -o simple_circle
using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < 360; i++) { 
        float theta = i * 3.14159 / 180; // get the current angle in radians
        glVertex2f(0.5 + 0.5 * cos(theta), 0.5 + 0.5 * sin(theta)); 
    }
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}