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
    while(1)
    {
        char ch;
        flag=checkLogin(&flag); // 1- admin , 0 - analiticar
        if(flag==2)
        {
            printf("You don't have a right account, but you are welcome to come any time! \n\n") ;
            printf("                                Exit\n");
            printf("*=============================================================================*\n");
            Sleep(2000);
            break;
        }
        else if(flag==0)
        {
            printf("You are logged in successfully as analyst !\n");
            head=fillHead();
            Sleep(2000);// pauzira izvrsavanje programa na par sekundi da se procita poruka iznad
            system("cls");//cisti ekran programa
            ch=analystMenu(head);
        }
        else
        {
            printf("You are logged in successfully as administrator !\n");
            Sleep(2000);// pauzira izvrsavanje programa na par sekundi da se procita poruka iznad
            system("cls");//cisti ekran programa
            ch=adminMenu();
        }
        if(ch=='e')
        {
            printf("                              Program is now shutting down!\n\n");
            Sleep(1000);
            printf("                                 Press any key to exit!\n");
            break;
        }
    }
    getchar();
    freeHead(&head);// free list
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


