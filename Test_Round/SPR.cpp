#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() 
{
    int a;
    cin>>a;
    string pkt[a];
    string im[a];
    for(int i=0;i<a;i++){
        cin>>im[i]>>pkt[i];
    }
    for(int i=0;i<a;i++){
        if(pkt[i][pkt[i].length()-1]=='7') cout<<im[i]<<endl;
    }
    return 0;
}