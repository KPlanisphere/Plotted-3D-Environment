#include "CollisionDetection.h"

extern float yaw;
float distance;
extern char ActualKey;

extern bool CStatus[50];

extern bool Forward;
extern bool Backward;
extern bool Left;
extern bool Right;
extern bool Up;
extern bool Down;

extern float camX,camY,camZ;

CollisionDetection::CollisionDetection(){}

void CollisionDetection::CheckCollsion( float x1,float y1,float z1,
                                        float x2,float y2,float z2, float _size, int obj){

    distance = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2) + pow(z1 - z2,2));

    if(distance < _size){
        CStatus[obj] = true;
        switch(ActualKey){
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
    else{
        CStatus[obj]= false;
    }
}
