#include "admin.h"
#include <string.h>
#include <stdio.h>
#include "login.h"
#include "strukturaAccount.h"
void adminMenu()
{
    char c[200],t[200],q[200];
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
    }
    while(c[0]!='e');
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
    }
    while(f==0);
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
    }
    while(f==0);
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
    int type,k=0,f=0;
    printf("Chose  account to delete :\n");
    getchar();
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
    do
    {
        printf("Type: ");
        scanf("%d",&type);
    }
    while(type<0 || type>1);
    char tt[2]= {0}, s1[20],s2[20],s3[20],s4[20];
    //FILE *fp=fopen("account1.txt","r+");
    int i=1,pom=0,g,m,promjenljiva=0,prvi;

    if((fp=fopen("account1.txt","r"))==0)
    {
        printf("No folder!\n");
        return;
    }
    else
    {
        FILE *fp=fopen("account1.txt","r");
        FILE *fp1=fopen("pomocna.txt","w");
        while(!feof(fp))
        {
            char z[20],*s2,*s3,*s4;
            fscanf(fp,"%s", &z);
            //printf("%s ",z);
            if((i%4)==1)
            {
                m=strlen(z);
                prvi=((int)z[0]-48);
                if((prvi-type)==0)promjenljiva++;
                g=(prvi-type);
                if(g!=0)
                    pom++;
                else pom=0;

            }
            else if((i%4)==2)
            {
                m=strlen(z);
                s2=(char*)malloc(m);
                g=strcmp(z,name);
                s2=z;
                if(g==0)
                    pom++;
                else pom=0;
            }
            else if((i%4)==3)
            {
                m=strlen(z);
                s3=(char*)malloc(m);
                g=strcmp(z,surname);
                s3=z;
                if(g==0)
                    pom++;
                else pom=0;
            }
            else if((i%4)==0)
            {
                m=strlen(z);
                s4=(char*)malloc(m);
                s4=z;
                g=strcmp(z,pin);
                if(g==0)
                    pom++;
                else pom=0;
            }
            if(pom==4)
            {
                f++;
                char j[20];
                printf("Osoba je obrisana sa liste accaunta !\n");
                rewind(fp);
                int br=1;
                do
                {
                    fscanf(fp, "%s",j);
                    if(strlen(j)==1 && ((int)j[0]-48)==type)
                    {
                        promjenljiva--;
                        if(promjenljiva==0)
                        {
                            fscanf(fp, "%s",j);
                            fscanf(fp, "%s",j);
                            fscanf(fp, "%s",j);
                        }
                    }
                    fputs(j,fp1);
                    fputs(" ",fp1);
                    if(br%4==0)
                        fputs(" ",fp1);
                    br++;
                }
                while(feof(fp)==0);
            }

            i++;
        }
        if(f==0)
            printf("Osoba nije pronadjena \n");
        fclose(fp);
        fclose(fp1);
    }

}


int delete_accountFILIP()      /// radi, ali nisam bas zadovoljan
{
    FILE *fp=fopen("account.txt","r+");
    fseek(fp,0,SEEK_SET);
    ACCOUNT tmp, tmp1;
    printf("Enter name: ");
    gets(tmp1.name);
    printf("Enter surname: ");
    gets(tmp1.surname);

    while((fscanf(fp,"%d %s %s %s",&tmp.type,tmp.name,tmp.surname,tmp.pin))==4)
    {

        if(strcmp(tmp.name,tmp1.name)==0 && strcmp(tmp.surname,tmp1.surname)==0 )
        {
            ACCOUNT tmp2;
            int d=strlen(tmp.name);
            d+=strlen(tmp.surname);
            d+=strlen(tmp.pin); // ili d+=4;
            d+=4;                                  // 1_filip_stojakovic_1234  d=23

            fseek(fp,-d,SEEK_CUR);
            fflush(stdin);
            for(int i=0; i<d; i++)
                fprintf(fp," ");

            fclose(fp);
            return 1;

        }
    }

//    fflush(stdin);
//    fseek(fp,0,SEEK_SET);
//    while((fscanf(fp,"%d %s %s %s",&tmp.type,tmp.name,tmp.surname,tmp.pin))==4)
//        printf("%d %s %s %s\n",tmp.type,tmp.name,tmp.surname,tmp.pin);
    fclose(fp);
     return 0;
}










