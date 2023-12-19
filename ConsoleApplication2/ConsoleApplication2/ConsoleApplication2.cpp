// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"


#include <iostream>
#include <string>
#include <functional>
using namespace std;

struct Dictionary
{
	unsigned int num;
	string eng;
	string rus;
};

struct Node
{
	Dictionary data;
	Node* left;
	Node* right;
};

void PrintTree(Node* p)
{
	if (p == nullptr)
		return;

	PrintTree(p->right);

	cout << p->data.eng << "    " << p->data.rus << "    " << p->data.num << endl;

	PrintTree(p->left);
}

void InsertNode(Node*& root, Dictionary R)
{
	if (root == nullptr)
	{
		root = new Node;
		root->data = R;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		if (root->data.eng < R.eng)
		{
			InsertNode(root->right, R);
		}
		else if (root->data.eng > R.eng)
		{
			InsertNode(root->left, R);
		}
		else
		{
			cout << "this element already exist" << endl;
		}
	}
}

void RemoveNode(Node*& root, unsigned int value)
{
	if (root != nullptr)
	{
		if (root->data.num != value)
		{
			RemoveNode(root->left, value);
			RemoveNode(root->right, value);
		}
		else
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
			}
			else if (root->left == nullptr)
			{
				Node* wasNext = root->right;
				delete root;
				root = wasNext;
			}
			else if (root->right == nullptr)
			{
				Node* wasNext = root->left;
				delete root;
				root = wasNext;
			}
			else
			{
				Node* wasNext;
				Dictionary R;

				if (root->right->left == nullptr)
				{
					R = root->right->data;
					wasNext = root->right;
					root->right = root->right->right;
					delete wasNext;
				}
				else
				{
					wasNext = root->right;
					Node* minNode = wasNext->left;

					while (minNode->left != nullptr)
					{
						wasNext = minNode;
						minNode = minNode->left;
					}

					R = minNode->data;
					wasNext->left = minNode->right;
					delete minNode;
				}

				root->data = R;
			}
		}
	}
}

Node* GetMaxValue(Node* r)
{
	if (r == nullptr)
		return nullptr;

	Node* found = r;

	std::function<void(Node*)> findMax = [&](Node* n)
	{
		if (n == nullptr)
			return;

		if (found->data.num < n->data.num)
			found = n;

		findMax(n->left);
		findMax(n->right);
	};

	findMax(r);
	return found;
}

void MoveNode(Node* p, Node* pnew)
{
	Node* pmax;

	do
	{
		pmax = GetMaxValue(p);

		if (pmax != nullptr)
		{
			cout << pmax->data.eng << endl;
			InsertNode(pnew, pmax->data);
			RemoveNode(p, pmax->data.num);
		}

	} while (p != nullptr);
}

void DisplayMenu() {
	cout << "===== Menu =====" << endl;
	cout << "1. Add word" << endl;
	cout << "2. Delete word" << endl;
	cout << "3. Print tree" << endl;
	cout << "4. Form new dictionary" << endl;
	cout << "5. Exit" << endl;
	cout << "================" << endl;
}

int main() {
	Node* root = nullptr;
	Node* rootnew = nullptr;
	Dictionary rec1;
	int choice;

	DisplayMenu();

	do
	{
		cout << endl << "Input your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Input number: ";
			cin >> rec1.num;
			cout << "Input english word: ";
			cin.ignore();
			getline(cin, rec1.eng);
			cout << "Input russian word: ";
			getline(cin, rec1.rus);
			InsertNode(root, rec1);
			cout << "Word added" << endl;
			break;

		case 2:
			unsigned int value;
			cout << "Input number of word to delete: ";
			cin >> value;
			RemoveNode(root, value);
			cout << "Word deleted" << endl;
			break;

		case 3:
			cout << "===== Tree =====" << endl;
			PrintTree(root);
			break;

		case 4:
			MoveNode(root, rootnew);
			cout << "New tree" << endl;
			break;

		case 5:
			cout << "Exit" << endl;
			break;

		default:
			cout << "Incorrect choice. Try again." << endl;
			break;

		}
	} while (choice != 5);

	return 0;
}


#pragma region SMTH
//#include <iostream>
//#include <string>
//using namespace std;
//
// Структура для представления узла двоичного дерева
//struct Node {
//    string englishWord;
//    string russianWord;
//    int counter;
//    Node* left;
//    Node* right;
//
//     Конструктор узла
//    Node(string eng, string rus, int cnt = 0) {
//        englishWord = eng;
//        russianWord = rus;
//        counter = cnt;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
// Класс для представления англо-русского словаря на основе двоичного дерева
//class Dictionary {
//private:
//    Node* root; // Корневой узел
//
//     Рекурсивная функция для вставки узла в дерево
//    Node* insertNode(Node* node, string eng, string rus, int cnt) {
//        if (node == nullptr) {
//            return new Node(eng, rus, cnt);
//        }
//
//         Сравнение английских слов для определения положения узла в дереве
//        if (eng < node->englishWord) {
//            node->left = insertNode(node->left, eng, rus, cnt);
//        }
//        else if (eng > node->englishWord) {
//            node->right = insertNode(node->right, eng, rus, cnt);
//        }
//
//        return node;
//    }
//
//     Функция для поиска компоненты с наибольшим значением счетчика обращений
//    Node* findMaxCountNode(Node* node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//
//        Node* maxNode = node;
//
//        Node* leftMax = findMaxCountNode(node->left);
//        Node* rightMax = findMaxCountNode(node->right);
//
//        if (leftMax != nullptr && leftMax->counter > maxNode->counter) {
//            maxNode = leftMax;
//        }
//
//        if (rightMax != nullptr && rightMax->counter > maxNode->counter) {
//            maxNode = rightMax;
//        }
//
//        return maxNode;
//    }
//
//     Рекурсивная функция для удаления узла из дерева
//    Node* deleteNode(Node* node, string eng) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//
//        if (eng < node->englishWord) {
//            node->left = deleteNode(node->left, eng);
//        }
//        else if (eng > node->englishWord) {
//            node->right = deleteNode(node->right, eng);
//        }
//        else {
//            if (node->left == nullptr) {
//                Node* temp = node->right;
//                delete node;
//                return temp;
//            }
//            else if (node->right == nullptr) {
//                Node* temp = node->left;
//                delete node;
//                return temp;
//            }
//
//            Node* temp = findMaxCountNode(node->left);
//            node->englishWord = temp->englishWord;
//            node->russianWord = temp->russianWord;
//            node->counter = temp->counter;
//            node->left = deleteNode(node->left, temp->englishWord);
//        }
//
//        return node;
//    }
//
//     Рекурсивная функция для формирования нового словаря с сортировкой по максимальной компоненте
//    void formNewDictionaryHelper(Node* node, Dictionary& newDict) {
//        if (node != nullptr) {
//            formNewDictionaryHelper(node->left, newDict);
//            newDict.addNode(node->englishWord, node->russianWord, node->counter);
//            formNewDictionaryHelper(node->right, newDict);
//        }
//    }
//
//public:
//     Конструктор словаря
//    Dictionary() {
//        root = nullptr;
//    }
//
//     Метод для добавления узла в словарь
//    void addNode(string eng, string rus, int cnt) {
//        root = insertNode(root, eng, rus, cnt);
//    }
//
//     Метод для удаления узла из словаря
//    void deleteNode(string eng) {
//        root = deleteNode(root, eng);
//    }
//
//     Метод для формирования нового представления словаря
//    Dictionary formNewDictionary() {
//        Dictionary newDict;
//        formNewDictionaryHelper(root, newDict);
//        return newDict;
//    }
//
//     Метод для вывода словаря на экран
//    void displayDictionary() {
//        displayNode(root);
//    }
//
//private:
//     Рекурсивная функция для вывода узлов дерева на экран (инфиксный обход)
//    void displayNode(Node* node) {
//        if (node != nullptr) {
//            displayNode(node->left);
//            cout << "English: " << node->englishWord << ", Russian: " << node->russianWord << ", Counter: " << node->counter << endl;
//            displayNode(node->right);
//        }
//    }
//};
//
// Функция для вывода меню и обработки пользовательского ввода
//void displayMenu() {
//    cout << "===== Menu =====" << endl;
//    cout << "1. Add word" << endl;
//    cout << "2. Delete word" << endl;
//    cout << "3. Form new dictionary" << endl;
//    cout << "4. Display original dictionary" << endl;
//    cout << "5. Exit" << endl;
//    cout << "================" << endl;
//}
//
//int main() {
//    Dictionary dict;
//    Dictionary newDict;
//    int choice;
//    string eng, rus;
//    int cnt;
//
//    while (true) {
//        displayMenu();
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "Enter English word: ";
//            cin >> eng;
//            cout << "Enter Russian word: ";
//            cin >> rus;
//            cout << "Enter counter: ";
//            cin >> cnt;
//            dict.addNode(eng, rus, cnt);
//            break;
//        }
//        case 2: {
//            cout << "Enter English word to delete: ";
//            cin >> eng;
//            dict.deleteNode(eng);
//            break;
//        }
//        case 3: {
//            newDict = dict.formNewDictionary();
//            cout << "New dictionary formed." << endl;
//            newDict.displayDictionary();
//            break;
//        }
//        case 4: {
//            cout << "Original dictionary:" << endl;
//            dict.displayDictionary();
//            break;
//        }
//        case 5: {
//            cout << "Exiting program." << endl;
//            return 0;
//        }
//        default: {
//            cout << "Invalid choice. Please try again." << endl;
//            break;
//        }
//        }
//
//        cout << endl;
//    }
//
//    return 0;
//}
#pragma endregion

#pragma region SecondLab
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct Node 
//{
//    string englishWord;
//    string russianWord;
//    int counter;
//    Node* left;
//    Node* right;
//
//    Node(const string& eng, const string& rus, int cnt = 0) 
//        : englishWord(eng), russianWord(rus) 
//    {
//        counter = cnt;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//class Dictionary 
//{
//private:
//    Node* root; 
//
//    Node* InsertNode(Node* node, string eng, string rus, int cnt) 
//    {
//        if (node == nullptr) {
//            return new Node(eng, rus, cnt);
//        }
//
//        if (eng < node->englishWord) 
//        {
//            node->left = InsertNode(node->left, eng, rus, cnt);
//        }
//        else if (eng > node->englishWord) 
//        {
//            node->right = InsertNode(node->right, eng, rus, cnt);
//        }
//
//        return node;
//    }
//
//    Node* FindMaxCountNode(Node* node) 
//    {
//        if (node == nullptr) 
//        {
//            return nullptr;
//        }
//
//        Node* maxNode = node;
//
//        Node* leftMax = FindMaxCountNode(node->left);
//        Node* rightMax = FindMaxCountNode(node->right);
//
//        if (leftMax != nullptr && leftMax->counter > maxNode->counter) 
//        {
//            maxNode = leftMax;
//        }
//
//        if (rightMax != nullptr && rightMax->counter > maxNode->counter) 
//        {
//            maxNode = rightMax;
//        }
//
//        return maxNode;
//    }
//
//    Node* deleteNode(Node* node, string eng) 
//    {
//        if (node == nullptr) 
//        {
//            return nullptr;
//        }
//
//        if (eng < node->englishWord) 
//        {
//            node->left = deleteNode(node->left, eng);
//        }
//        else if (eng > node->englishWord) 
//        {
//            node->right = deleteNode(node->right, eng);
//        }
//        else 
//        {
//            if (node->left == nullptr) 
//            {
//                Node* temp = node->right;
//                delete node;
//                return temp;
//            }
//            else if (node->right == nullptr)
//            {
//                Node* temp = node->left;
//                delete node;
//                return temp;
//            }
//
//            Node* temp = FindMaxCountNode(node->left);
//            node->englishWord = temp->englishWord;
//            node->russianWord = temp->russianWord;
//            node->counter = temp->counter;
//            node->left = deleteNode(node->left, temp->englishWord);
//        }
//
//        return node;
//    }
//
//    void DisplayNode(Node* node) {
//        if (node != nullptr) {
//            DisplayNode(node->left);
//            cout << "English: " << node->englishWord << ", Russian: " << node->russianWord << ", Counter: " << node->counter << endl;
//            DisplayNode(node->right);
//        }
//    }
//
//public:
//
//    Dictionary() 
//    {
//        root = nullptr;
//    }
// 
//    void AddNode(string eng, string rus, int cnt) 
//    {
//        root = InsertNode(root, eng, rus, cnt);
//    }
//  
//    void deleteNode(string eng) 
//    {
//        root = deleteNode(root, eng);
//    }
//
//    Dictionary FormNewDictionary() 
//    {
//        Dictionary newDict;
//        Node* maxNode;
//
//        while ((maxNode = FindMaxCountNode(root)) != nullptr) 
//        {
//            newDict.AddNode(maxNode->englishWord, maxNode->russianWord, maxNode->counter);
//            deleteNode(maxNode->englishWord);
//        }
//
//        return newDict;
//    }
//
//    void DisplayDictionary()
//    {
//        DisplayNode(root);
//    }
//};
//
//void DisplayMenu();
//
//int main() {
//    Dictionary dict;
//    Dictionary newDict;
//    int choice;
//    string eng, rus;
//    int cnt;
//
//    while (true) 
//    {
//        DisplayMenu();
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//            case 1: 
//                cout << "Enter English word: ";
//                cin >> eng;
//                cout << "Enter Russian word: ";
//                cin >> rus;
//                cout << "Enter counter: ";
//                cin >> cnt;
//                dict.AddNode(eng, rus, cnt);
//                break;
//
//            case 2:
//                cout << "Enter English word to delete: ";
//                cin >> eng;
//                dict.deleteNode(eng);
//                break;
//      
//            case 3:
//                newDict = dict.FormNewDictionary();
//                cout << "New dictionary formed." << endl;
//                newDict.DisplayDictionary();
//                break;
//
//            case 4:
//                cout << "Original dictionary:" << endl;
//                dict.DisplayDictionary();
//                break;
//
//            case 5:
//                cout << "Exiting program." << endl;
//                exit(EXIT_SUCCESS);
//
//            default:
//                cout << "Invalid choice. Please try again." << endl;
//                break;
//        }
//
//        cout << endl;
//    }
//
//}
//
//void DisplayMenu()
//{
//    cout << "===== Menu =====" << endl;
//    cout << "1. Add word" << endl;
//    cout << "2. Delete word" << endl;
//    cout << "3. Form new dictionary" << endl;
//    cout << "4. Display original dictionary" << endl;
//    cout << "5. Exit" << endl;
//    cout << "================" << endl;
//}

#pragma endregion

#pragma region FirstLabFinal
//#include <iostream>
//
//class BookInfo
//{
//private:
//    int _udk;
//    const char* _author;
//    const char* _title;
//    int _year;
//    int _quantity;
//public:
//    BookInfo(int udk, const char* author, const char* title, int year, int quantity) :
//        _udk(udk), _author(author), _title(title), _year(year), _quantity(quantity) 
//    {
//
//    }
//
//    int GetUdk() const
//    {
//        return _udk;
//    }
//
//    const char* GetAuthor() const
//    {
//        return _author;
//    }
//
//    const char* GetTitle() const
//    {
//        return _title;
//    }
//
//    int GetYear() const
//    {
//        return _year;
//    }
//
//    int GetQuantity() const
//    {
//        return _quantity;
//    }
//
//    void IncrementQuantity()
//    {
//        _quantity++;
//    }
//
//    void DecrementQuantity()
//    {
//        _quantity--;
//    }
//
//};
//
//class Node 
//{
//public:
//    BookInfo book;
//    Node* next;
//
//    Node(BookInfo b) : book(b), next(nullptr) 
//    {
//
//    }
//};
//
//class BookList 
//{
//private:
//    Node* head;
//public:
//    BookList() : head(nullptr) 
//    {
//
//    }
//
//    void AddBook(const BookInfo& book) 
//    {
//        Node* newNode = new Node(book);
//
//        if (head == nullptr) 
//        {
//            head = newNode;
//        }
//        else 
//        {
//            Node* currentNode = head;
//
//            while (currentNode->next != nullptr) 
//            {
//                currentNode = currentNode->next;
//            }
//
//            currentNode->next = newNode;
//        }
//    }
//
//    void TakeBook(int udk) 
//    {
//        Node* currentNode = head;
//
//        while (currentNode != nullptr) 
//        {
//            if (currentNode->book.GetUdk() == udk) 
//            {
//                if (currentNode->book.GetQuantity() > 0) 
//                {
//                    currentNode->book.DecrementQuantity();
//                    std::cout << "The book taken: " << currentNode->book.GetTitle() << std::endl;
//                    
//                    return;
//                }
//                else 
//                {
//                    std::cout << "The required book is not in the library." << std::endl;
//                    
//                    return;
//                }
//            }
//
//            currentNode = currentNode->next;
//        }
//
//        std::cout << "Book with UDC number" << udk << " not found." << std::endl;
//    }
//
//    void ReturnBook(int udk) 
//    {
//        Node* currentNode = head;
//
//        while (currentNode != nullptr) 
//        {
//            if (currentNode->book.GetUdk() == udk) 
//            {
//                currentNode->book.IncrementQuantity();
//                std::cout << "Returned Book: " << currentNode->book.GetTitle() << std::endl;
//                
//                return;
//            }
//
//            currentNode = currentNode->next;
//        }
//
//        std::cout << "Book with UDC number " << udk << " not found." << std::endl;
//    }
//
//    void Display() 
//    {
//        Node* currentNode = head;
//
//        while (currentNode != nullptr) 
//        {
//            std::cout << "UDK: " << currentNode->book.GetUdk() << std::endl;
//            std::cout << "Author: " << currentNode->book.GetAuthor() << std::endl;
//            std::cout << "Title: " << currentNode->book.GetTitle() << std::endl;
//            std::cout << "Year: " << currentNode->book.GetYear() << std::endl;
//            std::cout << "Quantity: " << currentNode->book.GetQuantity() << std::endl;
//            std::cout << std::endl;
//
//            currentNode = currentNode->next;
//        }
//    }
//
//};
//
//void DisplayMenu();
//
//int main()
//{
//    BookList library;
//
//    BookInfo firstBook(1234, "Keila Shaheen", "The Shadow Work Journal: A Guide to Integrate and Transcend your Shadows", 2021, 5);
//    library.AddBook(firstBook);
//
//    BookInfo secondBook(5678, "Shinjiro", "Fate/Zero Volume 5", 2017, 3);
//    library.AddBook(secondBook);
//
//    BookInfo thirdBook(9012, "Stephen Prata", "C Primer Plus", 2019, 2);
//    library.AddBook(thirdBook);
//
//    BookInfo fourthBook(3456, "Jon Skeet", "C# in Depth", 2019, 1);
//    library.AddBook(fourthBook);
//
//    BookInfo fifthBook(7890, "Kathy Sierra", "Head First Java", 2005, 7);
//    library.AddBook(fifthBook);
//
//    int command;
//
//    while (true)
//    {
//        DisplayMenu();
//
//        if (!(std::cin >> command))
//        {
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cout << "Wrong input. Try again.\n";
//            continue;
//        }
//
//        switch (command)
//        {
//            case 1:
//                int udkToBorrow;
//                std::cout << "Enter the UDC number of the book you want to take: ";
//
//                if (!(std::cin >> udkToBorrow))
//                {
//                    std::cin.clear();
//                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                    std::cout << "Wrong input. Try again.\n";
//                    break;
//                }
//
//                library.TakeBook(udkToBorrow);
//                break;
//
//            case 2:
//                int udkToReturn;
//                std::cout << "Enter the UDC number of the book you want to return: ";
//
//                if (!(std::cin >> udkToReturn))
//                {
//                    std::cin.clear();
//                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                    std::cout << "Wrong input. Try again.\n";
//                    break;
//                }
//
//                library.ReturnBook(udkToReturn);
//                break;
//
//            case 3:
//                library.Display();
//                break;
//
//            case 4:
//                std::cout << "Bye!\n";
//                exit(EXIT_SUCCESS);
//
//            default:
//                std::cout << "Wrong command. Try again." << std::endl;
//        }
//    }
//
//}
//
//void DisplayMenu()
//{
//    std::cout << "===== Menu =====" << std::endl;
//    std::cout << "1. Take book" << std::endl;
//    std::cout << "2. Return book" << std::endl;
//    std::cout << "3. Display list" << std::endl;
//    std::cout << "4. Exit" << std::endl;
//    std::cout << "================" << std::endl;
//}

#pragma endregion
