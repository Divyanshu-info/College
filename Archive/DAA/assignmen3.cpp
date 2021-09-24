#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

vector<int> values;             
vector<int> capacities;         
vector<vector<int>> solution_Table;

void pick(int No_of_items, int Max_Capacity) {
  if (No_of_items <= 0 || Max_Capacity <= 0)
    return;

  int k = solution_Table[No_of_items][Max_Capacity];
  if (k != solution_Table[No_of_items - 1][Max_Capacity]) {
    cout << No_of_items << " ";
    pick(No_of_items - 1, Max_Capacity - capacities[No_of_items]);
  } else {
     pick(No_of_items - 1, Max_Capacity);
  }
}

int main() {

  int Max_Capacity, No_of_items;
  int Weight, Value;

  capacities.push_back(-1);
  values.push_back(-1);

  cout << "Input Total No of items " << endl;
  cin >> No_of_items;
  cout << "Input Max Capacity of knapsack "<<endl;
  cin >> Max_Capacity;

  cout << "Total No. of items\t\t" << No_of_items
       << "\nMax Capacity of Knapsack\t" << Max_Capacity << endl;
  for (int i = 1; i <= No_of_items; ++i) {
    cout << "Input weight of item " << i << " ";
    cin >> Weight;
    cout << "Input Value of item " << i << " ";
    cin >> Value;
    capacities.push_back(Weight);
    values.push_back(Value);
  }
  for (int i = 1; i <= No_of_items; i++)
  {
    cout << "item : " << i << "\t\tValue : " << values[i]
         << "\t\tWeight : " << capacities[i] << endl;
  }


  solution_Table.resize(No_of_items + 1, vector<int>(Max_Capacity + 1, 0));

  auto start = high_resolution_clock::now();
  
  for (int i = 1; i <= No_of_items; i++) {
    for (int w = 1; w <= Max_Capacity; w++) {
      if (capacities[i] > w) {
        solution_Table[i][w] = solution_Table[i - 1][w];
      } else {
        solution_Table[i][w] = max(solution_Table[i - 1][w], values[i] + solution_Table[i - 1][w - capacities[i]]);
      }
    }
  }
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);

  cout << "The maximum profit found is : " << endl;
  cout << solution_Table[No_of_items][Max_Capacity] << endl;
  cout << "The selected items are : ";
  pick(No_of_items, Max_Capacity);
  cout << endl;
  cout << "Execution time : " << duration.count() << " Nanoseconds"<<endl;
  }