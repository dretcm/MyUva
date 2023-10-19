#include <list>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(){
	int t,T,N,M,i,j,k, n_list;
	string name, aux;
	vector<list<string>> list_names(5, list<string>());

	scanf("%d\n", &T);
	for (t=1;t <= T; t++) {
		map<string, pair<int, int>> passengers{ {"Ja",{0,0}}, {"Sam",{1,0}}, {"Sha",{2,0}}, {"Sid",{3,0}},{"Tan",{4,0}} };
		getline(cin, aux);
		istringstream iss(aux);
		iss >> M >> N >> name;
		for (i = 0;i < 5;i++) {
			scanf("%d ", &n_list);
			getline(cin, aux);
			istringstream iss(aux);
			for (j = 0;j < n_list;j++) {
				iss >> aux;
				list_names[i].push_back(aux);
			}
		}

		if (N >= M) {
			N -= M + 2;
			passengers[name].second += M;
			aux = list_names[passengers[name].first].front();
			list_names[passengers[name].first].push_back(aux);
			list_names[passengers[name].first].pop_front();
		}
		else {
			passengers[name].second += N;
			N = 0;
		}

		while(N>0) {
			if (N >= M) {
				N -= M + 2;
				passengers[aux].second += M;
			}
			else {
				passengers[aux].second += N>0 ? N : 0;
				break;
			}
			name = list_names[passengers[aux].first].front();
			list_names[passengers[aux].first].push_back(name);
			list_names[passengers[aux].first].pop_front();
			aux = name;
		}

		cout << "Case " << t <<":"<< endl;
		map<string, pair<int,int>>::iterator it = passengers.begin();
		while(it!=passengers.end()) {
			cout << it->first << " " << it->second.second << endl;
			it++;
		}
		list_names = vector<list<string>>(5, list<string>());
	}
		
	return 0;
}
