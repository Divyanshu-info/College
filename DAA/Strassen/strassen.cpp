#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
int dimensions;

int crossover=64;

void multiply (	vector< vector<int> > &A, 
				vector< vector<int> > &B, 
				vector< vector<int> > &C, int d)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int k = 0; k < d; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void split (vector< vector<int> > &A, 
			vector< vector<int> > &B, 
			int row, int col, int d) 
{
    for (int i1 = 0, i2 = row; i1 < d; i1++, i2++)
    {
        for (int j1 = 0, j2 = col; j1 < d; j1++, j2++)
        {
            B[i1][j1] = A[i2][j2];
        }
    }
}

void join (	vector< vector<int> > &A, 
			vector< vector<int> > &B, 
			int row, int col, int d) 
{
    for (int i1 = 0, i2 = row; i1 < d; i1++, i2++)
    {
        for (int j1 = 0, j2 = col; j1 < d; j1++, j2++)
        {
        	B[i2][j2] = A[i1][j1];
        }
    }
}

void add (	vector< vector<int> > &A, 
         	vector< vector<int> > &B, 
         	vector< vector<int> > &C, int d) 
{
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract (	vector< vector<int> > &A, 
         		vector< vector<int> > &B, 
         		vector< vector<int> > &C, int d) 
{
    for (int i = 0; i < d; i++) 
    {
        for (int j = 0; j < d; j++) 
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void print_m (vector< vector<int> > m, int d)
{
	for (int i = 0; i < d; i++) 
	{
        for (int j = 0; j < d; j++) 
        {
             cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}

void print_diag (vector< vector<int> > m, int d)
{
	for (int i = 0; i < d; i++)
	{
		cout << m[i][i] << "\n";
	}
}

void strassen (	vector< vector<int> > &A, 
              	vector< vector<int> > &B, 
              	vector< vector<int> > &C, int d)
{
	if (d % 2 != 0)
	{
		d++;
		A.resize (d);
		B.resize (d);
		C.resize (d);
		
		for (int i = 0; i < d; i++)
		{
			A[i].resize (d);
			B[i].resize (d);
			C[i].resize (d);
		}
	}
	
	if (d <= crossover)
	{
		multiply (A, B, C, d);
		return;
	}
	else
	{
		int new_d = d/2;
        
        vector<int> inside (new_d);

		vector< vector<int> > A11 (new_d, inside);
		vector< vector<int> > A12 (new_d, inside);
		vector< vector<int> > A21 (new_d, inside);
		vector< vector<int> > A22 (new_d, inside);
		vector< vector<int> > B11 (new_d, inside);
		vector< vector<int> > B12 (new_d, inside);
		vector< vector<int> > B21 (new_d, inside);
		vector< vector<int> > B22 (new_d, inside);
		vector< vector<int> > C11 (new_d, inside);
		vector< vector<int> > C12 (new_d, inside);
		vector< vector<int> > C21 (new_d, inside);
		vector< vector<int> > C22 (new_d, inside);

		split(A, A11, 0 , 0, new_d);
        split(A, A12, 0 , new_d, new_d);
        split(A, A21, new_d, 0, new_d);
        split(A, A22, new_d, new_d, new_d);
        split(B, B11, 0 , 0, new_d);
        split(B, B12, 0 , new_d, new_d);
        split(B, B21, new_d, 0, new_d);
        split(B, B22, new_d, new_d, new_d);

		vector< vector<int> > result1 (new_d, inside);
		vector< vector<int> > result2 (new_d, inside);

		add(A11, A22, result1, new_d);
		add(B11, B22, result2, new_d);
		vector< vector<int> > M1 (new_d, inside);
		strassen(result1, result2, M1, new_d);

		add(A21, A22, result1, new_d);
		vector< vector<int> > M2 (new_d, inside);
		strassen(result1, B11, M2, new_d);

		subtract(B12, B22, result2, new_d);
		vector< vector<int> > M3 (new_d, inside);
		strassen(A11, result2, M3, new_d);

		subtract(B21, B11, result2, new_d);
		vector< vector<int> > M4 (new_d, inside);
		strassen(A22, result2, M4, new_d);

		add(A11, A12, result1, new_d);
		vector< vector<int> > M5 (new_d, inside);
		strassen(result1, B22, M5, new_d);

		subtract(A21, A11, result1, new_d);
		add(B11, B12, result2, new_d);
		vector< vector<int> > M6 (new_d, inside);
		strassen(result1, result2, M6, new_d);

		subtract(A12, A22, result1, new_d);
		add(B21, B22, result2, new_d);
		vector< vector<int> > M7 (new_d, inside);
		strassen(result1, result2, M7, new_d);

       	add(M1, M4, result1, new_d);
       	add(result1, M7, result2, new_d);
       	subtract(result2, M5, C11, new_d);

       	add(M3, M5, C12, new_d);

       	add(M2, M4, C21, new_d);

       	subtract(M1, M2, result1, new_d);
       	add(M3, M6, result2, new_d);
       	add(result1, result2, C22, new_d);

       	join(C11, C, 0 , 0, new_d);
        join(C12, C, 0 , new_d, new_d);
        join(C21, C, new_d, 0, new_d);
        join(C22, C, new_d, new_d, new_d);
	}
}

int main(int argc, char *argv[]) {

  cout << "Input Dimensions\n";
  cin >> dimensions;
  if (dimensions < 2) {
    while (dimensions < 2) {
      cout << "Input Correct Dimensions\n";
      cin>>dimensions;
        }
  }
  vector<int> inside(dimensions);
  vector<vector<int>> A(dimensions, inside);
  vector<vector<int>> B(dimensions, inside);
  vector<vector<int>> C(dimensions, inside);
  cout << "Populating Matrix 1 with random values\n";
  cout << "Populating Matrix 2 with random values\n";
  for (int i = 0; i < dimensions; i++)
  {
	  for (int j = 0; j < dimensions; j++)
	  {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
          }
  }
	
	using namespace chrono;
        pid_t pid = fork();
        if (pid == 0) {
          while (true) {
            cout << ". ";
            fflush(stdout);
            sleep(1);
		  }
        }
        else{
	   high_resolution_clock::time_point start1 = high_resolution_clock::now();	   
		  multiply(A, B, C, dimensions);
	   high_resolution_clock::time_point end1 = high_resolution_clock::now();
	   auto duration1 = duration_cast<microseconds>(end1 - start1).count();
	   cout << "\rNaive Matrix Multiplication took: "<< duration1 << " microseconds.\n";
	

	   high_resolution_clock::time_point start2 = high_resolution_clock::now();	   
		  strassen(A, B, C, dimensions);
		  high_resolution_clock::time_point end2 = high_resolution_clock::now();
	   auto duration2 = duration_cast<microseconds>(end2 - start2).count();
           cout << "\rStrassen's Matrix Multiplication took: " << duration2 << " microseconds.\n";
           kill(pid, SIGKILL);
           return 0;
		}
}

