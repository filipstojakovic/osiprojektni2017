#include "admin.h"
#include <string.h>
#include <stdio.h>
#include "login.h"
#include "structures.h"
#define EURO 1.00
#define KM 1.95
#define DINAR 118.37

extern float currency;//variable that is used for changing the currency

char adminMenu()
{
    char c,ch;
    printf("*=============================================================================*\n");
    printf("                             Welcome Administrator! \n\n");
    printCurrency();
    do
    {
        fflush(stdin);
        printf("*=============================================================================*\n");
        printf("[c] - Account managment\n");
        printf("[v] - Currency settings\n");
        printf("[h] - Help menu\n");
        printf("========================\n");
        printf("[l] - Logout\n");
        printf("[e] - Exit\n");
        printf("========================\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        system("cls");
        if(ch!='\n')
        {
            printf("Wrong option!\n");
            continue;
        }
        if(letters_check_admin_menu(c)!=1)
        {
            printf("Unknown letter !\n");
        }
        else if(c=='h')
        {
            helpMenu();
            c=again_menu();
        }
        else if(c=='v')
        {
           changeCurrency();
           c=again_menu();
        }
        else if(c=='c')
        {
            printf("*=============================================================================*\n");
            if(account_menu()==0)
                signin();
            else
                delete_account();
            c=again_menu();
        }
    }
    while(c!='e' && c!='l');
    if(c=='e')
    {
        printf("                                    Exit\n");
        printf("*=============================================================================*\n");
        return 'e';
    }
    if(c=='l')
    {
        printf("                              Logout successful!\n");
        Sleep(2000);
        system("cls");
        return 'l';
    }
    return 'a';
}

char again_menu()
{
    char c,ch,s;
    do
    {
        fflush(stdin);
        printf("Do you want to go back to menu ? \n");
        printf("[y] - Yes\n");
        printf("[n] - No\n");
        fflush(stdin);
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || letters_check_Y_N(c)!=1)
        {
            printf("Wrong option!\n");
            continue;
        }
    }while(ch!='\n' || letters_check_Y_N(c)!=1);
    if(c=='y')
        s='y';
    else if(c=='n')
        s='e';
    system("cls");
    return s;
}

int letters_check_admin_menu(char s)
{
    if( s!='c'&& s!='v' && s!='h' && s!='e' && s!='l')
        return 0;
    return 1;
}

int letters_check_Y_N( char s)
{
    if( s=='y' ||  s=='n' )
        return 1;
    return 0;
}

int letters_check_D_C(char c)
{
    if(c=='d' || c=='c')
        return 1;
    else
        return 0;
}

int account_menu()
{
    char c,ch;
    do
    {
        fflush(stdin);
        printf("[d]- Delete account \n");
        printf("[c]- Create new account \n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || letters_check_D_C(c)==0 )
        {
            printf("Wrong option!\n");
            continue;
        }
    }while(ch!='\n' || letters_check_D_C(c)==0);
    if(c=='d')
        return 1;
    else
        return 0;
}

int delete_account()
{
    int br=0;
    FILE *fp=fopen("account.txt","r+");
    fseek(fp,0,SEEK_SET);
    ACCOUNT tmp, tmp1;
    printf("Chose  account to delete :\n");
    fflush(stdin);
    do
    {
        printf("Name: ");
        gets(tmp1.name);
    }
    while(letters_only_allowed(tmp1.name)!=1);
    do
    {
        printf("Surname: ");
        gets(tmp1.surname);
    }
    while(letters_only_allowed(tmp1.surname)!=1);
    system("cls");
    while((fscanf(fp,"%d %s %s %s",&tmp.type,tmp.name,tmp.surname,tmp.pin))==4) //searching for accaunt
    {
        if(strcmp(tmp.name,tmp1.name)==0 && strcmp(tmp.surname,tmp1.surname)==0 ) //if the account is found
        {
            br++;
            int d=strlen(tmp.name);
            d+=strlen(tmp.surname);
            d+=strlen(tmp.pin);
            d+=4;                                  // 1_filip_stojakovic_1234  d=23
            fseek(fp,-d,SEEK_CUR);
            fflush(stdin);
            int i;
            for(i=0; i<d; i++)
                fprintf(fp," ");
            printf("%s %s account successfully deleted !\n",tmp1.name,tmp1.surname);
            fclose(fp);
            return 1;
        }
    }
    if(br==0)                           //if the account exsists
        printf("Unsuccessfully to find account !\n");
    fclose(fp);
    return 0;
}

void helpMenu()
{
    system("cls");
    printf("Accout managment:\n");
    printf("Options to create or delete existing account. \nCreating account for administrator or analyst.\n\n\n");
    printf("Currency settings:\n");
    printf("Options to change used currency for reviewing data done by analyst.\n\n\n");
}

void changeCurrency()
{
    fflush(stdin);
    printf("Choose a Currency:\n");
    printf("1. Euro (Default)\n2. KM\n3. Dinar\n");
    int value;
    do
    {
        printf("Enter number: ");
        scanf("%d",&value);
    }
    while(value<=0 || value>3);
    switch(value)
    {
    case 1:
        currency=EURO;     // Euro (default)
        break;
    case 2:
        currency=KM;      //Euro to KM
        break;
    case 3:
        currency=DINAR;    // Euro to Dinar
    }
    printf("\n");
    printCurrency();
    printf("\n");
}

void printCurrency()
{
    fflush(stdin);
    printf("Currency: ");
    if(currency==(float)EURO)
        printf("EURO\n");
    else if(currency==(float)KM)
        printf("KM\n");
    else if(currency==(float)DINAR)
        printf("DINAR\n");
}









