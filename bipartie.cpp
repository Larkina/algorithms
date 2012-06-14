#pragma comment(linker, "/STACK:300000000")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > g;
vector<int> vis, o;

void dfs(int t, int odevity){
	if (o[t] == -1)
		o[t] = odevity;
	else {
		if(o[t] != odevity){
			cout << "NO";
			exit(0);
		}
		return;
	}
	for(int i = 0; i < g[t].size(); ++i)
		dfs(g[t][i],  1 - o[t]);
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	g.resize(n);
	vis.resize(n);
	o.resize(n);
	for(int i = 0; i < n; ++i)
		o[i] = -1;
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	if(n == 1){
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < n; ++i)
		if (o[i] == -1)
			dfs(i, 0);
	cout << "BIPARTITE";
	fclose(stdin);
	fclose(stdout);
}