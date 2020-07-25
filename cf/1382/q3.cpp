#include <bits/stdc++.h>
#define int long long 

using namespace std;

void split(string &a, string &s1, string &s2, int i){
	for(int j=0;j<i;j++){
		s1+=a[j];
	}
	for(int j=i;j<a.length();j++){
		s2+=a[j];
	}
}

void solve(){
	
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;

	if(a == b){
		cout<<0<<endl;
		return;
	}
	vector<int> ans;
	int i = n-1;
	while(i>=0){

		if(a[i] == b[i]){
			i--;
		} else {
			if(a[0] == b[i]){
				ans.push_back(1);
				a[0] = a[0] == '1'?'0':'1';
			}
			string rr = "", ss = "";
			split(a, rr,ss,i+1);

			string tt = "";
			for(int i=n-1;i>=0;i--){
				tt += (rr[i] == '1' ? '0' : '1');
			}

			// for(char &c : rr){
			// 	c = c == '1'?'0':'1';
			// }
			a = tt + ss;
			ans.push_back(i+1);
			i--;
		}
	}
	// cout<<a<<endl;
	cout<<ans.size()<<" ";
	for(int el : ans){
		cout<<el<<" ";
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
