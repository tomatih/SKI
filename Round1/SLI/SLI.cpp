#include <iostream>

int main() 
{
    long int a,b,c,Fa=1,Fb=1;;
    std::cin>>a>>b>>c;
    for(int i=1;i<=a;i++) Fa*=i;
    for(int i=1;i<=b;i++) Fb*=i;
    std::cout<<(Fa/Fb)%c<<std::endl;
    return 0;
}