#include "Movement.h"

Movement::Movement(){}

//struct Motion{
//    bool Forward,Backward,Left,Right,Up,Down;
//};
//
//Motion motion = {false,false,false,false,false,false};

extern char ActualKey;

extern const int width;
extern const int height;

extern float pitch, yaw;
extern float camX,camY,camZ;
extern bool jumping;

extern bool Forward;
extern bool Backward;
extern bool Left;
extern bool Right;
extern bool Up;
extern bool Down;

//void Movement::passive_motion(int x,int y){
//    /* two variables to store X and Y coordinates, as observed from the center
//      of the window
//    */
//    int dev_x,dev_y;
//    dev_x = (width/2)-x;
//    dev_y = (height/2)-y;
//
//    /* apply the changes to pitch and yaw*/
//    yaw+=(float)dev_x/50.0;
//    pitch+=(float)dev_y/50.0;
//
//    //PARA NO TENER GRADOS MAYORES A 360 (+/-)
//    if(yaw > 360 || yaw < -360){
//        yaw = 0;
//    }
//}

void Movement::camera(){
    if(Forward){
        camX += cos((yaw+90)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90)*TO_RADIANS)/5.0;
    }

    if(Backward){
        camX += cos((yaw+90+180)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90+180)*TO_RADIANS)/5.0;
    }

    if(Left){
        camX += cos((yaw+90+90)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90+90)*TO_RADIANS)/5.0;
    }

    if(Right){
        camX += cos((yaw+90-90)*TO_RADIANS)/5.0;
        camZ -= sin((yaw+90-90)*TO_RADIANS)/5.0;
    }

    if(Up){
        camY += 0.1;
    }

    if(Down){
        camY -= 0.1;
    }

    //limit the values of pitch
    //between -60 and 70

    if(pitch>=70)
        pitch = 70;
    if(pitch<=-60)
        pitch=-60;

    glRotatef(-pitch,1.0,0.0,0.0); // Along X axis
    glRotatef(-yaw,0.0,1.0,0.0);    //Along Y axis

    //MANO XD
    //glPushMatrix();
    //glTranslatef(-camX,-camY+1,-camZ);
    //glTranslated(-camX,-camY,-camZ);
    //C.drawCube(texture[12],texture[12],texture[12],texture[12],texture[12],texture[12],2);
    //glPopMatrix();
    //std::cout << yaw << std::endl;
    glTranslatef(-camX,-camY,-camZ);
}

//void Movement::keyboard(unsigned char key,int x,int y){
//    ActualKey = key;
//    switch(key){
//    case 'W':
//    case 'w':
//        motion.Forward = true;
//        break;
//    case 'A':
//    case 'a':
//        motion.Left = true;
//        break;
//    case 'S':
//    case 's':
//        motion.Backward = true;
//        break;
//    case 'D':
//    case 'd':
//        motion.Right = true;
//        break;
//    case 32:
//        motion.Up = true;
//        break;
//    case 'C':
//    case 'c':
//        motion.Down = true;
//        break;
//    }
//}
//void Movement::keyboard_up(unsigned char key,int x,int y){
//    switch(key){
//    case 'W':
//    case 'w':
//        motion.Forward = false;
//        break;
//    case 'A':
//    case 'a':
//        motion.Left = false;
//        break;
//    case 'S':
//    case 's':
//        motion.Backward = false;
//        break;
//    case 'D':
//    case 'd':
//        motion.Right = false;
//        break;
//    case 32:
//        motion.Up = false;
//        break;
//    case 'C':
//    case 'c':
//        motion.Down = false;
//        break;
//    }
//}
