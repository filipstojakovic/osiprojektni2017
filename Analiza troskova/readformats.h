#ifndef FORMAT1_H
#define FORMAT1_H

#include "structures.h"
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

POD readFormat1(char*);//reeds all bills data that are in the format 1
POD readFormat2(char*);//reeds all bills data that are in the format 2
POD readFormat3(char*);//reeds all bills data that are in the format 3
POD readFormat4(char*);//reeds all bills data that are in the format 4
POD readFormat5(char*);//reeds all bills data that are in the format 5

#endif // FORMAT1_H
