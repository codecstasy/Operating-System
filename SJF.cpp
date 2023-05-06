#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int processNo, burstTime, WaitTime;
}process;

bool comp(process p1, process p2) {
	return p1.burstTime < p2.burstTime;
}

void printSchedule(int cum[], process pc[], int n, int sum) {
	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(int i=1 ; i<=n ; i++) {
		printf("%d\t\t%d\t\t\t%d\t\t\t\t%d\n",pc[i].processNo,pc[i].burstTime,cum[i-1],cum[i]);
	}
	printf("Average Turnaround Time: %f\n", (double)sum/(double)n);
	
	printf("Average Waiting Time: %f", (double)(sum-cum[n])/(double)n);
}

int main() {
	int n;
	cin >> n;
	process pc[n+1];
	for(int i=1 ; i<=n ; i++) {
		cin >> pc[i].burstTime;
		pc[i].processNo = i;
	}
	sort(pc+1, pc+n+1, comp);
	int cum[n+2], sum = 0;
	cum[0] = 0;
	for(int i=1 ; i<=n ; i++) {
		cum[i] = cum[i-1] + pc[i].burstTime;
		sum += cum[i];
	}
	printSchedule(cum, pc, n, sum);
}