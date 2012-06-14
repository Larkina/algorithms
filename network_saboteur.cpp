#include <stdio.h>
#include <algorithm>

using namespace std;

int n, a[20][20], part[20], ans = 0;

int calc_ans(){
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      res += (part[i] != part[j]) * a[i][j];
  return res;
}

void rec(int t){
  if (t == n) {
    ans = max(calc_ans(), ans);
    return;
  }
  for(int i = 1; i <= 2; i++){
    part[t] = i;
    rec(t + 1);
  }
}

int main(){
	FILE *in, *out;
 	in = fopen ("input.txt","r");		
	out = fopen ("output.txt","w");
	fscanf(in, "%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			fscanf(in, "%d", &a[i][j]);
	rec(0);
	fprintf(out, "%d", ans);
	fclose(in);
	fclose(out);
}
