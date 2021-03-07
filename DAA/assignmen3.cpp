#include <bits/stdc++.h>
#include <csignal>
#include <cstdlib>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "original.c"

using namespace std;

class Matrix {
public:
  int **pos;
  Matrix(int x) {
    int **arr = new int *[x];
    for (int i = 0; i < x; ++i)
      arr[i] = new int[x];
    pos = arr;
  }
};

void print(Matrix M, int num) {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
      cout << M.pos[i][j] << " ";
    }
    printf("\n");
  }
}

//int num;

Matrix strassen(Matrix M1, Matrix M2, int size) {
  Matrix M3(size);
  Matrix p1(size / 2), p2(size / 2), p3(size / 2), p4(size / 2), p5(size / 2),
      p6(size / 2), p7(size / 2), temp1(size / 2), temp2(size / 2);
  //p1.init(size / 2), p2.init(size / 2), p3.init(size / 2), p4.init(size / 2), p5.init(size / 2),
   //   p6.init(size / 2), p7.init(size / 2), temp1.init(size / 2), temp2.init(size / 2);

  int q1, q2, q3, q4, q5, q6, q7, i, j;

  if (size >= 2) {
    // p1
    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i][j] + M1.pos[i + size / 2][j + size / 2];
      }
    }

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i][j] + M2.pos[i + size / 2][j + size / 2];
      }
    }

    size = size / 2;

    p1 = strassen(temp1, temp2, size / 2);
    // p2.pos
    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i + size / 2][j] + M1.pos[i + size / 2][j + size / 2];
      }
    }

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i][j];
      }
    }

    num = size / 2;

    p2 = strassen(temp1, temp2, size / 2);
    // p3.pos
    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i][j];
      }
    }

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i][j + size / 2] - M2.pos[i + size / 2][j + size / 2];
      }
    }

    num = size / 2;

    p3 = strassen(temp1, temp2, size / 2);
    // p4.pos
    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i + size / 2][j + size / 2];
      }
    }

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i + size / 2][j] - M2.pos[i][j];
      }
    }

    num = size / 2;

    p4 = strassen(temp1, temp2, size / 2);
    // p5.pos
    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i][j] + M1.pos[i][j + size / 2];
      }
    }

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i + size / 2][j + size / 2];
      }
    }
    
    num = size / 2;

    p5 = strassen(temp1, temp2, size / 2);

    // p6.pos

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i + size / 2][j] - M1.pos[i][j];
      }
    }

    num = size / 2;

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i][j] + M2.pos[i][j + size / 2];
      }
    }

    num = size / 2;

    p6 = strassen(temp1, temp2, size / 2);

    // p7.pos

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp1.pos[i][j] = M1.pos[i][j + size / 2] - M1.pos[i + size / 2][j + size / 2];
      }
    }

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        temp2.pos[i][j] = M2.pos[i + size / 2][j] + M2.pos[i + size / 2][j + size / 2];
      }
    }

    num = size / 2;

    p7 = strassen(temp1, temp2, size / 2);

    // c11

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        M3.pos[i][j] = p1.pos[i][j] + p4.pos[i][j] - p5.pos[i][j] + p7.pos[i][j];
      }
    }

    // c12

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        M3.pos[i][j + size / 2] = p3.pos[i][j] + p5.pos[i][j];
      }
    }

    // c21

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        M3.pos[i + size / 2][j] = p2.pos[i][j] + p4.pos[i][j];
      }
    }

    // c22

    for (i = 0; i < size / 2; i++) {
      for (j = 0; j < size / 2; j++) {
        M3.pos[i + size / 2][j + size / 2] =
            p1.pos[i][j] + p3.pos[i][j] - p2.pos[i][j] + p6.pos[i][j];
      }
    }

  } else if (size == 1) {
    M3.pos[0][0] = M1.pos[0][0] * M2.pos[0][0];
  }
  return M3;
}

bool check(int x) {
  if (x < 2) {
    return false;
  }
  
    while (x != 0 ) {
        if (x % 2 == 0) {
            x /= 2;
            if (x == 1) {
            return true;
            }
        }
        else {
          return false;
        }
    }
    return false;
    
}

int main() {
  int i, j, k, temp;
  cout << "Enter the size of nxn matrix:\n";
  cin>>num;

  if (!check(num)) {
    cout<<"Enter M1.pos positive no which can be expressed in powers of 2:\n";
    main();
  } else {
    Matrix M1(num), M2(num), M3(num), M4(num);
    cout<<"Allocating Random Values to Matrix1\n";
    
    for (i = 0; i < num; i++) {
      for (j = 0; j < num; j++) {
        M1.pos[i][j] = rand() % 10;
      }
      }
      cout<<"Allocating Random Values to Matrix2\n";
      
      for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
          M2.pos[i][j] = rand() % 10;
        }
      }

        printf("Matrix 1:\n");
        print(M1, num);
        printf("Matrix 2:\n");
        print(M2, num);

        clock_t t;
        t = clock();
        M3 = strassen(M1, M2, num);
        t = clock() - t;
        double time_taken =
            ((double)t) * 1000 / CLOCKS_PER_SEC; // calculate the elapsed time
        cout << "Strassen's matrix multiplication took " << time_taken
             << " miliseconds to execute\n";

        printf("\nMatrix 3 obtained from Strassens multiplication is:\n");
        print(M3, num);

       printf("\nMatrix 4 = M1.pos*M2.pos obtained from Normal multiplication is: \n ");
      
      pid_t pid = fork();
      if (pid == 0) {
        while (true) {
          cout << ". ";
          fflush(stdout);
          sleep(1);
        }
      } else{
        clock_t t2;
        t2 = clock();

        for (i = 0; i < num; i++) {
          for (j = 0; j < num; j++) {
            for (k = 0; k < num; k++) {
              M4.pos[i][j] = 0;
              M4.pos[i][j] += M1.pos[i][k] * M2.pos[k][j];
            }
          }
        }
        t2 = clock() - t2;

        double time_taken2 =
            ((double)t2) * 1000 / CLOCKS_PER_SEC; // calculate the elapsed time
        fflush(stdout);

        kill(pid, SIGKILL);
        cout << "\rNaive matrix multiplication took " << time_taken2
             << " miliseconds to execute\n";
        print(M4, num);
      }
      }
  return 0;
}
