#pragma comment(linker, "/STACK:64000000")
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 100001, MAXM = MAXN;
 
int n, m;
vector <vector <int> > g;
bool vis[MAXN], isCutPoint[MAXN];
int ent[MAXN], ret[MAXN];
int timer = 0;
 
void dfs(int v, int parent = -1) {
    vis[v] = true;
    ent[v] = ret[v] = timer++;
    int child = 0;
 
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == parent) continue;
        if (vis[to])
            ret[v] = min(ret[v], ent[to]);
        else {
            dfs(to, v); 
            ret[v] = min(ret[v], ret[to]);
            if (ret[to] >= ent[v] && parent != -1) {
                isCutPoint[v] = true;   
            }
            ++child;
        }
        if (parent == -1 && child > 1) isCutPoint[v] = true;
    }   
}
 
 
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);  
    }
 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++) 
		ans += isCutPoint[i];
    cout << ans << " ";
    for (int i = 0; i < n; i++) 
		if (isCutPoint[i]) 
			printf("%d ", i + 1);

}