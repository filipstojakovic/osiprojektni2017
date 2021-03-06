#include "analyst.h"

extern float currency;

char analystMenu(NODE *head)
{
    char c,ch;
    printf("*=============================================================================*\n");
    printf("                               Welcome Analyst! \n\n");
    do
    {
        NODE *tmp_head=head;
        fflush(stdin);
        printCurrency();
        printf("*=============================================================================*\n");
        printf("[r] - Review customer data\n");
        printf("[p] - Review product data\n");
        printf("[w] - Review of sale data\n");
        printf("[s] - Statistics review\n");
        printf("[b] - Report about bills\n");
        printf("[h] - Help menu\n");
        printf("===========================\n");
        printf("[l] - Logout\n");
        printf("[e] - Exit\n");
        printf("===========================\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        system("cls");
        if(ch!='\n' || letters_check_analyst_menu(c)!=1)
        {
            printf("Unknown letter !\n");
        }
        else if(c=='h')
        {
            helpMenu_analyst();
            c=again_menu_analyst();
        }
        else if(c=='r')
        {
            char name[15+1], surname[15+1];
            customerList(tmp_head);
            printf("Enter customer's\nName: ");
            scanf("%s",name);
            fflush(stdin);
            printf("Surname: ");
            fgets(surname, 15, stdin);
            surname[strlen(surname)-1]=0;
            customerArtikls(tmp_head,name,surname);
            fflush(stdin);
            c=again_menu_analyst();
        }
        else if(c=='s')
        {
            statistics_review(tmp_head);
            c=again_menu_analyst();
        }
        else if(c=='b')
        {
            bills_report();
            c=again_menu_analyst();
        }
        else if(c=='p')
        {
            printf("Enter specific product: ");
            char product[15+1];
            scanf("%s",product);
            productData(tmp_head,product);
            c=again_menu_analyst();
        }
        else if(c=='w')
        {
            unsigned char month;
            do
            {
                printf("Enter specific month (1-12): ");
                scanf("%hhu",&month);
            }
            while(month<1 || month>12);
            artiklsByDate(tmp_head,month);
            c=again_menu_analyst();
        }
        fflush(stdin);
    }
    while(c!='e' && c!='l');
    if(c=='e')
    {
        printf("                                  Exit\n");
        printf("*=============================================================================*\n");
        return 'e';
    }
    if(c=='l')
    {
        printf("                         Logout successful!\n");
        Sleep(2000);
        system("cls");
        return 'l';
    }
    return 'a';
}

int letters_check_analyst_menu(char s)
{
    if(s!='r' && s!='w' && s!='h' && s!='e' && s!='p' && s!='l' && s!='s' && s!='b')
        return 0;
    return 1;
}

char again_menu_analyst()
{
    char c,ch,s;
    do
    {
        fflush(stdin);
        printf("Do you want to go back to menu ? \n");
        printf("[y] - Yes\n");
        printf("[n] - No\n");
        fflush(stdin);
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || letters_check_analyst_Y_N(c)!=1)
        {
            printf("Wrong option!\n");
            continue;
        }
    }while(ch!='\n' || letters_check_analyst_Y_N(c)!=1);
    if(c=='y')
        s='y';
    else if(c=='n')
        s='e';
    system("cls");
    return s;
}

int letters_check_analyst_Y_N( char s)
{
    if( s=='y' ||  s=='n' )
        return 1;
    return 0;
}

void helpMenu_analyst()
{
    system("cls");
    printf("Review Customer Data:\n");
    printf("This option reviews all data for a specific customer.\n\n\n");
    printf("Review Product Data:\n");
    printf("This option reviews all data for a specific product. \n\n\n");
    printf("Review Of Sale Data:\n");
    printf("This option reviews data for all sales made in a specific timeline \n\n\n");
    printf("Statistics review:\n");
    printf("This option reviews total trafficing of company.\n\n\n");
    printf("Report about bills:\n");
    printf("This option reviews all valid and invalid bills.\n\n\n");
}

void customerList(NODE *head)
{
    printf("Customers list:\n");
    while(head)
    {
        printf("%s %s\n",head->name,head->surname);
        head=head->next;
    }
    printf("\n");
}

void customerArtikls(NODE* head,char* name,char* surname)
{
    while(head)
    {
        if(strcmp(head->name,name)==0 && strcmp(head->surname,surname)==0)
        {
            system("cls");
            printf("Customer: %s %s\n\n",name,surname);
            for(int j=0; j<head->num_bill; j++)
            {
                printf("Date: %hhu %u\n",head->artdate[j].month,head->artdate[j].year);
                printf("Product               Amount     Price      Total\n");
                printf("____________________ _______ _________ __________\n");
                for(int i=0; i<head->artdate[j].n_art; i++)
                    {
                        strcat(head->artdate[j].art[i].name, head->artdate[j].art[i].barcode);
                        printf("%-20s %7.2f %9.2f %10.2f\n",head->artdate[j].art[i].name,
                           head->artdate[j].art[i].amount,head->artdate[j].art[i].price*currency,
                           head->artdate[j].art[i].total*currency);
                    }
                printf("\nTotal: %.2f\tPDV: %.2f\tSum: %.2f\n\n",head->artdate[j].total*currency,head->artdate[j].PDV*currency,head->artdate[j].sum*currency);
                printf("\n");
            }
            printf("\n");
            break;
        }
        head=head->next;
    }
    if(head==0)
    {
        printf("No such name!\n");
    }
}

void artiklsByDate(NODE* head,unsigned char month)
{
    if(head==0)
        return printf("Empty list - no bill\n");
    int flag=1;
    while(head)
    {
        fflush(stdin);
        for(int j=0; j<head->num_bill; j++)
        {
            fflush(stdin);
            if(head->artdate[j].month==month)
            {
                if(flag)
                    flag=0;
                printf("Customer: %s %s\n",head->name,head->surname);
                printf("Date: %hhu %u\n",head->artdate[j].month,head->artdate[j].year);
                printf("Product               Amount     Price      Total\n");
                printf("____________________ _______ _________ __________\n");
                for(int i=0; i<head->artdate[j].n_art; i++)
                {
                    strcat(head->artdate[j].art[i].name,head->artdate[j].art[i].barcode);
                    printf("%-20s %7.2f %9.2f %10.2f\n",head->artdate[j].art[i].name,
                           head->artdate[j].art[i].amount,head->artdate[j].art[i].price*currency,
                           head->artdate[j].art[i].total*currency);
                }
                printf("\nTotal: %.2f\tPDV: %.2f\tSum: %.2f\n\n",head->artdate[j].total*currency,head->artdate[j].PDV*currency,head->artdate[j].sum*currency);
            }
        }
        fflush(stdin);
        head=head->next;
    }
    if(head==0 && flag)
        printf("No data for this month!\n\n");
}

void productData(NODE* head, char* product)
{
    if(head==0)
        return printf("No Data\n");
    ARTIKL result;
    strcpy(result.name,product);
    result.amount=0;
    result.price=0;
    result.total=0;
    while(head)
    {
        for(int j=0; j<head->num_bill; j++)
        {
            fflush(stdin);
            for(int i=0; i<head->artdate[j].n_art; i++)
            {
                fflush(stdin);
                if(strcmp(head->artdate[j].art[i].name,product)==0)
                {
                    if(result.amount==0)
                        strcpy(result.barcode,head->artdate[j].art[i].barcode);
                    result.amount+=head->artdate[j].art[i].amount;
                    result.price+=head->artdate[j].art[i].price;
                    result.total+=head->artdate[j].art[i].total;
                    break;
                }
            }
        }
        head=head->next;
    }
    fflush(stdin);
    printf("Result:\n");
    if(result.amount==0)
        printf("Product hasn't been purchased yet!\n\n");
    else
    {
       printf("Product               Amount     Price      Total\n");
       printf("____________________ _______ _________ __________\n");
       strcat(result.name,result.barcode);
        printf("%-20s %7.2f %9.2f %10.2f\n\n",result.name,result.amount,result.price*currency,result.total*currency);
    }
}

void statistics_review(NODE* head)
{
    ART_DATE result;
    NODE* temp=head;
    result.total=0;
    result.sum=0;
    result.PDV=0;
    if(temp==0)
        return printf("No Data\n");
    while(temp)
    {
        int j;
        for(j=0;j<temp->num_bill;j++)
        {
         result.total+=temp->artdate[j].total;
         result.sum+=temp->artdate[j].sum;
         result.PDV+=temp->artdate[j].PDV;
        }
        temp=temp->next;
    }
    fflush(stdin);
    if(result.total==0 || result.sum==0 ||  result.PDV==0)
        printf("Product hasn't been purchased yet!\n\n");
    else
    {
        printf("Results of total turn over:");
        printf("\nTotal: %.2f\nPDV: %.2f\nSum: %.2f\n\n",result.total*currency,result.PDV*currency,result.sum*currency);
    }
}

void bills_report()
{
    DIR *dir;
    struct dirent *dp;
    if((dir= opendir("./bills")) == NULL)
    {
        printf("Cannot open ./bills directory\n");
    }
    else
    {
        printf("All valid bills:\n");
        while((dp=readdir (dir)) != NULL)
        {
            if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0)
                continue;
            printf("%s\n",dp->d_name);
        }
    }
    printf("\n\n");
    if ((dir= opendir("./Error")) == NULL)
    {
        printf("\nCannot open ./Error directory\n");
    }
    else
    {
        printf("\nAll invalid bills:\n");
        while((dp=readdir (dir)) != NULL)
        {
            if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0)
                continue;
            printf("%s\n",dp->d_name);
        }
    }
    printf("\n\n");
    closedir(dir);
}












