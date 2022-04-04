#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int k=1;k<=n;k++){
		int d;
		scanf("%d",&d);
		map<int,int> M;
		while(d--){
			int l;
			scanf("%d",&l);
			M[l]++;
		}
		int qtd=0;
		for(auto i: M){
			for(int j=0;j<i.second;j++){
				if(i.first>qtd){
					qtd++;
				}
			}
		}
		printf("Case #1: %d\n",qtd);
	}
	return 0;
}
