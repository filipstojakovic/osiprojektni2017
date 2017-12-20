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
    //int flag=0,i=3,lista;
    NODE *head=0;

    head=fillHead();
    NODE *tmp=head;
    while(tmp)
    {
        printf("NAME: %s %s\n",tmp->pod.name,tmp->pod.surname);
        printf(" Artikli:\n");
        for(int i=0;i<tmp->pod.n;i++)
            printf("\t%s %s - %d - %d - %d\n",tmp->pod.art[i].name,tmp->pod.art[i].barcode,tmp->pod.art[i].kol,tmp->pod.art[i].cijena,tmp->pod.art[i].total);
        printf(" UKUPNO: %d + %.2f = %.2f\n",tmp->pod.total,tmp->pod.PDV,tmp->pod.sum);
        tmp=tmp->next;
    }


    flag=checkLogin(&flag); // funkcija koja provjerava da li je login ispravan, samo da main izgleda cisce
    printf("You are logged in successfully ");
    if(flag==1)
    {
        printf("as analyst !\n");
        Sleep(1000);// pauzira izvrsavanje programa na 3 sekunde da se procita poruka iznad
        system("cls");
        /*lista=fileList();
        if(i==0)
            printf("Can not open file in directory! \n");
        else
            printf("CAN OPEN FILE IN DIRECTORY!\n");*/
        analystMenu(head);
    }
    else
    {
        printf("as administrator !\n");
        Sleep(1000);// pauzira izvrsavanje programa na 3 sekunde da se procita poruka iznad
        system("cls");
        adminMenu(head);
    }
    getchar();

    /// free list

    return 0;
}
