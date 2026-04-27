#include <iostream>
#include <deque>

using namespace std;

class Queue
{
private:
    deque<int> _container;

public:
    void Enqueue(int value)
    {
        _container.push_back(value);
    }

    void Dequeue()
    {
        if (IsEmpty())
            throw "Queue is empty";
        _container.pop_front();
    }

    int Peek() const
    {
        if (IsEmpty())
            throw "Queue is empty";
        return _container.front();
    }

    bool IsEmpty() const
    {
        return _container.empty();
    }

    int Count() const
    {
        return _container.size();
    }

    void Print() const
    {
        for (int value : _container)
            cout << value << " ";
        cout << endl;
    }

    // Возвращает индекс (с 0) первого минимального элемента
    int FindFirstMinPosition() const
    {
        if (IsEmpty())
            return -1;

        int minValue = _container[0];
        int minPos = 0;

        for (size_t i = 1; i < _container.size(); ++i)
        {
            if (_container[i] < minValue)
            {
                minValue = _container[i];
                minPos = i;
            }
        }
        return minPos;
    }

    // Циклический сдвиг влево на k позиций
    void RotateLeft(int k)
    {
        if (IsEmpty() || k <= 0)
            return;

        k %= Count();
        for (int i = 0; i < k; ++i)
        {
            int value = Peek();
            Dequeue();
            Enqueue(value);
        }
    }
};

int main()
{
    int example[] = { 2, 5, 1, 4, 5, 3, 4, 5, 2, 1 };
    int n = sizeof(example) / sizeof(example[0]);

    Queue q;
    for (int i = 0; i < n; ++i)
        q.Enqueue(example[i]);

    cout << "Исходная очередь: ";
    q.Print();

    int minPos = q.FindFirstMinPosition();
    cout << "Позиция первого минимального элемента (с 0): " << minPos << endl;

    q.RotateLeft(minPos);

    cout << "Очередь после циклического сдвига: ";
    q.Print();

    return 0;
}