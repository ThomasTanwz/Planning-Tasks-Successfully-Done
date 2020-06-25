#include "scheduler.cpp"
using namespace std;
// This is the driver that creates and runs the task planner;
//it also provides a simple UI in the terminal

void process_input(scheduler& tmp){
	int user_input;
	cout << "enter task number: ";
	cin >> user_input;
	while(user_input != 1 && user_input != 2 && user_input != 3 && user_input != 4){
		cout<<"invald option, please enter numbers between 1-4. Enter 0 to quit\n";
		cin >> user_input;
		if(user_input == 0)
			return;
	}

	if(user_input == 1){
		string newTask;
		cout << "enter task: ";
		cin >> newTask;
		tmp.addTask(newTask);
	}

	if(user_input == 2){
		tmp.schedule_visualize("todo");
	}

	if(user_input == 3){
		tmp.schedule_visualize("done");
	}

	if(user_input == 4){
		tmp.popTask();
	}
}

int main(){
	scheduler instance;
	cout << "Welcome to Planning Things Successfully Done, your workspace assistant\n";
	cout << "menu: \n";
	cout << "1. add tasks to your current task queue \n";
	cout << "2. show your current task list\n";
	cout << "3. show tasks you have finished\n";
	cout << "4. finish your current task\n";
	process_input(instance);
}

