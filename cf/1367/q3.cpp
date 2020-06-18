#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	// int count = 0, len = 0,cZ = 0;
	// s = "1" + s + "1";
	// // bool prev1 = s[0] == '1';
	// for(int i=0;i<s.length();i++){
	// 	if(s[i] == '0'){
	// 		cZ+=1;
	// 		len+=1;
	// 	} else {
	// 		count += (len / (k+1));
	// 		len = 0;
	// 	}
	// }

	// if(cZ == n){
	// 	cout<<((n+1) / (k+1))<<endl;
	// 	return;
	// }

	// if(len!=0){
	// 	count += ((len)/(k+1));
	// }
	// cout<<count<<endl;
	vector<int> pref(n, -1), suf(n, -1);
	if(s[0] == '1'){
		pref[0] = 0;
	}

	if(s[n-1] == '1'){
		suf[n-1] = n-1;
	}
	for(int i=1;i<n;i++){
		if(s[i] == '1'){
			pref[i] = i;
		} else {
			pref[i] = pref[i-1];
		}
	}

	for(int i=n-2;i>=0;i--){
		if(s[i] == '1'){
			suf[i] = i;
		} else {
			suf[i] = suf[i+1];
		}
	}

	if(pref[0] == -1 && suf[0] == -1){
		int count = (n+1) / (k+1);
		cout<<count<<endl;
		return;
	}
	int len = 0;
	int count = 0;
	int last1 = -1;

	for(int i=0;i<n;i++){
	
		if(s[i] == '1'){
			last1 = i; 
		} else {
			if(last1 == -1){
				if(abs(i - suf[i]) >= k+1){
					count += 1;
					last1 = i;
					suf[i] = i;
				}
			} else if(suf[i] == -1){
				if(abs(last1 - i) >= k+1 ){
					count+=1;
					last1 = i;
					suf[i] = i;
					
				}	
			} else {
				if(abs(last1 - i) >= k+1  && abs(i - suf[i]) >= k+1){
					count += 1;
					last1 = i;
					suf[i] = i;
					
				}	
			}
			
		}
		
		
	}

	cout<<count<<endl;
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
