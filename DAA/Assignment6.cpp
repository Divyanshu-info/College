#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define nV 4

#define INF 999

void printMatrix(vector<vector<int>> m)
{
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (m[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(vector<vector<int>> g) {
    vector<vector<int>> m(
        g.size(),
        std::vector<int>(g.size()));
    
    int i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            m[i][j] = g[i][j];

    for (k = 0; k < nV; k++) {
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                if (m[i][k] + m[k][j] < m[i][j])
                    m[i][j] = m[i][k] + m[k][j];
            }
        }
    }
    printMatrix(m);
}



int main() {
  vector<vector<int>> v;
  v = {{0, 3, INF, 5}, {2, 0, 2, 4}, {1, 1, 0, 4}, {3, 2, 2, 1}};
  floydWarshall(v);
}