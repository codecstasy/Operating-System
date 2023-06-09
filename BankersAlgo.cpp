#include <bits/stdc++.h>
using namespace std;

int main() {
	cout << "Enter the number of processes and resources: ";
	int n, m;
	cin >> n >> m;
	cout << endl;
	cout << "Enter the number of instances per resource: ";
	int instances[m+1], occupied[m+1];
	for(int i=1 ; i<=m ; i++) {
		cin >> instances[i];
		occupied[i] = 0;
	}
	cout << endl;

	int allocation[n+1][m+1], maxNeed[n+1][m+1], remainingNeed[n+1][m+1];
	int available[m+1];

	for(int i=1 ; i<=n ; i++) {
		for(int j=1 ; j<=m ; j++) {
			cin >> allocation[i][j];
			occupied[j] += allocation[i][j];
		}
	}

	for(int i=1 ; i<=n ; i++) {
		for(int j=1 ; j<=m ; j++) {
			cin >> maxNeed[i][j];
			remainingNeed[i][j] = maxNeed[i][j] - allocation[i][j];
		}
	}

	for(int i=1 ; i<=m ; i++) available[i] = instances[i] - occupied[i];

	std::vector<int> sequence;
	bool ended[n+1] = {false};
	int endCnt = 0;
	while(endCnt < n) {
		bool bigflag = 0;
		for(int i=1 ; i<=n ; i++) {
			if(ended[i] == true) continue;
			bool flag = 0;
			for(int j=1 ; j<=m ; j++) {
				if(remainingNeed[i][j] > available[j]) {
					flag = 1;
					break;
				}
			}
			if(flag == 0) {
				bigflag = 1;
				for(int j=1 ; j<=m ; j++)
					available[j] += allocation[i][j];
				ended[i] = true;
				endCnt++;
				sequence.push_back(i);
				continue;
			}
		}
		if(bigflag == 0) {
			cout << "Deadlock" << endl;
			return 0;
		}
	}
	cout << "Safe Sequence: " << endl;
	for(int i=0 ; i<sequence.size() ; i++)
		cout << sequence[i] << " ";
}