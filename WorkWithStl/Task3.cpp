#include <iostream>
#include <vector>
#include <numeric>   // для inner_product
#include <functional> // для plus, equal_to

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите размер списка: ";
    cin >> n;

    vector<int> list1(n), list2(n);

    cout << "Введите элементы первого списка:" << endl;
    for (int i = 0; i < n; i++)
        cin >> list1[i];

    cout << "Введите элементы второго списка:" << endl;
    for (int i = 0; i < n; i++)
        cin >> list2[i];

    // Подсчёт количества попарно равных элементов с помощью inner_product
    int count = inner_product(list1.begin(), list1.end(), list2.begin(), 0,
        plus<int>(), equal_to<int>());

    cout << "Количество попарно равных элементов: " << count << endl;

    return 0;
}