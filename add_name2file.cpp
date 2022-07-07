#include "add_name2file.h"
#include <cstring>
    char *name2File(char *myname){//将某个人的用户名转换成.txt文件
    char file[40]={};
    int i = 0;
    file[0]='d';
    file[1]=':';
    file[2]='\\';
    file[3]='\\';
    for (i = 4;i < strlen(myname)+4;i++)
        file[i]=myname[i-4];
    file[i]='.';
    file[i+1]='t';
    file[i+2]='x';
    file[i+3]='t';
    return file;
    }