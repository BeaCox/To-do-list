#include "add_name2file.h"
#include <cstring>
char *name2File(char *myname)
{ //将某个人的用户名转换成.txt文件
    static char file[40] = {};
    memset(file,0,sizeof(file)); //初始化file
    int i = 0;
    /*file[0] = 'd';
    file[1] = ':';
    file[2] = '\\';
    file[3] = '\\';*/  //Linux版本与Windows不同先隐去
    for (i = 0; i < strlen(myname) + 0; i++)
        file[i] = myname[i + 0];  
    file[i] = '.';
    file[i + 1] = 't';
    file[i + 2] = 'x';
    file[i + 3] = 't';
    return file;
}