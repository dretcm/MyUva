#include <iostream>
using namespace std;
int main()
{
  int T,L,W,H,i;
  while(cin>>T&&T){
    int max_V = -1,max_H=-1;

    for(i=0;i<T;i++){
      cin>>L>>W>>H;
      if(H>max_H || (H==max_H && L*W*H>max_V)){
        max_H = H;
        max_V = L*W*H;
      }
    }
    cout<<max_V<<endl;
  }

  return 0;
}
