#pragma once
#include <iostream>
using namespace std;

class Node {
private:
	Node* next[26];
	int strings;

public:
	Node();
	~Node();

	void add(const string&);
	bool has(const string&);
	void del(const string&);

};