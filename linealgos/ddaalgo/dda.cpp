//line drawing dda algorithm using glut 
#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    float x1 = 0.1, y1 = 0.1, x2 = 0.9, y2 = 0.9;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy/dx;
    while(x1<x2){
        glVertex2f(x1, y1);
        x1 += 0.001;
        y1 += m*0.001;
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
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}