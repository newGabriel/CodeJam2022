#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		int e,w;
		scanf("%d%d",&e,&w);
		int mn[w];
		int m[e][w];
		for(int i=0;i<e;i++){
			for(int j=0;j<w;j++){
				scanf("%d",&m[i][j]);
				//mn[j] = min(mn[j],m[i][j]);
			}
		}
		int mv=0;
		for(int l=0;l<e;l++){
			for(int f=e;f>l;f--){
				for(int i=0;i<w;i++)mn[i] = 200;
				for(int i=l;i<f;i++){
					for(int j=0;j<w;j++){
						mn[j] = min(mn[j],m[i][j]);
					}
				}
				for(int i=0;i<w;i++){
					mv+=mn[i];
					for(int j=l+1;j<f;j++){
						m[j][i]-=mn[i];
					}
				}
			}
			for(int i=0;i<e;i++){
				for(int j=0;j<w;j++){
					mv+=m[i][j];
				}
			}
		}
		printf("Case #%d: %d\n",k,mv);
	}
	return 0;
}
