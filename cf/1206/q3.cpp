#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	int n;
	cin>>n;

	if(n == 1){
		cout<<"YES"<<endl;
		cout<<1<<" "<<2<<endl;
		return;
	}


	set<int> elems;
	vector<int> ans;
	int cur = 1;
	elems.insert(cur);
	ans.push_back(cur);
	while(elems.size() < (2*n)){
		
		cur += n;
		if(cur > 2*n){
			cur = cur - (2*n);
		}
		// cur %= (2*n);

		if(elems.find(cur)!=elems.end()){
			cout<<"NO"<<endl;
			return;
		}
		elems.insert(cur);
		ans.push_back(cur);
		if(elems.size() == 2*n){
			break;
		}
		cur += 1;
		if(cur > 2*n){
			cur = cur - (2*n);
		}

		if(elems.find(cur)!=elems.end()){
			cout<<"NO"<<endl;
			return;
		}
		elems.insert(cur);
		ans.push_back(cur);
		if(elems.size() == 2*n){
			break;
		}
	}
	int prev = -1;
	for(int i=0;i<(2*n);i++){
		int sm = ans[(i)%(2*n)] + ans[(i+1)%(2*n)] + ans[(i+2)%(2*n)];
		if(prev == -1){
			prev = sm;
		} else {
			if(abs(prev - sm) > 1){
				cout<<"NO"<<endl;
				return;
			}
		}
	}

	cout<<"YES"<<endl;
	for(int el : ans){
		if(el == 0){
			cout<<(2*n)<<" ";
		} else 
		cout<<el<<" ";
	}
	cout<<endl;
	
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
