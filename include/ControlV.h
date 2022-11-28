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

#ifndef CONTROLV_H
#define CONTROLV_H


class ControlV{
    public:
        ControlV();
        void OriginalControlVariables();
        void ResetBands();
        void setTXYZ(float , float , float );
        void setTX(float);
        void setTY(float);
        void setTZ(float);
        void setSXYZ(float , float , float );
        void setTheta(float);

        float getTX();
        float getTY();
        float getTZ();

    private:
        float TX,TY,TZ;
        float SX,SY,SZ;
        float Theta;
};

#endif // CONTROLV_H
