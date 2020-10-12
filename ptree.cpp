#include <iostream>
#include <string> 
#include <ctime> 
#include <cassert>
#include <vector>
#include <fstream>
#include <sstream>
#include "trie.h"
using namespace std;

vector<string> test0 = { "cow", "cat", "dog", "mouse", "mule"};
string test1 = "q w e r t y u i o p a s d f g h j k l z b g d r j x n m z l g j k w a s f g h l";
string test2 = "qw we er rt ty ui iu io po sd gf hj kj kl fg cv bv hp mn nm mk nj bh vg cf xd zs aq sw de fr gt hy ju ki lo pl ij uh yg";
string test3 = "qwe wer ert rty tyu yui uio iop sdf swr sdh fgg jkh vbh jkl xcv nmj hkl mnb cxz zaq xsw cde vfr bgt nhy mju kio lop qaz wsx edc rfv tgb yhn ujm ikz dbk alp nrx";
string test4 = "qwer wert erty rtyu yuio uiop ioas asdf sdfg dfgh hjkg qasd vbnm zxcv vcxz mgjf ijgf glxf qwea qugx qazx wsxc edcv rfvb tgbn yhnm ujmk zaqw xswe cder vfrt bgty nhyu mjui aqzn swxn decn frvn gtbn hynn";
string test5 = "qwert werty ertyu rtyui tyuio yuiop poiuy oiuyt trewq asdfg sdfgh ghjkl jklhg zxcvb xcvbn cvbnm mnbvc nbvcx hjkld wscbh qazxq wsxcw edcve rfvbr tgbnt yhnmy ujmku zaqwy xsweu cderi vfrto bgtyp nhyua mjuis aqznd swxnf decng frvnh gtbnj hynnk";
string test6 = "qwertq wertyw ertyue rtyuir tyuiot yuiopy poiuyu oiuyti trewqo asdfgp sdfgha ghjkls jklhgd zxcvba xcvbns cvbnmd mnbvcf nbvcxg hjkldg wscbhn qazxqm wsxcwn edcveb rfvbrv tgbntc yhnmyx ujmkuz zaqwyl xsweuk cderij vfrtoh bgtypg nhyuaf mjuisd aqznds swxnfa decngp frvnhi gtbnju hynnky";

vector<string> test = { test1, test2, test3, test4, test5, test6 };
void testtree() {
	int n = 5;
	Node root;
	cout << "Тест на работоспособность стурктуры данных префиксное дерево:";
	cout << endl;
	for (size_t i = 0; i < n; i++) {
		root.add(test0[i]);
	}
	assert(root.has("cat") == true);
	assert(root.has("mule") == true);
	assert(root.has("pig") == false);
	root.del("cat");
	assert(root.has("cat") == false);
	assert(root.has("bull") == false);
	root.add("cat");
	assert(root.has("cat") == true);
	cout << "Вывод юнит теста: Ok" << endl << endl;
}

void testadd() {
	cout << "Тест на добавление ключа:"<< endl;
	clock_t start, end;
	string word;
	for (int i = 0; i < 6; i++)
	{
		clock_t time = 0;
		for (size_t l = 0; l < 50000; l++)
		{
			Node root;
			istringstream istest(test[i]);
			start = clock();
			for (size_t j = 0; j < 40; j++)
			{
				istest >> word;
				root.add(word);
			}
			end = clock();
			time += end - start;
		}
		cout << "тест на словах из " << i + 1 << " букв прохошёл за столько тактов: " << time << endl;
	}
	cout << endl;
}

void testhas() {
	cout << "Тест на поиск ключа:" << endl;
	clock_t start, end;
	string word;
	for (int i = 0; i < 6; i++)
	{
		clock_t time = 0;
		for (size_t l = 0; l < 50000; l++)
		{
			Node root;
			istringstream istest(test[i]);
			for (size_t j = 0; j < 40; j++)
			{
				istest >> word;
				root.add(word);
			}
			istringstream istest2(test[i]);
			start = clock();
			for (size_t j = 0; j < 40; j++)
			{
				istest2 >> word;
				root.has(word);
			}
			end = clock();
			time += end - start;
		}
		cout << "тест на словах из " << i + 1 << " букв прохошёл за столько тактов: " << time << endl;
	}
	cout << endl;
}

void testdel() {
	cout << "Тест на удаление ключа:" << endl;
	clock_t start, end;
	string word;
	for (int i = 0; i < 6; i++)
	{
		clock_t time = 0;
		for (size_t l = 0; l < 50000; l++)
		{
			Node root;
			istringstream istest(test[i]);
			for (size_t j = 0; j < 40; j++)
			{
				istest >> word;
				root.add(word);
			}
			istringstream istest2(test[i]);
			start = clock();
			for (size_t j = 0; j < 40; j++)
			{
				istest2 >> word;
				root.del(word);
			}
			end = clock();
			time += end - start;
		}
		cout << "тест на словах из " << i + 1 << " букв прохошёл за столько тактов: " << time << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	testtree();
	testadd();
	testhas();
	testdel();
	return 0;
}

