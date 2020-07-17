#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    
	int n;
	cin>>n;
	vector<int> a;
	int nn = n;
	while(nn--){
		int vl;
		cin>>vl;
		a.push_back(vl);
	}

	
	for(int i=1;i<n-1;i++){
		int start = -1, end = -1;
		for(int j=0;j<=i-1;j++){
			if(a[j] < a[i]){
				start = j;
				break;
			}
		}
		for(int j=i+1;j<n;j++){
			if(a[j] < a[i]){
				end = j;
				break;
			}
		}

		if(start != -1 && end != -1){
			cout<<"YES"<<endl;
			cout<<start+1<<" "<<i+1<<" "<<end+1<<endl;
			return;
		}
	}

	cout<<"NO"<<endl;
  
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
