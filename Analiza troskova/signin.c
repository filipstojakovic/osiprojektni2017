#include "signin.h"

void signin()
{
    char name[15+1], surname[15+1], pin[4+1],pin2[4+1];
    char type;
    do
    {
        printf("[1] signin as admin\n"
                "[2] signin as analyst\n"
                "Option: ");
        scanf("%d",&type);
    }while(type<1 || type>2);
    fflush(stdin);
    do
    {
        printf("Enter Name: ");
        gets(name);
    }
    while(!checkString(name));
    do
    {
        printf("Enter Surname: ");
        gets(surname);

    }while(!checkString(surname));

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

    }while(strcmp(pin,pin2));

    FILE *fp=fopen("account.txt","r+");
    fseek(fp,0,SEEK_END);
    fprintf(fp," %d %s %s %s",type,name,surname,pin);
    fclose(fp);

}
int checkPin(char *pin)
{
    int d=strlen(pin);
    if(d!=4)
        return 0;
    for(int i=0; i<4; i++)
        if(!(pin[i]>='0' && pin[i]<='9'))
            return 0;
    return 1;
}

int checkString(char *name)
{
    int n=strlen(name);
    if(n>15)
        return printf("predugacak string\n"),0;
    for(int i=0; i<n; i++)
        if(name[i]>='0' && name[i]<='9')        // provjerava da li ima brojeva u stringu
        {                                                   /// treba bolji uslov da nema i simbola !!!!!
            printf("Podaci nisu dobro uneseni\n");
            return 0;
        }
    return 1;

}










