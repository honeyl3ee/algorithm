#include <stdio.h>

void merge(int *list, int *sort, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
		if (list[i] <= list[j])
			sort[k++] = list[i++];
		else
			sort[k++] = list[j++];

	if (i > mid)
		while (j <= right)
			sort[k++] = list[j++];
	else
		while (i <= mid)
			sort[k++] = list[i++];

	for (;left <= right; left++)
		list[left] = sort[left];
}

void partition(int *list, int *sort, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		partition(list, sort, left, mid);
		partition(list, sort, mid + 1, right);
		merge(list, sort, left, mid, right);
	}
}

int binary_search(int *list, int num, int left, int right)
{
	if (left <= right) {
		int mid = (left + right) / 2;

		if (list[mid] == num)
			return (1);
		else if (num < list[mid])
			return (binary_search(list, num, left, mid - 1));
		else
			return (binary_search(list, num, mid + 1, right));
	}
	return (0);
}

int main()
{
	int n, m, num;

	scanf("%d", &n);
	int list[n];
	int sort[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);
	scanf("%d", &m);
	partition(list, sort, 0, n - 1);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		printf("%d\n", binary_search(list, num, 0, n - 1));
	}
}