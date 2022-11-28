#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "RgbImage.h"
#include "Cubo.h"
#include "Piramide.h"
#include "CollisionDetection.h"

#include <GL/glut.h>
#include <math.h>

#define FPS 60
#define TO_RADIANS 3.14/180.0

#ifndef CASA_H
#define CASA_H

class Casa
{
    public:
        Casa();
        void DrawCasa(float,float,float);


    private:
};

#endif // CASA_H
