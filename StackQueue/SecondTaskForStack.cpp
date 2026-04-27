#include <iostream>
using namespace std;

class Stack
{
private:
    int* data;
    int capacity;
    int size;

    void Resize()
    {
        int newCapacity = capacity == 0 ? 4 : capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack() : data(nullptr), capacity(0), size(0) {}

    ~Stack()
    {
        delete[] data;
    }

    void Push(int value)
    {
        if (size == capacity)
            Resize();
        data[size++] = value;
    }

    void Pop()
    {
        if (IsEmpty())
            throw "Stack is empty";
        --size;
    }

    int Top() const
    {
        if (IsEmpty())
            throw "Stack is empty";
        return data[size - 1];
    }

    bool IsEmpty() const
    {
        return size == 0;
    }

    int Count() const
    {
        return size;
    }

    // Возвращает копию внутреннего массива (порядок: от дна к вершине)
    int* ToArray(int& outSize) const
    {
        outSize = size;
        int* arr = new int[size];
        for (int i = 0; i < size; ++i)
            arr[i] = data[i];
        return arr;
    }

    void Clear()
    {
        size = 0;
    }

    void Print() const
    {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");

    // Исходные данные (пример из условия)
    int example[] = { 2, 8, 4, 1, 2, 8, 8, 1, 2, 8 };
    int n = sizeof(example) / sizeof(example[0]);

    Stack stack;
    for (int i = 0; i < n; ++i)
        stack.Push(example[i]);

    cout << "Исходный стек (дно -> вершина): ";
    stack.Print();

    // Получаем массив элементов в порядке ввода
    int size;
    int* arr = stack.ToArray(size);

    // Поиск максимального и минимального значений
    int maxVal = arr[0];
    int minVal = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    // Поиск позиций первого и последнего максимального элемента
    int firstMaxPos = -1;
    int lastMaxPos = -1;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == maxVal)
        {
            if (firstMaxPos == -1)
                firstMaxPos = i;
            lastMaxPos = i;
        }
    }

    // Формирование новой последовательности с вставками
    int newSize = size;
    if (firstMaxPos != -1)
        newSize++; // вставка после первого максимума
    if (lastMaxPos != -1 && lastMaxPos != firstMaxPos)
        newSize++; // вставка после последнего максимума (если он не совпадает с первым)

    int* newArr = new int[newSize];
    int newIdx = 0;
    for (int i = 0; i < size; ++i)
    {
        newArr[newIdx++] = arr[i];
        if (i == firstMaxPos)
            newArr[newIdx++] = minVal;
        if (i == lastMaxPos && lastMaxPos != firstMaxPos)
            newArr[newIdx++] = minVal;
    }

    // Очищаем стек и заполняем его новой последовательностью
    stack.Clear();
    for (int i = 0; i < newSize; ++i)
        stack.Push(newArr[i]);

    cout << "Стек после преобразования (дно -> вершина): ";
    stack.Print();

    // Освобождение памяти
    delete[] arr;
    delete[] newArr;

    return 0;
}