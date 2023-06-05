#include <iostream>

int main(void) {
  int N, K;
  int res = 0;
  int num[10] = {0};
  std::cin >> N >> K;
  for (int i = 0; i < N; i++) {
    std::cin >> num[i];
  }
  for (int i = N - 1; i >= 0; i--) {
    if (K / num[i] > 0) {
      res += K / num[i];
      K %= num[i];
      if (K == 0) break;
    }
  }
  std::cout << res;
}