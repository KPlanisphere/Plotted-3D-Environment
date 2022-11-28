#include "Slimes.h"

extern GLuint texture[100];
extern float camX,camY,camZ;



Cubo CUBO_SLIME;
Piramide PYRA_SLIME;
CollisionDetection CD_SLIME;

Slimes::Slimes(){}


void Slimes::DrawSlime(float x,float y,float z){

    glPushMatrix();
    glTranslated(x,y,z);
    glColor3f(1.0,1.0,1.0);
    CUBO_SLIME.drawCube(texture[40],texture[41],texture[41],texture[41],texture[41],texture[41],0.5);
    glPopMatrix();

}
