#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	Head = Tail = nullptr;
	Count = 0;
}

List::List(const List & L)
{
	Head = Tail = nullptr;
	Count = 0;
	Elem * temp = L.Head;
	while (temp != nullptr)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	DelAll();
}

void List::AddHead(char data)
{
	Elem * temp = new Elem;
	temp->prev = nullptr;
	temp->data = data;
	temp->next = Head;
	if (Head != nullptr)
		Head->prev = temp;
	Head = temp;
	if (Tail == nullptr)
		Tail = temp;
	Count++;
}

void List::AddTail(char data)
{
	Elem * temp = new Elem;
	temp->next = nullptr;
	temp->data = data;
	temp->prev = Tail;
	if (Tail != nullptr)
		Tail->next = temp;
	Tail = temp;
	if (Head == nullptr)
		Head = temp;
	Count++;
}

void List::DelHead()
{
	if (Head != nullptr)
	{
		Elem *temp = Head;
		Head = Head->next;
		if (Head != nullptr)
			Head->prev = nullptr;
		else
			Tail = nullptr;
		delete temp;
		Count--;
	}
}

void List::DelTail()
{
	if (Tail != nullptr)
	{
		Elem *temp = Tail;
		Tail = Tail->prev;
		if (Tail != nullptr)
			Tail->next = nullptr;
		else
			Head = nullptr;
		delete temp;
		Count--;
	}
}

void List::Insert(char data, int pos)
{
	if (pos < 0 || pos > Count)
		return;

	if (pos == 0)
	{
		AddHead(data);
		return;
	}
	if (pos == Count)
	{
		AddTail(data);
		return;
	}
	Elem *current = nullptr;
	if (pos < Count / 2)
	{
		current = Head;
		int i = 0;
		while (i < pos)
		{
			current = current->next;
			i++;
		}
	}
	else
	{
		current = Tail;
		int i = Count - 1;
		while (i > pos)
		{
			current = current->prev;
			i--;
		}
	}
	Elem *temp = new Elem;
	temp->data = data;
	temp->prev = current->prev;
	temp->next = current;
	current->prev->next = temp;
	current->prev = temp;
	Count++;
}

void List::Del(int pos)
{
	if (pos < 0 || pos >= Count)
		return;
	if (pos == 0)
	{
		DelHead();
		return;
	}
	if (pos == Count - 1)
	{
		DelTail();
		return;
	}
	Elem *delElement = nullptr;
	if (pos < Count / 2)
	{
		delElement = Head;
		int i = 0;
		while (i < pos)
		{
			delElement = delElement->next;
			i++;
		}
	}
	else
	{
		delElement = Tail;
		int i = Count - 1;
		while (i > pos)
		{
			delElement = delElement->prev;
			i--;
		}
	}
	delElement->prev->next = delElement->next;
	delElement->next->prev = delElement->prev;
	delete delElement;
	Count--;
}

void List::PrintHead()
{
	Elem *current = Head;
	while (current != nullptr)
	{
		cout << current->data;
		current = current->next;
	}
	cout << endl;
}

void List::PrintTail()
{
	Elem *current = Tail;
	while (current != nullptr)
	{
		cout << current->data;
		current = current->prev;
	}
	cout << endl;
}

void List::DelAll()
{
	while (Head != nullptr)
		DelHead();
}

int List::GetCount()
{
	return Count;
}

Elem * List::GetElem(int pos)
{
	Elem *temp = Head;
	if (pos < 0 || pos >= Count)
		return nullptr;
	int i = 0;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

List& List::operator = (const List & L)
{
	if (this == &L)
		return *this;
	DelAll();
	Elem * temp = L.Head;
	while (temp != nullptr)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

int List::Find(char key)
{
	int pos = 0;
	Elem* curr = Head;
	while (curr != nullptr)
	{
		pos++;
		if (curr->data == key)
			return pos;

		curr = curr->next;
	}
	return -1;
}

void List::Replace(char value, int position)
{
	if (position < 1 || position > Count)
	{
		cout << "\nEntered position is out of Count(" << "1-" << Count << ")\n";
		cout << "\nPlease try again ...\n";
		return;
	}

	Elem* current = nullptr;

	if (position < Count / 2)
	{
		current = Head;
		int i = 1;
		while (i < position)
		{
			current = current->next;
			i++;
		}
	}
	else
	{
		current = Tail;
		int i = Count;
		while (i > position)
		{
			current = current->prev;
			i--;
		}
	}

	// Вставка нового элемента по позиции
	current->data = value;
	/*
		Elem* temp = new Elem;
	temp->data = value;
	temp->prev = current->prev;
	temp->next = current;
	current->prev->next = temp;
	current->prev = temp;

	// Удаление элемента по позиции
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	*/

}

void List::DelElementByKey(char key)
{

	Elem* temp2 = Head, * next;
	// Проверяем головной элемент
	if (temp2 != NULL && temp2->data == key)
	{
		temp2 = temp2->next;
		free(temp2);
		return;
	}

	// Ищем элемент по значению
	while (temp2 != NULL && temp2->data != key)
	{
		next = temp2;
		temp2 = temp2->next;
	}

	// Если значение не найдено
	if (temp2 == NULL)
	{
		cout << "\nENTERED KEY IS OUT LIST\n";
		return;
	}

	while (temp2 != NULL)
	{
		Elem* temp = Head, * next;

		// Проверяем головной элемент
		if (temp != NULL && temp->data == key)
		{
			temp = temp->next;
			free(temp);
			return;
		}

		// Ищем элемент по значению
		while (temp != NULL && temp->data != key)
		{
			next = temp;
			temp = temp->next;
		}

		// Если значение не найдено
		if (temp == NULL)
		{
			return;
		}
		// Отцепка элемента из списка
		next->next = temp->next;

		// Отцепка элемента от предыдущего
		if (temp->next != NULL)
			temp->next->prev = next;

		free(temp); // Очистка памяти
	}
	// Если значение не найдено
	if (temp2 == NULL)
	{
		cout << "\nEntered key is out of list\n";
		return;
	}
	//переход на следующий элемент
	temp2 = temp2->next;
}

char& List::operator[](int position)
{
	if (position<0||position>=Count)
	{
		throw std::out_of_range("INDEX OUT OF RANGE!");
	}
	Elem* current = Head;
	for (int i = 0; i < position; ++i) {
		current = current->next;
	}
	return current->data;
}

void List::Sort()
{
	Elem* temp2 = Head;

	while (temp2->next != NULL)
	{
		// Создаем новый указательна головной элемент
			Elem* temp = Head;
		// Проходим весь список
		while (temp->next != NULL)
		{
			// Сравниваем значения текущего и следующего элементов
			if (temp->data > temp->next->data)
			{
				// Меняем местами сравниваемые элементы
				int temp_data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp_data;

				temp = temp->next;
			}
			else
			{
				// переходим на следующий элемен
				temp = temp->next;
			}
		}

		// переходим на следующий элемен
		temp2 = temp2->next;
	}
}
