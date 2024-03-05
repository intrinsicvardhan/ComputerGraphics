#include <GL/gl.h>  //header file for the OpenGL api
#include <GL/glu.h>
#include <GL/glut.h>

void display(); 

void init() {
    glClearColor(0,1,1,1); //r, g, b, alpha (transparency)
}

int main(int argc, char **argv) {
    //argc and argv are used to initialize the glut library
    
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //RGB is the color mode and double is the buffering mode

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500, 500); 
    
    
    glutCreateWindow("Window 1"); 
    glutDisplayFunc(display); //takes one argument which is the function pointer
    init();


    glutMainLoop();//execution loop which runs continuously unless close instruction is provided
    return 0;
}


void display() {
    //what functions to be called in the display callback
    //always clear the canvas first
    glClear(GL_COLOR_BUFFER_BIT); //clear the frame buffer
    //default color for clearing color is black
    glFlush(); //display the frame buffer on the display window
    glLoadIdentity(); //resets all the matrix - resets the coordinate system
}