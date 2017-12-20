#ifndef READFILES_H
#define READFILES_H

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "strukture.h"

//#include <errno.h> za sad ne treba


int fileList();     // cita sve fajlove iz foldera " racuni "
FILE* findFile(char *);         // pronalazi fajl otvara ga i vraca pokazivac na taj otvoreni fajl

void renameFile(char *findname);        // pronadji fajl (findname) i promjeni naziv
int detectFormat(char *);                   // format racuna....return 1, 2 ,3 ,4 ,5

NODE *fillHead();


#endif // READFILES_H
