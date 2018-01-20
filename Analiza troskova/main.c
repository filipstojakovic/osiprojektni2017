#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
#include "readfiles.h"
#include "readformats.h"
#include "structures.h"
#include "windows.h"

int flag ;//variable that is used for flowing thru main function
void freeHead(NODE **);//function that has been used to clear allocated space in memory
NODE *head=0;
float currency=1.00;//variable that is used for changing the currency

int main()
{
    while(1)
    {
        char ch;
        flag=checkLogin(&flag);
        if(flag==2)
        {
            printf("You don't have a right account, but you are welcome to come any time! \n\n") ;
            printf("                                   Exit\n");
            printf("*=============================================================================*\n");
            Sleep(2000);
            break;
        }
        else if(flag==0)
        {
            printf("You are logged in successfully as analyst !\n");
            head=fillHead();
            Sleep(2000);    //paused the program on 2 seconds
            system("cls");  //cleans the screen
            ch=analystMenu(head);
        }
        else
        {
            printf("You are logged in successfully as administrator !\n");
            Sleep(2000);
            system("cls");
            ch=adminMenu();
        }
        if(ch=='e')
        {
            printf("                      Program is now shutting down!\n\n");
            Sleep(1000);
            printf("                         Press any key to exit!\n");
            break;
        }
    }
    getchar();
    freeHead(&head);//free list
    return 0;
}

void freeHead(NODE **head)
{
    if(*head==0)
        return;
    while(*head)
    {
        NODE *p=(*head)->next;
        for(int i=0; i<(*head)->num_bill; i++)
            free((*head)->artdate[i].art);
        free((*head)->artdate);
        free(*head);
        *head=p;
    }
}


