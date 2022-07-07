#ifndef TASK_H
    #define TASK_H
    #include <iostream>
    #include<time.h>
    using namespace std;
    struct timeT{
        int year;
        int month;
        int day;
        int hour;
        int minute;

        timeT(int y=0,int M=0,int d=0,int h=0,int m=0);
    };

    class task{
        friend void saveTask(char *password, task *mytask, char *userfile);
        friend void loadTask(task mytask[], char *userfile);
        friend void delTask(task *myTask);
        friend char *encrypt(char *password);
        friend bool checkpassword();
        friend void reminder(task t);
        friend void showTaskByDay(task *myTask,int year, int month, int day);
        friend void showTaskByMonth(task *myTask,int year, int month);
    private:
        int id;
        char name[20];
        timeT start;
        char classify[20];
        int priority;
        timeT timerReminder;
        static int taskNum;
        static int taskLive;
    public: 

        task();
        void display();
        void setTask(int id,char *name,int sYear,int sMonth,int sDay,int sHour,int sMinute,int rYear,int rMonth,int rDay,int rHour,int rMinute,char *classify,int priority);


    };

void delTask(task *myTask);//删除任务

void reminder(task t);//提醒任务

void showTaskByDay(task *myTask,int year, int month, int day);//按天显示任务
void showTaskByMonth(task *myTask,int year, int month);//按月显示任务
bool checkpassword();//还没写
char *encrypt(char *password);//还没写
void loadTask(task *mytask,char *userfile);//写完了
void saveTask(char *password,task *mytask,char *userfile);//写完了
#endif