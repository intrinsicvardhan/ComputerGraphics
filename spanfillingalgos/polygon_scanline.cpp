#include <GL/glut.h>
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <limits> 

using namespace std;

struct Vertex { 
    double x, y; 
};

struct Edge {
    Vertex start, end;
};

vector<Vertex> vertices; 
vector<Edge> edges;

bool compareEdges(const Edge& e1, const Edge& e2) {
    return min(e1.start.y, e1.end.y) < min(e2.start.y, e2.end.y);
}
void init(void);
void fillPolygon(); 
void display(); 
void handleKeypress(unsigned char key, int x, int y); 

int main(int argc, char**argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scan-Line Algorithm"); 

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);

    //define the vertices of the polygon
    vertices.push_back({100, 100});
    vertices.push_back({200, 200});
    vertices.push_back({400, 150});
    vertices.push_back({300, 300});
    vertices.push_back({150, 400});

    glutMainLoop();
}

void drawScanLine(int y, vector<double>& intersections) {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for(size_t i = 0; i<intersections.size(); i+=2) {
        double x1 = intersections[i];
        double x2 = intersections[i+1];
        glVertex2d(x1, y);
        glVertex2d(x2, y);
    }
    glEnd();
}

void fillPolygon() {
    edges.clear();
    for (size_t i = 0; i < vertices.size(); i++) {
        Edge edge = {vertices[i], vertices[(i + 1) % vertices.size()]};
        edges.push_back(edge);
    }

    std::sort(edges.begin(), edges.end(), compareEdges);

    std::vector<double> intersections;
    for (int y = static_cast<int>(vertices[0].y); y <= static_cast<int>(vertices[vertices.size() - 1].y); y++) {
        intersections.clear();
        for (const Edge& edge : edges) {
            if ((edge.start.y <= y && edge.end.y >= y) || (edge.end.y <= y && edge.start.y >= y)) {
                double x;
                if (edge.start.y == edge.end.y) {
                    // Handle horizontal edges
                    x = std::min(edge.start.x, edge.end.x);
                } else {
                    x = edge.start.x + (y - edge.start.y) / (edge.end.y - edge.start.y) * (edge.end.x - edge.start.x);
                }
                intersections.push_back(x);
            }
        }
        std::sort(intersections.begin(), intersections.end());
        drawScanLine(y, intersections);
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (const Vertex& vertex : vertices) {
        glVertex2d(vertex.x, vertex.y);
    }
    glEnd(); 
    fillPolygon();
    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Escape key
            exit(0);
            break;
    }
}

