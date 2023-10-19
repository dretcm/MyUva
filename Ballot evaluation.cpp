#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
  int p,g,i,j;
  int percentage,n;
  unordered_map<string,int> partys;
  unordered_map<string, bool(*)(int,int)> operations;
  operations[">"] = [](int a, int b){ return a>b;};
  operations["<"] = [](int a, int b){ return a<b;};
  operations[">="] = [](int a, int b){ return a>=b;};
  operations["<="] = [](int a, int b){ return a<=b;};
  operations["="] = [](int a, int b){ return a==b;};

  string input,aux;
  scanf("%d %d\n",&p,&g);
  while(p--){
    cin>>aux;cin.ignore();
    scanf("%d.%d\n",&percentage,&n);
    partys[aux] = percentage*10+n;
  }
  for(i=1;i<=g;i++){
    getline(cin, input);
    istringstream iss(input);
    percentage = 0;
    while(iss){
      iss>>aux;
      if (aux==">" || aux=="<" || aux==">=" || aux=="<=" || aux=="=")
        break;
      if(aux!="+")
        percentage += partys[aux];
    }
    iss>>n;
    cout<<"Guess #"<<i<<(operations[aux](percentage, n*10)?" was correct.":" was incorrect.")<<endl;
  }

  return 0;
}
