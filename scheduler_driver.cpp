#include "scheduler.cpp"
using namespace std;
// This is the driver that creates and runs the task planner; 
//it also provides a simple UI in the terminal
int main(){
	queue<string> a;
	for(int i = 0; i < 3; ++i){
		a.push("this number is " + to_string(i));
	}
	scheduler sample;
	sample.queueVisualize(a);
}
