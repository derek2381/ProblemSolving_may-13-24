// problem link
// https://www.codechef.com/problems/PIBRO

#include <iostream>
using namespace std;

int main() {
	// your code goes here

	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;

	    string str;
	    cin >> str;
	    str = '0' + str + '0';

	    int s = 1, e = k;
	    int t_s = s, t_e = e;
	    int count = 0, max_c = 0;
	    while(e <= n){
	        t_s = s-1;
	        t_e = e+1;
	        if(t_s > 0 && str[t_s] == '1'){
	            while(str[t_s] != '0'){
	                t_s--;
	            }
	        }

	        if(t_e <= n && str[t_e] == '1'){
	            while(str[t_e] != '0'){
	                t_e++;
	            }
	        }

	        count = k + (s - t_s-1) + (t_e - e - 1);

	        if(count > max_c){
	            max_c = count;
	        }

	        s++;
	        e++;


	        }

	        cout << max_c << endl;
	    }

	return 0;
}
