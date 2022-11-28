#include "Cubo.h"

Cubo::Cubo(){}

void Cubo::drawFace(float x1, float y1, float z1,
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

//  Draw a cube with the specific texture
void Cubo::drawCube(GLint FFront,GLint FRight,GLint FBack,GLint FLeft,GLint FSup,GLint FInf, float X){
   //Activate textures
   glEnable(GL_TEXTURE_2D);
   //front face
   glBindTexture(GL_TEXTURE_2D, FFront);        //                        A                           PLANISPHERE ENTERPRISES
   drawFace(-1.0*X, -1.0*X,  1.0*X,             //                       AAA    Y
            -1.0*X,  1.0*X,  1.0*X,             //                        E     SUPERIOR
             1.0*X,  1.0*X,  1.0*X,             //                        E
             1.0*X, -1.0*X,  1.0*X);            //                        E
   //right face                                 //                        E
   glBindTexture(GL_TEXTURE_2D, FRight);        //                        E
   drawFace( 1.0*X, -1.0*X,  1.0*X,             //    P L A N I S P H E R E P L A N
             1.0*X,  1.0*X,  1.0*X,             //    L K                 E        K
             1.0*X,  1.0*X, -1.0*X,             //    A   K               E           K
             1.0*X, -1.0*X, -1.0*X);            //    N     K             E             K
   //back face                                  //    I       K                           K
   glBindTexture(GL_TEXTURE_2D, FBack);         //    S         K                           K
   drawFace( 1.0*X, -1.0*X, -1.0*X,             //    P           P L A N I S P H E R E P L A N
             1.0*X,  1.0*X, -1.0*X,             //    H           L                           L
            -1.0*X,  1.0*X, -1.0*X,             //    E   LEFT    A                           A
            -1.0*X, -1.0*X, -1.0*X);            //    R   FACE    N                           N                 X
   //left face                                  //    E           I                           I                 RIGHT FACE
   glBindTexture(GL_TEXTURE_2D, FLeft);         //    P           S                           S
   drawFace(-1.0*X, -1.0*X, -1.0*X,             //    L           P                           P                      4
            -1.0*X,  1.0*X, -1.0*X,             //    A           H             O             H======================44>
            -1.0*X,  1.0*X,  1.0*X,             //    P           E               O           E                      4
            -1.0*X, -1.0*X,  1.0*X);            //      K         R                 O         R
   //Superior                                   //        K       E                   O       E
   glBindTexture(GL_TEXTURE_2D, FSup);          //          K     P                     O     P
   drawFace(-1.0*X,  1.0*X,  1.0*X,             //            K   L                       O   L
            -1.0*X,  1.0*X, -1.0*X,             //              K A                         O A
             1.0*X,  1.0*X, -1.0*X,             //                P L A N I S P H E R E P L A N
             1.0*X,  1.0*X,  1.0*X);            //                                              O
   //Inferior                                   //                                                O
   glBindTexture(GL_TEXTURE_2D, FInf);          //                                                  O
   drawFace(-1.0*X, -1.0*X,  1.0*X,             //                                    Z               O
            -1.0*X, -1.0*X, -1.0*X,             //                                    FRONT FACE        O
             1.0*X, -1.0*X, -1.0*X,             //                                                        O X
             1.0*X, -1.0*X,  1.0*X);            //                                                        X X
   //Disamble textures
   glDisable(GL_TEXTURE_2D);
}
