#include <GL/glut.h>

void display() {
    glClearColor(1,1,1,1); 
    glClear(GL_COLOR_BUFFER_BIT); 

    glOrtho(0,1,0,1,-1,1); // set the orthographic projection matrix

    glColor3f(0,0,1);
    glBegin (GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0); 

    glEnd(); 
    glFlush(); 
}

int main(int argc, char **argv) {
    glutInit(&argc, argv); 
    glutCreateWindow("Square");
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

