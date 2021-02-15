#include <bits/stdc++.h>
#define int long long 
using namespace std;

#define MAX 1000005

void solve(){

	int a,b; cin>>a>>b;

	queue< vector<int> > q;
	q.push({a, b, 0});

	while(!q.empty()){

		auto el = q.front(); q.pop();
		if(el[0] == 0) {
			cout<<el[2]<<endl;
			return;
		}
		q.push({el[0] / el[1], el[1], el[2] + 1});
		q.push({el[0], el[1] + 1, el[2] + 1});
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
