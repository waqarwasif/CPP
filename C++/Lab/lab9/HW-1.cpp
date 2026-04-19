#include <iostream>
#include <string>
using namespace std;

class Node
{
    string Data;
    int Priority_No;

public:
    Node(string d, int n) : Data(d), Priority_No(n) {}
    Node() : Data(""), Priority_No(0) {}

    int getPriority() { return Priority_No; }
    string getData() { return Data; }
};

class Priority_Queue
{
    Node *arr;
    int capacity;
    int size;

public:
    Priority_Queue(int c) : capacity(c), size(0)
    {
        arr = new Node[capacity];
    }
    ~Priority_Queue()
    {
        delete[] arr;
    }

    void Enqueue(string data, int priority)
    {
        if (size == capacity)
        {
            cout << "Queue is full, cannot enqueue more elements." << endl;
            return;
        }
        Node newNode(data, priority);
        int i = size - 1; // Start from the end of the queue
        // Searching for the position to insert new node
        while (i >= 0 && arr[i].getPriority() > priority)
        {
            arr[i + 1] = arr[i]; // shifting right
            i--;
        }
        arr[i + 1] = newNode;
        size++;
        cout << "Enqueued: \"" << data << "\" with priority " << priority << endl;
    }

    void Dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty, cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: \"" << arr[0].getData()
             << "\" with priority " << arr[0].getPriority() << endl;
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
};

int main()
{
    Priority_Queue pq(5);

    cout << " Enqueue Operations " << endl;
    pq.Enqueue("Do laundry", 4);
    pq.Enqueue("Fix server", 1); // highest priority
    pq.Enqueue("Reply emails", 2);
    pq.Enqueue("Buy groceries", 3);
    pq.Enqueue("Read book", 5);

    cout << endl<<" Overflow Test " << endl;
    pq.Enqueue("Extra task", 2);

    cout << endl<<" Dequeue Operations " << endl;
    pq.Dequeue(); // should give priority 1
    pq.Dequeue(); // should give priority 2
    pq.Dequeue(); // should give priority 3

    cout << endl<<" Dequeue Remaining " << endl;
    pq.Dequeue();
    pq.Dequeue();
    cout << endl<<" Underflow Test " << endl;
    pq.Dequeue();

    return 0;
}