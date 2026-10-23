#include <iostream>

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        bool keyIsEven = key % 2 == 0;

        while (j >= 0 &&
               ((keyIsEven && arr[j] % 2 != 0) ||
                (keyIsEven == (arr[j] % 2 == 0) && arr[j] > key)))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int FindLargestSmaller(const int values[], int n, int target)
{

    int left = 0;
    int right = n - 1;
    int result = -1; // Inicializar el resultado como -1 (no encontrado)

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] < target)
        {
            result = mid;   // Actualizar el resultado
            left = mid + 1; 
        }
        else
        {
            right = mid - 1; 
        }
    }

    return result; 
}

int main()
{
    int arr[] = {8, 5, 2, 7, 4, 1, 6};
    int values[] = {2, 4, 4, 7, 9, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int index = FindLargestSmaller(values, sizeof(values) / sizeof(values[0]), 2);
    std::cout << "El índice del mayor elemento estrictamente menor que target es: " << index << std::endl;

    return 0;
}