#include "login.h"
int main()
{
    int flag=0;         //1 admin ili 0- analiticar
    while(!login(&flag))
        printf("nisu dobri podatci!\n");

    int cmd;
    // system("cls"); brise sve sa konzole
    printf("ulogovan! ");
//    if(flag==0)
//        while(cmd!=0)
//        {
//
//            printf("logout................[0]");
//            printf("command: ");
//            scanf("%d",&cmd);
//        }
//

    getchar();
    getchar();
}
