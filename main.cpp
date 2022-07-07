#include<getopt.h>
#include"task.h"
void usage(const char * cmd)
{
	printf("离线日程管理系统\n");
	printf("可选参数   :  %s [-r][-a][-s][-d][-h]\n", cmd);
    printf("-r : 运行程序\n-a : 添加任务\n-s D/M: 按照日/月查看任务\n-d <num> : 删除id为num的任务\n-h : 查看帮助\n");

	printf("示例:\n");
	printf("   %s  -r\n",  cmd);
	printf("   %s  -a\n", cmd);
    printf("   %s  -s\n", cmd);
    printf("   %s  -d 1\n", cmd);
    printf("   %s  -h\n", cmd);
	return;
}



int main(int argc, char * argv[])
{
    int opt;
    const char *optstring = "ras:d:h"; // 有五个选项-rasdh，分别表示run add show del help
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'r':
                printf("程序正在运行……\n");
                break;
            case 'a':
                printf("请先登录\n");
                break;
            case 's':
                printf("请先登录\n");
                break;
            case 'd':
                printf("请先登录\n");
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