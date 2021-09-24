#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int input() {
  int a;
  cin >> a;
  return a;
}

int main(int argc, const char **argv) {
  int n;
  //   cout << "Input no of Combinations: \t";
  //   cin >> n;
  n = 8;
  vector<int> a, b;
  a = {-10, -79, -79, 67, 93, -85, -28, -94};
  b = {-2, 9, 69, 25, -31, 23, 50, 78};
  //   cout<<"Input Mices: \t";
  //   for (int i = 0; i < n; i++) {
  //     a.push_back(input());
  //     }
  //   cout << "\nInput Holes: \t";
  //   for (int i = 0; i < n; i++) {
  //     b.push_back(input());
  //   }
  if (a.size() == b.size()) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0, temp;
    for (int i = 0; i < n; i++) {
      int temp = abs(a[i] - b[i]);
      ans = max(ans, temp);
    }
    cout << "Mice: \t";
    for (auto i = a.begin(); i != a.end(); ++i)
      cout << *i << " ";
    cout << "\nHoles: \t";
    for (auto i = b.begin(); i != b.end(); ++i)
      cout << *i << " ";
    cout << "\nLargest Time taken by any Mouse to gets into hole : " << ans << endl;
  }
  return 0;
}