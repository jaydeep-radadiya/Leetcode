#include<bits/stdc++.h>
using namespace std;

bool dfsCycleDG(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis){
	vis[node] = 1;
	pathVis[node] = 1;

	for(int neighbour : adj[node]){
		if(vis[neighbour]==0){
			if(dfsCycleDG(neighbour,adj,vis,pathVis)==true){
				return true;
			}
		}
		else if(vis[neighbour]==1 && pathVis[neighbour]==1){
			return true;
		}
	}
	pathVis[node] = 0;
	return false;
}

// detect cycle in directed graph using dfs
bool isCycle(int n,vector<int> adj[]){
	vector<int> vis(n);
	vector<int> pathVis(n);

	for(int i=0;i<n;i++){
		if(vis[i]==0){
			if(dfsCycleDG(i,adj,vis,pathVis)==true){
				return true;
			}
		}
	}
	return false;
}

int main(){

	return 0;
}