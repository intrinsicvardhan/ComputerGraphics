//iterative approach to eight connected algorithm 
#include <GL/glut.h>
#include <iostream>
#include <stack>

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

void boundaryFill(int x, int y, float fillColor[3], float borderColor[3]) {
    std::stack<std::pair<int, int>> pixelStack;
    pixelStack.push(std::make_pair(x, y));

    while (!pixelStack.empty()) {
        std::pair<int, int> current = pixelStack.top();
        pixelStack.pop();
        int x = current.first;
        int y = current.second;

        float interiorColor[3];
        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, interiorColor);

        if ((interiorColor[0] != borderColor[0] || interiorColor[1] != borderColor[1] || interiorColor[2] != borderColor[2]) &&
            (interiorColor[0] != fillColor[0] || interiorColor[1] != fillColor[1] || interiorColor[2] != fillColor[2])) {
            drawPixel(x, y);
            glColor3fv(fillColor);
            pixelStack.push(std::make_pair(x + 1, y));
            pixelStack.push(std::make_pair(x - 1, y));
            pixelStack.push(std::make_pair(x, y + 1));
            pixelStack.push(std::make_pair(x, y - 1));
        }
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
    boundaryFill(125, 125, fillColor, borderColor);

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
