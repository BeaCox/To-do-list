#!/bin/bash
echo "请勿删除当前目录下的input文件夹和todo文件，并确保没有user1.txt文件"
echo "本脚本调用命令行参数完成的任务："
echo "创建并使用一个用户名为user1，密码为qwe123的用户"
echo "创建4个任务，其中只有task2指定分类为娱乐、指定优先级为4，其余为默认分类（学习）以及默认优先级3"
echo "创建一个任务show一次"
echo "删除id为3的任务（task3）"
echo "展示全部任务"
echo "展示2022年7月的任务"
echo "展示2022年7月14日的任务"
echo "退出程序"
echo "----------start test----------"
./todo -r < ./input/register.txt
./todo -a < ./input/addtask1.txt
./todo -s < ./input/login.txt >> ./output/output.txt
./todo -a < ./input/addtask2.txt
./todo -s < ./input/login.txt >> ./output/output.txt
./todo -a < ./input/addtask3.txt
./todo -s < ./input/login.txt >> ./output/output.txt
./todo -a < ./input/addtask4.txt
./todo -s < ./input/login.txt >> ./output/output.txt
./todo -d3 < ./input/login.txt
./todo -s < ./input/login.txt >> ./output/output.txt
./todo -s2022-07 < ./input/login.txt >> ./output/output.txt
./todo -s2022-07-14 < ./input/login.txt >> ./output/output.txt
echo "----------end test----------"
echo "请在./output/output.txt中查看输出"
