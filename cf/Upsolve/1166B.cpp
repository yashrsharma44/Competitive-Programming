#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int k;
	cin>>k;
	vector<pair<int,int> > an;
	for(int i=1;i*i<=k;i++){
		if(k%i == 0){
			an.push_back(make_pair(i,k/i));
		}
	}
	bool isPos = false;
	int f1 = -1, f2 = -1;
	for(auto el : an){
		if(el.first >= 5 && el.second >= 5){
			isPos = true;
			f1 = el.first;
			f2 = el.second;
		}
	}
	if(!isPos){
		cout<<-1<<endl;
		return;
	}
	string s = "aeiou";
	string ss="";
	for(int i=0;i<f1;i++){
		for(int j=0;j<f2;j++){
			ss+=s[(i+j)%5];
		}
	}
	cout<<ss<<endl;

}


int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
