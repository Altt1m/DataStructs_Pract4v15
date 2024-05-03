#include <iostream>;

using namespace std;

// 15.1 | Знайти добуток цифр введеного числа, використовуючи рекурсію
int digitProduct(int number)
{
    // Якщо число однозначне, повертаємо його як добуток
    if (number < 10)
    {
        return number;
    }
    // Рекурсивно викликаємо функцію для решти числа
    else
    {
        return (number % 10) * digitProduct(number / 10);
    }
}

void Task1()
{
    int number;
    std::cout << "Input number: ";
    std::cin >> number;

    int product = digitProduct(number);
    std::cout << "Mult of digits of " << number << " = " << product << std::endl;
}

// 15.2 | Дан масив дійсних чисел A розміру N. Напишіть рекурсивну функцію, яка знаходить добуток елементів масиву.
double arrayProduct(double arr[], int size)
{
    // Якщо масив порожній, повертаємо 1
    if (size == 0)
    {
        return 1.0;
    }
    // Множимо перший елемент на добуток решти масиву
    else
    {
        return arr[0] * arrayProduct(arr + 1, size - 1);
    }
}

void Task2()
{
    // Створюємо масив з введеним розміром
    const int size = 5;
    double arr[size];
    std::cout << "Input array elements:\n";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    // Обчислюємо добуток елементів масиву та виводимо результат
    double product = arrayProduct(arr, size);
    std::cout << "Mult of elements = " << (int)product << std::endl;
}

// 15.3 | Побудувати бінарне дерево пошуку з вхідної послідовності цілих чисел.
//Вивести значення вузлів дерева, кратних 3, а також номери рівня для кожного такого вузла.
struct Tree
{
    int data;
    Tree* left, * right;
};

void ShowTree(Tree*& tree)
{
    if (tree != NULL)
    {
        ShowTree(tree->left);
        cout << tree->data << ' ';
        ShowTree(tree->right);
    }
}

void Show(Tree* tree, int level)
{
    if (tree != NULL)
    {
        Show(tree->left, level + 1);

        if (tree->data % 3 == 0)
        {
            cout << "Value: " << tree->data << ", Level: " << level << endl;
        }

        Show(tree->right, level + 1);
    }
}

void PrintTree(Tree* tree, int& n)
{
    if (tree != NULL)
    {
        n++;
        PrintTree(tree->left, n);
        for (int i = 1; i <= n; i++) cout << " ";
        cout << tree->data << endl;
        PrintTree(tree->right, n);
        n--;
    }
}

void Add_node(int x, Tree*& tree)
{
    if (NULL == tree)
    {
        tree = new Tree;
        tree->data = x;
        tree->left = tree->right = NULL;
    }

    if (x < tree->data)
    {
        if (tree->left != NULL) Add_node(x, tree->left);
        else
        {
            tree->left = new Tree;
            tree->left->left = tree->left->right = NULL;
            tree->left->data = x;
        }
    }

    if (x > tree->data)
    {
        if (tree->right != NULL) Add_node(x, tree->right);
        else
        {
            tree->right = new Tree;
            tree->right->left = tree->right->right = NULL;
            tree->right->data = x;
        }
    }
}


void Delete(Tree*& tree)
{
    if (tree != NULL)
    {
        Delete(tree->left);
        Delete(tree->right);
        delete tree;
        tree = NULL;
    }
}

void Task3()
{
    Tree* root = NULL;

    int number;
    int countLvl = 7;

    cout << "Input 7 numbers: " << endl;

    for (int i = 1; i <= countLvl; i++)
    {
        cin >> number;
        Add_node(number, root);
    }

    cout << "\nBinary tree from 7 values: \n";
    PrintTree(root, countLvl);

    cout << "\nBinary tree from 7 values: \n";
    ShowTree(root);

    cout << "\n\nNodes in the tree that are multiples of 3:\n";
    Show(root, 0);

    cout << "\nThe root of a binary tree: " << root->data << endl;

    Delete(root);

    PrintTree(root, countLvl);
}

int main()
{
    //Task1();
    //Task2();
    Task3();
}
