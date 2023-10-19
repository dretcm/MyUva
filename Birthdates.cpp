#include<iostream>
using namespace std;
int main()
{
  int T,a,b,c;
  double i_max=0, i_min=3000,aux;
  string name_max, name_min, aux_name;
  cin>>T;
  
  while(T--){
    cin>>aux_name>>a>>b>>c;
    aux = c + b/100.0 + a/10000.0;
    if(aux>i_max){
      name_max = aux_name;
      i_max = aux;
    }
    if(aux<i_min){
      name_min = aux_name;
      i_min = aux;
    }
  }
  
  cout<<name_max<<endl<<name_min<<endl;

  return 0;
}
