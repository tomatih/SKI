#include <stdio.h> 
#include <limits.h>
#include <list>
#include <string>
#include <iostream>


// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[], int V) 
{ 
    int min = INT_MAX, min_index; 
   
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
    return min_index; 
} 
   
 
int printSolution(std::list<int> dist[], int n) 
{
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; i++){
        std::string k;
        for(int m:dist[i]){
            k+=std::to_string(m);
            k+=" ";
        }
        printf("%d \t\t ", i);
        std::cout<<k<<std::endl;
    } 
} 
   
 
int main() 
{ 
    int V=9;

    int graph[V][V][2]={{{0,0}, {4,1}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {8,2}, {0,0}}, 
                        {{4,1}, {0,0}, {8,3}, {0,0}, {0,0}, {0,0}, {0,0},{11,4}, {0,0}}, 
                        {{0,0}, {8,3}, {0,0}, {7,5}, {0,0}, {4,6}, {0,0}, {0,0}, {2,7}}, 
                        {{0,0}, {0,0}, {7,5}, {0,0}, {9,8},{14,9}, {0,0}, {0,0}, {0,0}}, 
                        {{0,0}, {0,0}, {0,0}, {9,8}, {0,0},{10,10},{0,0}, {0,0}, {0,0}}, 
                        {{0,0}, {0,0}, {4,6},{14,9},{10,10},{0,0},{2,11}, {0,0}, {0,0}}, 
                        {{0,0}, {0,0}, {0,0}, {0,0}, {0,0},{2,11}, {0,0},{1,12},{6,13}}, 
                        {{8,2},{11,4}, {0,0}, {0,0}, {0,0}, {0,0},{1,12}, {0,0},{7,14}}, 
                        {{0,0}, {0,0}, {2,7}, {0,0}, {0,0}, {0,0},{6,13},{7,14}, {0,0}} 
                        }; 
   
    //dijkstra(graph, 0);
    int src=0; 

    int dist[V];     // The output array.  dist[i] will hold the shortest 
                      // distance from src to i
    std::list<int> dist2[V];
    dist2[0] ={0};
   
    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest 
                     // path tree or shortest distance from src to i is finalized 
   
     // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     
    dist[src] = 0; 
   
     // Find shortest path for all vertices 
    for (int count = 0; count < V-1; count++) 
    { 
       // Pick the minimum distance vertex from the set of vertices not 
       // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet, V); 
   
       // Mark the picked vertex as processed 
        sptSet[u] = true; 
   
       // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
   
            // Update dist[v] only if is not in sptSet, there is an edge from  
            // u to v, and total weight of path from src to  v through u is  
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v][0] && dist[u] != INT_MAX && dist[u]+graph[u][v][0] < dist[v]){
                dist[v] = dist[u] + graph[u][v][0];
                dist2[v].push_back(graph[u][v][1]);
                } 
    } 

    printSolution(dist2, V); 
    return 0; 
} 
