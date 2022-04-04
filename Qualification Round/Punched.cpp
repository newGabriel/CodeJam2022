#include <stdio.h>

void printFirstLine(int c){
	printf("..+");
	for(int i=1;i<c;i++){
		printf("-+");
	}printf("\n");
}

void printDownLine(int c){
	printf("+");
	for(int i=0;i<c;i++){
		printf("-+");
	}printf("\n");
}

void printFirst(int c){
	printf(".");
	for(int i=0;i<c;i++){
		printf(".|");
	}printf("\n");
	printDownLine(c);
}

void printLine(int c){
	printf("|");
	for(int i=0;i<c;i++){
		printf(".|");
	}printf("\n");
	printDownLine(c);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int k=1;k<=n;k++){
		int r,c;
		scanf("%d%d",&r,&c);
		printf("Case #%d:\n",k);
		printFirstLine(c);
		printFirst(c);
		for(int i=1;i<r;i++){
			printLine(c);
		}
	}
	return 0;
}
