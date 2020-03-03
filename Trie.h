/**********************************************************
* Proj1Wk2
* Comp 15 Spring 2019 
* Trie.h
* Author: Lewis Bobrow
*********************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <tuple>
using namespace std;

#ifndef _TRIE_H_
#define _TRIE_H_


struct trieNode
{
	char DNA;
	trieNode* children[4];
	bool end_of_word;
};


class Trie{
public:
	Trie();
	~Trie();
	void getFilesPublic(string query, string out);
	void getCommandPublic();
private:
	string inputFile;
	string outputFile;
	trieNode *root;
	int numDNA(char ch);
	void insert(string sequence);
	bool search(string sequence);
	std::tuple<string, int> query(string sequence);	
	string printPrefixQuery(trieNode *current, char *wordArray, string 
							  &result, const string sequence, int pos);
	string prefixQuery(string sequence);
	bool remove(trieNode *current, string sequence, int index);
	bool isEmpty(trieNode* current);
	int numNodes(trieNode *current, int &count);
	string printWord(char *foundWords, int index);
	string print(trieNode *current, char *wordArray, string& result, int pos);
	int height(trieNode *current);
	void deleteTrie(trieNode *current);
	void getCommand();
};
#endif