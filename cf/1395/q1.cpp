#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define MAX 1000005

void solve(){

	int r,b,g,w;
	cin>>r>>b>>g>>w;
	int min_ = min({r,b,g});
	
	int count = 0;
	if(r%2==1) count++;
	if(b%2==1) count++;
	if(g%2==1) count++;
	if(w%2==1) count++;

	
	if(count == 0){
		cout<<"Yes"<<endl;
	} else if(count == 4 && min_ >= 1){
		cout<<"Yes"<<endl;
	} else if(count == 1){
		cout<<"Yes"<<endl;
	} else if(count == 3 && min_ >= 1){
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
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
