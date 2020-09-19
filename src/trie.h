#pragma once
#include <iostream>
using namespace std;

struct node {
	node* next[26];
	int strings;
	node() {
		for (int i = 0; i < 26; i++) {
			next[i] = nullptr;
		}
		strings = 0;
	}
	~node() {
		for (int i = 0; i < 26; i++) {
			if (next != NULL)
				delete next[i];
		}
	}
};

extern string cur_str;

void add(const string&, node* );

bool has(const string&, node* );

void del(const string&, node* );

void write(node* );