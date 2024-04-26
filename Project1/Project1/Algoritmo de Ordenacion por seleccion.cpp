#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    int max_index;

    for (int i = n - 1; i >= 1; i--)
    {
        max_index = i;
     
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[max_index]) 
            {
                max_index = j;
            }
        }
        swap(arr[max_index], arr[i]);
    }
}

int main() 
{
    vector<int> arr = { 64, 25, 12, 22, 11 }; // Lista de ejemplo
    cout << "Array original: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    selectionSort(arr); 

    cout << "Array ordenado: ";
    for (int num : arr) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
