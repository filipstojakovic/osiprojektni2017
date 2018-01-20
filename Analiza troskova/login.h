#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkFile();//function that checks login to program
int checkAccount(char *,char* , char *, int *);//function that compares entered account with existing ones
int login(int *);//enter the accounts name,surname and pin to compare with existing ones
void first_header();//login header
int letters_only_allowed(char *);//function used in login for enterying correct name and surname
int numbers_check(char *);//function used in login for enterying correct pin
int checkLogin(int); // function that checks the correctness of login

#endif // LOGIN_H
