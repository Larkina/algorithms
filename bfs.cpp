#include <iostream>
#include <string>
#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n, m, s;
	vector<vector<int> > g;
	vector<bool> vis;
	cin >> n >> m >> s;
	g.resize(n);
	vis.resize(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	queue<int> q;
	vector<int> ans;
	q.push(s - 1);
	ans.push_back(s - 1);
	vis[s - 1] = true;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = 0; i < g[t].size(); ++i)
			if (!vis[g[t][i]]){
				vis[g[t][i]] = true;
				q.push(g[t][i]);
				ans.push_back(g[t][i]);
			}
	}
	for(int i = 0; i < n; ++i)
		if (!vis[i]){
		 cout << -1;
		 return 0;
		}
	for(int i = 0; i < n; ++i)
		cout << ans[i] + 1 << " ";
	fclose(stdin);
	fclose(stdout);
}