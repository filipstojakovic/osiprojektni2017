#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
#include "readfiles.h"
// ovakav komentar je za opis funkcije ili neke komande
/// ovakav komentar je ako treba neku izmjenu napraviti

/// ubacena struktura ACCOUNTA, treba u kodu stavljati strukturu umjesto puno
int main()
{
//    delete_accountFILIP();
//    system("pause");

    int flag=0,i=0,c;
    START:
     pocetno_zaglavlje(0);
     printf("[1] Login\n[2] Sign In\nOption: ");
     do
     {
         scanf("%d",&c);
     }while(c<1 || c>2);
    system("cls");
    if(c==1)
    {while(!login(&flag) && i<4)
       {

	   printf("False log in!\n");
           i++;
           printf("Attempts left : %d\n",(3-i));
           if(i==3)
           {
            printf("Sorry to many attempts !\n");
            return 0;
           }
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
    }
    else
    {
        pocetno_zaglavlje(2);
        signin();
        goto START;
    }
}
