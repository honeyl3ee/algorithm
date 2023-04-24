#include <stdio.h>

void	merge(int (*list)[2], int (*sort)[2], int left, int right, int mid) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (list[i][0] < list[j][0]) {
			sort[k][0] = list[i][0];
			sort[k++][1] = list[i++][1];
		}
		else if (list[i][0] > list[j][0]) {
			sort[k][0] = list[j][0];
			sort[k++][1] = list[j++][1];
		}
		else {
			if (list[i][1] < list[j][1]) {
				sort[k][0] = list[i][0];
				sort[k++][1] = list[i++][1];
			}
			else {
				sort[k][0] = list[j][0];
				sort[k++][1] = list[j++][1];
			}
		}
	}
	if (i > mid) {
		for (int tmp = j; tmp <= right; tmp++, k++) {
			sort[k][0] = list[tmp][0];
			sort[k][1] = list[tmp][1];
		}
	}
	else {
		for (int tmp = i; tmp <= mid; tmp++, k++) {
			sort[k][0] = list[tmp][0];
			sort[k][1] = list[tmp][1];
		}
	}
	for (; left <= right; left++) {
		list[left][0] = sort[left][0];
		list[left][1] = sort[left][1]; 
	}
}

void	partition(int (*list)[2], int (*sort)[2], int left, int right)
{
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		partition(list, sort, left, mid);
		partition(list, sort, mid + 1, right);
		merge(list, sort, left, right, mid);
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	int list[n][2];
	int sort[n][2];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &list[i][0], &list[i][1]);
	if (n == 1)
		printf("%d %d\n", list[0][0], list[0][1]);
	else {
		partition(list, sort, 0, n - 1);
		for (int i = 0; i < n; i++)
			printf("%d %d\n", list[i][0], list[i][1]);
	}
}