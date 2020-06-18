#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n;
	cin>>n;
	vector<int> v;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		v.push_back(vl);
	}

	for(int i=0;i<n;i++){
		v[i] = v[i] % 2;
	}
	int count = 0;
	int c1 = 0, c2 = 0;
	for(int i=0;i<n;i++){
		if((v[i] % 2 == 0 && i%2 == 1)){
			count+=1;
			c1+=1;
		} if((v[i] % 2 == 1 && i%2 == 0)){
			c2+=1;
			count+=1;
		}
	}

	if(count % 2 == 0 && c1 == c2){
		count /= 2;
		cout<<count<<endl;
	} else {
		cout<<-1<<endl;
	}
	
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
