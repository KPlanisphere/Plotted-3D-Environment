#include "Arbol.h"
#include "CollisionDetection.h"

extern GLuint texture[100];
extern float camX,camY,camZ;

Arbol::Arbol(){}

Cubo CUBO_TREE;
Piramide PYRA_TREE;
CollisionDetection CD_TREE;

void Arbol::DrawArbol(float x,float y,float z){

    //TRONCO
    glPushMatrix();
    glTranslated(x+0,y+0,z+0);
    glColor3f(1.0,1.0,1.0);
    CUBO_TREE.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+0,y+2,z+0);
    glColor3f(1.0,1.0,1.0);
    CUBO_TREE.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+0,y+4,z+0);
    glColor3f(1.0,1.0,1.0);
    CUBO_TREE.drawCube(texture[20],texture[20],texture[20],texture[20],texture[20],texture[20],1);
    glPopMatrix();

    //HOJAS XD
    glPushMatrix();
    glTranslated(x+0,y+7,z+0);
    glColor3f(1.0,1.0,1.0);
    PYRA_TREE.drawPyramid(texture[12],texture[12],texture[12],texture[12],texture[12],3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(x+0,y+9,z+0);
    glColor3f(1.0,1.0,1.0);
    PYRA_TREE.drawPyramid(texture[12],texture[12],texture[12],texture[12],texture[12],2);
    glPopMatrix();

    CD_TREE.CheckCollsion(camX,camY,camZ,x,y+1,z,3,0);
}
