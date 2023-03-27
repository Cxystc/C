#include <stdio.h>

int jiaogu (int n){

if (n %2 == 0) {
	n /= 2 ;
}

else {
	n = n*3 + 1 ; 
}
return n ; 
}

int main (){
	int m = 0 , n ; 
	scanf("%d",&n);
	while (n != 1){
		n = jiaogu(n);
        m+=1;
	}
	printf("Finished:%d\n",m);
	return 0 ; 
}