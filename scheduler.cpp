#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#include<bits/stc++.h>
using namespace std;

class scheduler{
private:
	queue<string> notDone;
	stack<string> done;
	string taskFile = "./NotDone.txt";
	string doneFile = "./Done.txt";
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
	void remove_undone_task(string fileName){
		size_t targetNum = notDone.size();
		ifstream targetFile(fileName);
		ofstream doneFile;
		doneFile.open("temp.txt", ofstream::out);
		char c;
		int line_num = 0;
		while(targetFile.get(c)){
			if(c == '\n')
				line_number ++;
			if(line_number != targetNum)
				doneFile << c;
		}
		doneFile.close();
		targetFile.close();
		remove(fileName);
		rename("temp.txt", file_name);
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
			
		} else if(choice == "todo"){
		
		}
	}

};
