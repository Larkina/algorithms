#include <stdio.h>
#include <algorithm>
#include <string>
#include <ctype.h>

using namespace std;

const int MAX_N = 13;
const int ALFABET_SIZE = 26;
const int LETTERS_COUNT = 6;

int per[MAX_N], a[MAX_N][ALFABET_SIZE];
bool vis[MAX_N]; 
int n, size = 0;  
char ptrn[MAX_N];
FILE *in, *out;

void rec(int t){
	if (t == size) {	
		for(int i = 0; i < size; i++)
        	fprintf(out, "%d ", per[i] + 1);
    	fclose(in);
      	fclose(out);
      	exit(0);
	} 
	for (int i = 0; i < n; i++) {		
		bool fu = !vis[i] && a[i][ptrn[t] - 'A'] != 0; 				
		if (fu){
      		per[t] = i;
      		vis[i] = true;
      		rec(t + 1);
      		vis[i] = false;
    	}
	}
} 

int main(){
 	in = fopen ("input.txt","r");		
	out = fopen ("output.txt","w");
	fscanf(in, "%d\n", &n);
	fscanf(in, "%s\n", ptrn);
	while(ptrn[size]) {
		ptrn[size] = toupper(ptrn[size]);
		size++;	
    }
	for(int i = 0; i < n; i++)
		for(int j = 0; j < ALFABET_SIZE; j++)
			a[i][j] = 0;
	for(int i = 0; i < n; i++){
		char t;		
		for(int j = 0; j < LETTERS_COUNT; j++){
			fscanf(in, "%c", &t);
			a[i][toupper(t) - 'A']++;
		}
		fscanf(in, "\n");
	}
	rec(0);
	fprintf(out, "%d", 0);
	fclose(in);
	fclose(out);
}
