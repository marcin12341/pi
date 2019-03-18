#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double get_random(int min, int max) {
  return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}

double get_pi() {
  double number;
  const int SQUARE_POINTS = 5;
  sleep(1);
  int circle_points = 0;
  srand(getpid());

  for (int i = 0; i < SQUARE_POINTS; i++) {
    double x = get_random(0, 1);
    double y = get_random(0, 1);
    if (x * x + y * y <= 1) {
      circle_points++;
    }
  }
  return 4 * (circle_points / (double)SQUARE_POINTS);
}

int main() {
  int n = 10;
  pid_t pid;
  for (int i = 0; i < n; i++) {
    pid = fork();
    if (pid == 0) {
      sleep(1);
      break;
    }
  }
  if (pid == 0) {
    sleep(1);
    double pi = get_pi();
    printf("pi: %f\n", pi);
  }
}
