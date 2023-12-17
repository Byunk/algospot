#include <iostream>
#include <vector>

using namespace std;

int C, N, L;

int main() {
  freopen("input.txt", "r", stdin);
  cout << fixed;
  cout.precision(11);
  cin >> C;

  for (int i = 0; i < C; i++) {
    cin >> N >> L;
    vector<int> cost;
    for (int j = 0; j < N; j++) {
      int n;
      cin >> n;
      cost.push_back(n);
    }

    double minAvg = 100;
    for (int j = 0; j < N-L+1; j++) {
      int sum = 0, cnt = 0;
      for (int k = j; k < N; k++) {
        sum += cost[k];
        cnt += 1;
        if (cnt >= L) {
          double avg = (double)sum / cnt;
          if (minAvg > avg) {
            minAvg = avg;
          }
        }
      }
    }
    // cout << minAvg << endl;
    printf("%0.9lf\n", minAvg);
  }
  return 0;
}
