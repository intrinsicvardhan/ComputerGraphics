# Computer Graphics Algorithms Repository

This repository contains implementations of various computer graphics algorithms using OpenGL and GLUT. Below is a brief description of each algorithm implemented:

## Algorithms Implemented:

### 1. Eight Connected Boundary Fill Algorithm
- Description: This algorithm is used for filling polygons with a specified interior color. It employs an eight-connected approach to determine which pixels to fill.

### 2. Scanline Fill Algorithm
- Description: The scanline fill algorithm fills a polygon by scanning across the image horizontally, determining intersections with polygon edges, and filling the enclosed areas.

### 3. Span Fill Algorithm
- Description: Span fill algorithm fills the region by determining the minimum and maximum X-coordinates of the polygon edges intersecting a scanline.

### 4. Circle Drawing Algorithms:
   - Bresenham's Circle Drawing Algorithm
   - Midpoint Circle Drawing Algorithm
- Description: These algorithms are used to draw circles efficiently on the screen using discrete points.

### 5. Ellipse Midpoint Algorithm
- Description: The ellipse midpoint algorithm efficiently draws ellipses on the screen using a midpoint approach.

### 6. Line Drawing Algorithms:
   - DDA (Digital Differential Analyzer) Line Drawing Algorithm
   - Bresenham's Line Drawing Algorithm
- Description: These algorithms are used to draw lines between two given points on the screen.

## Instructions for Running:

1. Ensure you have OpenGL and GLUT installed on your system.
2. Compile the source files using a C++ compiler supporting OpenGL (e.g., g++).
3. Execute the compiled program to see the algorithm in action.
4. for linux: 
```bash
gcc polygon_scanline.cpp -o polygon_filling -lGL -lGLU -lglut -lm -lstdc++
```


