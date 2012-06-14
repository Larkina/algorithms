#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 101;

class DSU {
	vector<int> parent, rang;
public:
	DSU(int n){
		parent.resize(n + 1, -1);
		rang.resize(n + 1, -1);
	}

	void make_set(int v){
		parent[v] = v;
		rang[v] = 0;
	}

	int find_parent(int v) {
		if (v == parent[v])
			return v;
		else
			return parent[v] = find_parent(parent[v]);
	}

	void union_sets (int a, int b) {
		a = find_parent (a);
		b = find_parent(b);
		if (a != b){
			if (rang[a] < rang[b])
				swap (a, b);
			parent[b] = a;
			if (rang[a] == rang[b])
				++rang[a];
		}
	}

};

struct edge{
	int u, v, w;
};

int comp(edge l, edge r){
	return l.w < r.w;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	DSU set(n);
	vector<edge> edges(m);
	used.resize(n + 1);
	for(int i = 1; i <= n; ++i){
		set.make_set(i);
	}
	for(int i = 0; i < m; ++i){
		edge t;
		cin >> t.u >> t.v >> t.w;
		edges[i] = t;
	}
	sort(edges.begin(), edges.end(), comp);
	int ans = 0;
	int count = 0;
	for(int i = 0; i < m; ++i){
		int l = edges[i].u, r = edges[i].v;
		if (set.find_parent(l) != set.find_parent(r)){
			set.union_sets(l, r);
			ans += edges[i].w;
			count++;
		}
	}
	if (count < n - 1)
		cout << -1;
	else
		cout << ans;
}
