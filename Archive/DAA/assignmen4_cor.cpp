#include <bits/stdc++.h>
using namespace std;

int MH(int mp[], int hp[], int m) {
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int temp = abs(mp[i] - hp[i]);
    ans = max(ans, temp);
  }
  return ans;
}

int main() {
  int arr1[] = {-10, -79, -79, 67, 93, -85, -28, -94};
  int arr2[] = {-2, 9, 69, 25, -31, 23, 50, 78};
  int n = sizeof(arr1) / sizeof(arr1[0]);
  int q = sizeof(arr2) / sizeof(arr2[0]);
  cout << "Mice: ";
  for (int i = 0; i < n; ++i)
    cout << arr1[i] << " ";
  cout << "\nHoles: ";
  for (int i = 0; i < n; ++i)
    cout << arr2[i] << " ";

  sort(arr1, arr1 + n);
  sort(arr2, arr2 + q);
  
  cout << "\nTime for last Mouse gets into hole : " << MH(arr1, arr2, n)
       << endl;
}