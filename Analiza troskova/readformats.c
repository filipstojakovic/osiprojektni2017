
#include "readformats.h"
#include <stdio.h>
#include <string.h>

POD readFormat1(char* d_name) // cita sve podatke iz racuna formata 1
{
    FILE *fp;
    POD pod;
    if(strstr(d_name,"./racuni")!=0)        // ako je dat pun put do racuna ./racuni/deadpool.txt
        fp=fopen(d_name,"r");
    else                                            // else napravi da bude fullpath
    {
        char fullpath[50]="./racuni/";
        strcat(fullpath,d_name);
        fp=fopen(fullpath,"r");
    }
    fscanf(fp,"%*s %s %s",pod.name,pod.surname);        // %*s preskace citanje stringa
    if(strcmp(pod.surname,"Datum:")==0)
    {
        strcpy(pod.surname,"");         // da surname bude brazan
        fscanf(fp,"%hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    }
    else
        fscanf(fp,"%*s %hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    char ignore[1024];
    fscanf(fp,"%*s");
    fgets(ignore,sizeof(ignore),fp);    // preskace red
    fgets(ignore,sizeof(ignore),fp);
    fgets(ignore,sizeof(ignore),fp);
    /// if uslov ako je racun prazan
    int c=10, i=0;
    pod.art=(ARTIKL*)malloc(c*sizeof(ARTIKL));
    ARTIKL art;
    while((fscanf(fp,"%s %s - %f - %f - %f",art.name,art.barcode,&art.kol,&art.cijena,&art.total))==5)
    {
        strcpy(pod.art[i].name,art.name);
        strcpy(pod.art[i].barcode,art.barcode);
        pod.art[i].kol=art.kol;
        pod.art[i].cijena=art.cijena;
        pod.art[i].total=art.total;
        i++;
        if(i==c)
            pod.art=(ARTIKL*)realloc(pod.art,(c *= 2) * sizeof(ARTIKL));

    }
    pod.art=(ARTIKL*)realloc(pod.art, i * sizeof(ARTIKL));
    fscanf(fp,"%f",&pod.total);
    pod.n=i;    // broj artikala
    fscanf(fp,"%*s %f",&pod.PDV);
    fscanf(fp,"%*s %*s %*s %f",&pod.sum);
    fclose(fp);
    return pod;
}
/// readFormat2.....................................................................

POD readFormat2(char* d_name) // cita sve podatke iz racuna formata 2
{
    FILE *fp;
    POD pod;
    int n=4;
    char tmp[40];
    if(strstr(d_name,"./racuni")!=0)        // ako je dat pun put do racuna ./racuni/deadpool.txt
        fp=fopen(d_name,"r");
    else                                            // else napravi da bude fullpath
    {
        char fullpath[50]="./racuni/";
        strcat(fullpath,d_name);
        fp=fopen(fullpath,"r");
    }
    char ignore[1024];
    int i,g,l;
    for(l=0; l<n; l++)
        fgets(ignore,sizeof(ignore),fp);    // preskace red
    fscanf(fp,"%*s %s %s",pod.name,pod.surname);
    if(strcmp(pod.surname,"Proizvod")==0)
    {
        strcpy(pod.surname,"");
        n=2;
    }
    else
        n=4;
    for(g=0; g<n; g++)
        fgets(ignore,sizeof(ignore),fp);
    int c=10;
    pod.art=(ARTIKL*)malloc(c*sizeof(ARTIKL));
    ARTIKL art;
    i=0;
    while((fscanf(fp,"%s %s - %f - %f - %f",art.name,art.barcode,&art.kol,&art.cijena,&art.total))==5)
    {
        strcpy(pod.art[i].name,art.name);
        strcpy(pod.art[i].barcode,art.barcode);
        pod.art[i].kol=art.kol;
        pod.art[i].cijena=art.cijena;
        pod.art[i].total=art.total;
        i++;
        if(i==c)
            pod.art=(ARTIKL*)realloc(pod.art,(c *= 2) * sizeof(ARTIKL));
    }
    pod.art=(ARTIKL*)realloc(pod.art,i * sizeof(ARTIKL));
    pod.n=i;
    fscanf(fp,"%f",&pod.total);
    fscanf(fp,"%*s %f",&pod.PDV);
    fscanf(fp,"%*s %*s %*s %f",&pod.sum);
    fscanf(fp,"%*s %hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    fclose(fp);
    return pod;
}

/// readFormat3.....................................................................

POD readFormat3(char* d_name)
{
    FILE *fp;
    POD pod;
    if(strstr(d_name,"./racuni")!=0)        // ako je dat pun put do racuna ./racuni/deadpool.txt
        fp=fopen(d_name,"r");
    else                                            // else napravi da bude fullpath
    {
        char fullpath[50]="./racuni/";
        strcat(fullpath,d_name);
        fp=fopen(fullpath,"r");
    }
    char ignore[1024];
    int red=2;
    for(int i=0; i<red; i++)
        fgets(ignore,sizeof(ignore),fp);    // preskace red

    fscanf(fp,"%*s %s %s",pod.name, pod.surname);       // ime i prezime kupca

    if(strcmp(pod.surname,"Datum:")==0)    // ukoliko nema prezime
    {
        strcpy(pod.surname,"");
        fscanf(fp,"%hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    }
    else
    {
        fscanf(fp,"%*s %hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    }
    red=6;
    for(int i=0; i<red; i++)
        fgets(ignore,sizeof(ignore),fp);    // preskace red
    int c=10,i=0;
    pod.art=(ARTIKL*)malloc(c*sizeof(ARTIKL));
    ARTIKL art;
    long position;

    while(fscanf(fp,"%s %[^=]======%f======%f======%f",art.name,art.barcode,&art.kol,&art.cijena,&art.total)==5)
    {
        strcpy(pod.art[i].name,art.name);
        strcpy(pod.art[i].barcode,art.barcode);
        pod.art[i].kol=art.kol;
        pod.art[i].cijena=art.cijena;
        pod.art[i].total=art.total;
        i++;
        position=ftell(fp);     // pamti poslednju poziciju nakon fscanf

        if(i==c)
            pod.art=(ARTIKL*)realloc(pod.art,(c *= 2) * sizeof(ARTIKL));
    }

    pod.art=(ARTIKL*)realloc(pod.art,i * sizeof(ARTIKL));
    pod.n=i;
    fseek(fp,position,SEEK_SET);    // pozicioniranje prije poslednjeg fscanf iz while petlje

    fgets(ignore,sizeof(ignore),fp);    // preskace red
    fgets(ignore,sizeof(ignore),fp);    // preskace red

    fscanf(fp,"%*s %f",&pod.total);
    fscanf(fp,"%*s %f",&pod.PDV);
    fscanf(fp,"%*s %*s %*s %f",&pod.sum);

    fclose(fp);
    return pod;
}


POD readFormat4(char* d_name)
{
    FILE *fp;
    POD pod;
    if(strstr(d_name,"./racuni")!=0)        // ako je dat pun put do racuna ./racuni/deadpool.txt
        fp=fopen(d_name,"r");
    else                                            // else napravi da bude fullpath
    {
        char fullpath[50]="./racuni/";
        strcat(fullpath,d_name);
        fp=fopen(fullpath,"r");
    }
    fscanf(fp,"%*s %s %s",pod.name,pod.surname);        // %*s preskace citanje stringa
    if(strcmp(pod.surname,"Datum:")==0)
    {
        strcpy(pod.surname,"");         // da surname bude brazan
        fscanf(fp,"%hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    }
    else
        fscanf(fp,"%*s %hhu/%hhu/%u",&pod.dan,&pod.mj,&pod.god);
    char ignore[1024];
    fscanf(fp,"%*s %*s");
    fgets(ignore,sizeof(ignore),fp);    // preskace red
    fgets(ignore,sizeof(ignore),fp);
    fgets(ignore,sizeof(ignore),fp);
    fscanf(fp,"%*s");
    int c=10, i=0;
    pod.art=(ARTIKL*)malloc(c*sizeof(ARTIKL));
    ARTIKL art;
    while((fscanf(fp,"%s %s - %f - %f - %f",art.name,art.barcode,&art.kol,&art.cijena,&art.total))==5)
    {
        strcpy(pod.art[i].name,art.name);
        strcpy(pod.art[i].barcode,art.barcode);
        pod.art[i].kol=art.kol;
        pod.art[i].cijena=art.cijena;
        pod.art[i].total=art.total;
        i++;
        if(i==c)
            pod.art=(ARTIKL*)realloc(pod.art,(c *= 2) * sizeof(ARTIKL));

    }
    pod.art=(ARTIKL*)realloc(pod.art, i * sizeof(ARTIKL));
    fscanf(fp,"%f",&pod.total);
    pod.n=i;    // broj artikala
    fscanf(fp,"%*s %f",&pod.PDV);
    fscanf(fp,"%*s");
    fscanf(fp,"%*s %*s %*s %f",&pod.sum);
    fscanf(fp,"%*s");
    fclose(fp);
    return pod;
}



POD readFormat5(char* d_name)       /// ./racuni/KupacA#24.10.2017.csv
{
    int i;
    FILE *fp;
    POD pod;
    char name[30];
    if(!sscanf(d_name, "./racuni/%[^#]#%d.%d.%d",name,&pod.dan,&pod.mj,&pod.god))
        return pod;

    if(strstr(name," "))
        sscanf(name,"%s %s",pod.name,pod.surname);
    else
        strcpy(pod.name,name);


    if(strstr(d_name,"./racuni")!=0)        // ako je dat pun put do racuna ./racuni/deadpool.txt
        fp=fopen(d_name,"rb");
    else                                            // else napravi da bude fullpath
    {
        char fullpath[50]="./racuni/";
        strcat(fullpath,d_name);
        fp=fopen(fullpath,"rb");
    }
    char buffer[100];
    fgets(&buffer,100,fp);
    fflush(stdin);
    int c=10;
    i=0;
    pod.art=(ARTIKL*)malloc(c*sizeof(ARTIKL));

    float total=0;
    float PDV=0;
    float sum=0;
    ARTIKL art;

    while(fscanf(fp,"%[^,] , %f , %f , %f\n",&art.name,&art.kol,&art.cijena,&art.total)==4)
        {
            fflush(stdin);
            strcpy(pod.art[i].name,art.name);
            strcpy(pod.art[i].barcode,art.barcode);
            pod.art[i].kol=art.kol;
            pod.art[i].cijena=art.cijena;
            pod.art[i].total=art.total;
            total+=art.total;
            i++;
            if(i==c)
                pod.art=(ARTIKL*)realloc(pod.art,(c *= 2) * sizeof(ARTIKL));
        }
    pod.total=total;
    pod.PDV=total*(float)0.17;
    pod.sum=pod.total+pod.PDV;

     pod.art=(ARTIKL*)realloc(pod.art, i * sizeof(ARTIKL));
     pod.n=i;

    fclose(fp);
    return pod;
}














