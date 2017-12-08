#include "admin.h"
#include <string.h>
#include <stdio.h>
void adminMenu()
{
    char c[200],t[200],q[200];
    printf("*=============================================================================*\n");
    printf("                    Welcome Administrator! \n\n\n");
    do{
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
    }else
    if(c[0]=='e')//provjera za izlaz
    {
        printf("GOOOOODBAYYY! :D\n");

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
           delete_account();
        c[0]=ponovo_meni(t[0]);
    }
    gets(q);
     }while(c[0]!='e');
     printf("Exit\n");
     printf("*=============================================================================*\n");
}
char ponovo_meni(char c)
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
        }while(f==0);
        if(t[0]=='y')
            s='a';
    else if(t[0]=='n')
        s='e';
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

int rad_sa_account()
{
    char t[111],q[111];
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
        }while(f==0);
        if(t[0]=='d')
            return 1;
    else if(t[0]=='n')
        return 0;
}
int provera_slova123(char s)
{
    if( s!='d' &&  s!='n' )
            return 0;
   return 1;
}
void delete_account()//mora neko uraditi citavo kako spada
{
    FILE *fp;
     //FILE *fp=fopen("account1.txt","r+");
    int i=1;
    if((fp=fopen("account1.txt","r"))==0)
    {
        printf("No folder!\n");
        return;
    }
    else{
         //FILE *fp=fopen("account.txt","r+");
    while(!feof(fp))
    {
        char z[100];
        fscanf(fp,"%s", &z);
        printf("%s ",z);
        if((i%3)==0)
            printf("\n");
        i++;
    }
    fseek( fp, 0, SEEK_SET );
    printf("\n");
            char w[100];
    printf("Chose name of account to delete :");//ovdje obrati paznju kako zamagliti ili unistiti tu osobu
    scanf("%s",&w);
    while(!feof(fp))
    {
        char z[100];
        int l=1;
        fscanf(fp,"%s", &z);
        printf("%s ",z);
        if(strcmp(z,w)==0)
        {
            fseek(fp,-1,SEEK_CUR);
            fputs(w,fp);
            fputs(w,fp);
            fputs(w,fp);
        }
        if((l%3)==0)
            printf("\n");
        l++;
    }
    printf("\n");
        fseek( fp, 0, SEEK_SET );
     while(!feof(fp))
    {
        char z[100];
        int d;
        fscanf(fp,"%s", &z);
        printf("%s ",z);
        if((d%3)==0)
            printf("\n");
        d++;
    }
    fclose(fp);
    }
}
