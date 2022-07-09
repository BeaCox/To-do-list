#include"task.h"
#include<cstring>
#include <stdio.h>
#include"add_name2file.h"
#include"login_and_Register.h"
task mytask[2];
int main(){
    FILE *fp;
    char admin[30]="yyy";
    char password[8]="0123456";
    //mytask.setTask();
    /*mytask[0].display();*/
    char myname[50]={0},mypassword[50]={0};
    login(myname,mypassword);loadTask(mytask,name2File(myname),mypassword);
    memset(myname,0,sizeof(myname));
    memset(mypassword,0,sizeof(mypassword));
    Register(myname,mypassword);
    saveTask(password,mytask,name2File(admin));
    loadTask(mytask,name2File(admin),"0123456");
    return 0;
}
