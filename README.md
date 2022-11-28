# Plotted 3D Environment (OpenCraft)

## Overview

Plotted 3D Environment is a graphical project that simulates a 3D environment using OpenGL. The project aims to demonstrate various graphical techniques, including camera movement, texture mapping, collision detection, and object animations.

## Project Description

This project is inspired by Minecraft and is named OpenCraft. The goal is to navigate through a field with obstacles and enemies to find a specific object to win the game. The player is in first-person view and can move in all directions except up and down. The environment includes trees, houses, and other objects, with collision detection to prevent moving through them. Enemies move randomly and colliding with them results in losing the game.

<p align= "center">
    <img src="https://github.com/KPlanisphere/binary-tree-operations/assets/60454942/58e05fe9-f970-4ffa-8614-e9689d4cfe4a" style="width: 70%; height: auto;">
</p>

## Files and Structure

The repository contains the following files and directories:

- `PFinal_V1.cbp`: The project file for Code::Blocks IDE.
- `PFinal_V1.depend`: Dependency file for the project.
- `PFinal_V1.layout`: Layout configuration file for the project.
- `main.cpp`: The main source code file for the project.
- `Imagenes/`: Directory containing images used in the project.
- `bin/`: Directory for binary files.
- `include/`: Directory for header files.
- `obj/`: Directory for object files.
- `src/`: Directory for additional source files.
- `textura0.bmp` to `textura5.bmp`: Bitmap texture files used in the project.

## Features

### Object Creation and Animation

The project defines several 3D objects that implement animations through translations, rotations, and scaling. Each object is managed through its own class to maintain control over its specific variables and behaviors.

### Collision Detection

Collision detection ensures that objects do not pass through each other. This is managed by a dedicated class that detects if an object collides with any other object in the scene.

### First-Person View Navigation

The player navigates the environment in a first-person view. The camera movement is synchronized with the player's movement, controlled by keyboard inputs.

### Texture Mapping

Objects in the scene are textured using images loaded from files. The FileManager class handles the loading and application of textures to various objects.

### State Management

The project uses OpenGL's state stack to apply geometric transformations to objects. This includes using functions like `glPushMatrix` and `glPopMatrix` to manage the state.

## Main Source File: `main.cpp`

The main logic of the project is implemented in `main.cpp`. Below is a brief overview of its content:

```cpp
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "RgbImage.h"
#include "Stage.h"
#include "FileManager.h"
#include "Cubo.h"
#include "Movement.h"
#include "Arbol.h"
#include "ControlV.h"

#define FPS 60
#define TO_RADIANS 3.14159265358979323846 / 180.0

GLint tex;
char filename[100];
char ActualKey;
bool CStatus[50];
int band[50];
ControlV CV[50];
ControlV CVG;

void init(void) {
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
    glClearColor(0, 0, 0, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    FM.FileLoader();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    MOVE.camera();
    S.drawAxis();
    S.GeneralAmbient();
    S.drawSphere();
    std::cout << '(' << camX << ',' << camY << ',' << camZ << ')' << std::endl;
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 16.0 / 9.0, 1, 75);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x = (width / 2) - x;
    int dev_y = (height / 2) - y;
    yaw += (float)dev_x / 50.0;
    pitch += (float)dev_y / 50.0;
    if (yaw > 360) yaw = 0;
    else if (yaw < -360) yaw = 0;
}

void keyboard(unsigned char key, int x, int y) {
    ActualKey = key;
    switch (key) {
        case 'W':
        case 'w':
            Forward = true;
            break;
        case 'A':
        case 'a':
            Left = true;
            break;
        case 'S':
        case 's':
            Backward = true;
            break;
        case 'D':
        case 'd':
            Right = true;
            break;
        case 32:
            Up = true;
            break;
        case 'C':
        case 'c':
            Down = true;
            break;
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
        case 'W':
        case 'w':
            Forward = false;
            break;
        case 'A':
        case 'a':
            Left = false;
            break;
        case 'S':
        case 's':
            Backward = false;
            break;
        case 'D':
        case 'd':
            Right = false;
            break;
        case 32:
            Up = false;
            break;
        case 'C':
        case 'c':
            Down = false;
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Plotted 3D Environment | Final Project");
    CVG.OriginalControlVariables();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutMainLoop();
    return 0;
}
```

## How to Build and Run

### Prerequisites

-   Code::Blocks IDE
-   OpenGL and GLUT libraries

### Steps

1.  Clone the repository:
    
```bash
    git clone https://github.com/KPlanisphere/Plotted-3D-Environment.git
```

2.  Open the `PFinal_V1.cbp` project file in Code::Blocks.
3.  Build and run the project within the IDE.