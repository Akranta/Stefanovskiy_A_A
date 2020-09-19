#include <iostream>
#include <string> 
#include <ctime> 
#include <fstream>
#include "trie.h"
using namespace std;

void testtree() {
	int n;
	node* root = new node();
	cout << "Тест на работоспособность стурктуры данных префиксное дерево при помощи пользовательского интерфейса:";
	cout << "Введите количество слов, которые нужно добавить в префиксное дерево: ";
	cin >> n;
	cout << endl;
	cout << "Вводите слова по порядку:" << endl;
	string word;
	for (size_t i = 0; i < n; i++) {
		cin >> word;
		add(word, root);
	}
	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl << endl;
	cout << "Вывод всех слов в отсортированном порядке префиксного дерева при помощи DFS:" << endl << endl;
	write(root);
	delete root;
}

void testadd(string& filed) {
	cout << "Тест на добавление ключа:"<< endl;
	ifstream input;
	clock_t start, end;
	string word;
	string file = filed + "\\test";
	for (int i = 1; i <= 6; i++)
	{
		string filen = file + to_string(i) + ".txt";
		clock_t time = 0;
		for (size_t l = 0; l < 50000; l++)
		{
			node* root = new node();
			input.open(filen);
			start = clock();
			for (size_t j = 0; j < 40; j++)
			{
				input >> word;
				add(word, root);
			}
			end = clock();
			time += end - start;
			input.close();
			delete root;
		}
		cout << "тест на словах из " << i << " букв прохошёл за столько тактов: " << time << endl;
	}
	cout << endl;
}

void testhas(string& filed) {
	cout << "Тест на поиск ключа:" << endl;
	ifstream input;
	clock_t start, end;
	string word;
	string file = filed + "\\test";
	for (int i = 1; i <= 6; i++)
	{
		string filen = file + to_string(i) + ".txt";
		clock_t time = 0;
		for (size_t l = 0; l < 50000; l++)
		{
			node* root = new node();
			input.open(filen);
			for (size_t j = 0; j < 40; j++)
			{
				input >> word;
				add(word, root);
			}
			input.close();
			input.open(filen);
			start = clock();
			for (size_t j = 0; j < 40; j++)
			{
				input >> word;
				has(word, root);
			}
			end = clock();
			time += end - start;
			input.close();
			delete root;
		}
		cout << "тест на словах из " << i << " букв прохошёл за столько тактов: " << time << endl;
	}
	cout << endl;
}

void testdel(string& filed) {
	cout << "Тест на удаление ключа:" << endl;
	ifstream input;
	clock_t start, end;
	string word;
	string file = filed + "\\test";
	for (int i = 1; i <= 6; i++)
	{
		string filen = file + to_string(i) + ".txt";
		clock_t time = 0;
		for (size_t l = 0; l < 50000; l++)
		{
			node* root = new node();
			input.open(filen);
			for (size_t j = 0; j < 40; j++)
			{
				input >> word;
				add(word, root);
			}
			input.close();
			input.open(filen);
			start = clock();
			for (size_t j = 0; j < 40; j++)
			{
				input >> word;
				del(word, root);
			}
			end = clock();
			time += end - start;
			input.close();
			delete root;
		}
		cout << "тест на словах из " << i << " букв прохошёл за столько тактов: " << time << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Напишите путь для папки с тестами в формате С:\\test: ";
	string filed = "С:\\test";
	cin >> filed;
	testadd(filed);
	testhas(filed);
	testdel(filed);
	testtree();
	return 0;
}

