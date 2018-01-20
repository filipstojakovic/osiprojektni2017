#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
#include "login.h"
#include "structures.h"

int letters_check_admin_menu(char ); // letters needed to chose a function in adminMenu
int letters_check_Y_N(char ); // letters for again_menu function : yes or no
int letters_check_D_C(char ); //letters for account_menu function : delete or create account
char adminMenu();//administrators main menu with all of his functions
char again_menu();//administrator can chose to go back to his menu or end the program
int account_menu();//options to create a new or delete an exsisting account
int delete_account();//deleting account from program
void helpMenu(); //menu with detail description of each adminMenu function
void printCurrency();//function that prints the current currency
void changeCurrency();//function that change current currency


#endif // ADMIN_H
