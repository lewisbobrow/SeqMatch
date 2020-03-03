/**********************************************************
* Proj1Wk2
* Comp 15 Spring 2019 
* Trie.cpp
* Author: Lewis Bobrow
*********************************************************/

#include "Trie.h"

using namespace std; 

// Input: nothing
// Returns: nothing
// Does: default constructor, initializes all private variables.
Trie::Trie(){
	inputFile = "";
	outputFile = "";
	root = new trieNode;
	root->DNA = '\0';
	root->end_of_word = false;
	for(int i = 0; i < 4; i++){
		root->children[i] = NULL;
	}
}

// Input: nothing
// Returns: nothing
// Does: default destructor, post-order deletes the nodes and sets
//       root to NULL.
Trie::~Trie(){
	deleteTrie(root);
	root = NULL;
}

// Input: char
// Returns: int
// Does: converts a character, A, C, G or T into an int representing the
//       number child it is in a trieNode.
int Trie::numDNA(char ch){
	int result;
	if(ch == 'A'){
		result = 0;
	} else if(ch == 'C'){
		result = 1;
	} else if(ch == 'G'){
		result = 2;
	} else{
		result = 3;
	}
	return result;
}

// Input: string
// Returns: boolean
// Does: checks if the inputted sequence is in the trie.
bool Trie::search(string sequence){
	trieNode *current = root;
	int seqlen = sequence.length();
	for(int i = 0; i < seqlen; i++){
		if(current == NULL){
			return false;
		}
		current = current->children[numDNA(sequence[i])];
	}
	return (current != NULL and current->end_of_word);
}

// Input: string
// Returns: nothing
// Does: inserts a sequence into the trie. only create new nodes after
//       the part of the sequence (if any) that's already in the string.
void Trie::insert(string sequence){
	trieNode *current = root;
	int seqlen = sequence.length();
	for(int i = 0; i < seqlen; i++){
		if(current->children[numDNA(sequence[i])] == NULL){
			trieNode *newNode = new trieNode;
	        newNode->DNA = sequence[i];
	        newNode->end_of_word = false;
	        for (int i = 0; i<4; i++){
	                newNode->children[i] = NULL;
	        }
			current->children[numDNA(sequence[i])] = newNode;
		}
	current = current->children[numDNA(sequence[i])];
	}
	current->end_of_word = true;
}

// Input: string
// Returns: tuple of string and int
// Does: returns a string of the closest matching sequence in the trie
//       along with the %match.
std::tuple<string, int> Trie::query(string sequence){
	trieNode *current = root;
	double seqlen = sequence.length();
	string matchingChars = "";
	for(int i = 0; i < seqlen; i++){
		if(current->children[numDNA(sequence[i])] != NULL){
			matchingChars.push_back(sequence[i]);
			current = current->children[numDNA(sequence[i])];
		} else{
			break;
		}
	}
	char charArray1[height(root)];
	string allPrefixWords;
	string newRef = "";
	allPrefixWords = print(current, charArray1, newRef, 0);
	int count = 0;
	string lowest;
	for(size_t i = 0; i < allPrefixWords.length(); i++){
    	if (allPrefixWords[i] == '\n'){
    		count++;
    	}
	}
	string allWords[count];
	int count2 = 0;
	for(size_t i = 0; i < allPrefixWords.length(); i++){
		if(allPrefixWords[i] == '\n'){
			count2++;
		} else{
			allWords[count2].push_back(allPrefixWords[i]);
		}
	}
	lowest = allWords[0];
	for(int i = 0; i < count; i++){
		if(allWords[i].length() < lowest.length()){
			lowest = allWords[i];
		} else if(allWords[i].length() == lowest.length()){
			if(allWords[i].compare(lowest) > 0){
				lowest = allWords[i];
			}
		}
	}
	string queryResult = matchingChars + lowest;
	double matchlen = matchingChars.length();
	double querylen = queryResult.length();
	double percentMatch = (matchlen / (max(querylen, seqlen))) * 100;
	int percentMatchRounded = round(percentMatch);
	return std::make_tuple(queryResult, percentMatchRounded);
}

// Input: pointer to char array, int
// Returns: string
// Does: prints the characters from a char array up to a given index
//       into a string.
string Trie::printWord(char *foundWord, int index){
	stringstream ssj;
	for(int i = 0; i < index; i++){
		ssj << foundWord[i];
	}
	return ssj.str() + "\n";
}

// Input: trieNode, pointer to char array, reference to string, int
// Returns: string
// Does: prints all the words in a trie starting from the given parent node.
//       the words are separated by endline characters.
string Trie::print(trieNode *current, char *wordArray, string& result,
				   int pos = 0){
	if(current == NULL){
		result+= "";
	}
	if(current->end_of_word){
		result+= printWord(wordArray, pos);
	}
	for(int i = 0; i < 4; i++){
		if(current->children[i] != NULL){
			wordArray[pos] = current->children[i]->DNA;
			print(current->children[i], wordArray, result, pos + 1);
		}
	}
	return result;
}

// Input: trieNode, pointer to char array, reference to string, constant
//        string, int
// Returns: string
// Does: finds all the suffixes from a given prefix and returns a string of
//       them separated by endline characters. helper function to
//       prefixquery.
string Trie::printPrefixQuery(trieNode *current, char *wordArray, string 
							  &result, const string sequence, int pos = 0){
	if(current == NULL){
		result += "";
	}
	if(current->end_of_word){
		result += sequence + printWord(wordArray, pos);
	}
	for(int i = 0; i < 4; i++){
		if(current->children[i] != NULL){
			wordArray[pos] = current->children[i]->DNA;
			printPrefixQuery(current->children[i], wordArray, result, 
				sequence, pos + 1);
		}
	}
	return result;
}

// Input: trieNode
// Returns: int
// Does: finds the longest word in the trie, or, the height.
int Trie::height(trieNode *current){
	if(current == NULL){
		return -1;
	}
	int res = 0;
	for(int i = 0; i < 4; i ++){
		int h = height(current->children[i]);
		if(h > res){
			res = h;
		}
	}
	return res + 1;
}

// Input: string
// Returns: string
// Does: returns all words of a given prefix (sequence) in a string, separated
//       by endline characters by finding the matching characters in the trie
//       and then attaching all the suffixes beginning with that prefix.
string Trie::prefixQuery(string sequence){
	trieNode *current = root;
	if(!search(sequence)){
		return sequence + ": No Match found";
	}
	int seqlen = sequence.length();
	for(int i = 0; i < seqlen; i++){
		current = current->children[numDNA(sequence[i])];
	}
	char wordArray[height(root)];
	string preQueryResult;
	return printPrefixQuery(current, wordArray, preQueryResult, sequence, 0);
}

// Input: trieNode, string, int
// Returns: boolean
// Does: recursively removes the given sequence from the trie if it exists.
//       only removes the nodes that are not prefixes to longer words.
bool Trie::remove(trieNode *current, string sequence, int index){
	int seqlen = sequence.length();
	if(index == seqlen){
		if(!current->end_of_word){
			return false;
		}
		current->end_of_word = false;
		return isEmpty(current);
	}
	char ch = sequence[index];
	trieNode *node = current->children[numDNA(ch)];
	if(node == NULL){
		return false;
	}
	bool shouldDelete = remove(node, sequence, index + 1);

	if(shouldDelete){
		current->children[numDNA(ch)] = NULL;
		return isEmpty(current);
	}
	return false;
}

// Input: trieNode
// Returns: boolean
// Does: checks if the given trieNode has children.
bool Trie::isEmpty(trieNode* current){
	for(int i = 0; i < 4; i++){
		if(current->children[i])
			return false;
	}
	return true;
}

// Input: trieNode, int reference
// Returns: int
// Does: counts the number of nodes in the trie.
int Trie::numNodes(trieNode *current, int &count){ 
	for(int i = 0; i < 4; i++){
		if(current->children[i] != NULL){
			count ++;
			numNodes(current->children[i], count);
		}
	}
	return count;
}

// Input: trieNode
// Returns: nothing
// Does: post-order delete operation that deletes all the nodes in the trie.
void Trie::deleteTrie(trieNode *current){
	if(current == NULL){
		return;
	} else{
		for(int i = 0; i < 4; i++){
			if(current->children[i] != NULL){
				deleteTrie(current->children[i]);
			}
		}
	}
}

// Input: string, string
// Returns: nothing
// Does: sets the input and output private variables
//       to the inputted strings.
void Trie::getFilesPublic(string query, string out){
	inputFile = query;
	outputFile = out;
}

// Input: nothing
// Returns: nothing
// Does: Public version of getCommand function.
void Trie::getCommandPublic(){
	getCommand();
}

// Input: nothing
// Returns: nothing
// Does: takes in the commands from the query file line by line, performs
//       the requisite actions, and writes the relevant information
//       to an output file.
void Trie::getCommand(){
	string command;
	ifstream inFile;
	inFile.open(inputFile);
	ofstream outFile;
	outFile.open(outputFile);
	if(inFile.fail()){
		cout << "ERROR: File cannot be opened" << endl;
		return;
	}
	if(outFile.fail()){
		cout << "ERROR: File cannot be opened" << endl;
		return;
	}
	if(!inFile.is_open()){
		return;
	}
	if(!outFile.is_open()){
		return;
	}
	while(!inFile.eof()){
		getline(inFile, command);
		stringstream ss(command);
		string a, b;
		ss >> a;
		ss >> b;
		if(a == "i"){
			if(search(b)){
				outFile << b << " was previously inserted" << endl;
			} else{
				insert(b);
				outFile << b << " inserted" << endl;	
			}
		} else if(a == "q"){
			string closest;
			int percent;
			tie(closest, percent) = query(b);
			if(percent == 0){
				outFile << b << ": No match found" << endl;
			} else if(search(b)){
				outFile << "Match found with 100% similarity: " << b << endl;
			} else{
				outFile << "Match found: " << closest << " " << percent << "%"
						<< endl;
			}
		} else if(a == "pq"){
				outFile << prefixQuery(b) << endl;
		} else if(a == "r"){
			if(search(b)){
				remove(root, b, 0);
				outFile << b << " removed" << endl;
			} else{
				outFile << b << ": No match found" << endl;
			}
		} else if(a == "n"){
			int numNodes1 = 0;
			outFile << "There are " << numNodes(root, numNodes1)
				    << " nodes in the database" << endl;
		} else if(a == "p"){
			char charArray2[height(root)];
			string newReference = "";
			outFile << print(root, charArray2, newReference, 0);
		} else if(a == "d"){
			deleteTrie(root);
			outFile << "There are 0 nodes in the database" << endl;
		} else if(a == "f"){
			outFile.close();
			outputFile = b;
			outFile.open(outputFile);
			outFile << "Output file has been changed to " << b << endl;
		} else{
			outFile << "ERROR: invalid input" << endl;
		}
	}
	inFile.close();
	outFile.close();
}