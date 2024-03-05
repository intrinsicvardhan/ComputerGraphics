#include <GL/glut.h>
#include <cmath>

#define WIDTH 800
#define HEIGHT 600

float theta = 0.0;  // Initial rotation angle

void drawDonut() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0);  // Red color

    glBegin(GL_POINTS);

    for (float phi = 0; phi < 2 * M_PI; phi += 0.1) {
        for (float theta = 0; theta < 2 * M_PI; theta += 0.1) {
            float x = 0.5 * (2 + cos(theta)) * cos(phi);
            float y = 0.5 * (2 + cos(theta)) * sin(phi);
            float z = 0.5 * sin(theta);

            glVertex3f(x, y, z);
        }
    }

    glEnd();

    glutSwapBuffers();
}

void update(int value) {
    theta += 0.02;  // Update rotation angle

    if (theta > 2 * M_PI) {
        theta -= 2 * M_PI;  // Keep theta within [0, 2*pi)
    }

    glutPostRedisplay();  // Request a redraw
    glutTimerFunc(16, update, 0);  // Set up the next timer
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 27) {
        // 'Esc' key: Exit the program
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Rotating Donut");

    glutDisplayFunc(drawDonut);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25, update, 0);  // Set up a timer for continuous animation

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, (double)WIDTH / (double)HEIGHT, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glutMainLoop();

    return 0;
}
