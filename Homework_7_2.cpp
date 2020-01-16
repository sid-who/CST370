/*
 * Repl.it link: https://repl.it/@sidwho/Homework-72-370
 * Title: hw7_2.cpp
 * Abstract: This program generates an array of a size defined by the user
 *           in either ascending, descending, or random order. It then sorts 
 *           that array in 3 different ways: Merge Sort, Insertion Sort, and
 *           Quick Sort. It displays the time elasped for each sort.
 * Author: Gurpreet Sidhu
 * ID: 2486
 * Date: 10/24/2019
 */

#include <iostream>
#include <chrono>

using namespace std;

/*
** The Insertion Sort Method is adapted from a program
** created by Geeks for Geeks, it can be found @
** https://www.geeksforgeeks.org/insertion-sort/
*/
void insertionSort(int arr[], int size)
{
    int i, key, j;
    auto start = chrono::steady_clock::now();  
    for(i = 1; i < size; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }
    auto end = chrono::steady_clock::now();
    //cout << "Insertion Sort: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "\n"; 

    float temptime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    float finaltime = temptime/1000000;
    cout << "Insertion Sort: " << finaltime << " milliseconds \n";
}

/**
** The Merge Sort method and the Merge method
** are sampled from Geeks for Geeks @
** https://www.geeksforgeeks.org/merge-sort/
*/
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{  
    //auto start = chrono::steady_clock::now(); 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r);
    }
    //auto end = chrono::steady_clock::now();

    /*float temptime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    float finaltime = temptime/1000000;
    cout << "Merge Sort: " << finaltime << " milliseconds \n";*/  
} 
//=========END THE MERGE SORT SECTION================//

/**
** The Quick Sort method is lifted from 
** Geeks for Geeks. It can be found @
** https://www.geeksforgeeks.org/quick-sort/
*/
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}
//==============END QUICKSORT BLOCK============//  

void process(int size, int order)
{
    int *frame;
    frame = new int[size];

    if(order == 1)
    {
        //cout << "Asc. Works";
        cout << "\n" << "============================================================" << "\n";
        for(int i=0; i<size; i++)
        {
            frame[i] = i;
        }
        insertionSort(frame, size);

        auto start = chrono::steady_clock::now();
        mergeSort(frame, 0, size - 1);
        auto end = chrono::steady_clock::now();
        float temptime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        float finaltime = temptime/1000000;
        cout << "Merge Sort: " << finaltime << " milliseconds \n";

        auto start1 = chrono::steady_clock::now();
        quickSort(frame, 0, size -1);
        auto end1 = chrono::steady_clock::now();
        float temptime1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        float finaltime1 = temptime1/1000000;
        cout << "Quick Sort: " << finaltime1 << " milliseconds \n";

        cout << "============================================================";
    }
    else if(order == 2)
    {
        //cout << "Desc. Works";
        cout << "\n" << "============================================================" << "\n";
        int original = size -1;
        int i = size - 1;
        for(; i >= 0; i--)
        {
            frame[original-i] = i;
        }
        insertionSort(frame, size);

        auto start = chrono::steady_clock::now();
        mergeSort(frame, 0, size - 1);
        auto end = chrono::steady_clock::now();
        float temptime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        float finaltime = temptime/1000000;
        cout << "Merge Sort: " << finaltime << " milliseconds \n";

        auto start1 = chrono::steady_clock::now();
        quickSort(frame, 0, size -1);
        auto end1 = chrono::steady_clock::now();
        float temptime1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        float finaltime1 = temptime1/1000000;
        cout << "Quick Sort: " << finaltime1 << " milliseconds \n";

        cout << "============================================================";
    }
    else if (order == 3)
    {
        //cout << "Random Works";
        cout << "\n" << "============================================================" << "\n";
        int randHelper = size * 1000;
        for(int i=0; i< size; i++)
        {
            frame[i] = rand() % randHelper;
        }
        
        insertionSort(frame, size);

        auto start = chrono::steady_clock::now();
        mergeSort(frame, 0, size - 1);
        auto end = chrono::steady_clock::now();
        float temptime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        float finaltime = temptime/1000000;
        cout << "Merge Sort: " << finaltime << " milliseconds \n";

        auto start1 = chrono::steady_clock::now();
        quickSort(frame, 0, size -1);
        auto end1 = chrono::steady_clock::now();
        float temptime1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        float finaltime1 = temptime1/1000000;
        cout << "Quick Sort: " << finaltime1 << " milliseconds \n";

        cout << "============================================================";
    }

}

int main() 
{
    int inputSize;
    int order;

    cout << "Enter input size: ";
    cin >> inputSize;

    cout << "========== Select Order of Input Numbers ==========" << endl;
    cout << "\t" << "1. Ascending Order" << endl;
    cout << "\t" << "2. Descending Order" << endl;
    cout << "\t" << "3. Random Order" << endl;

    cout << "Choose Order: " ;
    cin >> order;

    cout << "============================================================" <<endl;

    switch(order)
    {
        case 1: cout << "Generate input data in ascending order . . ." << "\n" << "Done. \n";
                cout << "============================================================" <<endl;
                break;
        case 2: cout << "Generate input data in descending order . . ." << "\n" << "Done. \n";
                cout << "============================================================" <<endl;
                break;
        case 3: cout << "Generate input data in random order . . ." << "\n" << "Done. \n";
                cout << "============================================================" <<endl;
                break;
    }

    process(inputSize, order);
}
