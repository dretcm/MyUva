#include <iostream>
using namespace std;

int main()
{
  int num;
  while(cin>>num&&num){
    int out[2]{0,0},con=1;
    bool band=false;
    while(num){
      if(num & 1){
        out[band] += con;
        band = !band;
      }
      con *= 2;
      num/=2;
    }
    cout<<out[0]<<" "<<out[1]<<endl;
  }
	return 0;
}
