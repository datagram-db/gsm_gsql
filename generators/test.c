#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct test {
	char ciao[2];
	char test[];   //defining the traling part of our information
};


char myString[] = "This is some text of some arbitrary length";
char elements[200];

int main(void) {

	struct test *elem  = (struct test*)myString;
	int i;
	for (i = 0; i<2; i++)
		putchar(elem[0].ciao[i]);
	putchar('\n');
	for (i = 0; i<5; i++)
		putchar(elem[0].test[i]);
	putchar('\n');
	memset((void*)elements,0,200);
	printf("%lu\n",sizeof(struct test));
	
	return 0;
}
