#include <iostream>
#include <limits>
#include <vector>
#include<algorithm>

using namespace std;

struct path{
    int start;
    int destination;
    int weight;
    std::vector<int> through;
};

struct Node{
    int index;
    std::vector<int> paths;//indexes in dr
};


int main() 
{
    //prepare input
    int ldm,ldr;
    cin>>ldm>>ldr;
    Node dm[ldm+1];
    for (int i = 1; i <= ldm; ++i) dm[i].index=i; 
    //old int array scheme [startNode,StopNode,weight/lenght]
    path dr[ldr+1];
    int a,b,c;
    for(int i=1;i<=ldr;i++){
        cin>>a>>b>>c;
        dr[i].start=a;
        dr[i].destination=b;
        dr[i].weight=c;
        dm[a].paths.push_back(i);
        dm[b].paths.push_back(i);

    }

    for (int i = 1; i <= ldr; ++i)
    {
        cout<<dr[dm[i].paths[0]].start<<endl;
    }
}

/*
//https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Algorithm
path shortest(int start, int stop, int nodes, path paths, int ldm){
    int unvisited=nodes;
    int distances[ldm];
    for (int i = 0; i < ldm; ++i)
    {
        if(i==start) distances[i]=0;
        else distances[i]= numeric_limits<int>::max();
    }
    int current_node = start;

}*/