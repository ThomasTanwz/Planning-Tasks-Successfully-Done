#include<stdio.h>
#include<iostream>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

class scheduler{
private:
	queue<string> notDone;
	stack<string> done;
	char* taskFile = "./NotDone.txt";
	char* doneFile = "./Done.txt";
public:

	void writeFile(string filename, string task){
		ofstream manager;
		manager.open(filename);
		manager<<task;
		manager.close();
	}

	void addTask(string newTask){
		notDone.push(newTask);
		writeFile(taskFile, newTask);
	}

	void popTask(){
		string finishedTask = notDone.front();
		notDone.pop();
		writeFile(doneFile, finishedTask);
		remove_undone_task(taskFile);
	}

	//this function removes the last task line(aka the queue's front) in the text file
	void remove_undone_task(char* fileName){
		size_t targetNum = notDone.size();
		ifstream targetFile(fileName);
		ofstream doneFile;
		doneFile.open("temp.txt", ofstream::out);
		char c;
		int line_num = 0;
		while(targetFile.get(c)){
			if(c == '\n')
				line_num ++;
			if(line_num != targetNum)
				doneFile << c;
		}
		doneFile.close();
		targetFile.close();
		remove(fileName);
		rename("temp.txt", fileName);
	}

	void level_visualize(string target){
		size_t wrapper_length = target.length() + 4;
		for(int i = 0; i < wrapper_length; ++i)
			cout<<"*";
		cout << endl;
		cout << "* ";
		cout <<target;
		cout <<" *"<<endl;
		for(int i = 0; i < wrapper_length; ++i)
			cout<<"*";
		cout<<endl;
	}

	void scheduleVisualizer(string choice){
		if(choice == "done"){
			stackVisualize(done);
		} else if(choice == "todo"){
			queueVisualize(notDone);
		}
	}

	void stackVisualize(stack<string> target){
		while(!target.empty()){
			string curTask = target.top();
			level_visualize(curTask);
			target.pop();
		}
	}

	void queueVisualize(queue<string> target){
		while(!target.empty()){
			string curTask = target.front();
			level_visualize(curTask);
			target.pop();
		}
	}

};
