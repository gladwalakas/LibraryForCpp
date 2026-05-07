#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void InputVector(const vector<int>& vec)
{
    for (int num : vec)
        cout << num << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите размера списка: ";
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    //1
    cout << "Исходная последовательность";

    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    //2 
    int a, b, x;

    cout << "Введите границы интервала: ";
    cin >> a >> b;
    cout << "Введите число для замены: ";
    cin >> x;

    for (int& num : numbers)
        if (num >= a && num <= b)
            num = x;

    cout << "После замены";
    InputVector(numbers);

    //3

    sort(numbers.begin(), numbers.end());
    cout << "После сортировки:";
    InputVector(numbers);

    //4
    int newElement;
    cout << "Введите новый элемент: ";
    cin >> newElement;

    auto insertPos = upper_bound(numbers.begin(), numbers.end(), newElement);
    numbers.insert(insertPos, newElement);

    cout << "После вставки: ";
    InputVector(numbers);

    //5

    vector<int> uniqueNumbers;
    for (size_t i = 0; i < numbers.size(); i++)
        if (i == 0 || numbers[i] != numbers[i - 1])
            uniqueNumbers.push_back(numbers[i]);
    cout << "После удаления повторов: ";
    InputVector(uniqueNumbers);

    return 0;

}


