#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int> arr) {
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout << "\nBubble Sort Result: ";
    for(int x : arr)
        cout << x << " ";
}

// Selection Sort
void selectionSort(vector<int> arr) {
    int n = arr.size();

    for(int i=0; i<n-1; i++) {
        int minIndex = i;

        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "\nSelection Sort Result: ";
    for(int x : arr)
        cout << x << " ";
}

// Insertion Sort
void insertionSort(vector<int> arr) {
    int n = arr.size();

    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "\nInsertion Sort Result: ";
    for(int x : arr)
        cout << x << " ";
}

// Merge Function
void merge(vector<int>& arr, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i=0;i<n1;i++)
        L[i] = arr[left+i];

    for(int j=0;j<n2;j++)
        R[j] = arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i<n1)
        arr[k++] = L[i++];

    while(j<n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {

    if(left < right) {

        int mid = left + (right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++) {

        if(arr[j] < pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);

    return i+1;
}

void quickSort(vector<int>& arr,int low,int high) {

    if(low < high) {

        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main() {

    int n;

    cout<<"Enter Number of Elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter Elements:\n";

    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Bubble Sort
    auto start1 = high_resolution_clock::now();
    bubbleSort(arr);
    auto end1 = high_resolution_clock::now();

    // Selection Sort
    auto start2 = high_resolution_clock::now();
    selectionSort(arr);
    auto end2 = high_resolution_clock::now();

    // Insertion Sort
    auto start3 = high_resolution_clock::now();
    insertionSort(arr);
    auto end3 = high_resolution_clock::now();

    // Merge Sort
    vector<int> mergeArr = arr;

    auto start4 = high_resolution_clock::now();
    mergeSort(mergeArr,0,n-1);
    auto end4 = high_resolution_clock::now();

    cout<<"\nMerge Sort Result: ";
    for(int x: mergeArr)
        cout<<x<<" ";

    // Quick Sort
    vector<int> quickArr = arr;

    auto start5 = high_resolution_clock::now();
    quickSort(quickArr,0,n-1);
    auto end5 = high_resolution_clock::now();

    cout<<"\nQuick Sort Result: ";
    for(int x: quickArr)
        cout<<x<<" ";

    cout<<"\n\nExecution Time Comparison\n";

    cout<<"\nBubble Sort: "
        << duration_cast<nanoseconds>(end1-start1).count()
        <<" ns";

    cout<<"\nSelection Sort: "
        << duration_cast<nanoseconds>(end2-start2).count()
        <<" ns";

    cout<<"\nInsertion Sort: "
        << duration_cast<nanoseconds>(end3-start3).count()
        <<" ns";

    cout<<"\nMerge Sort: "
        << duration_cast<nanoseconds>(end4-start4).count()
        <<" ns";

    cout<<"\nQuick Sort: "
        << duration_cast<nanoseconds>(end5-start5).count()
        <<" ns";

    return 0;
}
