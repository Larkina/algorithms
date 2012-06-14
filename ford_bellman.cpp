#include <iostream>
#include <vector>
   
using namespace std;

class edge {
public:
	int u, v, w;
	edge(int a, int b, int c): u(a), v(b), w(c){}
};
   
const
	int max_n = 1001, inf = 12345678;

int n, m, s, d[max_n];
vector<edge> g;

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> m >> s;
	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back(edge(u, v, w));
	}
	for(int i = 1; i <= n; ++i)
		d[i] = inf;
	d[s] = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(d[g[j].u] != inf && d[g[j].v] > d[g[j].u] + g[j].w)
				d[g[j].v] = d[g[j].u] + g[j].w;
	for(int i = 1; i <= n; ++i)
		if(d[i] != inf)
			cout << d[i] << " ";
}