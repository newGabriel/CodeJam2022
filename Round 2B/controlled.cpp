#include <bits/stdc++.h>

#define f first
#define s second 

using namespace std;

typedef pair<int,int> pii;

int maxQ(int n, pii *v, int pos){
	if(pos==n)
		return 0;
	int nx = maxQ(n,v,pos+1);
	int q1 = abs(v[pos].f-v[pos+1].f)+nx;
	int q2 = abs(v[pos].f-v[pos+1].s)+nx;
	int q3 = abs(v[pos].s-v[pos+1].f)+nx;
	int q4 = abs(v[pos].s-v[pos+1].s)+nx;
	printf("%d ",nx);
	return min(min(q1,q2),min(q3,q4));
}

int main(){
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int n,m;
		scanf("%d%d",&n,&m);
		int v[m];
		pii nd[n+1]={{0,0}};
		long long int tot=0;
		for(int i=1;i<=n;i++){
			nd[i] = {INT32_MAX,0};
			for(int j=0;j<m;j++){
				scanf("%d",v+j);
				if(v[j]>nd[i].s)nd[i].s=v[j];
				if(v[j]<nd[i].f)nd[i].f=v[j];
			}
			sort(v,v+m);
			int b=v[0];
			for(int j=1;j<m;j++){
				tot+=abs(b-v[j]);
				b=v[j];
			}
		}
		tot+=maxQ(n,nd,0);
		printf("Case #%d: %lld\n",k,tot);
	}
	return 0;
}
