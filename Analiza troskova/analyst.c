#include "analyst.h"

void analystMenu(NODE *head)
{
    char c,ch;
    printf("*=============================================================================*\n");
    printf("                        Welcome Analyst! \n\n\n");
    do
    {
        NODE *tmp_head=head;    // za svaki slucaj da se ne koristi orginalna glava
        fflush(stdin);
        printf("*=============================================================================*\n");
        printf("[r] - review customer data\n");
        printf("[p] - review product data\n");
        printf("[w] - review of sale data\n");
        printf("[h] - help menu\n");
        printf("==========================\n");
        printf("[l] - logout\n");
        printf("[e] - exit\n");
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        system("cls");
        if(ch!='\n' || provera_slova_analyst(c)!=1)    //provjerava da li je unesono slovo jedno od ponudjenih
        {
            printf("Unknown letter !\n");
        }
        else if(c=='e')     //provjera za izlaz
        {
            printf("GOOOOODBAYYY! \n");
        }
        else if(c=='h')
        {
            helpMenu_analyst();
            c=ponovo_meni_analyst();
        }
        else if(c=='r')
        {

            char name[15+1], surname[15+1];
            customerList(tmp_head);
            printf("Enter customer's\nName: ");
            scanf("%s",name);
            fflush(stdin);
            printf("Surname: ");
            fgets(surname, 15, stdin);       // fgets - da moze uzeti '\n' kao string tj ako nema prezimena
            surname[strlen(surname)-1]=0;   // zato sto je '\n' poslednji karakter u stringu (brisemo ga)

            customerArtikls(tmp_head,name,surname);
            fflush(stdin);
            c=ponovo_meni_analyst();
        }
        else if(c=='p')
        {
            printf("review product data\n\n\n");
            c=ponovo_meni_analyst();
        }
        else if(c=='w')
        {
            unsigned char mj;
            do
            {
                printf("Enter specific month (1-12): ");
                scanf("%hhu",&mj);

            }
            while(mj<1 || mj>12);

            artiklsByDate(tmp_head,mj);
            c=ponovo_meni_analyst();
        }
        fflush(stdin);
    }
    while(c!='e' && c!='l');
    if(c=='e')
    {
        printf("                              Exit\n");
        printf("*=============================================================================*\n");
    }
    if(c=='l')// vraca u main ako je odabrana opcija Logout
    {
        printf("Logout successful!\n");
        main(); /// Ako neko ima bolju ideju kako doci do logina ponovo... Ovo je jako lose, al' nisam imao druge ideje
    }
}

int provera_slova_analyst(char s)
{
    if( s!='r' && s!='w' && s!='h' && s!='e' && s!='p' && s!='l')
        return 0;
    return 1;
}

char ponovo_meni_analyst()
{
    char c,ch,s;
    do
    {
        fflush(stdin);
        printf("Do you want to go back to menu ? \n");
        printf("[y] - yes\n");
        printf("[n] - no\n");
        fflush(stdin);
        printf("Option: ");
        scanf("%c",&c);
        scanf("%c",&ch);
        if(ch!='\n' || provera_slovaYN_analyst(c)!=1)
        {
            printf("Wrong option!\n");
            continue;
        }

    }
    while(ch!='\n' || provera_slovaYN_analyst(c)!=1);

    if(c=='y')
        s='y';
    else if(c=='n')
        s='e';
    system("cls");
    return s;
}

int provera_slovaYN_analyst( char s)  //funkcija za provjeru slova Y | N za ponovo_menu
{
    if( s=='y' ||  s=='n' )
        return 1;
    return 0;
}

void helpMenu_analyst() // help menu za analystMenu
{
    system("cls");
    printf("Review Customer Data:\n");
    printf("This option reviews all data for a specific customer.\n\n\n");
    printf("Review Product Data:\n");
    printf("This option reviews all data for a specific product. \n\n\n");
    printf("Review Of Sale Data:\n");
    printf("This option reviews data for all sales made in a specific timeline \n\n\n");
}


void customerList(NODE *head)
{
    printf("Customore list:\n");
    while(head)
    {
        printf("%s %s\n",head->name,head->surname);
        head=head->next;
    }
    printf("\n");

}

void customerArtikls (NODE* head,char* name,char* surname)
{
    while(head)
    {
        if(strcmp(head->name,name)==0 && strcmp(head->surname,surname)==0)
        {
            system("cls");
            printf("Kupac: %s %s\n\n",name,surname);


            for(int j=0; j<head->n_racuna; j++)
            {
                printf("Datum: %hhu %u\n",head->artdate[j].mj,head->artdate[j].god);
                printf("Proizvod        Barcode         Kol Cijena Ukupno\n");
                printf("_______________ _______________ ___ ______ ______\n");
                for(int i=0; i<head->artdate[j].n_art; i++)
                    printf("%-15s %-15s %3d %6d %6d\n",head->artdate[j].art[i].name,head->artdate[j].art[i].barcode,
                           head->artdate[j].art[i].kol,head->artdate[j].art[i].cijena,
                           head->artdate[j].art[i].total);
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


void artiklsByDate(NODE* head,unsigned char mj)
{
    if(head==0)
        return printf("Empty list - nema racuna\n");
        int i=0;
    while(head)
    {

        printf("i=%d\n",i);i++;
        fflush(stdin);
        for(int j=0; j<head->n_racuna; j++)
        {
            fflush(stdin);
            if(head->artdate[j].mj==mj)
            {

                printf("Kupac: %s %s\n",head->name,head->surname);
                printf("Datum: %hhu %u\n",head->artdate[j].mj,head->artdate[j].god);
                printf("Proizvod        Barcode         Kol Cijena Ukupno\n");
                printf("_______________ _______________ ___ ______ ______\n");
                for(int i=0; i<head->artdate[j].n_art; i++)
                {
                    printf("%-15s %-15s %3d %6d %6d\n",head->artdate[j].art[i].name,head->artdate[j].art[i].barcode,
                           head->artdate[j].art[i].kol,head->artdate[j].art[i].cijena,
                           head->artdate[j].art[i].total);
                }
                printf("\nTotal: %d\tPDV: %.2f\tSum:%.2f\n\n",head->artdate[j].total,head->artdate[j].PDV,head->artdate[j].sum);
            }
        }

        fflush(stdin);
        head=head->next;
    }

}



















