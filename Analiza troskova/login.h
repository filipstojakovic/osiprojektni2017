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

ACCOUNT *setNode(char group,char *name, char* surname, char *pin)
{
    ACCOUNT *novi=(ACCOUNT*)calloc(1,sizeof(ACCOUNT));
    novi->group=group;
    strcpy(novi->name,name);
    strcpy(novi->surname, surname);
    strcpy(novi->pin,pin);
    return novi;
}
void fillAccounts(ACCOUNT **head)
{
    int flag=checkFile(); // flag==1 procitaj sve accounte, flag==0 pravi datetku sa samo admin account
     // r+ stavlja pokazivac na pocetak datoteke

    if(flag)
    {
        FILE *fp=fopen("account.txt","r+");

        char name[15+1], surname[15+1], pin[4+1];
        char group;
        while(fscanf(fp,"%d %s %s %s",&group,name,surname,pin)==4)
        {

            ACCOUNT *novi=setNode(group,name,surname,pin);

            if(*head==0)
                *head=novi;
            else
            {
                novi->next=*head;
                *head=novi;
            }
        }
        fclose(fp);

    }
    else
       *head=setNode(1,"admin","admin","0000");

}

// searchList(ACCOUNT *head)
int login()
{


    ACCOUNT *head=0;
    fillAccounts(&head);

    printf("%s %s",head->next->name,head->next->pin);


}


#endif // LOGIN_H
