#include "readfiles.h"
#include "readformats.h"

int fileList()
{
    DIR *dir;
    struct dirent *dp;

    if ((dir= opendir("./racuni")) == NULL)
    {
        printf("Cannot open ./racuni directory\n");
        return 0;
    }
    else
    {
        while((dp=readdir (dir)) != NULL)       // cita redom fajlove i smjesta u strukturu dp
        {
            if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0) // da preskoci ove datoteke
                continue;                                                                        // . trenutna dat
            printf("%s\n",dp->d_name);                                                   // .. otac-datoteka
        }
    }

    closedir(dir);
    return 1;
}

void renameFile(char *findname) // trenutno se ne koristi findname u funkciji
{
    // bilo bi dobro da se poziva funkcija kao rename(dp->d_name)
    DIR *dir;
    struct dirent *dp;
    char findname1[10];
    printf("Ime datoteke za rename(sa .txt): ");    /// treba napraviti funkciju da provjeri da li ima .txt ili .bin
    gets(findname1);
    if ((dir= opendir("./racuni")) == NULL)
    {
        printf("Cannot open ./racuni directory\n");
        return 0;
    }
    else
    {
        while((dp=readdir (dir)) != NULL)       // cita redom fajlove i smjesta u strukturu dp
        {
            if(strcmp(dp->d_name,findname)==0)      /// treba malo srediti tijelo
            {
                char newname[20];
                char fullpath[50]="./racuni/";           // zbog ugradjene funkcije "rename()" treba put do fajla
                char fullpath1[50]="./racuni/";
                printf("Chose new name: ");
                gets(newname);
                strcat(newname,".txt");             /// treba uslova ako je .txt ili .bin
                strcat(fullpath,dp->d_name);
                strcat(fullpath1,newname);

                if(rename(fullpath,fullpath1)==0)
                    printf("renamed");
                else
                    printf("NOT renamed");
                closedir(dir);
                return;
            }

        }
        printf("nema datoteke sa tim nazivom!\n");
    }
    closedir(dir);
}

FILE* findFile(char *d_name)
{
    FILE *fp;
    DIR *dir;
    struct dirent *dp;
    if ((dir= opendir("./racuni")) == NULL)
    {
        printf("Cannot open ./racuni directory\n");
        return 0;
    }
    else
    {
        while((dp=readdir(dir)) != NULL)       // cita redom fajlove i smjesta u strukturu dp
        {
            if(strcmp(dp->d_name,d_name)==0)
            {
                char fullpath[50]="./racuni/";
                strcat(fullpath,dp->d_name);
                // printf("%s\n",fullpath);
                if(fp=fopen(fullpath,"r+"))
                {
                    fseek(fp,0,SEEK_END);
                    //   printf("%d\n",ftell(fp));
                }
                else
                   {
                       printf("NOT openedddd\n");
                       return 0;
                   }

                return fp;
            }
        }
    }
    return 0;
}

int detectFormat(char *d_name)
{
    FILE *fp;

    char kupac[6+1];
    if(strstr(d_name,".cvs")!=0)
        return 5;

    fp=findFile(d_name);
   // fp=fopen(d_name,"r+");
    if(fp==0)
        return 0;

    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s",&kupac);

    if(strcmp(kupac,"Kupac:")==0)
    {
        char jednako;
        fseek(fp,-1,SEEK_END);
        fscanf(fp,"%c",&jednako);
        if(jednako=='=')
            return 4;
        else
            return 1;
    }
    else
    {
        char tmp[15];
        int i;
        fseek(fp,0,SEEK_SET);
        for(i=0; i<7; i++)
            fscanf(fp,"%s",tmp);


        if(strcmp(tmp,"Kupac:")==0)
            return 3;
        else
            return 2;


    }

    fclose(fp);
    return 0;
}


NODE *fillHead()
{
    NODE *head=0;
    FILE *fp;
    DIR *dir;
    struct dirent *dp;
    if ((dir= opendir("./racuni")) == NULL)
    {
        printf("Cannot open ./racuni directory\n");
        return 0;
    }
    else
    {
        while((dp=readdir(dir)) != NULL)
        {
            if(!strcmp(dp->d_name,".") || (!strcmp(dp->d_name,"..")))
               continue;
            char fullpath[50]="./racuni/";
            strcat(fullpath,dp->d_name);
            int format=detectFormat(dp->d_name);

            NODE* novi=(NODE*)calloc(1,sizeof(NODE));
            POD tmp;

            if(format==1)
                tmp=readFormat1(fullpath);
            else if(format==2)
                tmp=readFormat2(fullpath);

            novi->pod=tmp;
            if(head==0)
                head=novi;

            else
            {
                NODE *p;
                for(p=head; p->next; p=p->next)
                {
                    if(strcmp(p->pod.name,tmp.name)==0 && strcmp(p->pod.surname,tmp.surname)==0)
                    {
                        // postoji vec kupac
                        // treba mu dodati artikle
                        // break;
                    }
                }
                if(p->next==0)
                {
                    novi->pod=tmp;
                    p->next=novi;
                }
            }
        }
    }
    return head;
}




