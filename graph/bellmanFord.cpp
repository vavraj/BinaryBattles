#include <iostream>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
  vector<int> distance(n + 1, 1e9);
  distance[src] = 0;
  
//   applying n-1 times the condition
  for (int i = 1; i < n; i++) {
      int flag=0;
    //   traversing all the edges
    for (int j = 0; j < m; j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int wt = edges[j][2];

      if (distance[u] != 1e9 && ((distance[u] + wt) < distance[v])) {
        distance[v] = distance[u] + wt;
        flag=1;
      }
    }
    // it means no update occurs that is there is no need of running the loop again
    if(flag==0)
    {
        return distance[dest];
    }
  }

  //    to check if there is any negative cycle present
  int flag = 0;
  for (int j = 0; j < m; j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int wt = edges[j][2];

    if (distance[u] != 1e9 && ((distance[u] + wt) < distance[v])) {
      flag = 1;
    }
  }

  return (flag == 0) ?  distance[dest] : -1;
}