#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;
	string s;
	cin>>s;

	for(ll i=25;i>0;i--){

		ll nn = s.length();

		while(nn--)
		for(ll j=0;j<s.length();j++){

			if(j > 0 && j < n-1){
				if(s[j] - 'a' == i){
					if(s[j-1] - 'a' == (i-1) || s[j+1] - 'a' == (i-1)){
						s.erase(s.begin()+j);
						j-=1;
					}
				}
			} else if(j == 0){
				if(s[j] - 'a' == i){
					if(s[j+1] - 'a' == (i-1)){
						s.erase(s.begin()+j);
						j-=1;
					}
				}
			} else {
				if(s[j] - 'a' == i){
					if(s[j-1] - 'a' == (i-1)){
						s.erase(s.begin()+j);
						j-=1;
					}
				}
			}
		}




		// string ss="";
		// for(char c : s){
		// 	if(c == '*'){
		// 		continue;
		// 	}
		// 	ss+=c;
		// }
		// s = ss;
	}

	cout<<(n - s.length())<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
