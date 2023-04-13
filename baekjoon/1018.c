#include <stdio.h>

int main(void)
{
	int m, n , w, b;
	int min = 64;
	char chess[8][9] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", \
	"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};

	scanf("%d %d", &n, &m);
	char board[n][m + 1];
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);
	for (int i = 0; i + 8 <= n; i++){
		for (int j = 0; j + 8 <= m; j++){
			w = 0;
			b = 0;
			for (int r = 0; r < 8; r++){
				for (int c = 0; c < 8; c++){
					if (board[i + r][j + c] != chess[r][c])
						w++;
					if (board[i + r][j + c] != chess[r][7 - c])
						b++;
				}
			}
			if (w < min) min = w;
			if (b < min) min = b;
		}
	}
	printf("%d\n", min);
}