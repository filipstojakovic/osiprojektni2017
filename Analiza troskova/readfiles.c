#include "readfiles.h"

int fileList()
{
    DIR *dir;
    struct dirent *dp;

    if ((dir= opendir("./racuni")) == NULL)
    {
        printf("Cannot open ./racuni directory\n");
        return 0;
    }
    else
    {
        while((dp=readdir (dir)) != NULL)       // cita redom fajlove i smjesta u strukturu dp
        {
            if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0) // da preskoci ove datoteke
                continue;                                                                        // . trenutna dat
            printf("%s\n",dp->d_name);                                                   // .. otac-datoteka
        }
    }

    closedir(dir);
    return 1;
}
