#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
#include "readfiles.h"
#include "readformats.h"
#include "strukture.h"
// ovakav komentar je za opis funkcije ili neke komande
/// ovakav komentar je ako treba neku izmjenu napraviti

int main()
{
    int flag=0,i=3;

    while(!login(&flag) && i>0)
       {

           printf("*=============================================================================*\n");
	   printf("False log in!\n");
           i--;
           if(i==0)
           {
            printf("Sorry no more attempts !\n");
            return 0;
           }
           printf("Attempts left : %d\n",i);

       }

    printf("You are logged in successfully ");

    if(flag==0)
    {
        printf("as analiticar !\n");
         system("cls");
         analystMenu();
    }
    else
    {
        printf("as administrator !\n");
         system("cls");
        adminMenu();
    }
    getchar();
}
