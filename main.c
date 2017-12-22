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
//    while(head)
//    {
//        printf("%s %s mj=%hhu  god=%u\ntotal=%d PDV=%.2f sum=%.2f\n",head->name,head->surname,head->artdate[0].mj,head->artdate[0].god,head->artdate[0].total,head->artdate[0].PDV,head->artdate[0].sum);
//        printf(" Artikl:\n");
//        for(int j=0; j<head->n_racuna; j++)
//            for(int i=0; i<head->artdate[j].n_art; i++)
//                printf("\t%s %d %d %d\n",head->artdate[j].art[i].name,head->artdate[j].art[i].kol,head->artdate[j].art[i].cijena,head->artdate[j].art[i].total);
//       printf("\n");
//        head=head->next;
//    }



    flag=checkLogin(&flag); // funkcija koja provjerava da li je login ispravan, samo da main izgleda cisce
    printf("You are logged in successfully ");
    if(flag==1)
    {
        printf("as analyst !\n");
  ///      Sleep(1000);// pauzira izvrsavanje programa na 3 sekunde da se procita poruka iznad
        system("cls");
        analystMenu(head);
    }
    else
    {
        printf("as administrator !\n");
  ///      Sleep(1000);// pauzira izvrsavanje programa na 3 sekunde da se procita poruka iznad
        system("cls");
        adminMenu(head);
    }
    getchar();

    /// free list

    return 0;
}
