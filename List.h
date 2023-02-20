#pragma once;

struct Elem
{
	char data; // данные
	Elem *next, *prev;
};

class List
{
	// Голова, хвост
	Elem *Head, *Tail;
	// Количество элементов
	int Count;

public:

	// Конструктор
	List();

	// Конструктор копирования
	List(const List&);

	// Деструктор
	~List();

	// Получить количество элементов
	int GetCount();

	// Получить элемент списка
	Elem* GetElem(int);

	// Удалить весь список
	void DelAll();

	// Удаление элемента по индексу
	void Del(int pos);

	// Вставка элемента в заданную позицию
	void Insert(char data, int pos);

	// Добавление в конец списка
	void AddTail(char data);

	// Добавление в начало списка
	void AddHead(char data);

	//Удаление головного элемента
	void DelHead();

	//Удаление хвостового элемента
	void DelTail();

	// Печать списка, начиная с головы
	void PrintHead();

	//Печать списка, начиная с хвоста
	void PrintTail();

	//перегрузка оператора =
	List& operator = (const List&);

	//Метод поиска заданного элемента по ключу
	int Find(char key);

	//Метод замены значения указанного элемента на другое значение, передаваемое методу в качестве параметра
	void Replace(char value, int position);

	//Метод удаления элементов списка, значение которых совпадает с заданным ключом
	void DelElementByKey(char key);

	//Перегруженный оператор индексирования
	char& operator[](int position);

	//Метод сортировки элементов списка.
	void Sort();
};
