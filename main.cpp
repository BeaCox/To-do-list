#include<getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"task.h"
#include"stringAndInt.h"
const int MAX_SIZE=100;
task myTask[MAX_SIZE];

void usage(const char * cmd)
{
	printf("离线日程管理系统\n");
	printf("可选参数   :  %s [-r][-a][-s][-d][-h]\n", cmd);
    printf("-r : 运行程序\n-a : 添加任务\n-s xxxx-xx或xxxx-xx-xx : 查看某月或某日的任务\n-d <num> : 删除id为num的任务\n-h : 查看帮助\n");

	printf("示例:\n");
	printf("   %s  -r\n",  cmd);
	printf("   %s  -a\n", cmd);
    printf("   %s  -s 2022-07-10\n", cmd);
    printf("   %s  -d 1\n", cmd);
    printf("   %s  -h\n", cmd);
	return;
}



int main(int argc, char * argv[])
{
    int opt,num;
    const char *optstring = "ras:d:h"; // 命令行参数有五个选项-rasdh，分别表示run add show del help
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'r':
                printf("请先登录……\n");//需要修改，如果没有用户则注册，如果有用户则登录
                printf("程序正在运行……输入help查看帮助\n");
                break;
            case 'a':
                printf("请先登录……\n");//需要修改，如果没有用户则注册，如果有用户则登录
                myTask[task::taskLive].setTask();
                break;
            case 's':
                printf("请先登录……\n");//需要修改，如果没有用户则注册，如果有用户则登录
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
                }
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
                }
                else {printf("参数错误\n");usage(argv[0]);}
                break;
            case 'd':
                printf("请先登录……\n");//需要修改，如果没有用户则注册，如果有用户则登录
                delTask(myTask,atoi(optarg));
                break;
            case 'h':
                usage(argv[0]);
			    break;
            case '?':
                printf("错误选项: %c\n", optopt);
                printf("错误参数: %d\n", opterr);
                usage(argv[0]);
                break;
        }
    }
    return 0;

}