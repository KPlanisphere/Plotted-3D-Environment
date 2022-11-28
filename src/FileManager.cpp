#include "FileManager.h"


extern GLuint texture[100];

char* FName[100];

FileManager::FileManager(){}

void FileManager::FileLoader(){
    //ENVIRONMENT  - RESERVADO: 0 - 9
    FName[ 0] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Environment\\FFRONT.bmp";
    FName[ 1] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Environment\\FRIGHT.bmp";
    FName[ 2] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Environment\\FBACK.bmp";
    FName[ 3] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Environment\\FLEFT.bmp";
    FName[ 4] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Environment\\FSUP.bmp";
    FName[ 5] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Environment\\FINF.bmp";

    //GRASS        - RESERVADO: 10 - 19
    FName[10] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Grass\\pastoLateral.bmp";
    FName[11] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Grass\\pastoSuperior.bmp";
    FName[12] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Grass\\pastoSuperiorNoche.bmp";

    //WOOD         - RESERVADO: 20 - 29
    FName[20] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Wood\\realWood.bmp";
    FName[21] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Wood\\wood.bmp";

    //STONE         - RESERVADO: 30 - 39
    FName[30] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Stone\\stone.bmp";

    //STONE         - RESERVADO: 40 - 49
    FName[40] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Slime\\slimeFACE.bmp";
    FName[41] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Slime\\slimeSIDE.bmp";

    //...

    //EXTRAS       - RESERVADO: 90 - 100
    FName[90] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Extras\\lesky.bmp";
    FName[91] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Extras\\topDOOR.bmp";
    FName[92] = "A:\\Principal\\Documentos\\Code Projects\\Codeblocks\\PFinal_V1\\Imagenes\\Extras\\infDOOR.bmp";
    for(int i = 0; i < 100;i++){
        loadTextureFromFile(FName[i],i);
    }
}

//Read a texture map from a BMP bitmap file.
void FileManager::loadTextureFromFile(char *filename, int index)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	//glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( filename );

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &texture[index]);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[index]);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}
