#include <vector>
#include <iostream>
using namespace std;

struct matrix {
	vector<vector<int>> M;
	int R, C;
	void set(int r, int c) {
		R = r;
		C = c;
		M = vector<vector<int>>(R, vector<int>(C, 0)); //vector<type>(quantity, fill)
	}
	void print() {
		for (int i = 0;i < R; i++) {
			for (int j = 0;j < C;j++) {
			    if(j) cout<<" ";
				cout << M[i][j];
			}
			cout << endl;
		}
	}
	void input() {
		for (int i = 0;i < R; i++) {
			for (int j = 0;j < C;j++) {
				scanf("%d", &M[i][j]);
			}
		}
	}
	void move(vector<vector<int>>& aux, int hired, int focus, int i, int j) {
		if (i - 1 > -1 && M[i - 1][j] == focus) aux[i - 1][j] = hired;
		if (i + 1 < R && M[i + 1][j] == focus) aux[i + 1][j] = hired;
		if (j - 1 > -1 && M[i][j - 1] == focus) aux[i][j - 1] = hired;
		if (j + 1 < C && M[i][j + 1] == focus) aux[i][j + 1] = hired;
	}
	void battle(int n, int r, int c, int k) {
		set(r, c);
		input();
		vector<vector<int>> aux;
		n--;
		while (k--) {
			aux = M;
			for (int i = 0;i < R; i++) {
				for (int j = 0;j < C;j++) {
					if (M[i][j] == n) {
						move(aux, n, 0, i, j);
					}
					else {
						move(aux, M[i][j], M[i][j] + 1, i, j);
					}
				}
			}
			M = aux;
		}
	}
};

int main(){
	int N,R,C,K;
	matrix table;

	while (cin>>N>>R>>C>>K&&N) {
		table.battle(N,R,C,K);
		table.print();
	}
		
	return 0;
}
