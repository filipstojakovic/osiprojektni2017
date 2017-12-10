#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
#include "readfiles.h"
#include "format1.h"
#include "strukture.h"
// ovakav komentar je za opis funkcije ili neke komande
/// ovakav komentar je ako treba neku izmjenu napraviti

int main()
{

   POD pod= readFormat1("format1.txt"); // procitaj racun koji je oblika format 1
    printf("Name: %s\nDatum: %d/%d/%d\n",pod.name,pod.dan,pod.mj,pod.god);
    for(int i=0;i<pod.n;i++)
        printf("%s %s %d %d %d\n",pod.art[i].name,pod.art[i].barcode,pod.art[i].kol,pod.art[i].cijena,pod.art[i].total);
    system("pause");

     //system("cls");
    int flag=0,i=0;

    while(!login(&flag) && i<4)
       {

           printf("*=============================================================================*\n");
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
    getchar();
}
