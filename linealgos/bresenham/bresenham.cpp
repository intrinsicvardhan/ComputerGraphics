#include <GL/glut.h>
#include <iostream>
#include <cmath>
//compile it using g++ bresenham.cpp -lGL -lGLU -lglut -lm -lstdc++ -o bresenham
using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluOrtho2D(0, 2, 0, 2);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS);
    glPointSize(2.0);
    glColor3f(1.0, 0.0, 0.0);
    float x1 = 0.4, y1 = 0.4, x2 = 0.98, y2 = 0.88;
    float dx = x2 - x1;
    float dy = y2 - y1;
    
    if(abs(dx) > abs(dy)) {
        float m = dy / dx;
        float p0 = 2 * dy - dx;
        float y = y1;
        
        for(float x = x1; x <= x2; x += 0.1) {
            glVertex2f(x, round(y));
            if(p0 < 0) {
                p0 += 2 * dy;
            } else {
                p0 += 2 * (dy - dx);
                y += m * 0.1;
            }
        }
    } else {
        float m = dx / dy;
        float p0 = 2 * dx - dy;
        float x = x1;
        
        for(float y = y1; y <= y2; y += 0.1) {
            glVertex2f(round(x), y);
            if(p0 < 0) {
                p0 += 2 * dx;
            } else {
                p0 += 2 * (dx - dy);
                x += m * 0.1;
            }
        }
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop(); 
    return 0;
}
