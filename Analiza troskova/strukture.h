#ifndef STRUKTURAACCOUNT_H_INCLUDED
#define STRUKTURAACCOUNT_H_INCLUDED

#include <stdlib.h>
typedef struct account
{
    int type;
    char name[15+1];
    char surname[15+1];
    char pin[4+1];

}ACCOUNT;

typedef struct artikl
{
    char name[15+1];
    char barcode[15+1];
    int kol;
    int cijena;
    int total;
}ARTIKL;

typedef struct podaci
{
    char name[15+1];
    char surname[15+1];
    unsigned char dan,mj;
    unsigned int god;
    ARTIKL *art;
    int n;
    int total;      // without PDV
    float PDV;
    float sum;  // with PDV
}POD;

typedef struct art_date
{
    unsigned char mj;
    unsigned int god;
    int n_art;          //  broj artikala sa ovim datumom
    ARTIKL *art;
    int total;      // without PDV
    float PDV;
    float sum;  // with PDV
}ART_DATE;

typedef struct node
{
    char name[15+1];
    char surname[15+1];
    ART_DATE *artdate;  // niz racuna
    int n_racuna;           // broj racuna sa razlicitim datumom

    struct node *next;
}NODE;

#endif // STRUKTURAACCOUNT_H_INCLUDED
