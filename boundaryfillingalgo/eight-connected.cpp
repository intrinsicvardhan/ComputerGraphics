#include <GL/glut.h>
#include <iostream>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set clear color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // Set the 2D orthographic viewing region
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void boundaryFill4(int x, int y, float fillColor[3], float borderColor[3]) { //4 connected
    float interiorColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, interiorColor);

    if ((interiorColor[0] != borderColor[0] || interiorColor[1] != borderColor[1] || interiorColor[2] != borderColor[2]) &&
        (interiorColor[0] != fillColor[0] || interiorColor[1] != fillColor[1] || interiorColor[2] != fillColor[2])) {
        drawPixel(x, y);
        glColor3fv(fillColor);
        boundaryFill4(x + 1, y, fillColor, borderColor);
        boundaryFill4(x - 1, y, fillColor, borderColor);
        boundaryFill4(x, y + 1, fillColor, borderColor);
        boundaryFill4(x, y - 1, fillColor, borderColor);
    }
}

void boundaryFill8(int x, int y, float fillColor[3], float borderColor[3]) {// 8connected
    float interiorColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, interiorColor);

    if ((interiorColor[0] != borderColor[0] || interiorColor[1] != borderColor[1] || interiorColor[2] != borderColor[2]) &&
        (interiorColor[0] != fillColor[0] || interiorColor[1] != fillColor[1] || interiorColor[2] != fillColor[2])) {
        drawPixel(x, y);
        glColor3fv(fillColor);
        boundaryFill8(x + 1, y, fillColor, borderColor);
        boundaryFill8(x - 1, y, fillColor, borderColor);
        boundaryFill8(x, y + 1, fillColor, borderColor);
        boundaryFill8(x, y - 1, fillColor, borderColor);
        boundaryFill8(x + 1, y + 1, fillColor, borderColor);
        boundaryFill8(x - 1, y + 1, fillColor, borderColor);
        boundaryFill8(x + 1, y - 1, fillColor, borderColor);
        boundaryFill8(x - 1, y - 1, fillColor, borderColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a square with a black border
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(150, 100);
    glVertex2i(150, 150);
    glVertex2i(100, 150);
    glEnd();

    // Fill the square with red color using boundary fill algorithm
    float fillColor[] = { 1.0, 0.0, 0.0 }; // Red color
    float borderColor[] = { 0.0, 0.0, 0.0 }; // Black border
    boundaryFill4(125, 125, fillColor, borderColor);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Boundary Fill Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
