#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){
	string s; cin>>s;
	int n = s.length();

	if(n < 3){
		
		if(stoi(s) % 8 == 0){
			cout<<"YES"<<endl;
			cout<<s<<endl;
			return;
		} else if((s[0] - '0') % 8 == 0){
			cout<<"YES"<<endl;
			cout<<(s[0] - '0')<<endl;
			return; 
		} else if(n > 1 && (s[1] - '0') % 8 == 0){
			cout<<"YES"<<endl;
			cout<<(s[1] - '0')<<endl;
			return;
		}
		cout<<"NO"<<endl;
		return;
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int num = 100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0');
				if(num % 8 == 0){
					cout<<"YES"<<endl;
					cout<<num<<endl;
					return;
				}			
			}

			int num1 = 10 * (s[i] - '0') + (s[j] - '0');
			if(num1 % 8 == 0){
				cout<<"YES"<<endl;
				cout<<num1<<endl;
				return;
			}	
		}

		int num2 = s[i] - '0';
		if(num2 % 8 == 0){
			cout<<"YES"<<endl;
			cout<<num2<<endl;
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
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}