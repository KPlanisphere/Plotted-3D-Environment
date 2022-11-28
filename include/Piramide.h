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

#ifndef PIRAMIDE_H
#define PIRAMIDE_H


class Piramide
{
    public:
        Piramide();
        void drawBase(float,float,float,
                      float,float,float,
                      float,float,float,
                      float,float,float);
        void drawLateralFace(float,float,float,
                      float,float,float,
                      float,float,float);
        void drawPyramid(GLint ,GLint ,GLint ,GLint ,GLint , float);

    private:
};

#endif // PIRAMIDE_H
