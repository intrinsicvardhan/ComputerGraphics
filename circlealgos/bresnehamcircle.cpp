#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

void init(); 
void display();

int main(int argc, char **argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Bresneham Circle Drawing Algorithm");
    
    init(); 
    glutDisplayFunc(display);
    
    glutMainLoop(); 
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

void display() {
    float h = 0.0, k = 0.0, r = 100; 
    float x = 0, y = r, d = 3-2*r; 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    while (x<=y) {
        glVertex2f(x+h, y+k);
        glVertex2f(-x+h, y+k);
        glVertex2f(x+h, -y+k);
        glVertex2f(-x+h, -y+k);
        glVertex2f(y+h, x+k);
        glVertex2f(-y+h, x+k);
        glVertex2f(y+h, -x+k);
        glVertex2f(-y+h, -x+k);
        if(d<0) {
            d += 4*x + 6; 
            ++x; 
        } else {
            d += 4*(x-y) + 10; 
            ++x; 
            --y; 
        }
    }
    glEnd(); 
    glFlush(); 
}
