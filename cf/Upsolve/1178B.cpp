#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll solve(string s){

	string small = "wow";
	vector< vector<ll> > table(small.length()+1, vector<ll>(s.length()+1, 0));

	

	// We will use dp to solve the problem
	// If we have an empty small string
	for(ll i=0;i<s.length()+1;i++){
		table[0][i] = 1;
	}

	for(ll i=1;i<=small.length();i++){

		for(ll j=1;j<s.length()+1;j++){

			if(s[j-1] == small[i-1]){
				table[i][j] = table[i][j-1] + table[i-1][j-1];
			} else {
				table[i][j] = table[i][j-1];
			}
		}
	}

	return table[small.length()][s.length()];


}

int main(){

	string s;
	cin>>s;

	bool isFirst = true;
	string ans="";
	for(ll i=0;i<s.length();i++){
		if(s[i] == 'v' && isFirst){
			isFirst = false;
			// ans += s[i];
		} else if(s[i] == 'v'){
			ans+="w";
		} else {
			ans += s[i];
			isFirst = true;
		}
	}
	// cout<<ans<<endl;
	cout<<solve(ans)<<endl;
}