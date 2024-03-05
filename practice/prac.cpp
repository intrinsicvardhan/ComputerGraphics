#include <GL/glut.h>
#include <iostream>
#include <cmath> 

//compile using g++ prac.cpp -lGL -lGLU -lglut -lm -lstdc++ -o prac
void init(void); 

void display();


int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Practice"); 
    init() ;

    glutDisplayFunc(display);
    glutMainLoop() ;

    return 0;
}

void init() { 
    glClearColor(0.0, 0.0, 0.0, 1.0); // set the background color to black
    glMatrixMode(GL_PROJECTION); // set the matrix mode to projection
    glLoadIdentity(); // reset the matrix
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // set the clipping area to -1.0 to 1.0
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // clear the color buffer
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); // set the color to red
    glVertex2f(0.0, 0.0); 
    glVertex2f(0.4,0.2); 
    glVertex2f(0.4,-0.2); 
    glEnd(); 
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0); 
    glVertex2f(0.4, 0.2); 
    glVertex2f(0.6, 0.2); 
    glVertex2f(0.6, -0.2);
    glVertex2f(0.4, -0.2);
    glEnd();
    glFlush();
}