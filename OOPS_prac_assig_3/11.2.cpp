// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Map to store the characters with their order
// in the new alphabetical order
unordered_map<char, int> h;

// Function that returns true if x < y
// according to the new alphabetical order
bool compare(string x, string y)
{
    for (int i = 0; i < min(x.size(), y.size()); i++)
    {
        if (h[x[i]] == h[y[i]])
            continue;
        return h[x[i]] < h[y[i]];
    }
    return x.size() < y.size();
}

// Driver code
int main()
{
    string str = "fguecbdavwyxzhijklmnopqrst";
    vector<string> v{"geeksforgeeks", "is", "the",
                     "best", "place", "for", "learning"};

    // Store the order for each character
    // in the new alphabetical sequence
    h.clear();
    for (int i = 0; i < str.size(); i++)
        h[str[i]] = i;

    sort(v.begin(), v.end(), compare);

    // Print the strings after sorting
    for (auto x : v)
        cout << x << " ";

    return 0;
}
