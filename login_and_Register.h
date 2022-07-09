#ifndef LOGIN_ANDREGISTER_H
    #define LOGIN_ANDREGISTER_H
    #include <stdio.h>
    #include <iostream>
    #include <cstring>
    void login(char *inputName,char *inputPassword){
        printf("请输入用户名(不超过40个字符，以换行符作为结尾)\n");
        std::cin.getline(inputName,45);
        printf("请输入密码(不超过40个字符，以换行符作为结尾)\n");
        std::cin.getline(inputPassword,45);
    }
    void Register(char *inputName,char *inputPassword){
        char flag[50]={0}; //等待用户确认状态
        while(!(strlen(flag)==1&&(flag[0]=='y'||flag[0]=='Y'))){
	memset(inputName,0,sizeof(inputName));
	memset(inputPassword,0,sizeof(inputPassword));
	memset(flag,0,sizeof(flag));
        printf("请注册用户名(不超过40个字符，以换行符作为结尾)\n");
        std::cin.getline(inputName,45);
        printf("请输入密码(不超过40个字符，以换行符作为结尾)\n");
        std::cin.getline(inputPassword,45);
        printf("请核对您的账户信息：\n");
        printf("用户名：%s\n",inputName);
        printf("密码：%s\n",inputPassword);
        printf("是否注册？注册请输入y或Y，按任意键重新注册\n");
        std::cin.getline(flag,45);
        }
        printf("注册成功！");
    }
#endif