#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<string> split(string s,char ch){
	istringstream var(s);
	vector<string> arr;
	string temp;
	while(getline(var,temp,ch)){
		arr.push_back(temp);
	}
	return arr;
}

#define ll long long
#define ld long double
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
#define mid(l,r) (l+(r-l)/2)
#define PI 3.141592653589793

vector<int> solve(vector<int> &arr){
	unordered_set<int> ss;
	int n = arr.size();
	vector<int> ans;

	for(int i=n-1;i>=0;i--){
		if(ss.find(arr[i])==ss.end()){
			ans.push_back(arr[i]);
			ss.insert(arr[i]);
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	fastIO();

	ll n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	vector<int> ans = solve(arr);
	cout<<ans.size()<<"\n";
	for(int ele : ans){
		cout<<ele<<" ";
	}

	return 0;
}