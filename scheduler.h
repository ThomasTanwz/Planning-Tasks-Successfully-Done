#include<stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<sys/stat.h>

using namespace std;

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

class scheduler{

private:
        queue<string> notDone;
        stack<string> done;
        char* taskFile;
        char* doneFile;
public:
	scheduler();
	void writeFile(string fileName, string task);
	void addTask(string newTask);
	void popTask();
	void remove_undone_task(char* fileName);
	//schedule visualization part
	void level_visualize(string target);
	void stack_visualize(stack<string> target);
	void queue_visualize(queue<string> target);
	void schedule_visualize(string choice);

};

#endif /*SCHEDULER_H_*/
