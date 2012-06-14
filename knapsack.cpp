#include <iostream>
#include <vector>
#include <utility>

using namespace std;
   
const
	int max_n = 41, max_w = 10000000;

int n, w; 
int pr[max_w], a[max_n];
bool ans[max_n];

int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> w;
	for(int i = 0; i <= w; ++i)
		pr[i] = -1;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	pr[0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= w; ++j)
			if(j + a[i] <= w && pr[j] != -1 && pr[j + a[i]] == -1 && pr[j] != i)
				pr[j + a[i]] = i;
	int k = pr[w];
	if (k == -1){
		cout << -1;
		return 0;
	}
	int t = w;
	while(k != 0){
		ans[k] = true;
		t -= a[k];
		k = pr[t];
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
}