#pragma comment(linker, "/STACK:300000000")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, s;
vector<vector<int> > g;
vector<int> vis, ans;

void dfs(int t){
	if (vis[t] == 1){
		cout << -1;
		exit(0);
	}
	if (vis[t] == 2)
		return;
	vis[t] = 1;
	for(int i = 0; i < g[t].size(); ++i)
		dfs(g[t][i]);
	vis[t] = 2;
	ans.push_back(t);
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	g.resize(n);
	vis.resize(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
	}
	for(int i = 0; i < n; ++i)
		dfs(i);
	for(int i = 0; i < n; ++i)
		cout << ans[n - i - 1] + 1 << " ";
	fclose(stdin);
	fclose(stdout);
}