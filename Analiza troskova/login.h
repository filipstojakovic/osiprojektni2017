#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct account
{
    char name[15+1], surname[15+1], pin[4+1];
    char group;                    // 1 admin , 0 analiticar
    struct account *next;       // kao lista
} ACCOUNT;

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
    FILE *fp=fopen("account.txt","r+");
    if(status==0)
    {
        fprintf(fp,"1 admin admin 0000");
        fclose(fp);
        if(!strcmp(name,"admin") && !strcmp(surname,"admin") && !strcmp(pin,"0000"))
            {
                *flag=1;
                return 1;
            }
        else
            return 0;
    }
    else
    {
        char name1[15+1], surname1[15+1], pin1[4+1];
        char type;

        while(fscanf(fp,"%d %s %s %s",&type,name1,surname1,pin1)==4)
        {
            if(!strcmp(name,name1) && !strcmp(surname,surname1) && !strcmp(pin,pin1))
            {
                *flag=type;
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
        return 0;
    }

}

int login(int *flag)       // return 1 uspjesan login else 0
{

    char name[15+1], surname[15+1], pin[4+1];
    printf("Name: ");
    gets(name);
    printf("Surname: ");
    gets(surname);
    do{
    printf("PIN: ");
    gets(pin);
    }while(strlen(pin)!=4); //treba uslov i da nema slova

   return checkAccount(name,surname,pin,flag);
}


#endif // LOGIN_H
