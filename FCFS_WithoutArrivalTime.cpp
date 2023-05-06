#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("\n");
	int bt[n+1], cum[n+1], sum = 0;
	bt[0] = 0, cum[0] = 0;
	for(int i=1 ; i<=n ; i++) {
		scanf("%d", &bt[i]);
		cum[i] = cum[i-1] + bt[i];
		sum += cum[i];
	}
	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(int i=1 ; i<=n ; i++) {
		printf("%d\t\t%d\t\t\t%d\t\t\t\t%d\n",i,bt[i],cum[i-1],cum[i]);
	}
	printf("Average Turnaround Time: %f\n", (double)sum/(double)n);
	sum -= cum[n];
	printf("Average Waiting Time: %f", (double)sum/(double)n);
}