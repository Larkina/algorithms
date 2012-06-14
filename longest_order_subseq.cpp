#include <iostream>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;
    
const
    int max_n = 1001;
 
int n, los;
int a[max_n], ans[max_n];
 
int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < i; ++j)
			if (a[i] > a[j])
				ans[i] = max(ans[i], ans[j] + 1);
	los = 0;
	for (int i = 0; i < n; ++i)
		los = max(los, ans[i]);
	cout << los + 1;
}