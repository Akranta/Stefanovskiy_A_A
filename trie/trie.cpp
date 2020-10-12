#include "trie.h"






Node::Node()
{
	for (int i = 0; i < 26; i++) {
		next[i] = nullptr;
	}
	strings = 0;
}

Node::~Node()
{
	for (int i = 0; i < 26; i++) {
		if (next != NULL)
			delete next[i];
	}
}

void Node::add(const string& s)
{
	Node* cur_v = this;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (cur_v->next[c - 'a'] == nullptr) {
			cur_v->next[c - 'a'] = new Node();
		}
		cur_v = cur_v->next[c - 'a'];
	}

	cur_v->strings++;
}

bool Node::has(const string& s)
{
	Node* cur_v = this;
	for (int i = 0; i < s.length(); i++) {
		cur_v = cur_v->next[s[i] - 'a'];
		if (cur_v == nullptr) {
			return false;
		}
	}

	return cur_v->strings > 0;
}

void Node::del(const string& s)
{
	Node* cur_v = this;
	for (int i = 0; i < s.length(); i++) {
		cur_v = cur_v->next[s[i] - 'a'];
	}

	cur_v->strings--;
}

