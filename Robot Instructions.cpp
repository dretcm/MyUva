#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {
	int T, n, pos, index, i, j;
	string inst, aux;
	vector<string> instructions;
	vector<int> positions;
	cin >> T;
	for (i = 0;i < T; i++) {
		cin >> n;
		cin.ignore();
		pos = 0;
		instructions.clear();
		for (j=0;j<n;j++) {
			getline(cin, inst);
			if (inst[0] == 'S') {
				istringstream iss(inst);
				iss >> aux >> aux >> index;
				inst = instructions[index - 1];
			}
			instructions.push_back(inst);
			if (inst == "LEFT")
				pos--;
			else if (inst == "RIGHT")
				pos++;
		}
		positions.push_back(pos);
	}

	for (i = 0;i < T;i++) {
		cout << positions[i] << endl;
	}
}
