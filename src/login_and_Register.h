
#ifndef LOGIN_ANDREGISTER_H
#define LOGIN_ANDREGISTER_H
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "add_name2file.h"
using namespace std;
void login(char *inputName, char *inputPassword) //简单的输入输出，记得执行loadtask指令
{
    memset(inputName, 0, sizeof(inputName));
    memset(inputPassword, 0, sizeof(inputPassword));
    printf("请输入用户名(不超过40个字符，以换行符作为结尾)\n");

    std::cin.getline(inputName, 45);
    printf("请输入密码(不超过40个字符，以换行符作为结尾)\n");
    std::cin.getline(inputPassword, 45);
}
void Register(char *inputName, char *inputPassword)
{
    char flag[50] = {0};      //等待用户确认状态
    bool checkNameRepeat = 0; //检查用户名是否之前注册过
    while (!(strlen(flag) == 1 && (flag[0] == 'y' || flag[0] == 'Y')))
    {
        checkNameRepeat = 0;
        memset(inputName, 0, sizeof(inputName));
        memset(inputPassword, 0, sizeof(inputPassword));
        memset(flag, 0, sizeof(flag));
        while (!checkNameRepeat)
        {
            printf("请注册用户名(不超过40个字符，以换行符作为结尾)\n");
            if(cin.peek()=='\n') getchar();
            std::cin.getline(inputName, 45);
            if (fopen(name2File(inputName), "r+") == NULL)
                checkNameRepeat = 1; //未注册用户则标记置为1
            else
            {
                printf("用户名已存在，请重新注册！\n");
                memset(inputName, 0, sizeof(inputName));
                checkNameRepeat = 0;
            }
        }
        printf("请输入密码(不超过40个字符，以换行符作为结尾)\n");
        std::cin.getline(inputPassword, 45);
        printf("请核对您的账户信息：\n");
        printf("用户名：%s\n", inputName);
        printf("密码：%s\n", inputPassword);
        printf("是否注册？注册请输入y或Y，按任意键重新注册\n");
        std::cin.getline(flag, 45);
    }
    printf("注册成功！\n");
}
#endif