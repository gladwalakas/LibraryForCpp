#include <iostream>
using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    // Конструктор копирования (глубокое копирование)
    Queue(const Queue& other) : front(nullptr), rear(nullptr), count(0)
    {
        Node* current = other.front;
        while (current)
        {
            push(current->data);
            current = current->next;
        }
    }

    ~Queue()
    {
        clear();
    }

    void push(int val)
    {
        Node* newNode = new Node(val);
        if (isEmpty())
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
    }

    void pop()
    {
        if (isEmpty())
            return;
        Node* temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        --count;
    }

    int frontValue() const
    {
        if (isEmpty())
            throw "Queue is empty";
        return front->data;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    int size() const
    {
        return count;
    }

    int lastValue() const
    {
        if (isEmpty())
            throw "Queue is empty";
        return rear->data;
    }

    int findMin() const
    {
        if (isEmpty())
            throw "Queue is empty";
        Node* current = front;
        int minVal = current->data;
        while (current)
        {
            if (current->data < minVal)
                minVal = current->data;
            current = current->next;
        }
        return minVal;
    }

    // Возвращает массив значений (память выделяется динамически)
    int* toArray(int& outSize) const
    {
        outSize = count;
        int* arr = new int[count];
        Node* current = front;
        for (int i = 0; i < count; ++i)
        {
            arr[i] = current->data;
            current = current->next;
        }
        return arr;
    }

    void clear()
    {
        while (!isEmpty())
            pop();
    }

    void print() const
    {
        Node* current = front;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");

    // Исходные данные
    int example[] = { 8, 2, 1, 6, 8, 8, 1, 2, 2, 8, 2 };
    int n = sizeof(example) / sizeof(example[0]);

    Queue original;
    for (int i = 0; i < n; ++i)
        original.push(example[i]);

    cout << "Исходная очередь: ";
    original.print();

    int last = original.lastValue();
    int minVal = original.findMin();

    cout << "Последний элемент: " << last << std::endl;
    cout << "Минимальный элемент: " << minVal << std::endl;

    // Получаем массив значений исходной очереди
    int size;
    int* values = original.toArray(size);

    // Строим новую очередь
    Queue result;
    for (int i = 0; i < size; ++i)
    {
        if (values[i] == last)
        {
            result.push(minVal);
            result.push(values[i]);
        }
        else
        {
            result.push(values[i]);
        }
    }

    cout << "Результирующая очередь: ";
    result.print();

    delete[] values;

    return 0;
}