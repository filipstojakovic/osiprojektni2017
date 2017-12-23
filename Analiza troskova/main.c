#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
#include "readfiles.h"
#include "readformats.h"
#include "strukture.h"
#include "windows.h"
// ovakav komentar je za opis funkcije ili neke komande
/// ovakav komentar je ako treba neku izmjenu napraviti

int flag = 0; // prebacio flag da bude globalna prom

int main()
{
    NODE *head=0;
    head=fillHead();
    flag=checkLogin(&flag); // funkcija koja provjerava da li je login ispravan, samo da main izgleda cisce
    printf("You are logged in successfully ");
    if(flag==1)
    {
        printf("as analyst !\n");
        ///      Sleep(1000);// pauzira izvrsavanje programa na par sekundi da se procita poruka iznad
        system("cls");
        analystMenu(head);
    }
    else
    {
        printf("as administrator !\n");
        ///      Sleep(1000);// pauzira izvrsavanje programa na par sekundi da se procita poruka iznad
        system("cls");
        adminMenu(head);
    }
    getchar();

    /// free list

    return 0;
}
