#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int maxn = 101, INF = 100000000;
int n;
double x[maxn], y[maxn];
double res[maxn][maxn];

double dist(int i, int j){
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	double pp = 0;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			res[i][j] = INF;

	for(int i = 0; i < n; ++i){
		res[i][i + 1] = 0;
		pp += dist(i, (i + 1) % n);
	}

	for(int i = 2; i < n; ++i)
		for(int j = 0; j < n - i; ++j)
			for(int k = j; k < j + i; ++k){
				double t = dist(j, k) + dist(k, j + i) + dist(j, j + i);
				res[j][j + i] = min(res[j][j + i], res[j][k] + t + res[k][j + i]);
			}
	
	printf("%0.4f", (res[0][n - 1] - pp) / 2)); 	
}
