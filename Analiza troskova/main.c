#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
// ovakav komentar je za opis funkcije ili neke komande
/// ovakav komentar je ako treba neku izmjenu napraviti

int main()
{
    int w=checkFile();
    printf("%d\n",w);
     pocetno_zaglavlje();
    int flag=0,i=0;         //1 admin ili 0- analiticar
    while(!login(&flag) && i<4)
       {
           printf("*=============================================================================*\n");
            // signin();
    /// signin treba staviti na pravo mjesto
	   printf("False log in!\n");
           i++;
           printf("Attempts left : %d\n",(3-i));
           if(i==3)
           {
            printf("Sorry to many attempts !\n");
            return 0;
           }
       }
    // system("cls"); brise sve sa konzole
    printf("You are logged in successfully ");
    if(flag==0)
    {
        printf("as analiticar !\n");
         analystMenu();
    }
    else
    {
        printf("as administrator !\n");
        adminMenu();
    }
    getchar();
}
