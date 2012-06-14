#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
  
#define inf 2128506
#define maxn 100001
 
struct Edge{
   int v, u;
};
 
using namespace std;
unsigned long d[maxn];
bool vis[maxn];
vector<Edge> e[maxn];
 
class comp
{
public:
    comp(){};
    bool operator() (const int& l, const int& r) const {
        return (d[l] > d[r]);
    }
};
 
int main(){
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout);
   int n, m, s;
   priority_queue<int, vector<int>, comp> q;
   scanf("%d %d %d", &n, &m, &s);
   for(int i = 0; i < n + 1; ++i){
      d[i] = inf;
      vis[i] = false;
   }
   for(int i = 0; i < m; ++i){
      int v1, v2, u;
      Edge x;
      scanf("%d %d %d", &v1, &v2, &u);
      x.u = u;
      x.v = v2;
      e[v1].push_back(x);
   }
   int curr = s;
   d[s] = 0;
   q.push(s);
   while(!q.empty()){
      vis[curr] = true;
      curr = q.top();     
      q.pop();
      for(int i = 0; i < e[curr].size(); ++i)
         if(!vis[e[curr][i].v] && d[e[curr][i].v] > e[curr][i].u + d[curr]){
            d[e[curr][i].v] = e[curr][i].u + d[curr];
            q.push(e[curr][i].v); 
         }
   }   
   for(int i = 1; i < n + 1; i++)
      printf("%d ", d[i] >= inf? -1: d[i]);
}