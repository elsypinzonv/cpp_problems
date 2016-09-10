#include<cstdio>
int n, k, res, i = 2;
int main() {
	scanf("%d%d", &n, &k);
	while(i <= n)
		res=((res + k) % (i++));
	res++;
	printf("%d\n",res); 
	return 0;
}