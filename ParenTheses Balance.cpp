#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int T,i,j;
  vector<char> data;
  string input;
  scanf("%d\n",&T);
  while(T--){
    getline(cin,input);
    j=0;
    for(i=0;i<input.length();i++){
        if(j && (data[j-1]==input[i]-1 || data[j-1]==input[i]-2)){ // (==( or [==[
            data.pop_back();
            j--;
        }
        else{
            data.push_back(input[i]);
            j++;
        }
    }
    cout<< (j ? "No": "Yes")<<endl;
    data.clear();
  }
  return 0;
}
