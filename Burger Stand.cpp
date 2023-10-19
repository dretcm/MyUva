#include <iostream>
using namespace std;

int main(){
	int T,i,con,c;
	string input;
	cin >> T;
    for (c=1;c<=T;c++) {
		con = 0;
		cin >> input;
		input = " " + input + "  ";
		for (i = 1;i < input.length()-2;i++) {
			if (input[i] == '-' && 
				input[i + 2] != 'B' && 
				input[i + 1] != 'B' && 
				input[i + 1] != 'S' && 
				input[i - 1] != 'S') {
				con++;
			}
		}
		cout <<"Case "<<c<<": "<<con << endl;
	}

	return 0;
}
