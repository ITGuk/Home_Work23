//Create a function that allows you to insert a block
//elements, starting from an arbitrary index of the array

#include <iostream>

using namespace std;

void Rand_mas(int* arr, int& size);
void ShowArr(int* arr, int& size);
void AddElement(int* arr, int* new_array, int& size);
void Show_New_Mas(int* new_array, int& size);

int main()
{
    int size = 5;
    int* arr = new int[size];
    int* new_array = new int[size + 1];
    Rand_mas(arr, size);
    ShowArr(arr, size);
    AddElement(arr, new_array, size);
    Show_New_Mas(new_array, size);
}

void Rand_mas(int* arr, int& size)//Add random nums
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }
}

void AddElement(int* arr, int* new_array, int& size)//Add new blok
{
    int element;
    cout << "Press index: ";
    int index;
    cin >> index;
    for (int i = 0; i < index; i++)
    {
        new_array[i] = arr[i];
    }
    int ind1 = index;
    int cont = 0;
    while (true)
    {
        cout << "Press new element: ";
        cin >> element;
        if (element == 0)
        {
            break;
        }
        new_array[ind1] = element;
        ind1++;
        cont++;
    }
    for (int i = ind1,j = index; i < size + ind1; i++, j++)
    {
        new_array[i] = arr[j];
    }

    size += cont;

    delete[] arr;//Delete old array
    arr = new_array;//Delete index old massiv
}

void ShowArr(int* arr, int& size)//Show old massiv
{
    cout << "Old massiv: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Show_New_Mas(int* new_array, int& size)//Show new massiv
{
    cout << "New massiv: ";
    for (int i = 0; i < size; i++)
    {
        cout << new_array[i] << " ";
    }
    cout << endl;
    //delete[] new_array;//Delete new array
}