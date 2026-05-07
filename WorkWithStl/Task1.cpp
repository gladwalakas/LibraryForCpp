#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int CountMaxNumber(const vector<int> numbers) 
{
    if (numbers.empty())
        return 0;

    int maxValue = *max_element(numbers.begin(), numbers.end());

    return count(numbers.begin(), numbers.end(), maxValue);
}

    
int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размеры списка: ";
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    int result = CountMaxNumber(numbers);
    cout << "Количество максимальных чисел: " << result << endl;

    return 0;
}


