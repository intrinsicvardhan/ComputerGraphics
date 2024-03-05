//span filling algorithm
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Span Filling Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250, 250, -250, 250);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = -250; i <= 250; i++) {
        glVertex2i(i, 0);
        glVertex2i(0, i);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100, 100);
    glVertex2i(100, -100);
    glVertex2i(-100, -100);
    glVertex2i(-100, 100);
    glEnd();
    glFlush();
    int x, y;
    for (int i = -250; i <= 250; i++) {
        for (int j = -250; j <= 250; j++) {
            glReadPixels(i, j, 1, 1, GL_RGB, GL_FLOAT, &x);
            if (x == 1.0) {
                y = j;
                while (x == 1.0) {
                    x = 0.0;
                    glReadPixels(i, y, 1, 1, GL_RGB, GL_FLOAT, &x);
                    y++;
                }
                glBegin(GL_POINTS);
                glColor3f(0.0, 1.0, 0.0);
                glVertex2i(i, y - 1);
                glEnd();
            }
        }
    }
    glFlush();
    glutMainLoop();
    return 0;
}


// Path: spanfillingalgos/span_filling.cpp
// Compare this snippet from boundaryfillingalgo/eight-connected.cpp: