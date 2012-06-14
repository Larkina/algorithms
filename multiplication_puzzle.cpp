#include <iostream>
#include <vector>
using namespace std;
#define maxn 101
int inf = 1000000000;

int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n;
   int p[maxn];
   int res[maxn][maxn];
   cin >> n;
   for(int i = 0; i < n; ++i)
	   cin >> p[i];
   for(int i = 0; i < 100; ++i)
      for(int j = 0; j < 100; ++j)
         res[i][j] = inf;

   for(int i = 0; i < n - 1; ++i)
      res[i][i + 1] = 0;

   for(int i = 2; i < n; ++i)
      for(int j = 0; j < n - i; ++j)
         for(int k = j + 1; k < j + i; ++k)
            res[j][j + i] = min(res[j][j + i], res[j][k] + p[j] * p[k] * p[j + i] + res[k][j + i]);

	cout << res[0][n - 1];            
}