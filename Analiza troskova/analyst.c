#include "analyst.h"

void analystMenu()
{
//    char c[200],t[200],q[200];
    char c,ch;
    printf("*=============================================================================*\n");
    printf("                        Welcome Analyst! \n\n\n");
    do
    {
        fflush(stdin);
        printf("*=============================================================================*\n");
        printf("[r] - review customer data\n");
        printf("[p] - review product data\n");
        printf("[w] - review of sale data\n");
        printf("[h] - help menu\n");
        printf("[e] - exit\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || provera_slova1(c)!=1)    //provjerava da li je unesono slovo jedno od ponudjenih
        {
            printf("Unknown letter !\n");
        }
        else if(c=='e')     //provjera za izlaz
        {
            printf("GOOOOODBAYYY! \n");

        }
        else if(c=='h')
        {
            printf("help\n\n\n");
            c=ponovo_meni();
        }
        else if(c=='r')
        {
            printf("review customer data \n\n\n");
            c=ponovo_meni();
        }
        else if(c=='p')
        {
            printf("review product data\n\n\n");
            c=ponovo_meni();
        }
        else if(c=='w')
        {
            printf("review of sale data\n\n\n");
            c=ponovo_meni();
        }
        fflush(stdin);
    }
    while(c!='e');
    printf("                              Exit\n");
    printf("*=============================================================================*\n");
}

int provera_slova1(char s)
{
    if( s!='r' && s!='w' && s!='h' && s!='e' && s!='p')
        return 0;
    return 1;
}


