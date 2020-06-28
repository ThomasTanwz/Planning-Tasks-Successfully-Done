#include"scheduler.h"
using namespace std;

scheduler::scheduler(): taskFile("./database/TO-DO.txt"), doneFile("./database/finished.txt"){
	if(mkdir("database", 0777) != -1){
		cout<<"creating database..."<<endl;
		ofstream outfile0(taskFile);
		ofstream outfile1(doneFile);
	}else{
		cout<<"existing database detected, welcome back!"<<endl;
	}
}

void scheduler::writeFile(string filename, string task){
	ofstream manager;
	manager.open(filename);
	manager<<task;
	manager.close();
}

void scheduler::addTask(string newTask){
	notDone.push(newTask);
	writeFile(taskFile, newTask);
}

void scheduler::popTask(){
	string finishedTask = notDone.front();
	notDone.pop();
	writeFile(doneFile, finishedTask);
	remove_undone_task(taskFile);
}

void scheduler::remove_undone_task(char* fileName){
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

//visualizing part
void scheduler::level_visualize(string target){
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

void scheduler::stack_visualize(stack<string> target){
        while(!target.empty()){
                string curTask = target.top();
                level_visualize(curTask);
                target.pop();
        }
}

void scheduler::queue_visualize(queue<string> target){
        while(!target.empty()){
                string curTask = target.front();
                level_visualize(curTask);
                target.pop();
        }
}


void scheduler::schedule_visualize(string choice){
        if(choice == "done"){
                stack_visualize(done);
        } else if(choice == "todo"){
                queue_visualize(notDone);
        }
}

