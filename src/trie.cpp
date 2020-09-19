#include "trie.h"

void add(const string& s, node* cur_v)
{
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (cur_v->next[c - 'a'] == nullptr) {
			cur_v->next[c - 'a'] = new node();
		}
		cur_v = cur_v->next[c - 'a'];
	}

	cur_v->strings++;

}

void del(const string& s, node* cur_v)
{
	for (int i = 0; i < s.length(); i++) {
		cur_v = cur_v->next[s[i] - 'a'];
	}

	cur_v->strings--;

}

bool has(const string& s, node* cur_v)
{
	for (int i = 0; i < s.length(); i++) {
		cur_v = cur_v->next[s[i] - 'a'];
		if (cur_v == nullptr) {
			return false;
		}
	}

	return cur_v->strings > 0;

}

string cur_str;

void write(node* v)
{
	for (int i = 0; i < v->strings; i++) {
		cout << cur_str << endl;
	}

	for (int i = 0; i < 26; i++) {
		if (v->next[i] != nullptr) {
			cur_str.push_back('a' + i);
			write(v->next[i]);
			cur_str.pop_back();
		}
	}

}
