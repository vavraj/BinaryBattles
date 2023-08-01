#include <iostream>
#include<queue>
using namespace std;

class heap
{
    int arr[100];
    int size;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteroot()
    {
        if (size == 0)
        {
            cout << "empty heap" << endl;
            return;
        }

        // step1: put last node to root node
        arr[1] = arr[size];

        // step2: delete last node
        size--;

        // step3: put root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
                return;
        }
    }
};
// indexing at 1
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// indexing at 0
void heapify_0(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify_0(arr, n, smallest);
    }
}

void heapsort(vector<int> &arr, int n)
{
    int size=n;
    while(size>1)
    {
        // step1
        swap(arr[1],arr[size]);

        // step2
        size--;

        // step3
        heapify(arr,size,1);

    }

}
int main()
{
    // heap h;
    // h.insert(60);
    // h.insert(50);
    // h.insert(40);
    // h.insert(30);
    // h.insert(20);

    // h.print();
    // h.insert(55);
    // h.print();

    // h.deleteroot();
    // h.print();

    vector<int> arr;
    arr.push_back(-1);
    arr.push_back(54);
    arr.push_back(53);
    arr.push_back(55);
    arr.push_back(52);
    arr.push_back(50);

    // 1 indexing

    int n = 5;
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << " ";
    } 
    cout<<endl;

    // 0 indexing

    // int n=6;
    // for(int i=n/2-1;i>=0;i--)
    // {
    //     heapify_0(arr,n,i);
    // }

    heapsort(arr,arr.size()-1);
    for(int i=1;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    // using stl

    // maxheap
    priority_queue<int>maxheap;

    maxheap.push(2);
    maxheap.push(6); 
    maxheap.push(3);
    maxheap.push(4);
    maxheap.push(1);

    cout<<"Top element "<<maxheap.top()<<endl;

    maxheap.pop();

    cout<<"Top element "<<maxheap.top()<<endl;

    // minheap

    priority_queue<int,vector<int>,greater<int> >minheap;
    minheap.push(2);
    minheap.push(1);
    minheap.push(5);
    minheap.push(-1);  
    minheap.push(10);
    cout<<"Top element of minheap"<<minheap.top()<<endl;

    return 0;
}