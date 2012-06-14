#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;
    
const
    int max_n = 200001;
 
int n, m;
int pref[max_n];
 
int main(){
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
	string s, key;
	getline(cin, s);
	getline(cin, key);
	n = key.length();
	s = key + "#" + s + " ";
	int curr_pref = 0;
	pref[0] = 0;
	for(int i = 1; i <= s.length() - 1; ++i){
		while(curr_pref > 0 && s[i] != s[curr_pref])
			curr_pref = pref[curr_pref - 1];
		if (s[curr_pref] == s[i])
			++curr_pref;
		pref[i] = curr_pref;
	}
	for(int i = 0; i < s.length(); ++i)
		if (pref[i] == n){
			cout << i + 1 - 2 * n;
			return 0;
		}
	cout << -1;
}