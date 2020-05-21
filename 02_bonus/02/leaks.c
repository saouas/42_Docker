#include <stdlib.h>
int main ()
{
	char *str;

	if(!(str = malloc(sizeof(char))))
		return (0);
	str[0] = 'x';
	return (0);
}
