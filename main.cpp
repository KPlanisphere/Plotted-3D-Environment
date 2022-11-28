// ███████╗░█████╗░░█████╗░██████╗░██╗░░░░░░██████╗░
// ██╔════╝██╔══██╗██╔══██╗██╔══██╗██║░░░░░██╔════╝░
// █████╗░░██║░░╚═╝██║░░╚═╝██║░░██║██║░░░░░██║░░██╗░
// ██╔══╝░░██║░░██╗██║░░██╗██║░░██║██║░░░░░██║░░╚██╗
// ██║░░░░░╚█████╔╝╚█████╔╝██████╔╝███████╗╚██████╔╝
// ╚═╝░░░░░░╚════╝░░╚════╝░╚═════╝░╚══════╝░╚═════╝░

//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA
//FACULTAD DE CIENCIAS DE LA COMPUTACIÓN

//ALEX ABDIEL RUANO FLORES
//JESUS HUERTA AGUILAR

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "RgbImage.h"
#include "Stage.h"
#include "FileManager.h"
#include "Cubo.h"
#include "Movement.h"
#include "Arbol.h"
#include "ControlV.h"

#include <GL/glut.h>
#include <math.h>

#define FPS 60
#define TO_RADIANS 3.14/180.0

//se define la cantidad de texturas que se manejaran
GLuint	texture[100];
char* filename[100];  //<-------------Se puede borrar (creo...)
char ActualKey;
bool CStatus[50];
int band[50];
ControlV CV[50];
ControlV CVG;

//Variables para matrices de rotacion y traslación
//La inicializacion del angulo depende de la posicion inicial del observador y su
//direccion
float Theta=0;
//float Radio=1.0;
float PI = 3.14159265359;
//float Direction[3] = {0.0,0.0,-1.0};
//GLfloat anguloSol = 0.0f;

//Variables para dibujar los ejes del sistema
float X_MIN=-500;
float X_MAX=500;
float Y_MIN=-500;
float Y_MAX=500;
float Z_MIN=-500;
float Z_MAX=500;

FileManager FM;
Stage S;
Cubo C;

Movement MOVE;
Movement *MOVES;

//width and height of the window ( Aspect ratio 16:9 )
const int width = 16*50;
const int height = 9*50;

float pitch = 0.0, yaw= -90.0;
float camX=-28.0,camY=2.0,camZ=0.0;
bool jumping = false;

//
//struct Motion{
//    bool Forward,Backward,Left,Right,Up,Down;
//};
//
//Motion motion = {false,false,false,false,false,false};

bool Forward    = false;
bool Backward   = false;
bool Left       = false;
bool Right      = false;
bool Up         = false;
bool Down       = false;

/* This function just draws the scene. I used Texture mapping to draw
   a chessboard like surface. If this is too complicated for you ,
   you can just use a simple quadrilateral */
//
//void draw(){
//    glEnable(GL_TEXTURE_2D);
//    GLuint texture;
//    glGenTextures(1,&texture);
//
//    unsigned char texture_data[2][2][4] =
//                    {
//                        0,0,0,255,
//                        255,255,255,255,
//                        255,255,255,255,
//                        0,0,0,255
//                    };
//
//    glBindTexture(GL_TEXTURE_2D,texture);
//    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,texture_data);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
//                    GL_NEAREST);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
//                    GL_NEAREST);
//
//    glBegin(GL_QUADS);
//
//    glTexCoord2f(0.0,0.0);  glVertex3f(-50.0,-5.0,-50.0);
//    glTexCoord2f(25.0,0.0);  glVertex3f(50.0,-5.0,-50.0);
//    glTexCoord2f(25.0,25.0);  glVertex3f(50.0,-5.0,50.0);
//    glTexCoord2f(0.0,25.0);  glVertex3f(-50.0,-5.0,50.0);
//
//    glEnd();
//
//    glDisable(GL_TEXTURE_2D);
//}



void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,16.0/9.0,1,75);
    glMatrixMode(GL_MODELVIEW);
}

/*this funtion is used to keep calling the display function periodically
  at a rate of FPS times in one second. The constant FPS is defined above and
  has the value of 60 */
void timer(int){
    glutPostRedisplay();
    glutWarpPointer(width/2,height/2);
    glutTimerFunc(1000/FPS,timer,0);
}

void passive_motion(int x,int y){
    /* two variables to store X and Y coordinates, as observed from the center
      of the window
    */
    int dev_x,dev_y;
    dev_x = (width/2)-x;
    dev_y = (height/2)-y;

    /* apply the changes to pitch and yaw*/
    yaw+=(float)dev_x/50.0;
    pitch+=(float)dev_y/50.0;

    //PARA NO TENER GRADOS MAYORES A 360 (+/-)
    if(yaw > 360 || yaw < -360){
        yaw = 0;
    }
}


void keyboard(unsigned char key,int x,int y){
    ActualKey = key;
    switch(key){
    case 'W':
    case 'w':
        Forward = true;
        break;
    case 'A':
    case 'a':
        Left = true;
        break;
    case 'S':
    case 's':
        Backward = true;
        break;
    case 'D':
    case 'd':
        Right = true;
        break;
    case 32:
        Up = true;
        break;
    case 'C':
    case 'c':
        Down = true;
        break;
    }
}

void keyboard_up(unsigned char key,int x,int y){
    switch(key){
        case 'W':
        case 'w':
            Forward = false;
            break;
        case 'A':
        case 'a':
            Left = false;
            break;
        case 'S':
        case 's':
            Backward = false;
            break;
        case 'D':
        case 'd':
            Right = false;
            break;
        case 32:
            Up = false;
            break;
        case 'C':
        case 'c':
            Down = false;
            break;
        }
}

void init(){
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutWarpPointer(width/2,height/2);
    glClearColor(0,0,0,0);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    FM.FileLoader();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    MOVE.camera();

    //draw();
    //S.drawAxis();
    S.GeneralAmbient();
    S.drawSphere();
    std::cout << '(' << camX << ',' << camY << ',' << camZ << ')' << std::endl;
    glutSwapBuffers();
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("PLANISPHERE | FINAL GRAFICACION PROJECT");
    CVG.OriginalControlVariables();

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0,timer,0);    //more info about this is given below at definition of timer()
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}
