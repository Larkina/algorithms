#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 101; 

long double b[MAX_N], a[MAX_N][MAX_N], c[MAX_N][MAX_N], res[MAX_N][MAX_N];
int s[MAX_N], w[MAX_N], pr[MAX_N][MAX_N];

int n, m, k;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			cin >> c[i][j];
			c[i][j] *= 10;
		}
	for(int i = 1; i <= k; ++i)
		cin >> s[i];
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= n; ++j) {
			res[i][j] = 0;
			pr[i][j] = 1;
			if (i == 1)
				res[i][j] = b[j];
			else
				for(int l = 1; l <= n; ++l)
					if (res[i][j] < res[i - 1][l] * a[l][j]){
						res[i][j] = res[i - 1][l] * a[l][j];
						pr[i][j] = l;
					}
			res[i][j] *= c[j][s[i]];
		}
	long double max = 0;
	int t = 1;
	for(int i = 1; i <= n; ++i)
		if (max < res[k][i]){
			t = i;
			max = res[k][i];
		}
	for(int i = k; i > 0; --i){
		w[i] = t;
		t = pr[i][t];
	}
	for(int i = 1; i <= k; ++i)
		cout << w[i] << " ";
}