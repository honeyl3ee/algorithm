#include <stdio.h>
#include <string.h>

int main()
{
	unsigned int m, x, s;
	char str[7];

	s = 0;
	scanf("%u", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		if (strcmp("all", str) != 0 && strcmp("empty", str) != 0)
			scanf("%u", &x);
		if (strcmp("add", str) == 0)
			s = s | (1 << (x - 1));
		else if (strcmp("remove", str) == 0)
			s = s & ~(1 << (x - 1));
		else if (strcmp("check", str) == 0)
			printf("%u\n", ((s & (1 << (x - 1))) != 0));
		else if (strcmp("toggle", str) == 0)
			s = s ^ (1 << (x - 1));
		else if (strcmp("all", str) == 0)
			s = -1;
		else
			s = 0;
		bzero(str, 7);
	}
}
