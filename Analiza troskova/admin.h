#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
#include "login.h"

int provera_slova(char );  // za admin menu
int provera_slovaYN(char ); // yes || no
int provjera_slovaDC(char ); // 'd' or 'c'
void adminMenu();
char ponovo_meni();
int rad_sa_account();
int delete_account();

#endif // ADMIN_H
