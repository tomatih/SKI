#include <iostream>

int main() 
{
    long int a,b,c,Fa=1;;
    std::cin>>a>>b>>c;
    for(int i=a;i>b;i--) Fa*=i;
    std::cout<<Fa%c<<std::endl;
    return 0;
}