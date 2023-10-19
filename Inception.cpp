#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
  int T,i,j;
  vector<string> data;
  string input,aux;
  scanf("%d\n",&T);
  while(T--){
    getline(cin, input);
    if(input[0]=='S'){
      istringstream iss(input);
      iss>>aux>>aux;
      data.push_back(aux);
    }
    else if(input[0]=='K' && !data.empty()){
      data.pop_back();
    }
    else if(input[0]=='T'){
      cout<<(data.empty() ? "Not in a dream" : data.back())<<endl;
    }
  }
  return 0;
}
