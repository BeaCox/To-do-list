#include"task.h"
#include"add_name2file.h"
task mytask[2];
int main(){
    char admin[30]="chenchiyu";
    char password[8]="0123456";
    //mytask.setTask();
    mytask[0].display();
    saveTask(password,mytask,name2File(admin));
    system("pause");
    return 0;
}