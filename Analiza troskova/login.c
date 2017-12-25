#include "login.h"
#include "strukture.h"


int checkFile()    // provjeri da li postoji datoteka account.txt
{
    FILE *fp;
    if( fp=fopen("account.txt","r"))
    {
        fclose(fp);
        return 1;
    }
    else
        return 0;
}

int checkAccount(char *name,char* surname, char *pin, int *flag)
{

    int status =  checkFile();

    FILE *fp1=fopen("account.txt","r+");
    if(status==1)
    {
        ACCOUNT acc1;

        while(fscanf(fp1,"%d %s %s %s",&acc1.type,acc1.name,acc1.surname,acc1.pin)==4)
        {
            if(!strcmp(name,acc1.name) && !strcmp(surname,acc1.surname) && !strcmp(pin,acc1.pin))
            {
                *flag=acc1.type;
                fclose(fp1);
                return 1;
            }
        }
        fclose(fp1);
        return 0;
    }
    else
    {

        fprintf(fp1,"1 admin admin 0000");

        if(!strcmp(name,"admin") && !strcmp(surname,"admin") && !strcmp(pin,"0000"))
        {
            *flag=1;
            fclose(fp1);
            return 1;
        }
        else
            return 0;
    }
}

int login(int *flag)       // return 1 uspjesan login else 0
{

    char name[15+1], surname[15+1], pin[4+1],name1[15+1], surname1[15+1];
    fflush(stdin);
    pocetno_zaglavlje();
    do
    {
        printf("Name: ");
        gets(name);
    }
    while(provjera_imena(name)!=1);
    strcpy(name1,name);
    do
    {
        printf("Surname: ");
        gets(surname);
    }
    while(provjera_imena(surname)!=1);
    strcpy(surname1,surname);
    do
    {
        printf("PIN: ");
        gets(pin);
    }
    while(provjera_pina(pin)!=1);
    return checkAccount(name1,surname1,pin,flag);
}

int provjera_pina(char *rec)
{
    int i,pom;
    if(strlen(rec)!=4)
    {
        printf("It has to be number with four digits !\n");
        return 0;
    }
    for(i=0; i<strlen(rec); i++)
    {
        pom=(int)rec[i];
        if(pom<47 ||  pom>58)
        {
            printf("Only numbers allowed !\n");
            return 0;
        }
    }
    return 1;
}

int provjera_imena(char *rec)
{
    int i,pom;
    for(i=0; i<strlen(rec); i++)
    {
        pom=(int)rec[i];
        if(pom<65 ||  pom>122)
        {
            printf("Only letters allowed !\n");
            return 0;
        }
        if(pom>90 && pom<97)
        {
            printf("Only letters allowed !\n");
            return 0;
        }
    }
    return 1;
}

int checkLogin(int flag) // funkcija koja provjerava ispravnost logina i vraca flag administratora ili analiticara
{
    int i=3;
    while(!login(&flag) && i>0)
    {
         system("cls");
        printf("*=============================================================================*\n");
        printf("False log in!\n");
        i--;
        if(i==0)
        {
            printf("Sorry no more attempts !\n");
            flag=2;
            return flag;
        }
        printf("Attempts left : %d\n",i);
    }
    return flag;
}

void pocetno_zaglavlje()
{
    printf("*=============================================================================*\n");
    printf("                                  -LOG IN-                                     \n");

}
