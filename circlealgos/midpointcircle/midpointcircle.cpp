//Midpoint circle algoorithm using GLUT 
#include <iostream>
#include <GL/glut.h>

#define radius 100

using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    int x = 0, y = radius, p = 1-radius;
    while(x<=y) {
        glVertex2i(x,y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);
        glVertex2i(y,x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-y,-x);

        if(p<0) {
            p += 2*x+3;
        } else {
            p += 2*(x-y)+5;
            y--;
        } 
        x++;
        }
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200.0, 200.0, -200, 200);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Circle Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}