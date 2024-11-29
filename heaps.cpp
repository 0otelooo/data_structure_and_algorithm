#include <iostream>
#include <vector>
using namespace std;

void displayTree(vector <int>& tree){

for (int i=0; i<0, i<tree.size(); ++i){
cout<<tree[i]<<" ";
}
cout<<endl;
}

void minHeapify(vector<int>& heap, int n, int i) {
    int lowest = i;        // lowest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // Check if the left child exists and is greater than the root
    if (left < n && heap[left] > heap[lowest]) {
        lowest = left;
    }

    // Check if the right child exists and is greater than the smallest so far
    if (right < n && heap[right] > heap[lowest]) {
        lowest = right;
    }

    // If the smallest is not the root, swap and recursively heapify
    if (lowest != i) {
        swap(heap[i], heap[lowest]);
        minHeapify(heap, n, lowest);
    }
}

void heapSort(vector<int>& heap) {
    int n = heap.size();

    // Build a min heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(heap, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (minimum) to the end
        swap(heap[0], heap[i]);

        // Call minHeapify on the reduced heap
        minHeapify(heap, i, 0);
    }
}

// Function to display the tree/array
void displayTree(const vector<int>& tree) {
    for (int i = 0; i < tree.size(); ++i) {
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main(){
cout<<endl<<endl;
cout<<"Age of each of my family members (max heap): ";
vector <int> tree={59,32,23,20,17,15};
displayTree(tree);

cout<<"After sorting it from youngest to oldest(min-heap): ";
heapSort(tree);


displayTree(tree);



return 0;

}
