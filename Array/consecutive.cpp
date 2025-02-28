#include <iostream>
using namespace std;

int consecutive(int arr[], int n) { 
    int count = 1;  
    int maxx = INT16_MIN;  

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;  
        } else {
            count = 1;  
        }
        maxx = max(count, maxx);  
    }

    return maxx;  // Return outside the loop
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 3};  
    int size = sizeof(arr) / sizeof(arr[0]);  

    cout << "Longest consecutive count: " << consecutive(arr, size) << endl;  
    return 0;
}