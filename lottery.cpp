#include <iostream>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;
    
const
    int max_n = 1001;
 
int n, lcs, m;
int a[max_n], b[max_n], ans[max_n][max_n];
 
int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if (a[i] == b[j])
				ans[i][j] = ans[i - 1][j - 1] + 1;
			else
				ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
	cout << ans[n][m];
}