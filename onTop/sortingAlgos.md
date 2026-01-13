| Algorithm          | Best Case | Average | Worst | Space | Stable | In-Place |
| ------------------ | --------- | ------- | ----- | ----- | ------ | -------- |
| **Bubble Sort**    | O(n)      | O(n²)   | O(n²) | O(1)  | ✅ Yes  | ✅ Yes    |
| **Insertion Sort** | O(n)      | O(n²)   | O(n²) | O(1)  | ✅ Yes  | ✅ Yes    |
| **Selection Sort** | O(n²)     | O(n²)   | O(n²) | O(1)  | ❌ No   | ✅ Yes    |

## Bubble Sort 
- is one of the simplest sorting algorithms.
- It works by repeatedly swapping adjacent elements if they are in the wrong order—just like bubbles rising to the surface 🫧.
```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps, array is already sorted
        if (!swapped)
            break;
    }
}
```
> 📌 Idea: Largest element “bubbles” to the end after each pass.

## 🟢 2. Insertion Sort (C++)
> 📌 Idea: Insert each element into its correct position in the sorted part.
```c
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

3. 🟠 3. Selection Sort (C++)
> 📌 Idea: Repeatedly select the minimum element and place it at the front.
```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
```
## 🔵 Merge Sort (C++)
- Divide array into halves
- Sort each half
- Merge sorted halves
- 
| Feature        | Merge Sort | Quick Sort |
| -------------- | ---------- | ---------- |
| Time (Best)    | O(n log n) | O(n log n) |
| Time (Average) | O(n log n) | O(n log n) |
| Time (Worst)   | O(n log n) | O(n²)      |
| Space          | O(n)       | O(log n)   |
| Stable         | ✅ Yes      | ❌ No       |
| In-Place       | ❌ No       | ✅ Yes      |

## 🟢 Quick Sort (C++)
- Pick a pivot
- Place pivot in correct position
- Recursively sort left & right subarrays

