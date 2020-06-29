#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n;
	cin>>n;
	string s;
	cin>>s;

	vector<string> ans;
	string ss = to_string(s[0] - '0');
	for(int i=1;i<n;i++){

		if(s[i] == s[i-1]){
			ss+=s[i];
		} else {
			if(s[i] == '1' && s[i-1] == '0'){
				ans.push_back(ss);
				ss = s[i];
			} else {
				ss+=s[i];
			}
		}
	}
	if(ss!=""){
		ans.push_back(ss);
	}

	string last = ans[ans.size()-1];
	bool isSame = true;
	for(int i=1;i<last.length();i++){
		if(last[i] != last[i-1]){
			isSame = false;
			break;
		}
	}

	

	string first = ans[0];
	bool isSameF = true;
	for(int i=1;i<first.length();i++){
		if(first[i] != first[i-1]){
			isSameF = false;
			break;
		}
	}	

	if(isSame && isSameF && ans.size() <= 2){
		cout<<s<<endl;
		return;
	}

	string strt = "", end = "";
	if(isSameF){
		strt = first;
	}
	if(isSame){
		end = last;
	}

	cout<<(strt+"0"+end)<<endl;



	// string first = ans[0];
	// if(isSame){
	// 	// If 0
	// 	if(last[0] == '0'){
	// 		cout<<s<<endl;
	// 	} else {
	// 		// 1
	// 		string a = first;
	// 		if(ans.size() > 2){
	// 			first += "0";
	// 		}
	// 		first+=last;
	// 		cout<<first<<endl;
	// 	}
	// } else {
		
	// 	cout<<"0"<<endl;
	
	// }



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
