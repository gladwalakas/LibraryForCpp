#include <iostream>
#include <vector>
using namespace std;

struct Node 
{
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

// Вставка узла в BST (оставлено без изменений)
Node* insert(Node* root, int key) 
{
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Построение BST из массива (без изменений)
Node* buildBST(const vector<int>& arr) 
{
    Node* root = nullptr;
    for (int x : arr)
        root = insert(root, x);
    return root;
}

// Рекурсивное удаление всего дерева (оставлено)
void deleteTree(Node* root) 
{

    if (!root)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// In-order обход (вывод в отсортированном порядке)
void inorderPrint(Node* root) 
{
    if (!root)
        return;

    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

// Поиск минимального ключа в дереве (предполагается, что root != nullptr)
int getMin(Node* root) 
{
    while (root->left) 
        root = root->left;

    return root->key;
}

// Стандартное удаление узла по ключу (возвращает новый корень поддерева)
Node* deleteNode(Node* root, int key) 
{
    if (!root) 
        return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else 
    {
        // Нашли узел, который нужно удалить
        if (!root->left) 
        {
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        }

        else if (!root->right) 
        {
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        }

        else 
        {
            // У узла два потомка: заменяем его минимальным элементом из правого поддерева
            int minRight = getMin(root->right);
            root->key = minRight;
            root->right = deleteNode(root->right, minRight);
        }
    }
    return root;
}

// Объединение двух BST, где все ключи left < все ключи right
Node* join(Node* left, Node* right) 
{
    if (!left) 
        return right;

    if (!right)
        return left;

    // Берём минимальный ключ из правого дерева
    int minRight = getMin(right);
    // Удаляем этот ключ из правого дерева
    right = deleteNode(right, minRight);
    // Создаём новый узел-корень, который связывает left и right
    Node* newRoot = new Node(minRight);
    newRoot->left = left;
    newRoot->right = right;
    return newRoot;
}

// Удаление всех чётных элементов из дерева (рекурсивное, с сохранением BST)
Node* removeEvenNumbers(Node* root)
{
    if (!root) 
        return nullptr;

    // Сначала очищаем от чётных левое и правое поддеревья
    root->left = removeEvenNumbers(root->left);
    root->right = removeEvenNumbers(root->right);
    // Если текущий узел чётный — удаляем его, объединяя left и right
    if (root->key % 2 == 0) 
    {
        Node* newRoot = join(root->left, root->right);
        delete root;
        return newRoot;
    }

    else 
        return root;
}

int main() {
    setlocale(LC_ALL, "RUS");

    vector<int> numbers = { 50, 25, 75, 12, 37, 62, 87, 4, 18, 30, 44, 55, 68, 80, 95 };
    Node* root = buildBST(numbers);

    cout << "Исходное дерево (in-order обход): ";
    inorderPrint(root);
    cout << endl;

    // Удаляем чётные элементы
    root = removeEvenNumbers(root);

    cout << "Дерево после удаления чётных чисел (только нечётные): ";
    inorderPrint(root);
    cout << endl;

    // Освобождаем память
    deleteTree(root);

    return 0;
}