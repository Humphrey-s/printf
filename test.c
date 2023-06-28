#include "main.h"
#include <stdio.h>

int main(void)
{
	_printf("%c", '\0');
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("%c", '\0');
return (0);
}
