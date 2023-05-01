#include <iostream>
#include <cmath>

int main()
{
	int a, b, c, l;

	while (1)
	{
		std::cin >> a >> b >> c;
		if (a + b + c == 0)
			break ;
		l = (a > b) ? a : ((b > c) ? b : c); 
		if ((l == a && a == sqrt(pow(b, 2) + pow(c, 2)))
			|| l == b && b == sqrt(pow(a, 2) + pow(c, 2))
			|| l == c && c == sqrt(pow(a, 2) + pow(b, 2)))
			std::cout << "right\n";
		else
			std::cout << "wrong\n";
	}
}