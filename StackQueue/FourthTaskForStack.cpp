#include <iostream>
using namespace std;

class Stack
{
private:
    int* data;      
    int capacity;   
    int count;      

    void resize()
    {
        int newCapacity = capacity == 0 ? 4 : capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i < count; ++i)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack() : data(nullptr), capacity(0), count(0) {}

    ~Stack()
    {
        delete[] data;
    }

    // Добавление элемента на вершину
    void push(int value)
    {
        if (count == capacity)
            resize();
        data[count++] = value;
    }

    // Удаление элемента с вершины
    void pop()
    {
        if (isEmpty())
            throw "Стэк пуст";
        --count;
    }

    // Чтение элемента с вершины
    int top() const
    {
        if (isEmpty())
            throw "Стэк пуст";
        return data[count - 1];
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    int size() const
    {
        return count;
    }

    // Доступ к элементу по индексу (0 – дно, size()-1 – вершина)
    int get(int index) const
    {
        if (index < 0 || index >= count)
            throw "Индекс вне диапазона";
        return data[index];
    }

    // Получение копии внутреннего массива (от дна к вершине)
    int* toArray(int& outSize) const
    {
        outSize = count;
        int* arr = new int[count];
        for (int i = 0; i < count; ++i)
            arr[i] = data[i];
        return arr;
    }

    // Вывод стека от дна к вершине
    void printBottomToTop() const
    {
        for (int i = 0; i < count; ++i)
            cout << data[i] << " ";
        cout << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");

    // Ввод исходного стека
    int n;
    cout << "Введите количество элементов стека: ";
    cin >> n;

    Stack original;
    cout << "Введите целые числа: ";
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        original.push(x);
    }

    cout << "Исходный стек: ";
    original.printBottomToTop();

    // Ввод нового элемента для вставки
    int newElement;
    cout << "Введите элемент, который нужно вставить: ";
    cin >> newElement;

    // Поиск позиции первого нечётного элемента 
    int insertPos = -1;
    for (int i = 0; i < original.size(); ++i)
    {
        if (original.get(i) % 2 != 0)
        {
            insertPos = i;
            break;
        }
    }

    if (insertPos == -1)
    {
        cout << "В стеке нет нечётных элементов. Новый стек будет копией исходного";
        Stack newStack;
        for (int i = 0; i < original.size(); ++i)
            newStack.push(original.get(i));

        cout << "Новый стек: ";
        newStack.printBottomToTop();
    }
    else
    {
        // Создаём новый стек, вставляя новый элемент после первого нечётного
        Stack newStack;
        for (int i = 0; i < original.size(); ++i)
        {
            newStack.push(original.get(i));
            if (i == insertPos)
                newStack.push(newElement);
        }

        cout << "Первый нечётный элемент находится на позиции " << insertPos;
        cout << "Новый стек после вставки: ";

        newStack.printBottomToTop();
    }

    return 0;
}