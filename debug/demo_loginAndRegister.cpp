#include"task.h"
#include"login_and_Register.h"
#include"add_name2file.h"
int main(){
    task mytask[2];
    char myname[50],mypassword[50];
    login(myname,mypassword);loadTask(mytask,name2File(myname),mypassword);
    Register(myname,mypassword);
}