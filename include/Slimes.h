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

#ifndef SLIMES_H
#define SLIMES_H


class Slimes
{
    public:
        Slimes();
        void DrawSlime(float ,float ,float );

    private:
};

#endif // SLIMES_H
