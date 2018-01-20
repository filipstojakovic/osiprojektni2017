#ifndef ANALITCOMMANDS_H
#define ANALITCOMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include "readfiles.h"
#include "structures.h"

char analystMenu(NODE* );//the main analyst menu with all of his functions
int letters_check_analyst_menu(char ); //letters needed to chose a function in analystMenu
int letters_check_analyst_Y_N(char ); //letters for function again_menu_analyst
char again_menu_analyst();//analyst can chose to go back to his menu or end the program
void helpMenu_analyst(); //menu with detail description of each analystMenu function
void customerList(NODE *);//function that prints full name and surname of customers
void customerArtikls (NODE*,char*,char*);//function that shows a list of bills for specific customer
void artiklsByDate(NODE*,unsigned char);//function thay shows a list of bills for specific date
void productData(NODE*, char*);//function that shows all details of chosen product from all bills
void statistics_review(NODE*);//total company turnover
void bills_report();//prints all names of valid or invalid bills

#endif // ANALITCOMMANDS_H
