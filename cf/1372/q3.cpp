#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    
	int n;
	cin>>n;
	int nn = n;
	vector<int> arr;
	while(nn--){
		int vl;
		cin>>vl;
		arr.push_back(vl);
	}
	vector<int> cp(arr);
	sort(cp.begin(), cp.end());
	
	string ss = "";
	for(int i=0;i<n;i++){
		if(arr[i] == cp[i]){
			ss+="1";
		} else {
			ss+="0";
		}
	}

	vector<string> rle;
	string s = ss[0] == '1' ? "1" : "0";
	for(int i=1;i<n;i++){
		if(ss[i] == ss[i-1]){
			s+=ss[i];
		} else {
			rle.push_back(s);
			s = ss[i];
		}
	}
	rle.push_back(s);

	if(rle.size() == 1){
		if(rle[0][0] == '1'){
			cout<<0<<endl;
		} else {
			cout<<1<<endl;
		}
		return;
	}

	if(rle.size() == 2){
		cout<<1<<endl;
		return;
	}
	if(rle.size() == 3){
		if(rle[0][0] == '1'){
			cout<<1<<endl;
		} else {
			cout<<2<<endl;
		}
		return;
	}

	cout<<2<<endl;
  
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
