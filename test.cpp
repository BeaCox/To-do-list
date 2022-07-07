#include"task.h"
#include<cstring>
#include <stdio.h>
#include"add_name2file.h"
task mytask[2];
int main(){
    FILE *fp;
    char admin[30]="d:\\yyy.txt";
    char password[8]="0123456";
    //mytask.setTask();
    mytask[0].display();
    saveTask(password,mytask,admin);
    //system("pause");
    return 0;
}