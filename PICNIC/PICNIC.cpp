#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, M;
int res;
bool assigned[10];

void dfs(int remained, vector<pair<int, int> > &friends);
bool are_friend(int a, int b, const vector<pair<int, int> > &friends);

int main () {
  freopen("input.txt", "r", stdin);
  cin >> C;

  for (int i = 0; i < C; ++i) {
    cin >> N >> M;

    vector<pair<int, int> > friends;
    for (int j = 0; j < M; ++j) {
      int a, b; cin >> a >> b;
      if (a > b) {
        swap(a, b);
      }
      friends.push_back(make_pair(a, b));
    }

    res = 0;
    for (int j = 0; j < 10; ++j) {
      assigned[j] = false;
    }
    dfs(N, friends);

    cout << res << endl;
  }
  return 0;
}

void dfs(int remained, vector<pair<int, int> > &friends) {
  if (remained == 0) {
    ++res;
    return;
  }

  int a;
  for (int i = 0; i < N; ++i) {
    if (!assigned[i]) {
      a = i;
      break;
    }
  }

  for (int i = 0; i < N; ++i) {
    // i should be larger than a to prevent duplication
    if (i <= a) {
      continue;
    }

    if (!assigned[i] && are_friend(a, i, friends)) {
      assigned[a] = true;
      assigned[i] = true;
      dfs(remained-2, friends);
      assigned[a] = false;
      assigned[i] = false;
    }
  }
}

bool are_friend(int a, int b, const vector<pair<int, int> > &friends) {
  auto cond = [&a, &b](const pair<int, int> &elem) { return ((elem.first == a) && (elem.second == b)); };
  auto it = find_if(friends.begin(), friends.end(), cond);
  if (friends.end() == it) {
    return false;
  }
  return true;
}