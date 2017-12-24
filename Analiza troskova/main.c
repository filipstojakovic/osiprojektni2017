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
void freeHead(NODE **);

NODE *head=0;

int main()
{

    freeHead(&head);    // zbog logout opcije

    flag=checkLogin(&flag); // 1- admin , 0 - analiticar

    printf("You are logged in successfully ");
    if(flag==0)
    {
        printf("as analyst !\n");
        head=fillHead();
        //      Sleep(1000);// pauzira izvrsavanje programa na par sekundi da se procita poruka iznad
        system("cls");
        analystMenu(head);
    }
    else
    {
        printf("as administrator !\n");
        //      Sleep(1000);// pauzira izvrsavanje programa na par sekundi da se procita poruka iznad
        system("cls");
        adminMenu();
    }
    getchar();

    // free list
    freeHead(&head);
    return 0;
}

void freeHead(NODE **head)
{
    if(*head==0)
        return;
    while(*head)
    {
        NODE *p=(*head)->next;
        for(int i=0; i<(*head)->n_racuna; i++)
            free((*head)->artdate[i].art);
        free((*head)->artdate);
        free(*head);
        *head=p;
    }
}


