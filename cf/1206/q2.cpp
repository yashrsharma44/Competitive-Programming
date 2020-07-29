#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	int n;
	cin>>n;
	vector<int> a;
	int countZ = 0;
	while(n--){
		int vl;
		cin>>vl;
		if(vl == 0){
			countZ++;
		}
		a.push_back(vl);
	}

	int count = 0;
	for(int &el : a){
		if(el > 1){
			count += (el - 1);
			el = 1;
		} else if(el < -1){
			count += (-1 - el);
			el = -1;
		}
	}

	int prod = 1;
	for(int el : a){
		if(el == 0){
			continue;
		}
		prod *= el;
	}

	if(prod == 1){
		if(countZ > 0){
			count += countZ;
		}
	} else {
		if(countZ > 0){
			count += countZ;
		} else {
			count += 2;
		}
	}

	cout<<count<<endl;

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
