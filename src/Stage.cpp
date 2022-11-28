#include "Stage.h"
#include "Cubo.h"
#include "Piramide.h"
#include "CollisionDetection.h"
#include "Arbol.h"
#include "Casa.h"
#include "Slimes.h"
#include "ControlV.h"

extern GLuint texture[100];

extern float Theta;
//float Radio=1.0;
extern float PI;
extern float Direction[3];
extern GLfloat anguloSol;
extern float camX,camY,camZ;
extern bool CStatus[50];


//Variables para dibujar los ejes del sistema
extern float X_MIN;
extern float X_MAX;
extern float Y_MIN;
extern float Y_MAX;
extern float Z_MIN;
extern float Z_MAX;

//Figuras
Cubo CUBO;
Piramide PYRA;
CollisionDetection CD;
Arbol TREE;
Casa HOME;
Slimes SLIME;
extern ControlV CV[50];
extern int band[50];

//Constructor
Stage::Stage(){}

void Stage::drawAxis(){
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
}

void Stage::GeneralAmbient(void){
    //CUBO AMBIENTAL GIGANTE
    glPushMatrix();
    glTranslated(0,5,0);
    glColor3f(1.0,1.0,1.0);
    CUBO.drawCube(texture[0],texture[1],texture[2],texture[3],texture[4],texture[5],30);
    glPopMatrix();

    //CD LIMITES DEL MAPA
    for(int i = -30; i <= 30; i ++){
        CD.CheckCollsion(camX,camY,camZ,-30,2,i,2,2);
        CD.CheckCollsion(camX,camY,camZ,30,2,i,2,2);
        CD.CheckCollsion(camX,camY,camZ,i,2,-30,2,2);
        CD.CheckCollsion(camX,camY,camZ,i,2,30,2,2);
    }

    for(int i = -15; i <= 15;i++){
        for(int j = -15; j <= 15;j++){
            glPushMatrix();
            glTranslated(i*2,-2,j*2);
            CUBO.drawCube(texture[12],texture[12],texture[12],texture[12],texture[12],texture[12],1);
            glPopMatrix();
            //CD.CheckCollsion(camX,camY,camZ,i*2,-3,j*2,3);
        }
    }

    TREE.DrawArbol(10,0,8);
    TREE.DrawArbol(-10,0,20);
    TREE.DrawArbol(-10,0,-15);
    TREE.DrawArbol(-24,0,20);
    TREE.DrawArbol(0,0,-15);
    TREE.DrawArbol(7,0,-22);
    TREE.DrawArbol(23,0,-23);
    TREE.DrawArbol(20,0,4);

    HOME.DrawCasa(-10,0,0);
    HOME.DrawCasa(15,0,-10);
    HOME.DrawCasa(10,0,22);

    glPushMatrix();
    if(band[0] == 0){
        CV[0].setTZ(CV[0].getTZ()+0.09);
        if(CV[0].getTZ() > 10){
            band[0] = 1;
            glRotatef(-180, 1.0f, 0.0f, 0.0f);

        }
    }
    else if(band[0] == 1){
        CV[0].setTZ(CV[0].getTZ()-0.09);
        if(CV[0].getTZ() < -10){
            band[0] = 0;

        }
    }
    glTranslated(CV[0].getTX(),CV[0].getTY(),CV[0].getTZ());
    CD.CheckCollsion(camX,camY,camZ,CV[0].getTX(),CV[0].getTY()+2,CV[0].getTZ(),2,4);
    SLIME.DrawSlime(CV[0].getTX(),CV[0].getTY(),CV[0].getTZ());
    if(CStatus[1]){
        camX=-28.0;
        camY=2.0;
        camZ=0.0;
    }
    glPopMatrix();


//    glPushMatrix();
//    if(band[1] == 0){
//        CV[1].setTZ(CV[1].getTZ()-0.09);
//        if(CV[1].getTZ() < 10){
//            band[1] = 1;
//            glRotatef(-180, 1.0f, 0.0f, 0.0f);
//
//        }
//    }
//    else if(band[1] == 1){
//        CV[1].setTZ(CV[1].getTZ()+0.09);
//        if(CV[1].getTZ() > 10){
//            band[1] = 0;
//
//        }
//    }
//    glTranslated(CV[1].getTX(),CV[1].getTY(),CV[1].getTZ());
//    CD.CheckCollsion(camX,camY,camZ,CV[1].getTX(),CV[1].getTY()+2,CV[1].getTZ(),2,4);
//    SLIME.DrawSlime(CV[1].getTX(),CV[1].getTY(),CV[1].getTZ());
//    if(CStatus[4]){
//        camX=-28.0;
//        camY=2.0;
//        camZ=0.0;
//    }
//    glPopMatrix();
    //glPopMatrix();

    //dibujado de cubos sin textura
//    glPushMatrix();
//    glTranslated(0,10,0);
//    glColor3f(0.0,1.0,0.0);
//    glutSolidCube(1);
//    glPopMatrix();
//
//    CD.CheckCollsion(camX,camY,camZ,0,10,0,2);
//
//    glPushMatrix();
//    glTranslated(0,0,10);
//    glColor3f(0.0,0.0,1.0);
//    glutSolidCube(1);
//    glTranslated(0,0,-20);
//    glutSolidCube(1);
//    glPopMatrix();

}

void Stage::drawSphere(){
    //activando texturas
//    glEnable(GL_TEXTURE_2D);
//    glPushMatrix();
//    glTranslated(10,5,0);
//    glRotatef(-90, 1.0f, 0.0f, 0.0f);
//    glRotatef(anguloSol, 0.0f, 0.0f, 1.0f);
//    glColor3f(1.0,1.0,1.0);
//    glBindTexture(GL_TEXTURE_2D, texture[90]);
//    GLUquadric *qobj = gluNewQuadric();
//    gluQuadricTexture( qobj, GL_TRUE );
//    gluSphere( qobj, 1.0f, 20, 20 );
//    gluDeleteQuadric( qobj );
//    glPopMatrix();
//    glDisable(GL_TEXTURE_2D);
//    anguloSol = (anguloSol + 0.1 > 360) ? 0.0 : anguloSol + 5;
//    CD.CheckCollsion(camX,camY,camZ,10,5,0,2);
}
