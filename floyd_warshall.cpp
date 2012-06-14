#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
const
    int max_n = 101, inf = 12345678;
 
int n, m, g[max_n][max_n];
 
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            g[i][j] = i == j ? 0 : inf;
        }
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1][v - 1] = w;
    }
    for(int k  = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if (g[i][j] > g[i][k] + g[k][j] && g[i][k] != inf && g[k][j] != inf)
                    g[i][j] = g[i][k] + g[k][j];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            if(g[i][j] != inf)
                cout << g[i][j] << " ";
            else
                cout << "  ";
        cout << "\n";
    }
}