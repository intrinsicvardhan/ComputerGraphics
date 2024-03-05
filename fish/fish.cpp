#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>

void init();

void drawFish() {

      // Body (blue color)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.2);
    glVertex2f(-0.5, 0.2);
    glVertex2f(0.5, 0.2);
    glVertex2f(0.5, -0.2);
    glEnd();

    // Tail (green color)
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.8, -0.2);
    glEnd();

    // Fins (red color)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.1, 0.5);
    glVertex2f(-0.1, 0.2);

    glVertex2f(-0.3, -0.3);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, -0.2);
    glEnd();

    // Mouth (black color)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.3, -0.1);
    glVertex2f(-0.4, -0.1);
    glEnd();


}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 

    drawFish(); 

    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutCreateWindow("Fish");
    glutDisplayFunc(display);

    init();

    glutMainLoop();
}

void init() {
    glClearColor(1,1,1,1); 
    glColor3f(0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
}
