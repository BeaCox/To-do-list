<p align="center">
    <h1 align="center">To-do-list</h1>
</p>
  <p align="center">
    本地运行的任务管理系统
    <br />
    <br />
    <a href="https://github.com/BowenYoung/To-do-list/blob/main/requirements.md">作业目标</a>
    ·
    <a href="https://github.com/BowenYoung/To-do-list/releases">
    程序下载</a>
    ·
    <a href="https://github.com/BowenYoung/To-do-list/issues">报告Bug</a>
  </p>

<p align="center">
<img src="https://img.shields.io/github/license/pureink/inkrss?style=for-the-badge"/>  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
</p>
[TOC]

## 项目背景

2021-2022学年夏季学期，SJTU计算机编程实践课程NIS1336大作业要求：使用C++语言开发一个有用而且有趣的日程管理软件，以小组方式完成，每个小组不超过3人。我与[@cyChen2003](https://github.com/cyChen2003)、[@skywalker107](https://github.com/skywalker107)合作完成了该项目。

## 作业目标

[阅读更多](https://github.com/BowenYoung/To-do-list/blob/main/requirements.md)

## 运行环境
🎉绝大多数Linux发行版。

## 特点

🔒**md5加密** - 密码采用md5加密后保存在`[用户名].txt`文件中
<br />📢**多线程** - 任务提醒功能与其他功能采用不同线程，互不影响
<br />⚡**快捷调用** - 能够一次性执行多条命令，也可以快速调用命令行参数完成动作

## 使用方法

```bash
-r #运行程序
-a #添加任务
-sxxxx-xx #查看某月的任务
-sxxxx-xx-xx #查看某天的任务
-s #查看所有任务
-d<num> #删除id为num的任务
-h #查看帮助
```

其中`-r`方式以shell方式循环运行，等待用户输入命令。其他选项在验证登陆状态后，执行一条命令则结束。
创建用户并添加任务后，用户名、加密后的密码以及任务信息将保存在与用户名同名的txt文件中，请勿删除。

## TODO

- [x] 账户登录
- [x] 任务录入
- [x] 任务保存
- [x] 任务加载
- [x] 任务删除
- [x] 任务显示
- [x] 任务提醒
- [x] 命令行参数
- [x] 多线程检查任务
- [ ] 图形界面

## 作者

[@BowenYoung](https://github.com/BowenYoung)
<br />[@cyChen2003](https://github.com/cyChen2003)
<br />[@skywalker107](https://github.com/skywalker107)

(根据用户名首字母排序)

## 鸣谢

MD5加密代码来源[@foolsparadise](https://github.com/foolsparadise)

## 协议

[The MIT License](https://opensource.org/licenses/MIT)

