/*
Íàïèøèòå ïðîãðàììó ïåðåáèðàþùóþ âñå ïåðåñòàíîâêè ìàññèâà áóêâ â ëåêñèêîãðàôè÷åñêîì ïîðÿäêå.
Ïðîãðàììà äîëæíà ðàáîòàòü íå áîëåå ÷åì çà O(n!*n) øàãîâ.
*/

#include <iostream>
#include <iterator>

using namespace std;

void func(int n, char* arr)
{
    for (int i = 0; i < n - 1; i++) 
      for (int j = 0; j < n - i - 1; j++) 
         if (arr[j] > arr[j + 1]) 
         {
            char temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }  
}

int main()
{
    char* arr = new char;
    
    cout << "Enter letters without spaces" << endl;
    
    cin.getline(arr, size_t(arr));
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    func(n, arr);
   
    for (int i = 0; i < n; i++)
       cout << arr[i];
   
    delete [] arr;
   
   return 0;
}

/*
Ïîëüçóåìñÿ ìåòîäîì ñîðòèðîâêè "Ïóçûð¸ê"
*/
