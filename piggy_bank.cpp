#include <iostream>
#include <vector>
#include <utility>

using namespace std;
   
const
	int max_n = 101, inf = 12345678;

int n, e, f; 
int c[max_n], w[max_n];
int ans[max_n * max_n];

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> e >> f >> n;
	for(int i = 1; i <= n; ++i)
		cin >> c[i] >> w[i];
	for(int i = 0; i <= f; ++i)
		ans[i] = inf;
	ans[e] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= f; ++j)
			ans[j + w[i]] = min(ans[j + w[i]], ans[j] + c[i]);
	int res = ans[f] == inf ? -1 : ans[f]; 
	cout << res;
}