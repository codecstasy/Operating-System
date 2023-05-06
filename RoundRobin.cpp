#include <bits/stdc++.h>
using namespace std;

struct Process{
	int processNo, burstTime, remainingTime, waitingTime, turnaroundTime;
};

int main() {
	int n;
	cin >> n;
	vector <Process> pc(n+1);
	for(int i=1 ; i<=n ; i++) {
		int x;
		cin >> x;
		pc[i].processNo = i;
		pc[i].burstTime = x;
		pc[i].remainingTime = x;
	}
	
	cout << "Enter time quanta size: ";
	int quanta;
	cin >> quanta;
	cout << endl;

	int time = 0, endCnt = 0;
	vector <int> completionSequence;

	for(int i=1 ; ; i++) {
		if(endCnt == n) break;
		if(i == n+1) i = 1;
		
		if(pc[i].remainingTime == 0) continue;
		if(pc[i].remainingTime <= quanta) {
			time += pc[i].remainingTime;
			pc[i].remainingTime = 0;
			completionSequence.push_back(i);
			pc[i].waitingTime = time - pc[i].burstTime;
			pc[i].turnaroundTime = time;
			endCnt++;
		}
		else {
			time += quanta;
			pc[i].remainingTime -= quanta;
		}
	}

	int wtSum = 0, ttSum = 0;
	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(int i=1 ; i<=n ; i++) {
		wtSum += pc[i].waitingTime;
		ttSum += pc[i].turnaroundTime;
		printf("%d\t\t%d\t\t\t%d\t\t\t\t%d\n", pc[i].processNo, pc[i].burstTime, pc[i].waitingTime, pc[i].turnaroundTime);
	}
	printf("Average Turnaround Time: %f\n", (double)ttSum/(double)n);
	
	printf("Average Waiting Time: %f\n", (double)wtSum/(double)n);

	cout << "Completion Sequence: ";
	for(int i=0 ; i<completionSequence.size() ; i++)
		cout << completionSequence[i] << " ";
}