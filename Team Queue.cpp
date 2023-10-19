#include <queue>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int teams[10000000];

int main(){
	int t=1,T,N,n,i,j;
	string name, aux;

	while(cin>>T&&T) {
		cin.ignore();
		vector<queue<int>> team(T, queue<int>());
    queue<int> out;

		for (i = 0;i < T;i++) {
			getline(cin, aux);
			istringstream iss(aux);
			iss >> N;
			for (j = 0;j < N;j++) {
				iss >> n;
				teams[n] = i;
			}
		}
		cout << "Scenario #" << t++ << endl;
		while (1) {
			getline(cin, aux);
			if (aux[0] == 'E') {
				istringstream iss(aux);
				iss >> aux >> n;
				if (team[teams[n]].empty())
					out.push(teams[n]);
        team[teams[n]].push(n);
			}
			else if (aux[0] == 'D' && !out.empty()) {
        cout << team[out.front()].front() << endl;
        team[out.front()].pop();
        if (team[out.front()].empty())
          out.pop();
			}
			else if (aux[0] == 'S')
				break;
		}
		printf("\n");
	}
		
	return 0;
}
