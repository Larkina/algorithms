#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iostream>

using namespace std;

const int MAX_N = 1000; 

int q, p;
string a[MAX_N];
int	o[MAX_N];
	
bool check(string s){
	for(int i = 0; i < p; i++){
		int t = 0;
		for(int j = 0; j < q; j++)
			t += s[j] == a[i][j];
		if (t != o[i]) return false;
	}
  	return true;
}

void rec(int k, string s){
	if (k == q){
    	if (check(s)) {
			cout << s;
 			fclose(stdin);
			fclose(stdout);
			exit(0);
		}
		return;
	}
	rec(k + 1, s + '+');
	rec(k + 1, s + '-');
}

int main(){
 	freopen ("input.txt", "r", stdin);		
	freopen ("output.txt", "w", stdout);
	cin >> p >> q;
	for(int i = 0; i < p; i++)
		cin >> a[i] >> o[i];	
	rec(0, "");
	fclose(stdin);
	fclose(stdout);
}
