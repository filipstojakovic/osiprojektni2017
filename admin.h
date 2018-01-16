#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
#include "login.h"
#include "strukture.h"

int provera_slova(char );  // za admin menu
int provera_slovaYN(char ); // yes || no
int provjera_slovaDC(char ); // 'd' or 'c'
char adminMenu();
char ponovo_meni();
int rad_sa_account();
int delete_account();
void helpMenu(); // kratak opis funkcija u administratorskom meniju

#endif // ADMIN_H
