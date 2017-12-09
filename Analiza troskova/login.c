#include "login.h"

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
        char name1[15+1], surname1[15+1], pin1[4+1];
        int type;

        while(fscanf(fp1,"%d %s %s %s",&type,name1,surname1,pin1)==4)
        {
            if(!strcmp(name,name1) && !strcmp(surname,surname1) && !strcmp(pin,pin1))
            {
                *flag=type;
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
    pocetno_zaglavlje(1);
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
void pocetno_zaglavlje(int i)
{
    printf("*=============================================================================*\n");
    if(i==1)
        printf("                                  -LOG IN-                                     \n");
    else if(i==2)
        printf("                                 -SIGN IN-                                     \n");
}
