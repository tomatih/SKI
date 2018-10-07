#include<iostream>
using namespace std;

int main(){
    int a,b,c,r;

    cin>>a>>b>>c;
    r = a - b;
    for(int i=r; i<=a){
        r *= ++i;
    }
    r %= c;
    cout<<r<<endl;

    return 0;
}