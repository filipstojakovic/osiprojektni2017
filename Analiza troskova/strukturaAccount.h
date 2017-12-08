#ifndef STRUKTURAACCOUNT_H_INCLUDED
#define STRUKTURAACCOUNT_H_INCLUDED

typedef struct account
{
    int type;
    char name[15+1];
    char surname[15+1];
    char pin[4+1];

}ACCOUNT;

#endif // STRUKTURAACCOUNT_H_INCLUDED
