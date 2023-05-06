#include <bits/stdc++.h>
using namespace std;

struct Process {
	int processNo, burstTime, priority, waitingTime, turnaroundTime;
};

bool comp(Process p1, Process p2) {
	if(p1.priority == p2.priority)
		return p1.burstTime < p2.burstTime;
	return p1.priority < p2.priority;
}

int main() {
	int n;
	cin >> n;
	Process pc[n+1];
	for(int i=1 ; i<=n ; i++) {
		cin >> pc[i].burstTime;
		cin >> pc[i].priority;
		pc[i].processNo = i;
	}
	sort(pc+1, pc+n+1, comp);
	
	int cum[n+2], sum = 0; cum[0] = 0;
	for(int i=1 ; i<=n ; i++) {
		cum[i] = cum[i-1] + pc[i].burstTime;
		sum += cum[i];
	}

	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(int i=1 ; i<=n ; i++) {
		printf("%d\t\t%d\t\t\t%d\t\t\t\t%d\n",pc[i].processNo,pc[i].burstTime,cum[i-1],cum[i]);
	}
	printf("Average Turnaround Time: %f\n", (double)sum/(double)n);
	
	printf("Average Waiting Time: %f", (double)(sum-cum[n])/(double)n);
}