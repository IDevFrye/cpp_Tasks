#include <iostream>

using namespace std;

void countingSort(int* array, int length)
{
  int max = INT_MIN, min = INT_MAX, index = 0;
  for (int i = 0; i < length; ++i)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
    if (array[i] < min)
    {
      min = array[i];
    }
  }
  int* PositivCounter = new int[max + 1] {};
  int* NegativCounter = new int[abs(min) + 1] {};
  for (int i = 0; i < length; ++i)
  {
    if (array[i] >= 0)
    {
      ++PositivCounter[array[i]];
    }
    else
    {
      ++NegativCounter[abs(array[i])];
    }
  }
  for (int i = abs(min); i > 0; --i)
  {
    for (int j = 0; j < NegativCounter[i]; ++j)
    {
      array[index++] = -i;
    }
  }
  for (int i = 0; i < max + 1; ++i)
  {
    for (int j = 0; j < PositivCounter[i]; ++j)
    {
      array[index++] = i;
    }
  }
  delete[] PositivCounter;
  delete[] NegativCounter;
}
bool isSortedArray(int* array, int length)
{
  for (std::size_t i = length - 1; i != 0; --i)
  {
    if (array[i] < array[i - 1])
    {
      return false;
    }
  }
  return true;
}
int main()
{
  std::setlocale(LC_ALL, "rus");
  cout << "===================|Сортировка подсчётом|===================\n\n";
  const int len1 = 8, len2 = 45, len3 = 25;
  int test1[len1] = { 1, 2, 4, 3, 6, 5, 0, 7 }, test3[len3] = { -2, 6, 7, 243, -34, 10, 41, -104, -98, 11, 52, 63, 74, 85, -120, 32, 99, -17, -1, 0, 13, 12, -8, -4, 21 }, test2[len2] = {};
  cout << "-------------------|Лучший случай|-------------------\nМассив до сортировки:\n";
  for (int i = 0; i < len1; ++i)
  {
    cout << test1[i] << " ";
  }
  cout << "\nПроверка на упорядоченность: " << std::boolalpha << isSortedArray(test1, len1);
  countingSort(test1, len1);
  cout << "\nМассив после сортировки:\n";
  for (int i = 0; i < len1; ++i)
  {
    cout << test1[i] << " ";
  }
  cout << "\nПроверка на упорядоченность: " << std::boolalpha << isSortedArray(test1, len1);
  cout << "\nСложность построенного алгоритма: O(" << len1 << ").";
  cout << "\n\n-------------------|Средний случай|-------------------\nМассив до сортировки:\n";
  for (int i = 0; i < len2; ++i)
  {
    test2[i] = rand() % 105 + (-55);
    cout << test2[i] << " ";
  }
  cout << "\nПроверка на упорядоченность: " << std::boolalpha << isSortedArray(test2, len2);
  countingSort(test2, len2);
  cout << "\nМассив после сортировки:\n";
  for (int i = 0; i < len2; ++i)
  {
    cout << test2[i] << " ";
  }
  cout << "\nПроверка на упорядоченность: " << std::boolalpha << isSortedArray(test2, len2);
  cout << "\nСложность построенного алгоритма: O(" << len2 << " + " << "("<< test2[len2 - 1] - test2[0] << ")" << ").";
  cout << "\n\n-------------------|Худший случай|-------------------\nМассив до сортировки:\n";
  srand(time(NULL));
  for (int i = 0; i < len3; ++i)
  {
    cout << test3[i] << " ";
  }
  cout << "\nПроверка на упорядоченность: " << std::boolalpha << isSortedArray(test3, len3);
  countingSort(test3, len3);
  cout << "\nМассив после сортировки:\n";
  for (int i = 0; i < len3; ++i)
  {
    cout << test3[i] << " ";
  }
  cout << "\nПроверка на упорядоченность: " << std::boolalpha << isSortedArray(test3, len3);
  cout << "\nСложность построенного алгоритма: O(" << len3 << " + " << "(" << test3[len3 - 1] - test3[0] << ")" << ").";
  cout << "\n";
}

