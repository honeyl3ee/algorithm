#include <iostream>

void merge(int *list, int *sort, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (list[i] < list[j])
			sort[k++] = list[i++];
		else
			sort[k++] = list[j++];
	}
	if (i > mid)
		while (j <= right)
			sort[k++] = list[j++];
	else
		while (i <= mid)
			sort[k++] = list[i++];
	for (; left <= right; left++)
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

int main() {
	int n;

	std::cin >> n;
	int list[n];
	int sort[n];

	for (int i = 0; i < n; i++)
		std::cin >> list[i];
	partition(list, sort, 0, n - 1);
	for (int i = 0; i < n; i++)
		std::cout << list[i] << '\n';
}