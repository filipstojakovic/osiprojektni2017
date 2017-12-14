#include "admin.h"
#include <string.h>
#include <stdio.h>
#include "login.h"
#include "strukture.h"
void adminMenu()   ///
{
    char c[20],t[20],q[20];
    printf("*=============================================================================*\n");
    printf("                    Welcome Administrator! \n\n\n");
    do
    {
        printf("*=============================================================================*\n");
        printf("[c] - account managment\n");
        printf("[v] - currency settings\n");
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
            printf("GOOOOODBAYYY! \n");

        }
        else if(c[0]=='h')
        {
            printf("help\n\n\n");
            c[0]=ponovo_meni(t[0]);
        }
        else if(c[0]=='v')
        {
            printf("valuta\n\n\n");
            c[0]=ponovo_meni(t[0]);
        }
        else if(c[0]=='c')
        {
            if(rad_sa_account()==0)
                signin();
            else
               delete_accountFILIP();
            c[0]=ponovo_meni(t[0]);
        }
        gets(q);
    }
    while(c[0]!='e');
    printf("                                Exit\n");
    printf("*=============================================================================*\n");
}
char ponovo_meni(char c)   ///funkcija preko koje se ponovo vraca u meni ili izlazi iz programa
{
    char t[111],s,q[111];
    int f=0;
    printf("Do you want to go back to manu ? \n");
    printf("[y] - yes\n");
    printf("[n] - no\n");
    do
    {
        scanf("%s",&t);
        if(strlen(t)>1 || provera_slova22(t[0])==0 )
            printf("False letter!\n");
        else f=1;
    }
    while(f==0);
    if(t[0]=='y')
        s='a';
    else if(t[0]=='n')
        s='e';
        system("cls");
    return s;
}
int provera_slova2(char s)  ///funkcija za provjeru slova iz admin_meni
{
    if( s!='c'&& s!='v' && s!='h' && s!='e')
        return 0;
    return 1;
}
int provera_slova22(char s)  ///funkcija za provjeru slova iz ponovo_meni
{
    if( s=='y' ||  s=='n' )
        return 1;
    return 0;
}

int rad_sa_account()  ///funkcija za upravljanje sa account-om
{
    char t[20],q[20];
    int f=0,k;
    printf("[d]- delete account \n");
    printf("[n]- create new account \n");
    do
    {
        gets(q);
        scanf("%s",&t);
        if(strlen(t)>1 || provera_slova123(t[0])==0 )
            printf("False letter!\n");
        else f=1;
    }
    while(f==0);
    if(t[0]=='d')
        return 1;
    else if(t[0]=='n')
        return 0;
}
int provera_slova123(char s)  ///funkcija za provjera slova u rad_sa_account
{
    if( s!='d' &&  s!='n' )
        return 0;
    return 1;
}

int delete_accountFILIP()      ///funkicja za brisanje accounta
{
    int br=0;
    FILE *fp=fopen("account.txt","r+");
    fseek(fp,0,SEEK_SET);
    ACCOUNT tmp, tmp1;
 printf("Chose  account to delete :\n");
    getchar();
    do                          //provjera da li je dobro tneseno ime
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
    while((fscanf(fp,"%d %s %s %s",&tmp.type,tmp.name,tmp.surname,tmp.pin))==4) //trazenje osobe u datoteci account
    {

        if(strcmp(tmp.name,tmp1.name)==0 && strcmp(tmp.surname,tmp1.surname)==0 ) //pronalazenje osobe
        {
            br++;
            ACCOUNT tmp2;
            int d=strlen(tmp.name);
            d+=strlen(tmp.surname);
            d+=strlen(tmp.pin);
            d+=4;                                  // 1_filip_stojakovic_1234  d=23
            fseek(fp,-d,SEEK_CUR);
            fflush(stdin);
            int i;
            for(i=0; i<d; i++)
                fprintf(fp," ");
            printf(" %s %s account successfully deleted !\n",tmp1.name,tmp1.surname);
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










