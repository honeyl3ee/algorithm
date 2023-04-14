#include <stdio.h>

//Josephus problem
int main(void)
{
	int n, k, q, cnt, idx;
	int p[1000] = {0};
	int res[1000] = {0};

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		p[i] = i + 1;
	idx = 0;
	q = 0;
	cnt = 0;
	while (1){
		for (int i = 0; i < n; i++){
			if (p[(q + i) % n] != 0)
				cnt++;
			if (cnt == k){
				q = (q + i) % n;
				res[idx++] = p[q];
				p[q] = 0;
				cnt = 0;
				break ;
			}
		}
		if (idx == n)
			break ;
	}
	printf("<");
	for (int i = 0; i < n; i++){
		printf("%d", res[i]);
		if (i != n - 1)
			printf(", ");
		else
			printf(">\n");
	}
}
