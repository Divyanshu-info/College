#include <stdbool.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#define N 1000
class process {
    public:
    int Process_id;
    int size;
    bool allocated;
};

class slots {
  public:
    int Process_id; //-1 if free
    int size;
};

process Process[N];
slots Slots[N];
int Max_size, n, tot;

int external_fragment()
{
    int Fragmented_value = 0;
    for (int i = 0; i < tot; i++)
        if (Slots[i].Process_id == -1)
            Fragmented_value += Slots[i].size;
    return Fragmented_value;
}

void insert(int Position, int Process_id)
{
    for (int i = tot; i > Position; i--)
        Slots[i] = Slots[i - 1];

    Slots[Position].Process_id = Process_id;
    Slots[Position].size = Process[Process_id].size;
    Process[Process_id].allocated = true;

    Slots[Position + 1].size -= Process[Process_id].size;
    tot++;
}

int get_slot(int Process_id)
{
    int Position = -1, mini = 1e9;
    for (int i = 0; i < tot; i++)
        if (Slots[i].Process_id == -1 && Slots[i].size >= Process[Process_id].size && mini > Slots[i].size) {
            Position = i;
            mini = Slots[i].size;
        }

    return Position;
}

int free_slot(int Position)
{
    Slots[Position].Process_id = -1;

    if (Position != tot - 1 && Slots[Position + 1].Process_id == -1) {
        Slots[Position].size += Slots[Position + 1].size;
        for (int i = Position + 1; i < tot - 1; i++)
            Slots[i] = Slots[i + 1];

        tot--;
    }

    if (Position > 0 && Slots[Position - 1].Process_id == -1) {
        Slots[Position - 1].size += Slots[Position].size;
        for (int i = Position; i < tot - 1; i++)
            Slots[i] = Slots[i + 1];

        tot--;
    }
    return Position;
}



void print_memory_table()
{
    cout<<"\n\n====== Memory Table ==========\n";
    cout<<"Size\t|\tProcess\n";
    cout<<"============================== \n";
    for (int i = 0; i < tot; i++) {
        cout << Slots[i].size  << "\t|\t";
        if (Slots[i].Process_id == -1)
            cout<<"None\n";
        else
            cout << Slots[i].Process_id + 1 << "\n";
    }

    cout<<("============================== \n");
}

int main()
{
    system("clear");
    int Max_size, n = 0, ch;

    cout<<"Enter the total size of memory : ";
    cin>>Max_size;

    tot = 1;
    
    Slots[0].Process_id = -1;
    Slots[0].size = Max_size;

    do {
        cout<<("\n1. Add new processs\n2. Remove existing process\nEnter your choice : ");
        cin>>ch;

        if (ch == 1) {
            cout<<"\nEnter new process size : ";
            cin>>Process[n].size;
            Process[n].Process_id = n;
            Process[n].allocated = false;

            int Position = get_slot(n);
            if (Position == -1)
                cout<<"\nNot enough contiguous memory to allocate memory to process\n";
            else if (Slots[Position].size == Process[n].size) {
                Process[n].allocated = true;
                Slots[Position].Process_id = n;
            } else
                insert(Position, n);

            print_memory_table();
            n++;
            cout<<"External Fragmentation "<< external_fragment();
        } else if (ch == 2) {
            int prem;
            cout<<"\nWhich process would you like to remove? ";
            cin>>prem;
            prem--;

            for (int i = 0; i < tot; i++)
                if (Slots[i].Process_id == prem)
                    free_slot(i);

            print_memory_table();
            cout << "External Fragmentation " << external_fragment();
        }

    } while (ch == 1 || ch == 2);
}