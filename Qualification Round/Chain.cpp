#include <stdio.h>
#include <iostream>
#include <vector>

#define N 100005

#define pb push_back

using namespace std;

vector<int>g[N];
int w[N];
int gr[N];

void cleanG(int n){
	for(int i=0;i<=n;i++){
		g[i].clear();
		w[i] = 0;
		gr[i]=0;
	}
}

int dfs(int x){
	if(!gr[x])return w[x];
	int mn = w[x];
	int sum=w[x];
	for(int i=0;i<g[x].size();i++){
		int v = dfs(g[x][i]);
		mn = min(mn,v);
		sum+=v;
	}
	return sum-mn;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int n;
		scanf("%d",&n);
		cleanG(n);
		for(int i=1;i<=n;i++){
			scanf("%d",w+i);
		}
		for(int i=1;i<=n;i++){
			int l;
			scanf("%d",&l);
			g[l].pb(i);
			gr[l]++;
		}
		int mx = dfs(0);
		printf("Case #%d: %d\n",k,mx);
	}
	return 0;
}
