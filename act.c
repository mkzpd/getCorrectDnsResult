#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define resutFILEname "nohup.out"
#define bufSIZE 100

int main()
{
    int fd, k, m = 0;
    off_t currpos, currposT;
    ssize_t readNum, readNumT;
    char TTT[1] = {0};
    char buf[bufSIZE] = {0};
    char printResult[bufSIZE] = {0};
    fd = open(resutFILEname, O_RDONLY);
    if(-1 == fd){
        printf("open file %s ERROR!  *** MAY BE YOUR COMMAND NOT RUN AT THE SAME DIRECTORY *** \n",resutFILEname);
        exit(1);
    }
    currposT = lseek(fd, -2, SEEK_END);
    if(-1 == currposT){
        printf("lseek 1 ERROR!\n");
        exit(1);
    }
    readNumT = read(fd, &TTT, 1);
    if(readNumT == -1){
        printf("read 1 ERROR!\n");
        exit(1);
    }
    if(TTT[0] != 'T'){
        printf("No found correct result,you may try again!\n");
        exit(1);
    }
    currpos = lseek(fd, -20, SEEK_END);
    if(currpos == -1){
        printf("lseek 2 ERROR!\n");
        exit(1);
    }
    readNum = read(fd, buf, 15);
    if(readNum == -1){
        printf("read 2 ERROR!\n");
        exit(1);
    }
    buf[15] = '\0';
    for(k = 15; k >= 0; k--){
        if(buf[k] != ' '){
            printResult[m] = buf[k];
            m++;
        }else{
            printResult[m] = '\0';
            break;
        }
    }
    printf("\n");
    for(; m >= 0; m--){
        putchar(printResult[m]);
    }
    close(fd);
    return 0;
}

