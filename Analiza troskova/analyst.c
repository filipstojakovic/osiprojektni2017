#include "analyst.h"

void analystMenu()
{

    int pom=0;
    char c,t;
    printf("*=============================================================================*\n");
    printf("                        Welcome Analyst! \n\n\n");
    do{
    printf("*=============================================================================*\n");
    printf("[r] - review customer data\n");
    printf("[p] - review product data\n");
    printf("[w] - review of sale data\n");
    printf("[h] - help menu\n");
    printf("[e] - exit\n");
    scanf("%c",&c);
    if(provera_slova1(c)==0)
    {
        printf("Unknown letter !\n");
    }
    else if(c=='e')
    {
        printf("GOOOOODBAYYY! :D\n");

    }
    else if(c=='h')
    {
        printf("help");
    }
    else if(c=='w')
    {
        printf("valuta");
    }
    else if(c=='p')
    {
        printf("product men\n");
    }
     else if(c=='r')
    {
        printf("costumer men\n");
    }
    if(c=='h' || c=='r' || c=='p' || c=='w')
    {
    do
        {
    printf("Do you want to go back to manu ? \n");
    printf("[y] - yes\n");
    printf("[n] - no\n");
    scanf("%c",&t);
    if(provera_slova222(t)==0)
        printf("False letter!\n");
    else if(t=='y')
    pom=1;
    else if(t=='n')
        c='e';
    }while(pom==0);
    }
     }while(c!='e');
}

int provera_slova1(char s)
{
    if( s!='r' && s!='w' && s!='h' && s!='e' && s!='p')
            return 0;
   return 1;
}
int provera_slova222(char s)
{
    if( s!='y' &&  s!='n' )
            return 0;
   return 1;
}
