#include "analyst.h"

void analystMenu()
{
    char c[200],t[200],q[200];
    printf("*=============================================================================*\n");
    printf("                        Welcome Analyst! \n\n\n");
    do{
    printf("*=============================================================================*\n");
    printf("[r] - review customer data\n");
    printf("[p] - review product data\n");
    printf("[w] - review of sale data\n");
    printf("[h] - help menu\n");
    printf("[e] - exit\n");
    scanf("%s",&c);
    strcpy(t,c);
     if(strlen(c)>1 || provera_slova2(c[0])!=1)//provjerava da li je unesono slovo jedno od ponudjenih
    {
        printf("Unknown letter !\n");
    }
    else if(c[0]=='e')//provjera za izlaz
    {
        printf("GOOOOODBAYYY! :D\n");

    }
    else if(c[0]=='h')
    {
        printf("help\n\n\n");
        c[0]=ponovo_meni(t[0]);
    }
    else if(c=='v')
    {
        printf("valuta\n\n\n");
        c[0]=ponovo_meni1(t[0]);
    }
    else if(c[0]=='c')
    {
        printf("acccoutn men\n\n\n");
        c[0]=ponovo_meni1(t[0]);
    }
    getchar();
     }while(c[0]!='e');
      printf("Exit\n");
     printf("*=============================================================================*\n");
}
char ponovo_meni1(char c)
{
    char t[111],s,q[111];
    int f=0;
    printf("Do you want to go back to manu ? \n");
    printf("[y] - yes\n");
    printf("[n] - no\n");
    do
        {
            gets(q);
        scanf("%s",&t);
        if(strlen(t)>1 || provera_slova11(t[0])==0 )
        printf("False letter!\n");
        else f=1;
        }while(f==0);
        if(t[0]=='y')
            s='a';
    else if(t[0]=='n')
        s='e';
        return s;
}
int provera_slova1(char s)
{
    if( s!='r' && s!='w' && s!='h' && s!='e' && s!='p')
            return 0;
   return 1;
}
int provera_slova11(char s)
{
    if( s!='y' &&  s!='n' )
            return 0;
   return 1;
}
