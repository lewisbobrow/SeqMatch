/**********************************************************
* Proj1Wk2
* Comp 15 Spring 2019 
* main.cpp
* Author: Lewis Bobrow
*********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
using namespace std;

// creates an instance of the Trie class, sets the input and output files to
// the 2nd and 3rd command line arguments, and then calls the public
// get command function.
int main(int argc, char* argv[]){
	argc = 3;
	Trie trieTree;
	trieTree.getFilesPublic(argv[1], argv[2]);
	trieTree.getCommandPublic();
	return 0;
}