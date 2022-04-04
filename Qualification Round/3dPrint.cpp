#include <stdio.h>
#include <iostream>

#define N 1000000

using namespace std;

typedef struct{
	int c;
	int m;
	int y;
	int k;	
} printer;

printer resp;

void printPrinter(printer p){
	printf("%d ",p.c);
	printf("%d ",p.m);
	printf("%d ",p.y);
	printf("%d\n",p.k);
}

bool maxSum(printer p[3]){
	int c = min(p[0].c,min(p[1].c,p[2].c));
	int m = min(p[0].m,min(p[1].m,p[2].m));
	int y = min(p[0].y,min(p[1].y,p[2].y));
	int k = min(p[0].k,min(p[1].k,p[2].k));
	
	int tot = c+m+y+k;
	
	int dif = tot-N;
	
	if(dif==0){
		resp = {c,m,y,k};
		return true;
	}
	
	else if(dif<0)return false;
	
	else{
		//cyan
		if(c>=dif){
			c-=dif;
			resp = {c,m,y,k};
			return true;
		}
		else{
			dif-=c;
			c=0;
		}
		//magenta
		if(m>=dif){
			m-=dif;
			resp = {c,m,y,k};
			return true;
		}
		else{
			dif-=m;
			m=0;
		}
		//yellow
		if(y>=dif){
			y-=dif;
			resp = {c,m,y,k};
			return true;
		}
		else{
			dif-=y;
			y=0;
		}
		//black
		if(k>=dif){
			k-=dif;
			resp = {c,m,y,k};
			return true;
		}
		else{
			dif-=k;
			k=0;
		}
	}
	
	return false;
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int k=1;k<=n;k++){
		printer p[3];
		int tot;
		for(int i=0;i<3;i++){
			scanf("%d",&p[i].c);
			scanf("%d",&p[i].m);
			scanf("%d",&p[i].y);
			scanf("%d",&p[i].k);
		}
		bool f=maxSum(p);
		printf("Case #%d: ",k);
		if(f){
			printPrinter(resp);
		}
		else puts("IMPOSSIBLE");
	}
	return 0;
}
