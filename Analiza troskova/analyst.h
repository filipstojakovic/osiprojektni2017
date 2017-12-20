#ifndef ANALITCOMMANDS_H
#define ANALITCOMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "readfiles.h"
#include "strukture.h"

void analystMenu(NODE* );
int provera_slova_analyst(char );  // za Analyst menu
int provera_slovaYN_analyst(char ); // provjera yes || no za Analyst menu
char ponovo_meni_analyst();
void helpMenu_analyst(); // kratak opis funkcija u Analyst meniju

#endif // ANALITCOMMANDS_H
