#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkFile();
int checkAccount(char *,char* , char *, int *);
int login(int *);
void pocetno_zaglavlje();
int provjera_imena(char *);
int provjera_pina(char *);
int checkFile1();


#endif // LOGIN_H
