#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char array[1000] = {0};
    char result[1000] = {0};
    while(1){
        printf("Please enter want to query domain:");
        scanf("%s",array);
        sprintf(result, "dig @8.8.8.8 %s > delete.txt",array);
        printf("   <------>   %s",array);
        system(result);
        sleep(1);
        system("./act");
        printf("\n\n");
    }
    return 0;
}

