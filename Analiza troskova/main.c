#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
#include "readfiles.h"
#include "readformats.h"
#include "strukture.h"
#include "windows.h"
// ovakav komentar je za opis funkcije ili neke komande
sebi/// ovakav komentar je ako treba neku izmjenu napraviti

int flag = 0; // prebacio flag da bude globalna prom

int main()
{
    //int flag=0,i=3,lista;

    flag=checkLogin(&flag); // funkcija koja provjerava da li je login ispravan, samo da main izgleda cisce
    printf("You are logged in successfully ");
    if(flag==0)
    {
        printf("as analyst !\n");
        Sleep(3000);// pauzira izvrsavanje programa na 3 sekunde da se procita poruka iznad
        system("cls");
        /*lista=fileList();
        if(i==0)
            printf("Can not open file in directory! \n");
        else
            printf("CAN OPEN FILE IN DIRECTORY!\n");*/
        analystMenu();
    }
    else
    {
        printf("as administrator !\n");
        Sleep(3000);// pauzira izvrsavanje programa na 3 sekunde da se procita poruka iznad
        system("cls");
        adminMenu();
    }
    getchar();
    return 0;
}
