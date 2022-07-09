#include<getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"task.h"
#include"login_and_Register.h"
const int MAX_SIZE=100;


//命令行传参时显示的帮助信息
void usage(const char * cmd)
{
	printf("离线日程管理系统\n");
	printf("可选参数 : %s [-r][-a][-s][-d][-h]\n", cmd);
    printf("-r : 运行程序\n-a : 添加任务\n-s xxxx-xx或xxxx-xx-xx或不加参数 : 查看某月或某日或全部的任务\n-d <num> : 删除id为num的任务\n-h : 查看帮助\n");
	printf("示例:\n");
	printf("   %s  -r\n",  cmd);
	printf("   %s  -a\n", cmd);
    printf("   %s  -s 2022-07-10\n", cmd);
    printf("   %s  -d 1\n", cmd);
    printf("   %s  -h\n", cmd);
	return;
}

//-r进入后显示的帮助信息
void helpinfo()
{
    printf("帮助信息");
    printf("可选参数 : [help][add][show][del][quit]\n");
    printf("用法:\n");
    printf("   help : 查看帮助\n");
    printf("   add : 添加任务\n");
    printf("   show xxxx-xx或xxxx-xx-xx或不加参数: 查看某月或某日或全部的任务\n");
    printf("   del 1: 删除id为1的任务\n");
    printf("   quit : 退出程序\n");
}


void getCommand(int& count, char** commands) {
	while (cin.peek() != '\n'){
		cin >> commands[count];
		count++;
	}
	char rest[5]=" ";
	cin.getline(rest, 5);//清空cin的缓存区
}


int main(int argc, char * argv[]){
    task myTask[MAX_SIZE];
    int opt,num;
    char inputName[41];
    char inputPassword[41];
    const char *optstring = "ras::d:h"; // 命令行参数有五个选项-rasdh，分别表示run add show del help
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'r'://循环运行程序
                bool active = true;
                printf("请选择注册/登录/退出(r/l/q)\n");
                char opt;
                cin >> opt;
                if (opt=='r' || opt=='R'){
                    Register(inputName,inputPassword);
                }
                else if (opt=='l' || opt=='L'){
                    login(inputName,inputPassword);
                }
                else if (opt=='q' || opt=='Q'){
                    return 0;
                }
                else{
                    printf("输入错误，退出程序\n");
                    return 0;
                }
                helpinfo();
                
                char help[]="help";
                char add[]="add";
                char show[]="show";
                char del[]="del";
                char quit[]="quit";
                int commandcount = 0;//命令总参数数量
                int opt_r = 0;//命令量化参数
                char** commands = new char* [MAX_SIZE];//储存命令参数
                for (int i = 0; i < MAX_SIZE; ++i) {
                    commands[i] = new char[MAX_SIZE];
                }
                while (active){
                //此处进入while循环，接收用户输入的命令，可以参考命令行传参实现
                commandcount = 0;//命令置空
                opt_r = 0;//量化命令复原
                for (int i = 0; i < MAX_SIZE; ++i) {
                    for (int j = 0; j < MAX_SIZE; ++j) {
                        commands[i][j] = ' ';
                    }
                }//命令存储置空
                printf("请输入命令(输入help获取帮助信息)：\n");

                getCommand(commandcount, commands);//获取命令
                //将命令转换成数字
                if (strcmp(commands[0],help)) opt = 1;
                if (strcmp(commands[0], add)) opt = 2;
                if (strcmp(commands[0], show)) opt = 3;
                if (strcmp(commands[0], del))opt = 4;
                if (strcmp(commands[0], quit)) opt = 5;

                		switch (opt) {
                            //命令help
                            case 1: {
                                if (commandcount != 1) {//参数检查
                                    cout << "help命令后应当没有参数！" << endl;
                                    break;
                                }
                                else helpinfo();
                                break;
                            }
                            //命令add
                            case 2: {
                                if (commandcount != 1) {
                                    cout << "add命令后应当没有参数" << endl;
                                    break;
                                }
                                else myTask[task::taskLive].setTask();
                                break;
                            }
                            //命令show
                            case 3: {
                                if (commandcount != 2 && commandcount != 1) {
                                    cout << "show命令后应当有0或1个参数" << endl;
                                    break;
                                }
                                else {
                                    if (strlen(commands[1])==10){
                                    int year,month,day;
                                    char temp1[5];
                                    char temp2[3];
                                    char temp3[3];
                                    strncpy(temp1,commands[1],4);
                                    temp1[4]='\0';
                                    year=atoi(temp1);
                                    strncpy(temp2,commands[1]+5,2);
                                    temp2[2]='\0';
                                    month=atoi(temp2);
                                    strncpy(temp3,commands[1]+8,2);
                                    temp3[2]='\0';
                                    day=atoi(temp3);
                                    showTaskByDay(myTask,year,month,day);
                                }//如果参数为10字符即xxxx-xx-xx，按日查看任务
                                else if (strlen(commands[1])==7){
                                    int year,month;
                                    char temp1[5];
                                    char temp2[3];
                                    strncpy(temp1,commands[1],4);
                                    temp1[4]='\0';
                                    year=atoi(temp1);
                                    strncpy(temp2,commands[1]+5,2);
                                    temp2[2]='\0';
                                    month=atoi(temp2);
                                    showTaskByMonth(myTask,year,month);
                                }//如果参数为7字符即xxxx-xx，按月查看任务
                                else if (strlen(commands[1])==0){
                                    showTaskAll(myTask);
                                }//如果参数为0字符即不加参数，查看全部任务
                                else {printf("参数错误\n");usage(argv[0]);}//如果非上述情况，参数错误，报错并展示帮助信息
                                }
                                break;
                            }
                            //命令del
                            case 4: {
                                if (commandcount != 2) {
                                    cout << "del命令后应当有一个参数" << endl;
                                    break;
                                }
                                else delTask(myTask,atoi(commands[1]));
                                break;
                            }
                            //命令quit
                            case 5: {
                                if (commandcount != 1) {
                                    cout << "quit命令后应当没有参数" << endl;
                                    break;
                                }
                                else active = false;
                                break;
                            }
                            default: {
                                cout << "输入错误，请重新输入命令" << endl;
                                break;
                            }
                        }
                }
                break;
            case 'a':
                printf("请先登录……\n");//在这里续写
                myTask[task::taskLive].setTask();
                break;
            case 's':
                printf("请先登录……\n");//在这里续写
                if (strlen(optarg)==10){
                    int year,month,day;
                    char temp1[5];
                    char temp2[3];
                    char temp3[3];
                    strncpy(temp1,optarg,4);
                    temp1[4]='\0';
                    year=atoi(temp1);
                    strncpy(temp2,optarg+5,2);
                    temp2[2]='\0';
                    month=atoi(temp2);
                    strncpy(temp3,optarg+8,2);
                    temp3[2]='\0';
                    day=atoi(temp3);
                    showTaskByDay(myTask,year,month,day);
                }//如果参数为10字符即xxxx-xx-xx，按日查看任务
                else if (strlen(optarg)==7){
                    int year,month;
                    char temp1[5];
                    char temp2[3];
                    strncpy(temp1,optarg,4);
                    temp1[4]='\0';
                    year=atoi(temp1);
                    strncpy(temp2,optarg+5,2);
                    temp2[2]='\0';
                    month=atoi(temp2);
                    showTaskByMonth(myTask,year,month);
                }//如果参数为7字符即xxxx-xx，按月查看任务
                else if (strlen(optarg)==0){
                    showTaskAll(myTask);
                }//如果参数为0字符即不加参数，查看全部任务
                else {printf("参数错误\n");usage(argv[0]);}//如果非上述情况，参数错误，报错并展示帮助信息
                break;
            case 'd':
                printf("请先登录……\n");//在这里续写
                delTask(myTask,atoi(optarg));
                break;
            case 'h':
                usage(argv[0]);//展示帮助信息
			    break;
            default:
                printf("错误选项: %c\n", optopt);
                printf("错误参数: %d\n", opterr);
                usage(argv[0]);
                break;
        }
    }
    return 0;

}