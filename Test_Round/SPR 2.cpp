#include <iostream>

using namespace std;

int main() 
{
    int a;
    cin>>a;
    int pkt[a];
    string im[a];
    for(int i=0;i<a;i++){
        cin>>im[i]>>pkt[i];
    }
    for(int i=0;i<a;i++){
        if(pkt[i]%10==7) cout<<im[i]<<endl;
    }
    return 0;
}