#ifndef READFILES_H
#define READFILES_H

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

//#include <errno.h> za sad ne treba


int fileList();     // cita sve fajlove iz foldera " racuni "
FILE* findFile(char *);         // pronalazi fajl otvara ga i vraca pokazivac na taj otvoreni fajl

void renameFile(char *findname);        // pronadji fajl (findname) i promjeni naziv

#endif // READFILES_H
