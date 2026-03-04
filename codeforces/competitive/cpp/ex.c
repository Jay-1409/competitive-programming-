#include<stdio.h>
int isPrime(int x);
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",isPrime(n));
}
int isPrime(int x){
	for(int i=0;i<x;i++){
		if(i!=1){
		if(x%i==0){
			return 1;
		}
	}
	}
	return 0;
}