#include "login.h"
#include "admin.h"
#include "analyst.h"
#include "signin.h"
// ovakav komentar je za opis funkcije ili neke komande
/// ovakav komentar je ako treba neku izmjenu napraviti

int main()
{
    int flag=0;         //1 admin ili 0- analiticar
    while(!login(&flag))
        printf("nisu dobri podaci!\n");

    // signin();
    /// signin treba staviti na pravo mjesto
    int cmd;
    // system("cls"); brise sve sa konzole
    printf("ulogovan! ");
     if(flag==1)
        adminMenu();
    else
        analystMenu();


    getchar();
    getchar();
}
