#include "admin.h"
#include <string.h>
#include <stdio.h>
#include "login.h"
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
      char name[15+1], surname[15+1], pin[4+1],name1[15+1], surname1[15+1];
      int type,k=0;
      printf("Chose  account to delete :\n");
      getchar();
      do{
            printf("Name: ");
            gets(name);
    }while(provjera_imena(name)!=1);
    strcpy(name1,name);
    do{
    printf("Surname: ");
    gets(surname);
    }while(provjera_imena(surname)!=1);
    strcpy(surname1,surname);
    do{
    printf("PIN: ");
    gets(pin);
    }while(provjera_pina(pin)!=1);
    do{
        printf("Type: ");
        scanf("%d",&type);
    }while(type<0 || type>1);
    char tt[20]={};
    tt[0]=(char)type;
     //FILE *fp=fopen("account1.txt","r+");
    int i=1,pom=0,g,m;
    printf("ajdee\n");
    if((fp=fopen("account1.txt","r"))==0)
    {
        printf("No folder!\n");
        return;
    }
    else{
        FILE *fp=fopen("account1.txt","r");
        FILE *fp1=fopen("pomocna.txt","w");
    while(!feof(fp))
    {
        char z[20];
        fscanf(fp,"%s", &z);
        printf("%s ",z);
        if((i%4)==1)
           {
               m=strlen(z);
              g=strcmp(z,tt);
              printf("Da li se poklapa tip %d\n",g);
              if(g!=0)
                pom++;
              else pom=0;
              printf("%d\n",pom);
           }
           else if((i%4)==2)
           {
               m=strlen(z);
                g=strcmp(z,name);
                printf("Da li se poklapa tip IME %d\n",g);
              if(g==0)
                pom++;
              else pom=0;
              printf("%d\n",pom);
           }
           else if((i%4)==3)
            {
                m=strlen(z);
                g=strcmp(z,surname);
                printf("Da li se poklapa PREzime %d\n",g);
              if(g==0)
                pom++;
              else pom=0;
              printf("%d\n",pom);
           }
           else if((i%4)==0)
            {
                m=strlen(z);
                g=strcmp(z,pin);
                printf("Da li se poklapa  PINNN %d\n",g);
              if(g==0)
                pom++;
              else pom=0;
              printf("%d\n",pom);
           }
         if(pom==4)
         {
             printf("pronasao sam jeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee!\n");
             //fseek( fp, , SEEK_SET );
         }

        i++;
    }
    fseek( fp, 0, SEEK_SET );
    printf("\n");
    }
    printf("VRACENO U DELETE!\n");
}
