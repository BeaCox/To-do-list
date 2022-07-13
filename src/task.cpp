#include "task.h"
#include <cstring>
#include <stdio.h>
#include "stringAndInt.h"
#include "deleteSpace.h"
#include "EntryMD5.h"
#include <unistd.h>
char defaultName[20] = "学习C++";
char defaultClassify[20] = "学习";
int LIST_SIZE = 100;
timeT::timeT(int y, int M, int d, int h, int m)
{
    year = y;
    month = M;
    day = d;
    hour = h;
    minute = m;
}

int task::taskNum = 0;
int task::taskLive = 0;

task::task()
    : start(2022, 1, 1, 0, 0), timerReminder(2022, 1, 1, 0, 0)
{
    this->id = 0;
    int i = 0;
    strcpy(this->name, defaultName);
    // this->name[i] = defaultName[i];
    // this->name[i] = '\0';
    i = 0;

    strcpy(this->classify, defaultClassify);
    // this->classify[i] = defaultClassify[i];

    this->priority = 3;
}

void task::display()
{
    cout << "任务id: " << id << endl;
    cout << "任务名称: " << name << endl;
    cout << "任务开始时间: " << start.year << "-" << start.month << "-" << start.day << " " << start.hour << ":" << start.minute << endl;
    cout << "任务分类: " << classify << endl;
    cout << "任务优先级: " << priority << endl;
    cout << "任务提醒时间: " << timerReminder.year << "-" << timerReminder.month << "-" << timerReminder.day << " " << timerReminder.hour << ":" << timerReminder.minute << endl
         << endl;
}

void task::setTask()
{
    id = taskNum + 1;
    int i = 0;
    cout << "请输入任务名称：";
    char _name[20];
    cin >> _name;
    for (; _name[i] != '\0'; ++i)
    {
        this->name[i] = _name[i];
    }
    this->name[i] = '\0';
    cout << "请输入任务开始时间（年 月 日 时 分）：";
    int sYear, sMonth, sDay, sHour, sMinute;
    cin >> sYear >> sMonth >> sDay >> sHour >> sMinute;
    this->start.year = sYear;
    this->start.month = sMonth;
    this->start.day = sDay;
    this->start.hour = sHour;
    this->start.minute = sMinute;
    cout << "请输入提醒时间（年 月 日 时 分）：";
    int rYear, rMonth, rDay, rHour, rMinute;
    cin >> rYear >> rMonth >> rDay >> rHour >> rMinute;
    this->timerReminder.year = rYear;
    this->timerReminder.month = rMonth;
    this->timerReminder.day = rDay;
    this->timerReminder.hour = rHour;
    this->timerReminder.minute = rMinute;
    char opt;
    cout << "是否需要指定分类，默认为学习(y/n)：";
    cin >> opt;
    if (opt == 'y' || opt == 'Y')
    {
        char _classify[20];
        cin >> _classify;
        i = 0;
        for (; _classify[i] != '\0'; ++i)
        {
            this->classify[i] = _classify[i];
        }
        this->classify[i] = '\0';
    }
    else if (opt == 'n' || opt == 'N')
        cout << "已默认为学习" << endl;
    else
        cout << "输入错误，已默认为学习" << endl;

    cout << "是否需要指定优先级，默认为3，数字越小优先级越高(y/n)：";
    cin >> opt;
    if (opt == 'y' || opt == 'Y')
    {
        int priority;
        cin >> priority;
        this->priority = priority;
    }
    else if (opt == 'n' || opt == 'N')
        cout << "已默认为3" << endl;
    else
        cout << "输入错误，已默认为3" << endl;
    taskNum++;
    taskLive++;
    cout << "任务创建成功！" << endl;
    getchar();
}

void delTask(task *myTask, int deleteId)
{
    if (deleteId <= 0)
    {
        cout << "任务id不存在!" << endl;
    }
    int i = 0;
    for (; i < LIST_SIZE; i++)
    {
        if (myTask[i].id == deleteId)
            break;
    }
    if (i == LIST_SIZE)
    {
        cout << "任务id不存在!" << endl;
        return;
    }
    for (int j = i; j < LIST_SIZE - 1; j++)
    {
        myTask[j] = myTask[j + 1];
    }
    task::taskLive--;
    cout << "此任务已删除!" << endl;
    return;
} //删除任务

void reminder(task t[])
{
    while (1)
    {
        time_t timep;
        bool flag = false; //用来判断是否有任务提醒
        struct tm *nowTime;
        time(&timep);                //获取从1970至今过了多少秒，存入time_t类型的timep
        nowTime = localtime(&timep); //用localtime将秒数转化为struct tm结构体
        for (int i = 0; i < task::taskLive; i++)
        {
            if ((nowTime->tm_year + 1900) == t[i].timerReminder.year && (1 + nowTime->tm_mon) == t[i].timerReminder.month && nowTime->tm_mday == t[i].timerReminder.day && nowTime->tm_hour == t[i].timerReminder.hour && nowTime->tm_min == t[i].timerReminder.minute)
            {
                cout << "现在" << t[i].timerReminder.hour << "时" << t[i].timerReminder.minute << "分,"
                     << "您在" << t[i].start.hour << "时" << t[i].start.minute << "分有任务：" << t[i].name << endl;
                flag = true;
            }
        }
        if (flag)
            sleep(60);
        else
            sleep(5);
    }
}; //提醒任务

void showTaskByDay(task *myTask, int year, int month, int day)
{
    int loc[LIST_SIZE] = {-1}; //用来记录每个任务的位置
    int num = 0;               //用来记录任务的个数
    for (int i = 0; i < task::taskLive && myTask[i].id != 0; i++)
    {
        if (myTask[i].start.year == year && myTask[i].start.month == month && myTask[i].start.day == day)
        {
            loc[num] = i;
            num++;
        }
    } //查找day匹配的Task并记录其下标，存储于loc数组

    bool flag; //记录起泡中是否发生交换
    int i, j, temp;
    for (i = 1; i < num; i++)
    {
        flag = false;
        for (j = 0; j < num - i; j++)
        {
            if ((myTask[j + 1].start.hour < myTask[j].start.hour) || (myTask[j + 1].start.hour == myTask[j].start.hour && myTask[j + 1].start.minute < myTask[j].start.minute))
            {
                temp = loc[j];
                loc[j] = loc[j + 1];
                loc[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    } //按照时间冒泡排序

    for (i = 0; i < num; i++)
    {
        myTask[loc[i]].display();
    }
} //显示某一天的任务

void showTaskByMonth(task *myTask, int year, int month)
{
    int loc[LIST_SIZE] = {-1}; //用来记录每个任务的位置
    int num = 0;               //用来记录任务的个数
    for (int i = 0; i < task::taskLive && myTask[i].id != 0; i++)
    {
        if (myTask[i].start.year == year && myTask[i].start.month == month)
        {
            loc[num] = i;
            num++;
        }
    } //查找month匹配的Task并记录其下标，存储于loc数组

    bool flag; //记录起泡中是否发生交换
    int i, j, temp;
    for (i = 1; i < num; i++)
    {
        flag = false;
        for (j = 0; j < num - i; j++)
        {
            if ((myTask[j + 1].start.day < myTask[j].start.day) || (myTask[j + 1].start.day = myTask[j].start.day && myTask[j + 1].start.hour < myTask[j].start.hour) || (myTask[j + 1].start.day = myTask[j].start.day && myTask[j + 1].start.hour == myTask[j].start.hour && myTask[j + 1].start.minute < myTask[j].start.minute))
            {
                temp = loc[j];
                loc[j] = loc[j + 1];
                loc[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    } //按照时间冒泡排序

    for (i = 0; i < num; i++)
    {
        myTask[loc[i]].display();
    }
} //显示某一月的任务

void showTaskAll(task *myTask)
{
    int loc[LIST_SIZE] = {-1}; //用来记录每个任务的位置
    for (int i = 0; i < task::taskLive && myTask[i].id != 0; i++)
    {
        loc[i] = i;
    } //查找id不为0的任务记录其下标，存储于loc数组

    bool flag; //记录起泡中是否发生交换
    int i, j, temp;
    for (i = 1; i < task::taskLive; i++)
    {
        flag = false;
        for (j = 0; j < task::taskLive - i; j++)
        {
            if ((myTask[j + 1].start.year < myTask[j].start.year) || (myTask[j + 1].start.year == myTask[j].start.year && myTask[j + 1].start.month < myTask[j].start.month) || (myTask[j + 1].start.year == myTask[j].start.year && myTask[j + 1].start.month == myTask[j].start.month && myTask[j + 1].start.day < myTask[j].start.day) || (myTask[j + 1].start.year == myTask[j].start.year && myTask[j + 1].start.month == myTask[j].start.month && myTask[j + 1].start.day == myTask[j].start.day && myTask[j + 1].start.hour < myTask[j].start.hour) || (myTask[j + 1].start.year == myTask[j].start.year && myTask[j + 1].start.month == myTask[j].start.month && myTask[j + 1].start.day == myTask[j].start.day && myTask[j + 1].start.hour == myTask[j].start.hour && myTask[j + 1].start.minute < myTask[j].start.minute))
            {
                temp = loc[j];
                loc[j] = loc[j + 1];
                loc[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    } //按照时间冒泡排序

    for (i = 0; i < task::taskLive; i++)
    {
        myTask[loc[i]].display();
    }
} //显示所有任务

void saveTask(char *password, task *mytask, char *userfile)
{
    FILE *fp;
    // int len = strlen(userfile);
    if ((fp = fopen(userfile, "wt")) == NULL)
    {
        fprintf(stderr, "Fail to open file!\n");
        exit(0); //这种情况下，只有可能异常终止，返回0
    }
    int i = 0;
    char keyValue[64];                     //存储变换后的md5密码的文件
    memset(keyValue, 0, sizeof(keyValue)); //初始化
    EntryMD5(password, keyValue);
    fputs(keyValue, fp);
    fputs("\n", fp);                      //密文保存md5
    fputs(Int2String(task::taskNum), fp); //保存总共的taskNum数
    fputs("\n", fp);
    fputs(Int2String(task::taskLive), fp); //保存活着的taskLive数
    fputs("\n", fp);
    while ((mytask[i].id) != 0)
    {
        fputs(Int2String(mytask[i].id), fp);
        fputs("\n", fp);
        fputs(mytask[i].name, fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].start.year), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].start.month), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].start.day), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].start.hour), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].start.minute), fp);
        fputs("\n", fp);
        fputs(mytask[i].classify, fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].priority), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].timerReminder.year), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].timerReminder.month), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].timerReminder.day), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].timerReminder.hour), fp);
        fputs("\n", fp);
        fputs(Int2String(mytask[i].timerReminder.minute), fp);
        fputs("\n", fp);
        i++;
    }
    fclose(fp);
}
bool loadTask(task mytask[], char *userfile, char *inputPassword)
{
    FILE *fp;
    int flag = -1;                //判断密码是否正确
    char mypassword[50], tmp[50]; // mypassword是用来储存第一行的密码的，tmp为临时储存的变量
    memset(mypassword, 0, sizeof(mypassword));
    if ((fp = fopen(userfile, "r+")) == NULL)
    {
        fprintf(stderr, "未找到该用户，请重新登录！\n");
        return 0; //返回0，用if判断登录失败重新登录
    }
    else
    {
        int tasknum = 0, tmpnumber = 0; // tasknum用来收集task数目，tmpnumber用来收集task的第i位值
        memset(tmp, 0, sizeof(tmp));
        fgets(mypassword, 50, fp);
        deleteSpace(mypassword);
        EntryMD5(inputPassword, tmp);
        flag = strcmp(tmp, mypassword);
        if (flag == 0)
        {
            fgets(tmp, 45, fp);
            deleteSpace(tmp);
            task::taskNum = String2Int(tmp);
            memset(tmp, 0, sizeof(tmp));
            fgets(tmp, 45, fp);
            deleteSpace(tmp);
            task::taskLive = String2Int(tmp);
            memset(tmp, 0, sizeof(tmp));
            while ((fgets(tmp, 45, fp) != NULL))
            {
                deleteSpace(tmp);
                switch (tmpnumber)
                {
                case 0:
                {
                    mytask[tasknum].id = String2Int(tmp);
                    tmpnumber++;
                    break;
                }
                case 1:
                    strcpy(mytask[tasknum].name, tmp);
                    tmpnumber++;
                    break;
                case 2:
                    mytask[tasknum].start.year = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 3:
                    mytask[tasknum].start.month = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 4:
                    mytask[tasknum].start.day = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 5:
                    mytask[tasknum].start.hour = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 6:
                    mytask[tasknum].start.minute = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 7:
                    strcpy(mytask[tasknum].classify, tmp);
                    tmpnumber++;
                    break;
                case 8:
                    mytask[tasknum].priority = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 9:
                    mytask[tasknum].timerReminder.year = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 10:
                    mytask[tasknum].timerReminder.month = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 11:
                    mytask[tasknum].timerReminder.day = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 12:
                    mytask[tasknum].timerReminder.hour = String2Int(tmp);
                    tmpnumber++;
                    break;
                case 13:
                    mytask[tasknum].timerReminder.minute = String2Int(tmp);
                    tmpnumber = 0;
                    tasknum++;
                    break;
                }
                memset(tmp, 0, sizeof(tmp)); //记得清零tmp为后来做准备
            }
            fclose(fp);
            printf("登录成功！\n");
            return 1; //登录成功返回1，条件判断成立，进入下一步
        }
        else
            printf("密码错误！请重新登录！\n");
        return 0; //密码错误，条件判断，重新登录或注册即可
    }
}
