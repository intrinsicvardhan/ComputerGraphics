#include <iostream>
#include <GL/glut.h>
#include <cmath>



using namespace std;

void ellipsePlotPoints(int, int, int, int);

void display() {
    int rx = 100, ry = 50, xc = 0, yc = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glBegin(GL_POINTS);

    int x = 0, y = ry;
    int rx2 = rx * rx, ry2 = ry * ry;
    int tworx2 = 2 * rx2, twory2 = 2 * ry2;
    int px = 0, py = tworx2 * y;

    // Region 1
    int p1 = round(ry2 - (rx2 * ry) + 0.25 * rx2);

    while (px < py) {
        x++;
        px += twory2;
        if (p1 < 0) {
            p1 += ry2 + px;
        } else {
            y--;
            py -= tworx2;
            p1 += ry2 + px - py;
        }
        ellipsePlotPoints(xc, yc, x, y);
    }

    // Region 2
    int p2 = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y > 0) {
        y--;
        py -= tworx2;
        if (p2 > 0) {
            p2 += rx2 - py;
        } else {
            x++;
            px += twory2;
            p2 += rx2 - py + px;
        }
        ellipsePlotPoints(xc, yc, x, y);
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

void ellipsePlotPoints(int xc, int yc, int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
