//The array is given: А[M] (M is entered from the keyboard).
//The user enters data into the array, as well as by
//using the menu decides what to delete from
//array to choose from :
//● Paired elements
//● Odd element
//● Maximum element
//● Minimal element
//● Elements greater than the median of the array
//● Elements smaller than the median of the array

#include <iostream>

using namespace std;

void Creat_mas(int* arr, int& size);
void Del_even(int* arr, int& size);
void Del_odd(int* arr, int& size);
void Del_max(int* arr, int& size);
void Del_min(int* arr, int& size);
void Max_Med(int* arr, int& size);
void Min_Med(int* arr, int& size);
void ShowArray(int* new_arr, int& size);

int main()
{
    int size = 10;
    int* arr = new int[size];
    Creat_mas(arr, size);
    int vubir;
    cout << "Press 1 - Paired elements." << endl <<
        "Press 2 - Odd element." << endl <<
        "Press 3 - Delete maximum element." << endl <<
        "Press 4 - Delete minimum element." << endl <<
        "Press 5 - Elements greater than the median of the array." << endl <<
        "Press 6 - Elements smaller than the median of the array." << endl << 
        endl;

    cin >> vubir;
    bool check = true;
    while (check)
    {
        if (vubir == 1)
        {
            Del_even(arr, size);
            check = false;
        }
        if (vubir == 2)
        {
            Del_odd(arr, size);
            check = false;
        }
        if (vubir == 3)
        {
            Del_max(arr, size);
            check = false;
        }
        if (vubir == 4)
        {
            Del_min(arr, size);
            check = false;
        }
        if (vubir == 5)
        {
            Max_Med(arr, size);
            check = false;
        }
        if (vubir == 6)
        {
            Min_Med(arr, size);
            check = false;
        }
    }
}

void Creat_mas(int* arr, int& size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 500;
    }
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void Del_even(int* arr, int& size)
{
    int* new_arr = new int[size / 2];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            new_arr[j] = arr[i];
            j++;
        }      
    }
    size /= 2;
    ShowArray(new_arr, size);
    delete[] arr;
    new_arr = arr;
    delete[] new_arr;
}

void Del_odd(int* arr, int& size)
{
    int* new_arr = new int[size / 2];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (i % 2 != 0)
        {
            new_arr[j] = arr[i];
            j++;
        }
    }
    size /= 2;
    ShowArray(new_arr, size);
    delete[] arr;
    new_arr = arr;
    delete[] new_arr;
}

void Del_max(int* arr, int& size)
{
    int* new_arr = new int[size];
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
            }
        }
    }
    for (int i = 0,j = 0; i < size; i++)
    {
        if (arr[i] != max)
        {
            new_arr[j] = arr[i];
            j++;
        }
    }
    size--;
    cout << endl << "Maximum: " << max << endl << endl;
    ShowArray(new_arr, size);
    delete[] arr;
    new_arr = arr;
    delete[] new_arr;
}

void Del_min(int* arr, int& size)
{
    int* new_arr = new int[size];
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
            }
        }
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        if (arr[i] != min)
        {
            new_arr[j] = arr[i];
            j++;
        }
    }
    size--;
    cout << endl << "Minimum: " << min << endl << endl;
    ShowArray(new_arr, size);
    delete[] arr;
    new_arr = arr;
    delete[] new_arr;
}

void Max_Med(int* arr, int& size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    sum /= size;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > sum)
        {
            for (int j = i; j < size - 1; ++j)
            {
                swap(arr[j], arr[j + 1]);
            }
            size -= 1;
            i--;
        }
    }
    ShowArray(arr, size);
    delete[] arr;
}

void Min_Med(int* arr, int& size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    sum /= size;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < sum)
        {
            for (int j = i; j < size - 1; j++)
            {
                swap(arr[j], arr[j + 1]);
            }
            size -= 1;
            i--;
        }
    }
    ShowArray(arr, size);
    delete[] arr;
}

void ShowArray(int* arr, int& size)
{
    cout << endl << "New Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}