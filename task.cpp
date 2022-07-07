#include "task.h"
    char defaultName[20]="学习C++";
    char defaultClassify[20]="学习";
    int LIST_SIZE=100;
    timeT::timeT(int y,int M,int d,int h,int m){
        year=y;
        month=M;
        day=d;
        hour=h;
        minute=m;
    }


    int task::taskNum=0;
    int task::taskLive=0;

    task::task()
    :start(2022,1,1,0,0),timerReminder(2022,1,1,0,0)
    {
    this->id=0;
    int i = 0;
	for (; name[i] != '\0'; ++i) {
		this->name[i] = name[i];
	}
	this->name[i] = '\0';
    i = 0;
	for (; classify[i] != '\0'; ++i) {
		this->classify[i] = classify[i];
	}
    this->priority=3;
    }

    void task::display(){
        cout << "任务id: " << id << endl;
        cout << "任务名称: " << name << endl;
        cout << "任务开始时间: " << start.year << "-" << start.month << "-" << start.day << " " << start.hour << ":" << start.minute << endl;
        cout << "任务分类: " << classify << endl;
        cout << "任务优先级: " << priority << endl;
        cout << "任务提醒时间: " << timerReminder.year << "-" << timerReminder.month << "-" << timerReminder.day << " " << timerReminder.hour << ":" << timerReminder.minute << endl << endl;
    }


    void task::setTask(int id=0,char *name=defaultName,int sYear=2022,int sMonth=1,int sDay=1,int sHour=0,int sMinute=0,int rYear=2022,int rMonth=1,int rDay=1,int rHour=0,int rMinute=0,char *classify=defaultClassify,int priority=1)
    {
    this->id=id;//！！！！！！！！！！随机分配id应该写在这里！！！！！！！！！！！
    int i = 0;
	for (; name[i] != '\0'; ++i) {
		this->name[i] = name[i];
	}
	this->name[i] = '\0';
    this->start=start;
    i = 0;
	for (; classify[i] != '\0'; ++i) {
		this->classify[i] = classify[i];
	}
    this->classify[i] = '\0';
    this->priority=priority;
    this->timerReminder=timerReminder;
    this->start.year=sYear;
    this->start.month=sMonth;
    this->start.day=sDay;
    this->start.hour=sHour;
    this->start.minute=sMinute;
    this->timerReminder.year=rYear;
    this->timerReminder.month=rMonth;
    this->timerReminder.day=rDay;
    this->timerReminder.hour=rHour;
    this->timerReminder.minute=rMinute;
    taskNum++;
    taskLive++;
    }

void delTask(task *myTask){
    int deleteId;
    cout << "请输入你要删除的任务对应的id: ";
    cin >> deleteId;
    if(deleteId <=0 ){
        cout << "任务id不存在!" << endl;
    }
    int i=0;
    for(;i<LIST_SIZE;i++){
        if(myTask[i].id==deleteId) break;
    }
    if(i==LIST_SIZE){
        cout<<"任务id不存在!"<<endl;
        return;
    }
    for(int j=i;j<LIST_SIZE-1;j++){
        myTask[j]=myTask[j+1];
    }
    task::taskLive--;
    cout<<"此任务已删除!"<<endl;
    return;
}//删除任务

    void reminder(task t){
	time_t timep;
	struct tm *nowTime;
	time(&timep); //获取从1970至今过了多少秒，存入time_t类型的timep
	nowTime = localtime(&timep);//用localtime将秒数转化为struct tm结构体
        if ((nowTime->tm_year+1900) == t.timerReminder.year && (1 + nowTime->tm_mon) == t.timerReminder.month && nowTime->tm_mday == t.timerReminder.day && nowTime->tm_hour == t.timerReminder.hour && nowTime->tm_min == t.timerReminder.minute){
            cout << "现在" << t.timerReminder.hour <<"时" << t.timerReminder.minute << "分," << "您在" << t.start.hour <<"时" << t.start.minute << "分有任务：" << t.name << endl;
            
        }
        else 
            return;
    };//提醒任务


    void showTaskByDay(task *myTask,int year, int month, int day){
        int loc[LIST_SIZE]={-1};//用来记录每个任务的位置
        int num=0;//用来记录任务的个数
        for(int i=0;i<LIST_SIZE && myTask[i].id!=0;i++){
            if(myTask[i].start.year==year&&myTask[i].start.month==month&&myTask[i].start.day==day){
                loc[num]=i;
                num++;
            }
        }//查找day匹配的Task并记录其下标，存储于loc数组

        bool flag;//记录起泡中是否发生交换
        int i,j,temp;
        for( i=0;i<num;i++){
            flag=false;
            for( j=0;j<num-i;j++){
                if((myTask[loc[j+1]].start.hour < myTask[loc[j]].start.hour) || (myTask[loc[j+1]].start.hour == myTask[loc[j]].start.hour && myTask[loc[j+1]].start.minute < myTask[loc[j]].start.minute)){
                    temp=loc[j];
                    loc[j]=loc[j+1];
                    loc[j+1]=temp;
                    flag=true;
                }
            }
            if(!flag) break;
        }//按照时间冒泡排序

        for (i=0; i<num; i++){
            myTask[loc[i]].display();
        }
    }//显示某一天的任务



        void showTaskByMonth(task *myTask,int year, int month){
        int loc[LIST_SIZE]={-1};//用来记录每个任务的位置
        int num=0;//用来记录任务的个数
        for(int i=0;i<LIST_SIZE && myTask[i].id!=0;i++){
            if(myTask[i].start.year==year&&myTask[i].start.month==month){
                loc[num]=i;
                num++;
            }
        }//查找month匹配的Task并记录其下标，存储于loc数组

        bool flag;//记录起泡中是否发生交换
        int i,j,temp;
        for( i=0;i<num;i++){
            flag=false;
            for( j=0;j<num-i;j++){
                if((myTask[loc[j+1]].start.day<myTask[loc[j]].start.day) || (myTask[loc[j+1]].start.day=myTask[loc[j]].start.day&&myTask[loc[j+1]].start.hour < myTask[loc[j]].start.hour) || (myTask[loc[j+1]].start.day=myTask[loc[j]].start.day && myTask[loc[j+1]].start.hour == myTask[loc[j]].start.hour && myTask[loc[j+1]].start.minute < myTask[loc[j]].start.minute)){
                    temp=loc[j];
                    loc[j]=loc[j+1];
                    loc[j+1]=temp;
                    flag=true;
                }
            }
            if(!flag) break;
        }//按照时间冒泡排序

        for (i=0; i<num; i++){
            myTask[loc[i]].display();
        }
    }//显示某一月的任务