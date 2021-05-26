#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char[]);
using namespace std;
struct hole {
    int start, size, mark;
    bool filled;
    hole* next;
};
int total = 0; 
class MemorySeg {
    hole* head = NULL;

public:
    MemorySeg()
    {
        int i;
        hole *p, *q;
        for (i = 0; i < 10; i++) {
            if (head == NULL) 
            {
                p = (hole*)malloc(sizeof(hole));
                p->start = 0;
                p->size = 1 + random() % 16;
                total += p->size;
                p->filled = false;
                p->next = NULL;
                head = p;
            } else 
            {
                p = head;
                int s = 0;
                while (p->next != NULL) {
                    s += p->size;
                    p = p->next;
                }
                q = (hole*)malloc(sizeof(hole));
                q->size = 1 + random() % 16;
                total += q->size;
                q->start = s + (p->size);
                q->filled = false;
                q->next = NULL;
                p->next = q;
            }
        }
    }
    void display()
    {
        cout << "Total mem avail=" << total << endl;
        hole* p = head;
        while (p != NULL) {
            cout << p->start << "  " << p->size << " " << p->mark << endl;
            p = p->next;
            
        }
        cout << "\nSegment tables\n"; 
        p = head;
        int i;
        for (i = 1; i < 10; i++) {
            p = head;
            while (p != NULL) {
                if ((p->mark) / 10 == i) {
                    cout << "Process:" << i << " Segment:" << (p->mark) % 10 << " Base:" << p->start << " Limit:" << p->size << endl;
                }
                p = p->next;
            }
        }
    }
    void allocBest(int id, int tdh, int data)
    {
        //Best fit
        char a[10];
        switch (tdh) {
        case 0:
            strcpy(a, "Text");
            break;
        case 1:
            strcpy(a, "Data");
            break;
        case 2:
            strcpy(a, "Heap");
            break;
        }
        cout << "Allocating " << a << " for process no. " << id << endl;
        hole *p = head, *temp;
        int flag = 0, min = 99999;
        while (p != NULL) {
            if (!(p->filled) && (p->size) < min && (p->size) >= data) {
                min = p->size;
                temp = p;
                flag = 1;
            }
            p = p->next;
        }
        if (flag == 0) {
            if (total < data)
                cout << "Error:Memory not available\n";
            else
                cout << "Error:Memory not available due to external fragmentation\n";
        } else {
            p = temp;
            p->mark = id * 10 + tdh;
            p->filled = true;

            if (p->size != data) {
                int a = pow2(data);
                if ((p->size) > a) {
                    hole* q;
                    q = (hole*)malloc(sizeof(hole));
                    q->start = p->start + a;
                    q->size = p->size - a;
                    p->size = a;
                    q->next = p->next;
                    q->filled = false;
                    p->next = q;
                }
                cout << (p->size) - data << " units of memory lost due to internal fragmentation\n";
            }
        }
    }

    void allocFirst(int id, int tdh, int data) 
    {
        char a[10];
        switch (tdh) {
        case 0:
            strcpy(a, "Text");
            break;
        case 1:
            strcpy(a, "Data");
            break;
        case 2:
            strcpy(a, "Heap");
            break;
        }
        cout << "Allocating " << a << " for process no. " << id << endl;
        hole* p = head;
        int flag = 0;
        while (p != NULL) {
            if ((p->size) >= data && !p->filled) {
                p->mark = id * 10 + tdh;
                p->filled = true;
                flag = 1;
                break;
            }

            p = p->next;
        }
        if (flag == 0) {
            if (total < data)
                cout << "Error:Exceeding total memory\n";
            else
                cout << "Error:Memory not available due to external fragmentation\n";
        }

        else {
            if (p->size != data) {
                int a = pow2(data);
                if ((p->size) > a) {
                    hole* q;
                    q = (hole*)malloc(sizeof(hole));
                    q->start = p->start + a;
                    q->size = p->size - a;
                    p->size = a;
                    q->next = p->next;
                    q->filled = false;
                    p->next = q;
                }
                cout << (p->size) - data << " units of memory lost due to internal fragmentation\n";
            }
        }
    }

    void allocWorst(int id, int tdh, int data)
    {
        char a[10];
        switch (tdh) {
        case 0:
            strcpy(a, "Text");
            break;
        case 1:
            strcpy(a, "Data");
            break;
        case 2:
            strcpy(a, "Heap");
            break;
        }
        cout << "Allocating " << a << " for process no. " << id << endl;
        hole *p = head, *temp;
        int flag = 0, max = data;
        while (p != NULL) {
            if (!(p->filled) && (p->size) >= max) {
                max = p->size;
                temp = p;
                flag = 1;
            }
            p = p->next;
        }
        if (flag == 0) {
            if (total < data)
                cout << "Error:Memory not available\n";
            else
                cout << "Error:Memory not available due to external fragmentation\n";
        } else {
            p = temp;
            p->mark = id * 10 + tdh;
            p->filled = true;
            if (p->size != data) {
                int a = pow2(data);
                if ((p->size) > a) {
                    hole* q;
                    q = (hole*)malloc(sizeof(hole));
                    q->start = p->start + a;
                    q->size = p->size - a;
                    p->size = a;
                    q->next = p->next;
                    q->filled = false;
                    p->next = q;
                }
                cout << (p->size) - data << " units of memory lost due to internal fragmentation\n";
            }
        }
    }
    void dealloc(int id)
    {
        hole* p = head;
        int flag = 0;
        while (p != NULL) {
            if ((p->mark) / 10 == id) {
                flag = 1;
                p->filled = false;
                p->mark = 0;
            }
            p = p->next;
        }
        if (flag == 0)
            cout << "Process not found\n";
        compact();
    }
    void compact() 
    {
        hole *p = head, *q, *r;
        while (p->next != NULL) {
            q = p->next;
            if (q != NULL) {
                if (!(p->filled) && !(q->filled)) {
                    (p->size) += (q->size);
                    p->next = q->next;
                    free(q);
                } else
                    p = p->next;
            }
        }
    }
    int pow2(int a)
    {
        if (a > 8)
            return 16;
        if (a > 4)
            return 8;
        if (a > 2)
            return 4;
        return a;
    }
};

int main()
{
    srand(time(NULL));
    MemorySeg Memory;
    cout << "\nThe initial memory partition:\n";
    Memory.display();
    int choice, algorithm_choice, text_size, data_size, heap_size, id = 1, pid;

    while (1) {
        cout << "\nEnter choice:\n1>New process\n2>Deallocate\n3>Exit\n";
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "\nEnter text, data and heap size\n";
            cin >> text_size >> data_size >> heap_size;
            cout << "\nEnter 1 for First Fit,2 for Best fit and 3 for worst fit\n";
            cin >> algorithm_choice;
            switch (algorithm_choice) {
            case 1:
                Memory.allocFirst(id, 0, text_size);
                Memory.allocFirst(id, 1, data_size);
                Memory.allocFirst(id, 2, heap_size);
                Memory.display();
                break;
            case 2:
                Memory.allocBest(id, 0, text_size);
                Memory.allocBest(id, 1, data_size);
                Memory.allocBest(id, 2, heap_size);
                Memory.display();
                break;
            case 3:
                Memory.allocWorst(id, 0, text_size);
                Memory.allocWorst(id, 1, data_size);
                Memory.allocWorst(id, 2, heap_size);
                Memory.display();
                break;
            }
            id++;
            break;
        case 2:
            cout << "Enter id of process to deallocate\n";
            cin >> pid;
            Memory.dealloc(pid);

            Memory.display();
            break;
        case 3:
            exit(0);
        }
    }
}