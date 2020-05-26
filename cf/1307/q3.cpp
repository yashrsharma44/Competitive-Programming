#include <bits/stdc++.h>
#define ll long long int 

using namespace std;

void solve(){

	string s;
	cin>>s;

	vector<ll> arr1(26,0);

	vector < vector<ll> > arr2(26, vector<ll>(26, 0));
	for(char c : s){
		for(int i=0;i<26;i++){
// For a given char c, we choose all possible chars [a..z]
// and multiply count of prev char with that, more like choosing all k characters before 
// that and using them with the current character.
// arr1[i] -> denotes all count of 'a'+i uptil current char
			arr2[i][c-'a'] += arr1[i];
		}
		arr1[c-'a']++;
	}

	ll mx = -1;
	for(ll el : arr1){
		mx = max(mx, el);
	}

	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			mx = max(mx, arr2[i][j]);
		}
	}

	cout<<mx<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}

}