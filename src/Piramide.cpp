#include "Piramide.h"

Piramide::Piramide(){}

void Piramide::drawBase(float x1, float y1, float z1,
                    float x2, float y2, float z2,
                    float x3, float y3, float z3,
                    float x4, float y4, float z4){
   glBegin(GL_QUADS);
       glTexCoord2f(0.0, 0.0);
       glVertex3f(x1, y1, z1);

       glTexCoord2f(0.0, 1.0);
       glVertex3f(x2, y2, z2);

       glTexCoord2f(1.0, 1.0);
       glVertex3f(x3, y3, z3);

       glTexCoord2f(1.0, 0.0);
       glVertex3f(x4, y4, z4);
   glEnd();
}

void Piramide::drawLateralFace(float x1, float y1, float z1,
                    float x2, float y2, float z2,
                    float x3, float y3, float z3){
   glBegin(GL_TRIANGLES);
       glTexCoord2f(0.0, 0.0);
       glVertex3f(x1, y1, z1);

       glTexCoord2f(0.0, 1.0);
       glVertex3f(x2, y2, z2);

       glTexCoord2f(1.0, 1.0);
       glVertex3f(x3, y3, z3);

   glEnd();
}


//  Draw a cube with the specific texture
void Piramide::drawPyramid(GLint FFront,GLint FRight,GLint FBack,GLint FLeft,GLint FInf, float X){
   //Activate textures
   glEnable(GL_TEXTURE_2D);
   //front face
   glBindTexture(GL_TEXTURE_2D, FFront);
   drawLateralFace(-1.0*X, -1.0*X,  1.0*X,
                      0*X,  1.0*X,    0*X,
                    1.0*X, -1.0*X,  1.0*X);
   //right face
   glBindTexture(GL_TEXTURE_2D, FRight);
   drawLateralFace( 1.0*X, -1.0*X,  1.0*X,
                      0*X,  1.0*X,    0*X,
                    1.0*X, -1.0*X, -1.0*X);
   //back face
   glBindTexture(GL_TEXTURE_2D, FBack);
   drawLateralFace( 1.0*X, -1.0*X, -1.0*X,
                      0*X,  1.0*X,    0*X,
                   -1.0*X, -1.0*X, -1.0*X);
   //left face
   glBindTexture(GL_TEXTURE_2D, FLeft);
   drawLateralFace(-1.0*X, -1.0*X, -1.0*X,
                      0*X,  1.0*X,  0*X,
                   -1.0*X, -1.0*X,  1.0*X);
   //Inferior
   glBindTexture(GL_TEXTURE_2D, FInf);
   drawBase(-1.0*X, -1.0*X,  1.0*X,
            -1.0*X, -1.0*X, -1.0*X,
             1.0*X, -1.0*X, -1.0*X,
             1.0*X, -1.0*X,   1.0*X);
   //Disamble textures
   glDisable(GL_TEXTURE_2D);
}
