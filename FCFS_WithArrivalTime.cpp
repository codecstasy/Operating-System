#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "Enter the number of processes: ";
	int n;
	cin >> n;
	int bt[n+1], at[n+1];
	cout << endl;
	cout << "Enter the burst times: ";
	for(int i=1 ; i<=n ; i++)
		cin >> bt[i];
	cout << endl;
	cout << "Enter the arrival times: ";
	for(int i=1 ; i<=n ; i++)
		cin >> at[i];
	cout << endl;
	int wt[n+1], tt[n+1], cur = bt[1];
	wt[1] = at[1];
	tt[1] = bt[1];
	int ttsum = tt[1], wtsum = wt[1];
	for(int i=2 ; i<=n ; i++) {
		if(at[i] <= cur) {
			wt[i] = cur - at[i];
			cur += bt[i];
		}
		else {
			wt[i] = 0;
			cur = at[i] + bt[i];
		}
		tt[i] = bt[i] + wt[i];
		ttsum += tt[i];
		wtsum += wt[i];
		// cout << cur << endl;
	}
	printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
	for(int i=1 ; i<=n ; i++) {
		printf("%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\n",i,bt[i],at[i],wt[i],tt[i]); 
	}
	printf("Average Turnaround Time: %f\n", (double)ttsum/(double)n);
	printf("Average Waiting Time: %f", (double)wtsum/(double)n);
}