#ifndef STRUKTURAACCOUNT_H_INCLUDED
#define STRUKTURAACCOUNT_H_INCLUDED

#include <stdlib.h>

typedef struct account //structure that contains all information for a administrator or analyst
{
    int type;
    char name[15+1];
    char surname[15+1];
    char pin[4+1];
}ACCOUNT;

typedef struct artikl //structure that contains all the information about a specific product
{
    char name[15+1];
    char barcode[15+1];
    float amount;
    float price;
    float total;
}ARTIKL;

typedef struct data //structure that contains all information about a specific bill
{
    char name[15+1];
    char surname[15+1];
    unsigned char day,month;
    unsigned int year;
    ARTIKL *art;
    int n;
    float total;      // without PDV
    float PDV;
    float sum;  // with PDV
}POD;

typedef struct art_date //structure that contains all information about specific articles on some dates
{
    unsigned char month;
    unsigned int year;
    int n_art;          // number of products with this date
    ARTIKL *art;
    float total;      // without PDV
    float PDV;
    float sum;  // with PDV
}ART_DATE;

typedef struct node //structure that contains bills with diferent dates
{
    char name[15+1];
    char surname[15+1];
    ART_DATE *artdate;  // list of bills
    int num_bill;           // number of bills with diferent date
    struct node *next;
}NODE;

#endif // STRUKTURAACCOUNT_H_INCLUDED
