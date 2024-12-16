
#include <iostream>
#include <string>

using namespace std;

class MyString {
	char* arr;
	int Capacity;
	int Length;
public:
	MyString() { // Конструктор за замовчуванням
		this->arr = new char[0];
		this->Capacity = 0;
	}

	MyString(const char* arr) { // Конструктор з параметрами
		int amount = 0;

		for (int i = 0;; i++) {
			amount++;
			if (arr[i] == '\0') {
				break;
			}
		}
		this->Capacity = amount;

		this->arr = new char[amount];

		for (int i = 0;; i++) {
			this->arr[i] = (char)arr[i];
			if (this->arr[i] == '\0') {
				break;
			}
		}
	}

	MyString(MyString& other) { // Конструктор копіювання
		this->Capacity = other.capacity();
		this->arr = new char[this->Capacity];

		for (int i = 0;; i++) {
			if ((char)other.arr[i] == '\0') {
				break;
			}
			this->arr[i] = (char)other.arr[i];
		}
		this->arr[this->Capacity - 1] = '\0';
	}

	void append(char symbol) { // Додати елемент в кінець рядку
		int amount = size();

		char* tempArr = new char[amount + 1];

		for (int i = 0; i < amount; i++) {
			tempArr[i] = (char)this->arr[i];
		}

		delete[] this->arr;
		this->arr = nullptr;

		this->arr = new char[amount + 2];

		for (int i = 0; i < amount; i++) {
			this->arr[i] = (char)tempArr[i];
		}

		delete[] tempArr;
		tempArr = nullptr;

		this->arr[amount] = symbol;
		this->arr[amount + 1] = '\0';
	}

	int size() { // Отримати кіл-ть елементів
		int amount = 0;

		for (int i = 0;; i++) {
			if (this->arr[i] == '\0') {
				break;
			}
			else {
				amount++;
			}
		}

		return amount;
	}

	int capacity() { // Отримати об'єм елементів
		return this->Capacity;
	}

	bool compare(MyString& other) {
		if (size() > other.size()) {
			return true;
		}
		else {
			false;
		}
	}

	void clear() {
		for (int i = 0;; i++) {
			if (this->arr[i] == '\0') {
				break;
			}
			this->arr[i] = '\0';
		}
	}

	void copy(MyString& other) {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
		}

		this->Capacity = other.capacity();
		this->arr = new char[this->Capacity];

		for (int i = 0; i < other.size(); i++) {
			this->arr[i] = other.arr[i];
		}
		this->arr[other.size()] = '\0'; 
	}

	int length() {
		int Length = 0;

		for (int i = 0;; i++) {
			if (this->arr[i] == '\0') {
				break;
			}
			else if(this->arr[i] != ' '){
				Length++;
			}
		}
		
		return Length;
	}

	void find(char subString) {
		for (int i = 0;; i++) {
			if (arr[i] == subString) {
				cout << "[" << i << "] " << subString;
			}
		}

	}
	
	void insert(int index) {
		for (int i = 0;i < Capacity; i++) {
			if (i = index) {
				cout << "Enter symbol to insert" << endl;
				cin >> arr[i];
			}
		}
	}

	void pop_back() { 
		int amount = size();
		if (amount == 0) {
			
		}
		else {
			char* tempArr = new char[amount];

			for (int i = 0; i < amount - 1; i++) {
				tempArr[i] = this->arr[i];
			}
			tempArr[amount - 1] = '\0';

			delete[] this->arr;
			this->arr = tempArr;
			this->Capacity = amount;
		}

		
	}

	void push_back(char symbol) { 
		int amount = size();
		char* tempArr = new char[amount + 2];

		tempArr[0] = symbol;
		for (int i = 0; i < amount; i++) {
			tempArr[i + 1] = this->arr[i];
		}
		tempArr[amount + 1] = '\0';

		delete[] this->arr;
		this->arr = tempArr;
		this->Capacity = amount + 2;
	}


	void PrintInfo() {
		for (int i = 0; i < size(); i++) {
			cout << "[" << i << "] " << this->arr[i];
		}
	}



	~MyString() {
		delete[] this->arr;
		this->arr = nullptr;
	}
};

int main()
{
	MyString str = "Boryslav";
	
	MyString str2;
	
	MyString str3 = str;
	str3.append('s');
	str3.append('s');
	cout << str3.compare(str) << endl;
	str2.copy(str);
	cout << str.length() << endl;
	
	char subString = ' ';
	int index = 0;
	cout << "Enter subString for find: " << endl;
	cin >> subString;

	cout << "Enter index: " << endl;
	cin >> index;
	str.find(subString);
 
	str.pop_back();
	str.push_back('B');

	//str.append(); // +
	//str.capacity(); // +
	//str.clear(); .. +
	//str.size(); // +
	//str.compare(); // Порівняння двох рядків +
	//str.copy(); // Копіювання
	//str.find(); // Пошук підрядка в рядку
	//str.insert(); // Вставка за індексом
	//str.length(); // Кіл-ть символів
	//str.pop_back(); // Видалення з початку
	//str.push_back(); // Вставлення в початок
	// Оператор присвоювання
	// Оператор індексації
	// Оператор виводу в консоль

	// Hello, world // index= 7
	// world

	// str.find("world")
	// 7
}

//Ви маєте реалізувати такі методи, як:
//copy() +
//find() +
//insert() +
//length() +
//pop_back() +
//push_back() +
//Оператор присвоювання ?
//Оператор індексації ?
//Оператор виводу в консоль ?