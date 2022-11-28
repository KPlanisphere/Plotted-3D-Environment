#include "Casa.h"


extern GLuint texture[100];
extern float camX,camY,camZ;

Casa::Casa(){}

Cubo CUBO_HOME;
Piramide PYRA_HOME;
CollisionDetection CD_HOME;

void Casa::DrawCasa(float x,float y,float z){

    //PARED FRONTAL
    glPushMatrix();
    glTranslated(x+1,y+0,z+2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+2,z+2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+4,z+2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+4,z);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    //TOP DOOR
    glPushMatrix();
    glTranslated(x+1,y+2,z);
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[91]);
    CUBO_HOME.drawFace( -1.0, -1.0, -1.0,
                        -1.0,  1.0, -1.0,
                        -1.0,  1.0,  1.0,
                        -1.0, -1.0,  1.0);
    glPopMatrix();

    //BUTTOM DOOR
    glPushMatrix();
    glTranslated(x+1,y+0,z);
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[92]);
    CUBO_HOME.drawFace( -1.0, -1.0, -1.0,
                        -1.0,  1.0, -1.0,
                        -1.0,  1.0,  1.0,
                        -1.0, -1.0,  1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+1,y+0,z+-2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+2,z+-2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+4,z+-2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    //PARED TRASERA
    glPushMatrix();
    glTranslated(x+9,y+0,z+2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+2,z+2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+4,z+2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+9,y+4,z);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+0,z);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+9,y+0,z+-2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+2,z+-2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+4,z+-2);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    //PARED DER
    glPushMatrix();
    glTranslated(x+3,y+0,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+3,y+2,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+3,y+4,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+5,y+0,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+5,y+4,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+7,y+0,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+7,y+2,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+7,y+4,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    //PARED IZQ
    glPushMatrix();
    glTranslated(x+3,y+0,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+3,y+2,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+3,y+4,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+5,y+0,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+5,y+4,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+7,y+0,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+7,y+2,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+7,y+4,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[30],texture[30],texture[30],texture[30],texture[30],texture[30],1);
    glPopMatrix();

    //PILA 1
    glPushMatrix();
    glTranslated(x+1,y+0,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+2,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+4,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();

    //PILA 2
    glPushMatrix();
    glTranslated(x+1,y+0,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+2,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+1,y+4,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();


    //PILA 3
    glPushMatrix();
    glTranslated(x+9,y+0,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+2,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+4,z+4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();

    //PILA 4
    glPushMatrix();
    glTranslated(x+9,y+0,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+2,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+9,y+4,z+-4);
    glColor3f(1.0,1.0,1.0);
    CUBO_HOME.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();

    //TECHO
    glPushMatrix();
    glTranslated(x+5,y+11,z+0);
    glColor3f(1.0,1.0,1.0);
    PYRA_HOME.drawPyramid(texture[21],texture[21],texture[21],texture[21],texture[21],6);
    glPopMatrix();


    //CD FRONTAL
    CD_HOME.CheckCollsion(camX,camY,camZ,x+1,y+2,z+3,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+1,y+2,z+4,2.5,1); //<<<< TRONCO IZQ
    CD_HOME.CheckCollsion(camX,camY,camZ,x+1,y+2,z-3,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+1,y+2,z-4,2.5,1); //<<<< TRONCO DER

    //CD FRONTAL
    CD_HOME.CheckCollsion(camX,camY,camZ,x+9,y+2,z+3,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+9,y+2,z,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+9,y+2,z+4,2.5,1); //<<<< TRONCO IZQ 2
    CD_HOME.CheckCollsion(camX,camY,camZ,x+9,y+2,z-3,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+9,y+2,z-4,2.5,1); //<<<< TRONCO DER 2

    //CD DERECHO
    CD_HOME.CheckCollsion(camX,camY,camZ,x+3,y+2,z+4,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+5,y+2,z+4,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+7,y+2,z+4,2.5,1);

    //CD IZQUIERDO
    CD_HOME.CheckCollsion(camX,camY,camZ,x+3,y+2,z-4,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+5,y+2,z-4,2.5,1);
    CD_HOME.CheckCollsion(camX,camY,camZ,x+7,y+2,z-4,2.5,1);

}
