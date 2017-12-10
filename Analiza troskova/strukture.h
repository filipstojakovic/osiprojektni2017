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
    char surname[15+1] ;
    unsigned char dan,mj;
    unsigned int god;
    int total;
    ARTIKL *art;
    int n;
}POD;
#endif // STRUKTURAACCOUNT_H_INCLUDED
