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
        friend void delTask(task *myTask, int deleteId);
        friend void reminder(task t);
        friend void showTaskByDay(task *myTask,int year, int month, int day);
        friend void showTaskByMonth(task *myTask,int year, int month);
        friend void showTaskAll(task *myTask);
    private:
        int id;
        char name[20];
        timeT start;
        char classify[20];
        int priority;
        timeT timerReminder;
    public: 
        static int taskNum;
        static int taskLive;
        task();
        void display();
        void setTask();


    };

void delTask(task *myTask);//删除任务

void reminder(task t);//提醒任务

void showTaskByDay(task *myTask,int year, int month, int day);//按天显示任务
void showTaskByMonth(task *myTask,int year, int month);//按月显示任务
void showTaskAll(task *myTask);//显示所有任务
#endif