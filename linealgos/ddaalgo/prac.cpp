#include <GL/glut.h>
#include <iostream>
#include <cmath>
 

using namespace std;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10); //set the clipping planes for the window
}

void display();

int main(int argc, char ** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("dda prac"); 
    
    init(); 
    glutDisplayFunc(display);
    glutMainLoop();

    return 0; 
}


void display() { 
    float x1 = 1, y1 = 1, x2 = -4, y2 = 5;
    glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer
    glBegin(GL_POINTS); 
    glColor3f(1.0, 0.0, 0.0); 
    float dx = x2 - x1;
    float dy = y2 - y1; 


    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_inc = dx/steps; 
    float y_inc = dy/steps; 

    float x = x1; 
    float y = y1;
    glVertex2f(x, y); 

    for(int i = 0; i < steps; i++) {
        x += x_inc; 
        y += y_inc; 
        glVertex2f(x, y); 
    }
    glEnd(); 
    glFlush();
}