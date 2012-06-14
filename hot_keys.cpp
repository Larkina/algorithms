#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iostream>
#include <vector>
 
using namespace std;
const int MAXN = 11;

string h[MAXN];
int l[MAXN][26];
int ans[MAXN], best[MAXN];
int n, sum = 1000, s = 0, w = 0, word = 0;
bool used[26];

void rec(int t){
	if (w + n - t < word || (w + n - t == word && s >= sum))
		return;
	if( t >= n){
		if (w > word || (w == word && s < sum)){
			word = w;
			sum = s;
			memcpy(ans, best, sizeof(best));
		}
		return;
	}
	best[t] = 0;
	rec(t + 1);
	for(int i = 0; i < 26; ++i){
		if (l[t][i] == 0 || used[i])
			continue;
		used[i] = true;
		w++;
		s += l[t][i];
		best[t] = l[t][i];
		rec(t + 1);
		s -= l[t][i];
		w--;
		used[i] = false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> h[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < h[i].size(); ++j)
			if (l[i][h[i][j] - 'a'] == 0)
				l[i][h[i][j] - 'a'] = j + 1;

	rec(0);

	for(int i = 0; i < n; ++i) {
		if (ans[i] != 0)
			h[i].insert(ans[i] - 1, "&");
		cout << h[i] << endl;
	}
}
