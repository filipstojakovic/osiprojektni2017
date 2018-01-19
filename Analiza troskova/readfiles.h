#ifndef READFILES_H
#define READFILES_H

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "strukture.h"
#include "math.h"

//#include <errno.h> za sad ne treba


int fileList();     // cita sve fajlove iz foldera " racuni "
void renameFile(char *findname);        // pronadji fajl (findname) i promjeni naziv
int detectFormat(char *);                   // format racuna....return 1, 2 ,3 ,4 ,5
NODE *fillHead();
void fillNode(NODE**, POD);
int isValid(POD);

#endif // READFILES_H
