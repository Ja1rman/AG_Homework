/*
Напишите программу перебирающую все перестановки массива букв в лексикографическом порядке.
Программа должна работать не более чем за O(n!*n) шагов.
*/

#include <iostream>

using namespace std;

int main()
{
   char arr[] = "sgfedcba";
   int size = sizeof(arr) / sizeof(arr[0]) - 1;

   for (int i = 0; i < size - 1; i++)
      for (int j = 0; j < size - i - 1; j++)
         if (arr[j] > arr[j + 1])
         {
            char temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }

   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";

   return 0;
}

/*
Пользуемся методом сортировки "Пузырёк"
*/
