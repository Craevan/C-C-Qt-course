#include <stdio.h>

int symbolicF(char a){
	return (int)a;
}

void main(){
	int i = 101;
	printf("%c\n", symbolicF(i));
}