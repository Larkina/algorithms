#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1001;

int g[MAX_N][MAX_N];
bool used[MAX_N];
int w[MAX_N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
    for(int i = 1; i <= n; ++i)
		for(int j= 1 ; j <= n; ++j)
			g[i][j] = -1;
	for(int i = 0; i < m; ++i){
        int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
    }
	for(int i = 1; i <= n; ++i)
		w[i] = g[1][i];
	used[1] = true;
	int count = 0, ans = 0;
	while (count < n - 1){
		int idx = 0;
		for(int i = 1; i <= n; ++i)
			if (!used[i] && w[i] != -1 && (idx == 0 || w[idx] > w[i]))
				idx = i;
		if (idx == 0)
			break;
		used[idx] = true;
		count++;
		ans += w[idx];
		for(int i = 1; i <= n; ++i)
			if (!used[i] && g[idx][i] != -1 && (w[i] == -1 || w[i] > g[idx][i]))
				w[i] = g[idx][i];
	}
	cout << (count < n -  1 ? -1 : ans);
}
