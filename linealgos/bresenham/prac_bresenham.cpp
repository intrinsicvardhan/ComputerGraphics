#include <GL/glut.h>
#include <iostream>
#include <cmath> 

using namespace std;

void init(void);
void display();
void bresneham(float, float, float, float);

int main(int argc, char ** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100);

    
    glutCreateWindow("bresenham");
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
}


void init() { 
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-10, 10, -10, 10);
}


void display() {
    float x1, y1, x2, y2;
    cout << "Enter x1, y1, x2, y2: ";
    cin >> x1 >> y1 >> x2 >> y2;
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    bresneham(x1, y1, x2, y2); 
    glEnd(); 
}

void bresneham(float x1, float y1, float x2, float y2) {
    
}
