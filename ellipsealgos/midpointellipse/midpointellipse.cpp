#include <iostream>
#include <GL/glut.h>
#include <cmath>

void init();
void display();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

void display() {
    float a = 100.0, b = 50.0, h = 0.0, k = 0.0;
    float a_2 = a * a, b_2 = b * b;
    float x = 0, y = b;
    float p1 = b_2 - (a_2 * b) + (0.25 * a_2);

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);

    // Phase 1
    while (a_2 * (y - 0.5) > b_2 * (x + 1)) {
        glVertex2f(x + h, y + k);
        glVertex2f(-x + h, y + k);
        glVertex2f(x + h, -y + k);
        glVertex2f(-x + h, -y + k);

        if (p1 < 0) {
            p1 += b_2 * (2 * x + 3);
        } else {
            p1 += b_2 * (2 * x + 3) + a_2 * (-2 * y + 2);
            y--;
        }
        x++;
    }

    // Phase 2
    p1 = b_2 * (x + 0.5) * (x + 0.5) + a_2 * (y - 1) * (y - 1) - a_2 * b_2;

    while (y >= 0) {
        glVertex2f(x + h, y + k);
        glVertex2f(-x + h, y + k);
        glVertex2f(x + h, -y + k);
        glVertex2f(-x + h, -y + k);

        if (p1 > 0) {
            p1 += a_2 * (-2 * y + 3);
        } else {
            p1 += b_2 * (2 * x + 2) + a_2 * (-2 * y + 3);
            x++;
        }
        y--;
    }

    glEnd();
    glFlush();
}