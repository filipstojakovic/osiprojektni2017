#ifndef READFILES_H
#define READFILES_H

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
//neke biblioteke za rad sa fajlovima/folderima
//#include <stdlib.h>
//#include <string.h>
//#include <sys/types.h>
//#include <dirent.h>

//#include <errno.h>


int fileList();     // cita sve fajlove iz foldera " racuni "
int findFile(char *);

void renameFile(char *findname);

#endif // READFILES_H
