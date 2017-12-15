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
        printf("==========================\n");
        printf("[l] - logout\n");
        printf("[e] - exit\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || provera_slova_analyst(c)!=1)    //provjerava da li je unesono slovo jedno od ponudjenih
        {
            printf("Unknown letter !\n");
        }
        else if(c=='e')     //provjera za izlaz
        {
            printf("GOOOOODBAYYY! \n");
        }
        else if(c=='h')
        {
            helpMenu_analyst();
            c=ponovo_meni_analyst();
        }
        else if(c=='r')
        {
            printf("review customer data \n\n\n");
            c=ponovo_meni_analyst();
        }
        else if(c=='p')
        {
            printf("review product data\n\n\n");
            c=ponovo_meni_analyst();
        }
        else if(c=='w')
        {
            printf("review of sale data\n\n\n");
            c=ponovo_meni_analyst();
        }
        fflush(stdin);
    }
    while(c!='e' && c!='l');
    if(c=='e')
    {
        printf("                              Exit\n");
        printf("*=============================================================================*\n");
    }
    if(c=='l')// vraca u main ako je odabrana opcija Logout
    {
        printf("Logout successful!\n");
        main(); /// Ako neko ima bolju ideju kako doci do logina ponovo... Ovo je jako lose, al' nisam imao druge ideje
    }
}

int provera_slova_analyst(char s)
{
    if( s!='r' && s!='w' && s!='h' && s!='e' && s!='p' && s!='l')
        return 0;
    return 1;
}

char ponovo_meni_analyst()
{
    char c,ch,s;
    do
    {
        fflush(stdin);
        printf("Do you want to go back to menu ? \n");
        printf("[y] - yes\n");
        printf("[n] - no\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || provera_slovaYN_analyst(c)!=1)
        {
            printf("Wrong option!\n");
            continue;
        }

    }while(ch!='\n' || provera_slovaYN_analyst(c)!=1);

    if(c=='y')
        s='y';
    else if(c=='n')
        s='e';
    system("cls");
    return s;
}

int provera_slovaYN_analyst( char s)  //funkcija za provjeru slova Y | N za ponovo_menu
{
    if( s=='y' ||  s=='n' )
        return 1;
    return 0;
}

void helpMenu_analyst() // help menu za analystMenu
{
    system("cls");
    printf("Review Customer Data:\n");
    printf("This option reviews all data for a specific customer.\n\n\n");
    printf("Review Product Data:\n");
    printf("This option reviews all data for a specific product. \n\n\n");
    printf("Review Of Sale Data:\n");
    printf("This option reviews data for all sales made in a specific timeline \n\n\n");
}
