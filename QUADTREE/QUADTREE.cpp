#include <iostream>
#include <vector>
#include <string>

using namespace std;

int C;

string solve(string& quad, int p);

int main() {
    freopen("input.txt", "r", stdin);

    cin >> C;
    for (int i = 0; i < C; ++i) {
        string s; cin >> s;
        string ret = solve(s, 0);
        cout << ret << endl;
    }
}

string solve(string& quad, int p) {
    // base case
    if (quad[p] != 'x') {
        string s;
        s += quad[p];
        return s;
    }

    // divide into 4 subquad
    vector<string> subquad;
    string s = "";
    s += quad[p];
    p += 1;

    for (int i = 0; i < 4; ++i) {
        string ss = solve(quad, p);
        p += ss.length();
        subquad.push_back(ss);
    }

    return s + subquad[2] + subquad[3] + subquad[0] + subquad[1];
}