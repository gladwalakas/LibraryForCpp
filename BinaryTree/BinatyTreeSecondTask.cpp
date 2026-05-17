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

Node* buildBST(const vector<int>& arr) 
{
    Node* root = nullptr;
    for (int x : arr) 
        root = insert(root, x);
    
    return root;
}

// Функция вычисления суммы внутренних узлов
int sumInternalNodes(Node* root) 
{
    if (!root) 
        return 0;  // Базовый случай: пустое дерево

    int sum = 0;

    if (root->left != nullptr || root->right != nullptr) 
    
        sum += root->key;  // Добавляем значение текущего узла
    

    // Рекурсивно обходим левое и правое поддеревья
    sum += sumInternalNodes(root->left);
    sum += sumInternalNodes(root->right);

    return sum;
}

int main() 
{
    setlocale(LC_ALL, "RUS");

    // Создаем дерево
    vector<int> numbers = { 50, 30, 70, 20, 40, 60, 80, 15, 25, 55, 65 };
    Node* root = buildBST(numbers);

    int result = sumInternalNodes(root);
    cout << "Сумма внутренних узлов: " << result << endl;

    cout << "\nКлючи узлов дерева:\n";
    cout << "Листья (без потомков): ";


    return 0;
}