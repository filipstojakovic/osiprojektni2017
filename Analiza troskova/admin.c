#include "admin.h"
#include <string.h>
#include <stdio.h>
#include "login.h"
#include "strukture.h"
#define EURO 1.00
#define KM 1.95
#define DINAR 118.37

extern float currency;

char adminMenu()
{
    char c,ch;
    printf("*=============================================================================*\n");
    printf("                    Welcome Administrator! \n\n");
    printCurrency();
    do
    {
        fflush(stdin);
        printf("*=============================================================================*\n");
        printf("[c] - account managment\n");
        printf("[v] - currency settings\n");
        printf("[h] - help menu\n");
        printf("=======================\n");
        printf("[l] - logout\n");
        printf("[e] - exit\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        system("cls");
        if(ch!='\n')
        {
            printf("Wrong option!\n");
            continue;
        }
        if(provera_slova(c)!=1)    //provjerava da li je unesono slovo jedno od ponudjenih
        {
            printf("Unknown letter !\n");
        }
        else if(c=='h')
        {
            helpMenu();
            c=ponovo_meni();
        }
        else if(c=='v')
        {
           changeCurrency();
            c=ponovo_meni();
        }
        else if(c=='c')
        {
            printf("*=============================================================================*\n");
            if(rad_sa_account()==0)
                signin();
            else
                delete_account();
            c=ponovo_meni();
        }
    }
    while(c!='e' && c!='l');
    if(c=='e')
    {
        printf("                                Exit\n");
        printf("*=============================================================================*\n");
        return 'e';
    }
    if(c=='l') // vraca u main ako je odabrana opcija Logout
    {
        printf("                              Logout successful!\n");
        Sleep(2000);
        system("cls");
        return 'l';
    }
    return 'a';
}


char ponovo_meni()   //funkcija preko koje se ponovo vraca u meni ili izlazi iz programa
{
    char c,ch,s;
    do
    {
        fflush(stdin);
        printf("Do you want to go back to menu ? \n");
        printf("[y] - yes\n");
        printf("[n] - no\n");
        fflush(stdin);
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || provera_slovaYN(c)!=1)
        {
            printf("Wrong option!\n");
            continue;
        }

    }while(ch!='\n' || provera_slovaYN(c)!=1);

    if(c=='y')
        s='y';
    else if(c=='n')
        s='e';
    system("cls");
    return s;
}


int provera_slova(char s)  //funkcija za provjeru slova iz admin_meni
{
    if( s!='c'&& s!='v' && s!='h' && s!='e' && s!='l')
        return 0;
    return 1;
}
int provera_slovaYN( char s)  //funkcija za provjeru slova iz ponovo_meni
{
    if( s=='y' ||  s=='n' )
        return 1;
    return 0;
}
int provjera_slovaDC(char c)
{
    if(c=='d' || c=='c')
        return 1;
    else
        return 0;
}

int rad_sa_account()  //funkcija za upravljanje sa account-om
{
    char c,ch;
    do
    {
        fflush(stdin);
        printf("[d]- delete account \n");
        printf("[c]- create new account \n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || provjera_slovaDC(c)==0 )
        {
            printf("Wrong option!\n");
            continue;
        }

    }while(ch!='\n' || provjera_slovaDC(c)==0);

    if(c=='d')
        return 1;
    else
        return 0;
}

int delete_account()      //funkicja za brisanje accounta
{
    int br=0;
    FILE *fp=fopen("account.txt","r+");
    fseek(fp,0,SEEK_SET);
    ACCOUNT tmp, tmp1;
    printf("Chose  account to delete :\n");
    fflush(stdin);
    do                          //provjera da li je dobro uneseno ime
    {
        printf("Name: ");
        gets(tmp1.name);
    }
    while(provjera_imena(tmp1.name)!=1);
    do                                  //provjera da li je dobro uneseno prezime
    {
        printf("Surname: ");
        gets(tmp1.surname);
    }
    while(provjera_imena(tmp1.surname)!=1);
    system("cls");
    while((fscanf(fp,"%d %s %s %s",&tmp.type,tmp.name,tmp.surname,tmp.pin))==4) //trazenje osobe u datoteci account
    {

        if(strcmp(tmp.name,tmp1.name)==0 && strcmp(tmp.surname,tmp1.surname)==0 ) //pronalazenje osobe
        {
            br++;
            //ACCOUNT tmp2;
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
    if(br==0)                           //provjera da li postoji account
        printf("Unsuccessfully to find account !\n");
//    fflush(stdin);
//    fseek(fp,0,SEEK_SET);
//    while((fscanf(fp,"%d %s %s %s",&tmp.type,tmp.name,tmp.surname,tmp.pin))==4)
//        printf("%d %s %s %s\n",tmp.type,tmp.name,tmp.surname,tmp.pin);
    fclose(fp);
    return 0;
}
void helpMenu() // help menu za adminMenu
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









