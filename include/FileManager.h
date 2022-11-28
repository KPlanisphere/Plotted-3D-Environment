#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "RgbImage.h"

#include <GL/glut.h>
#include <math.h>

#define FPS 60
#define TO_RADIANS 3.14/180.0

#ifndef FILEMANAGER_H
#define FILEMANAGER_H


class FileManager{
    public:
        FileManager();
        void FileLoader();
        void loadTextureFromFile(char *, int);

    private:
};

#endif // FILEMANAGER_H
