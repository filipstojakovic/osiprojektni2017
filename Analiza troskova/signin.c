#include "signin.h"
#include "strukture.h"
void signin()
{
    ACCOUNT acc;
//    char name[15+1], surname[15+1], pin[4+1],
char pin2[4+1];
//    int type;
    fflush(stdin);
    do
    {
        printf("[1] - signin as admin\n"
                "[0] - signin as analyst\n"
                "Option: ");
        scanf("%d",&acc.type);
    }while(acc.type<0 || acc.type>1);
    fflush(stdin);
    do
    {
        printf("Enter Name: ");
        gets(acc.name);
    }
    while(checkString(acc.name)==0);
    do
    {
        printf("Enter Surname: ");
        gets(acc.surname);

    }while(checkString(acc.surname)==0);

    do
    {
        do
        {
            printf("Enter PIN: ");
            gets(acc.pin);
        }
        while(!checkPin(acc.pin));

        printf("Confirm PIN: ");
        gets(pin2);
            if(strcmp(acc.pin,pin2)!=0)
                printf("Not confirmed !\n");
    }while(strcmp(acc.pin,pin2));

    FILE *fp=fopen("account.txt","r+");
    fseek(fp,0,SEEK_END);
    fprintf(fp," %d %s %s %s",acc.type,acc.name,acc.surname,acc.pin);
    printf("Sign in successful\n");
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









