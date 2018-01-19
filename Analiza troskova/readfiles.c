#include "readfiles.h"
#include "readformats.h"


int fileList()  // lista naziva svih racuna
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

void renameFile(char *d_name) // trenutno se ne koristi findname u funkciji
{
    DIR *dir;
    struct dirent *dp;

    if ((dir= opendir("./Error")) == NULL)
    {
        system("mkdir Error");
    }
    else
        closedir(dir);
    char newpath [100]="Error";

    char oldpath[100];
    strcpy(oldpath,d_name+2);

    int len = strlen("./racuni");
    strcat(newpath,d_name+len);

   rename(oldpath,newpath);

}

int detectFormat(char *d_name)  // vraca format racuna
{
    FILE *fp;

    if((strstr(d_name,".csv"))!=0)
            return 5;

    fp=fopen(d_name,"r");
    if(fp==0)
        {
             fclose(fp);
            return 0;
        }
    char kupac[6+1];
    fseek(fp,0,SEEK_SET);
    fscanf(fp,"%s",&kupac);

    if(strcmp(kupac,"Kupac:")==0)
    {
        char jednako;
        fseek(fp,-1,SEEK_END);
        fscanf(fp,"%c",&jednako);
        fclose(fp);
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

        fclose(fp);
        if(strcmp(tmp,"Kupac:")==0)
            return 3;
        else
            return 2;


    }

    fclose(fp);
    return 0;
}

NODE* fillHead()    // formira se lista kupaca i njihovih racuna po datumu
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
            if(!strcmp(dp->d_name,".") || (!strcmp(dp->d_name,"..")))       // preskace '.' i '..' folder
                continue;
            char fullpath[50]="./racuni/";
            strcat(fullpath,dp->d_name);
            int format=detectFormat(dp->d_name);

            POD tmp_pod;

            if(format==1)
                tmp_pod=readFormat1(fullpath);
            else if(format==2)
                tmp_pod=readFormat2(fullpath);
            else if(format==3)
                tmp_pod=readFormat3(fullpath);
            else if(format==4)
                tmp_pod=readFormat4(fullpath);
            else if(format==5)
                tmp_pod=readFormat5(fullpath);
             else
                {
                    printf("%s\n",fullpath);
                    renameFile(fullpath);
                    continue;
                }

            int helping;                //pomocni int za provjeru ispravnosti racuna 1 = ispravan, 0 = neispravan
            helping = isValid(tmp_pod); //poziv funkcije za provjeru ispravnosti racuna
            if(helping)
            {
                if(head==0)
                {
                    NODE* novi=(NODE*)calloc(1,sizeof(NODE));
                    fillNode(&novi,tmp_pod);
                    head=novi;
                }
                else
                {
                    NODE *p;
                    NODE *pp;

                    for(p=head; p; p=p->next)
                    {
                        pp=p;       // pp pokazuje na cvor prije p nakon zavrsetka petlje
                        fflush(stdin);
                        if(strcmp(p->name,tmp_pod.name)==0 && strcmp(p->surname,tmp_pod.surname)==0)   // ako postoji kupac
                        {

                            fflush(stdin);
                            p->n_racuna+=1;
                            p->artdate=(ART_DATE*)realloc(p->artdate,p->n_racuna*sizeof(ART_DATE));

                            int m=p->n_racuna-1;        // m je pozicija u nizu tj zadnje mjesto

                            p->artdate[m].mj=tmp_pod.mj;
                            p->artdate[m].god=tmp_pod.god;
                            p->artdate[m].n_art=tmp_pod.n;
                            p->artdate[m].total=tmp_pod.total;
                            p->artdate[m].PDV=tmp_pod.PDV;
                            p->artdate[m].sum=tmp_pod.sum;
                            p->artdate[m].art=tmp_pod.art;
                            break;
                        }
                    }

                    if( pp->next==0 && p==0)
                    {
                        NODE* novi=(NODE*)calloc(1,sizeof(NODE));
                        fillNode(&novi,tmp_pod);
                        pp->next=novi;
                    }

                }
            }
            else
              {
                  renameFile(fullpath);
                  free(tmp_pod.art);
              }
        }
    }
    closedir(dir);
    return head;
}

void fillNode(NODE** novi, POD tmp) // popunjava cvor (NODE) sa podacima iz POD
{
    strcpy((*novi)->name,tmp.name);
    strcpy((*novi)->surname,tmp.surname);
    (*novi)->n_racuna=1;
    (*novi)->artdate=(ART_DATE*)calloc(1,sizeof(ART_DATE));
    (*novi)->artdate->mj=tmp.mj;
    (*novi)->artdate->god=tmp.god;
    (*novi)->artdate->n_art=tmp.n;
    (*novi)->artdate->art=tmp.art;
    (*novi)->artdate->total=tmp.total;
    (*novi)->artdate->PDV=tmp.PDV;
    (*novi)->artdate->sum=tmp.sum;
}

int isValid(POD tmp)
{
    int i,brArt=tmp.n;
    float totalHelp=0,pdvHelp=0;
    const EPS=0.001;
    for(i=0; i<brArt; i++)
    {
        if(fabs((tmp.art[i].kol * tmp.art[i].cijena) - tmp.art[i].total)<EPS)
            return 0;

        totalHelp+=tmp.art[i].total;
    }
    pdvHelp=totalHelp*(float)0.17;

    if(fabs(totalHelp-tmp.total)<EPS)
        return  0;
    if(fabs(pdvHelp - tmp.PDV)<EPS)
        return  0;
    if(fabs((totalHelp+pdvHelp) - tmp.sum) < EPS)
        return  0;

    return 1;
}









