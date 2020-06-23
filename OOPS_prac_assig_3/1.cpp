#include<iostream>

using namespace std;

int main(){
    int M,N,sum=0;
    cout<<"Enter number of Row : \t\t";
    cin>>M;
    cout<<"Enter number of Column : \t";
    cin>>N;

    int** A = new int*[M];

	// dynamically allocate memory of size N for each row
	for (int i = 0; i < M; i++)
		A[i] = new int[N];

	// assign values to allocated memory
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = rand() % 100;

	// print the 2D array
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << A[i][j] << " ";

		std::cout << std::endl;
	}

	// deallocate memory using delete[] operator
	for (int i = 0; i < M; i++)
		delete[] A[i];

	delete[] A;

	return 0;

}
