#include "signin.h"

void signin()
{
    char name[15+1], surname[15+1], pin[4+1],pin2[4+1];
    int type;
    do
    {
        printf("[1] signin as admin\n"
                "[0] signin as analyst\n"
                "Option: ");
        scanf("%d",&type);
    }while(type<0 || type>1);
    fflush(stdin);
    do
    {
        printf("Enter Name: ");
        gets(name);
    }
    while(checkString(name)==0);
    do
    {
        printf("Enter Surname: ");
        gets(surname);

    }while(checkString(surname)==0);

    do
    {
        do
        {
            printf("Enter PIN: ");
            gets(pin);
        }
        while(!checkPin(pin));

        printf("Confirm PIN: ");
        gets(pin2);
            if(strcmp(pin,pin2)!=0)
                printf("Not confirmed !\n");
    }while(strcmp(pin,pin2));

    FILE *fp=fopen("account1.txt","r+");
    fseek(fp,0,SEEK_END);
    fprintf(fp," %d %s %s %s",type,name,surname,pin);
    fclose(fp);

}
int checkPin(char *pin)
{
    int i,d=strlen(pin);
    if(d!=4)
        return 0;
    for(i=0; i<4; i++)
        if(!(pin[i]>='0' && pin[i]<='9'))
            return 0;
    return 1;
}

int checkString(char *rec)
{
   int i,pom;
    for(i=0;i<strlen(rec);i++)
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









