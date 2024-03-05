//Arc algorithm by trigonometric method
#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std; 

const float radius = 0.5;
const float theta1 = M_PI/3.0; // Starting angle in radians
const float theta2 = M_PI; // Ending angle in radians

void init(void);
void display(void);

int main(int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500.0, 500.0);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sector Drawing Algorithm");

    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 

    return 0;
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0); // Center of the sector
    // Draw the arc
    for (float theta = theta1; theta <= theta2; theta += 0.01) {
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }

    // Draw the radial lines
    float x1 = radius * cos(theta1);
    float y1 = radius * sin(theta1);
    float x2 = radius * cos(theta2);
    float y2 = radius * sin(theta2);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
}