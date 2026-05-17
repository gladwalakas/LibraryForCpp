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

// Вставка узла в BST
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

// Построение дерева из списка
Node* buildBST(const vector<int>& arr) 
{
    Node* root = nullptr;
    for (int x : arr) 
        root = insert(root, x);
    
    return root;
}

// Функция поиска пути от корня до узла X
vector<int> findPath(Node* root, int X) 
{
    vector<int> path;
    Node* current = root;

    while (current) {

        path.push_back(current->key);

        if (X == current->key) 
   
            return path;  // Узел найден, возвращаем путь
        
        else if (X < current->key)
            current = current->left;  // Идем в левое поддерево
        
        else 
            current = current->right; // Идем в правое поддерево
        
    }

    path.clear(); // Узел не найден
    return path;
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    
    // Создаем дерево
    vector<int> numbers = { 50, 30, 70, 20, 40, 60, 80 };
    Node* root = buildBST(numbers);

    // Ищем путь до узла 40
    int X = 40;
    vector<int> path = findPath(root, X);

    if (!path.empty()) 
    {
        cout << "Путь от корня до узла " << X << ": ";
        for (int i = 0; i < path.size(); i++) 
        {
            cout << path[i];
            if (i < path.size() - 1) 
                cout << " -> ";
        }
        cout << endl;
    }

    else 
        cout << "Узел " << X << " не найден в дереве" << endl;
    

    return 0;
}