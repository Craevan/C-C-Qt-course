#include <stdio.h>

int main() {
	char c = -128;
	c--;
	printf("%d\n", c);
	printf("%c\n", --c); // 127 это delete
	return 0;
}