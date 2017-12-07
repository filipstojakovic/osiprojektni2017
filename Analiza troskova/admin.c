#include "admin.h"

void adminMenu()
{
    char c,t;
    printf("*=============================================================================*\n");
    printf("                    Welcome Administrator! \n\n\n");
    do{
    printf("*=============================================================================*\n");
    printf("[c] - account managment\n");
    printf("[v] - currency settings\n");
    printf("[h] - help menu\n");
    printf("[e] - exit\n");
    c=getchar();
    t=c;
    if(provera_slova2(c)!=1)//provjerava da li je unesono slovo jedno od ponudjenih
    {
        printf("Unknown letter !\n");
    }
    else if(c=='e')//provjera za izlaz
    {
        printf("GOOOOODBAYYY! :D\n");

    }
    else if(c=='h')
    {
        printf("help\n\n\n");
        c=ponovo_meni(t);
    }
    else if(c=='v')
    {
        printf("valuta\n\n\n");
        c=ponovo_meni(t);
    }
    else if(c=='c')
    {
        printf("acccoutn men\n\n\n");
        c=ponovo_meni(t);
    }
     }while(c!='e');
}
char ponovo_meni(char c)
{
    char t,s='a';
    int pom=0;
    printf("Do you want to go back to manu ? \n");
    printf("[y] - yes\n");
    printf("[n] - no\n");
    do
        {
    scanf("%c",&t);
    if(provera_slova22(t)==0)
        printf("False letter!\n");
    else if(t=='y')
    pom++;
    else if(t=='n')
        s='e';
        }while(pom==0);
        return s;
}
int provera_slova2(char s)
{
    if( s!='c'&& s!='v' && s!='h' && s!='e')
            return 0;
   return 1;
}
int provera_slova22(char s)
{
    if( s=='y' ||  s=='n' )
            return 1;
   return 0;
}
