#include <bits/stdc++.h>
using namespace std;

struct Process {
	int id, burstTime, arrivalTime, remainingTime;
};

bool comp(Process p1, Process p2) {
	if(p1.arrivalTime == p2.arrivalTime)
		return p1.burstTime < p2.burstTime;
	return p1.arrivalTime < p2.arrivalTime;
}

int main() {
	std::vector<Process> pc {
		{1, 6, 0, 0},
        {2, 8, 1, 0},
        {3, 7, 2, 0},
        {4, 3, 3, 0},
        {5, 4, 4, 0}
	};
	sort(pc.begin(), pc.end(), comp);

	int time = 0, completionTime = 0;
	vector <int> executionOrder;

	while(!pc.empty()) {
		int shortestProcessIndex = -1;
		int shortestRemainingTime = INT_MAX;
		for(int i=0 ; i<pc.size() ; i++) {
			if(pc[i].arrivalTime <= time && pc[i].remainingTime < shortestRemainingTime) {
				shortestProcessIndex = i;
				shortestRemainingTime = pc[i].remainingTime;
			}
		}

		if(shortestProcessIndex == -1) {
			time++;
			continue;
		}

		pc[shortestProcessIndex].remainingTime--;
		time++;

		if(pc[shortestProcessIndex].remainingTime == 0) {
			completionTime += time - pc[shortestProcessIndex].arrivalTime;
			executionOrder.push_back(pc[shortestProcessIndex].id);
			pc.erase(pc.begin() + shortestProcessIndex);
		}
	}

	double averageTurnaroundTime = (double)completionTime / executionOrder.size();
	cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
	cout << "Execution Order: ";
	for(int i : executionOrder) {
		cout << i << " ";
	}
	cout << endl;
}