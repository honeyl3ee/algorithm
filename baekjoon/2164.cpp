#include <iostream>
#include <queue>

int main()
{
	int n;
	std::cin >> n;
	std::queue<int> card;
	for (int i = 1; i <= n; i++)
		card.push(i);
	while (card.size() != 1)
	{
		card.pop();
		if (card.size() == 1)
			break ;
		card.push(card.front());
		card.pop();
	}
	std::cout << card.front() << '\n';
}