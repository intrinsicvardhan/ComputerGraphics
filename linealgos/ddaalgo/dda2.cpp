#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); // Use GL_LINES to draw a line segment
    glPointSize(2.0);
    glColor3f(1.0, 0.0, 0.0);

    float x1 = 4, y1 = 7, x2 = 92, y2 = 90;
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xinc = dx / steps;
    float yinc = dy / steps;
    float x = x1;
    float y = y1;

    glVertex2f(x1, y1); // Start point of the line

    for (int i = 0; i < steps; i++) {
        x += xinc;
        y += yinc;
        glVertex2f(x, y); // End point of the line
    }

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
