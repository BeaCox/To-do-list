#include "task.h"
#include <cstring>
#include <stdio.h>
#include "stringAndInt.h"
#include "deleteSpace.h"
#include "EntryMD5.h"
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
    for (; name[i] != '\0'; ++i)
    {
        this->name[i] = name[i];
    }
    this->name[i] = '\0';
    i = 0;
    for (; classify[i] != '\0'; ++i)
    {
        this->classify[i] = classify[i];
    }
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

void task::setTask(int id = 0, char *name = defaultName, int sYear = 2022, int sMonth = 1, int sDay = 1, int sHour = 0, int sMinute = 0, int rYear = 2022, int rMonth = 1, int rDay = 1, int rHour = 0, int rMinute = 0, char *classify = defaultClassify, int priority = 1)
{
    this->id = id; //！！！！！！！！！！随机分配id应该写在这里！！！！！！！！！！！
    int i = 0;
    for (; name[i] != '\0'; ++i)
    {
        this->name[i] = name[i];
    }
    this->name[i] = '\0';
    this->start = start;
    i = 0;
    for (; classify[i] != '\0'; ++i)
    {
        this->classify[i] = classify[i];
    }
    this->classify[i] = '\0';
    this->priority = priority;
    this->timerReminder = timerReminder;
    this->start.year = sYear;
    this->start.month = sMonth;
    this->start.day = sDay;
    this->start.hour = sHour;
    this->start.minute = sMinute;
    this->timerReminder.year = rYear;
    this->timerReminder.month = rMonth;
    this->timerReminder.day = rDay;
    this->timerReminder.hour = rHour;
    this->timerReminder.minute = rMinute;
    taskNum++;
    taskLive++;
}

void delTask(task *myTask)
{
    int deleteId;
    cout << "请输入你要删除的任务对应的id: ";
    cin >> deleteId;
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

void reminder(task t)
{
    time_t timep;
    struct tm *nowTime;
    time(&timep);                //获取从1970至今过了多少秒，存入time_t类型的timep
    nowTime = localtime(&timep); //用localtime将秒数转化为struct tm结构体
    if ((nowTime->tm_year + 1900) == t.timerReminder.year && (1 + nowTime->tm_mon) == t.timerReminder.month && nowTime->tm_mday == t.timerReminder.day && nowTime->tm_hour == t.timerReminder.hour && nowTime->tm_min == t.timerReminder.minute)
    {
        cout << "现在" << t.timerReminder.hour << "时" << t.timerReminder.minute << "分,"
             << "您在" << t.start.hour << "时" << t.start.minute << "分有任务：" << t.name << endl;
    }
    else
        return;
}; //提醒任务

void showTaskByDay(task *myTask, int year, int month, int day)
{
    int loc[LIST_SIZE] = {-1}; //用来记录每个任务的位置
    int num = 0;               //用来记录任务的个数
    for (int i = 0; i < LIST_SIZE && myTask[i].id != 0; i++)
    {
        if (myTask[i].start.year == year && myTask[i].start.month == month && myTask[i].start.day == day)
        {
            loc[num] = i;
            num++;
        }
    } //查找day匹配的Task并记录其下标，存储于loc数组

    bool flag; //记录起泡中是否发生交换
    int i, j, temp;
    for (i = 0; i < num; i++)
    {
        flag = false;
        for (j = 0; j < num - i; j++)
        {
            if ((myTask[loc[j + 1]].start.hour < myTask[loc[j]].start.hour) || (myTask[loc[j + 1]].start.hour == myTask[loc[j]].start.hour && myTask[loc[j + 1]].start.minute < myTask[loc[j]].start.minute))
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
    for (int i = 0; i < LIST_SIZE && myTask[i].id != 0; i++)
    {
        if (myTask[i].start.year == year && myTask[i].start.month == month)
        {
            loc[num] = i;
            num++;
        }
    } //查找month匹配的Task并记录其下标，存储于loc数组

    bool flag; //记录起泡中是否发生交换
    int i, j, temp;
    for (i = 0; i < num; i++)
    {
        flag = false;
        for (j = 0; j < num - i; j++)
        {
            if ((myTask[loc[j + 1]].start.day < myTask[loc[j]].start.day) || (myTask[loc[j + 1]].start.day = myTask[loc[j]].start.day && myTask[loc[j + 1]].start.hour < myTask[loc[j]].start.hour) || (myTask[loc[j + 1]].start.day = myTask[loc[j]].start.day && myTask[loc[j + 1]].start.hour == myTask[loc[j]].start.hour && myTask[loc[j + 1]].start.minute < myTask[loc[j]].start.minute))
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
void saveTask(char *password, task *mytask, char *userfile)
{
    FILE *fp;
    // int len = strlen(userfile);
    if ((fp = fopen(userfile, "wt")) == NULL)
    {
        fprintf(stderr, "Fail to open file!\n");
        exit(0);
    }
    int i = 0;
    mytask[i].id = 1;
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
void loadTask(task mytask[], char *userfile, char *inputPassword)
{
    FILE *fp;
    int flag = -1;                //判断密码是否正确
    char mypassword[50], tmp[50]; // mypassword是用来储存第一行的密码的，tmp为临时储存的变量
    memset(mypassword,0,sizeof(mypassword));
    if ((fp = fopen(userfile, "r+")) == NULL)
    {
        fprintf(stderr, "未找到该用户，请重新登录！\n");
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
            fgets(tmp,45,fp);deleteSpace(tmp);task::taskNum = String2Int(tmp);memset(tmp,0,sizeof(tmp));
            fgets(tmp,45,fp);deleteSpace(tmp);task::taskLive = String2Int(tmp);memset(tmp,0,sizeof(tmp));
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
            printf("登录成功！");
        }
        else
            printf("密码错误！请重新登录！\n");
    }
}
