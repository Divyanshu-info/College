#include <iostream>
using namespace std;
class process {
  public:
    int id;
    int memory_required;
    int allocated_partition;
    int external_fragment;
    bool allocated;
};
class partition {
  public:
    int id;
    int size;
    int internal_fragment;
    bool alloted;
};
int main()
{
    int m, n_par, n_p, i, j, sum = 0;
    cout<<"Enter total memory: ";
    cin>>m;
    cout<<"Enter number of partitions: ";
    cin>>n_par;
    partition partition[n_par];
    for (i = 0; i < n_par; i++) {
        cout<<"Enter memory for partition " << i + 1 << " ";
        cin>>partition[i].size;
        partition[i].id = i + 1;
        partition[i].alloted = false;

        sum += partition[i].size;
    }
    if (sum < m) {
        n_par++;
        partition[i].size = m - sum;
        partition[i].id = i + 1;
        partition[i].alloted = false;
        cout << "Size of partition " << i << ": " << partition[i].size<<endl;
    }
    int total_internal_fragment = 0, total_external_fragment = 0;
    cout<<"Enter number of processes: ";
    cin>>n_p;
    process process[n_p];
    for (i = 0; i < n_p; ++i) {
        cout<<"Enter memory required for process " << i + 1 << " ";
        cin>>process[i].memory_required;
        process[i].id = i + 1;
        process[i].external_fragment = 0;
        process[i].allocated = false;
        for (j = 0; j < n_par; j++) {
            if (process[i].memory_required <= partition[j].size && !partition[j].alloted) {
                process[i].allocated = true;
                process[i].allocated_partition = partition[j].id;
                partition[j].internal_fragment = partition[j].size - process[i].memory_required;
                total_internal_fragment += partition[j].internal_fragment;
                partition[j].alloted = true;
                break;
            }
        }
        for (j = 0; j < n_par; j++) {
            if (partition[j].alloted == false) {
                process[i].external_fragment += partition[j].size;
            }
        }
    }
    for (j = 0; j < n_par; j++) {
        if (!partition[j].alloted) {
            total_external_fragment += partition[j].size;
            partition[j].internal_fragment = -1;
        }
    }
    cout<<"ProcessID\tMemory required\tAllocated\tAllocated Partition\n";
    for (i = 0; i < n_p; i++) {
      if (process[i].allocated) {
          cout << process[i].id << "\t\t" << process[i].memory_required << "\t\t\tYES\t" << process[i].allocated_partition << "\t\n";
        } else {
            cout << process[i].id << "\t\t" << process[i].memory_required << "\t\t\tNO\t" << process[i].external_fragment << endl;
        }
    }
    cout<<"\n";
    cout<<"Internal Fragmentation\n";
    for (i = 0; i < n_par; i++) {
        if (partition[i].internal_fragment == -1) {
            cout<<" ---\n"<< partition[i].id;
        } else
            cout<<partition[i].id << " " << partition[i].internal_fragment<<endl;
    }
    cout << "\nTotal internal Fragmentation: " << total_internal_fragment << "\nTotal external Fragmentation: " << total_external_fragment << "\n";
}