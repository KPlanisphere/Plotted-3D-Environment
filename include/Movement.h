#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "RgbImage.h"

#include <GL/glut.h>
#include <math.h>

#define FPS 60
#define TO_RADIANS 3.14/180.0

#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>

class Movement
{
    public:
        Movement();
        //void passive_motion(int ,int );
        void camera();
//        void keyboard(unsigned char ,int ,int );
//        void keyboard_up(unsigned char ,int ,int );


    private:
};

#endif // MOVEMENT_H
