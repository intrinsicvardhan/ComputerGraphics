//drawing some primitives

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>


void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();

    glPointSize(10.0); //size of the point is set to 10 pixels

    //glBegin() is used to tell what kind of primitive are we starting to draw
    glBegin(GL_TRIANGLES); 

    glVertex2f(0.0,5.0);
    glVertex2f(4.0, -3.0);
    glVertex2f(-4.0, -3.0);


    glEnd();

    glFlush();

}

void init() { 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
}

void reshape(int, int);

int main(int argc, char **argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500,500); 

    glutCreateWindow("Window 2");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init(); 

    glutMainLoop(); 
    return 0;
}


//width and height is the width and height of the window
void reshape(int width, int height) { //used by the api whenever the window is reshaped - changing the clipping area
    //result in the distortion of the graphic if not defined
    //viewport is the actual area where the graphic is displayed
    glViewport(0,0,(GLsizei) width, (GLsizei) height); // specify the bottom left corner of the viepwort along with its height and width
    //projection
    
    //different matrices are to be manipulated to display
    glMatrixMode(GL_PROJECTION); // used to change the matrix mode
    glLoadIdentity(); //first reset all the parameters of the model view matrix
    gluOrtho2D(-10, 10, -10, 10); // origin should be at the centre
    glMatrixMode(GL_MODELVIEW); //always be in the model view matrix to draw stuff
    


}