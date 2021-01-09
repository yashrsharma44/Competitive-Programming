#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int n; cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int u; cin>>u;
		a.push_back(u);
	}

	if(n <= 3){
		cout<<0<<endl;
		return;
	}

	vector<int> post;
	post.push_back(0);
	post.push_back(0);
	for(int i=n-1;i>=2;i--){
		if((a[i-2] > a[i-1] && a[i-1] < a[i]) || (a[i-2] < a[i-1] && a[i-1] > a[i])){
			post.push_back(post.back()+1);
		} else {
			post.push_back(0);
		}
	}
	// for(auto el : post){
	// 	cout<<el<<" ";
	// }
	// cout<<endl;
	reverse(post.begin(), post.end());
	int ans = min({post[2], post[3]});
	int pre = 0;
	for(int i=2;i+2<n;i++){
		if((a[i-2] > a[i-1] && a[i-1] < a[i]) || (a[i-2] < a[i-1] && a[i-1] > a[i])){
			pre+=1;
			// cout<<pre<<"P";
		}	
		// cout<<"pre"<<pre<<"post"<<post[i+2]<<endl;
		ans = min(ans, pre + post[i+2]);
	}

	cout<<ans<<endl;
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
