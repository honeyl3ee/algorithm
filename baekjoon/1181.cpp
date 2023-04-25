#include <iostream>
#include <string>

using namespace std;

void merge(string *word, string *sort, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (word[i].length() < word[j].length())
			sort[k++] = word[i++];
		else if (word[i].length() > word[j].length())
			sort[k++] = word[j++];
		else {
			if (word[i] <= word[j])
				sort[k++] = word[i++];
			else
				sort[k++] = word[j++];
		}
	}
	if (i > mid)
		while (j <= right)
			sort[k++] = word[j++];
	else
		while (i <= mid)
			sort[k++] = word[i++];
	for (; left <= right; left++)
		word[left] = sort[left];
}

void sort_word(string *word, string *sort, int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;

		sort_word(word, sort, left, mid);
		sort_word(word, sort, mid + 1, right);
		merge(word, sort, left, mid, right);
	}
}

int main()
{
	int n;

	cin >> n;
	string word[n];
	string sort[n];
	for (int i = 0; i < n; i++)
		cin >> word[i];
	sort_word(word, sort, 0, n - 1);
	for (int i = 0; i < n; i++)
		if (i == 0 || (i > 0 && word[i - 1] != word[i]))
			cout << word[i] << '\n';
}