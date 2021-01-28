#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

bool check(int i, string &s, string &t){
	string com = s.substr(0, i);
	int k = 0;
	for(int j=0;j<s.length();j++){
		if(s[j] != com[k % (int)com.length()]){
			return false;
		}
		k++;
	}
	if(k % (int)(com.length()) != 0){
		return false;
	}
	k = 0;
	for(int j=0;j<t.length();j++){
		if(t[j] != com[k % (int)com.length()]){
			return false;
		}
		k++;
	}	

	return (k % (int)(com.length())) == 0;
}

void solve(){

	string s,t; cin>>s>>t;

	string com = "";
	int p1 = 0, p2 = 0;
	while(p1 < s.length() && p2 < t.length()){
		if(s[p1] == t[p2]){
			p1++;p2++;
		} else {
			break;
		}
	}

	com = s.substr(0,p1);
	int ans = 0;
	for(int i=1;i<=com.length();i++){
		if(check(i, s, t)){
			ans = i;
			break;
		}
	}
	if(ans == 0){
		cout<<-1<<endl;
		return;
	}
	// cout<<ans<<endl;
	int m1 = s.length(), m2 = t.length();
	int m3 = m1 / ans, m4 = m2 / ans;
	// cout<<m3<<"P"<<m4<<"O"<<__gcd(m3, m4)<<endl;
	int anss = (m3*m4) / __gcd(m3, m4);

	string aa = s.substr(0,ans);

	while(anss--){
		cout<<aa;
	}
	cout<<endl;

}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
