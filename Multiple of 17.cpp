#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    long long i, is, len;
    char n[1000000];
    while(scanf("%s",n) && n[0]!='0'){
        len = strlen(n);
        is = 0;
        for(i=0;i<len;i++)
            is = ((is*10) + (n[i]-'0')) % 17;
        cout<<(is==0)<<endl;
    }

    return 0;
}
