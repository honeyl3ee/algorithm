#include <iostream>
int num[41][2] = {
    0,
};
void fibonacci(int n, int (*num)[2]) {
  if (n == 0 || n == 1 || num[n][0] > 0 || num[n][1] > 0)
    return;
  else if ((num[n - 1][0] >= 1 || num[n - 1][1] >= 1) &&
           (num[n - 2][0] >= 1 || num[n - 2][1] >= 1)) {
    num[n][0] = num[n - 1][0] + num[n - 2][0];
    num[n][1] = num[n - 1][1] + num[n - 2][1];
    return;
  } else {
    fibonacci(n - 1, num);
    fibonacci(n - 2, num);
    num[n][0] = num[n - 1][0] + num[n - 2][0];
    num[n][1] = num[n - 1][1] + num[n - 2][1];
  }
}

int main() {
  int T, N;

  std::cin >> T;
  num[0][0] = 1;
  num[1][1] = 1;
  for (int i = 0; i < T; i++) {
    std::cin >> N;
    fibonacci(N, num);
    std::cout << num[N][0] << " " << num[N][1] << std::endl;
  }
}