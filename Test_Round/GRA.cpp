#include <iostream>
#include <math.h>

using namespace std;

int main() 
{
    int n,k;
    int los=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)<k) los++;
        }
    }
    cout.precision(16);
    cout<<((n*n)-los)/(n*n*1.0)<<endl;
    return 0;
}