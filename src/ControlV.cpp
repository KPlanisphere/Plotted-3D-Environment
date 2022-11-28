#include "ControlV.h"

extern ControlV CV[50];
extern int band[50];
extern bool CStatus[50];

ControlV::ControlV(){
    TX = TY = TZ = 0;
    SX = SY = SZ = 0;
    Theta = 0;
}

void ControlV::OriginalControlVariables(){

    for(int i = 0;i < 50;i++){
        band[i] = 0;
        CStatus[i] = false;
    }
    CV[0].setTXYZ(-10,0,-10);
    CV[1].setTXYZ(3,0,10);
    //CV[0].setTX(-15);
}

void ControlV::ResetBands(){
    for(int i = 0;i < 50;i++){
        band[i] = 0;
    }
}

//SETTERS
void ControlV::setTXYZ(float x, float y, float z){
    TX = x;
    TY = y;
    TZ = z;
}

void ControlV::setTX(float x){
    TX = x;
}
void ControlV::setTY(float y){
    TY = y;
}
void ControlV::setTZ(float z){
    TZ = z;
}

void ControlV::setSXYZ(float x, float y, float z){
    SX = x;
    SY = y;
    SZ = z;
}

void ControlV::setTheta(float ang){
    Theta = ang;
}

//GETTERS
float ControlV::getTX(){
    return TX;
}

float ControlV::getTY(){
    return TY;
}

float ControlV::getTZ(){
    return TZ;
}


