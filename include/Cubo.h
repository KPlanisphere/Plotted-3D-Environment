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

#ifndef CUBO_H
#define CUBO_H


class Cubo{
    public:
        Cubo();
        void drawFace(float,float,float,
                      float,float,float,
                      float,float,float,
                      float,float,float);
        void drawCube(GLint ,GLint ,GLint ,GLint ,GLint ,GLint , float);
    private:
};

#endif // CUBO_H
