/**********************************************************
* Proj1Wk2
* Comp 15 Spring 2019 
* TestMain.cpp
* Author: Lewis Bobrow
*********************************************************/

//#include "Trie.h"

//using namespace std;

//COMMENTED OUT BECAUSE FUNCTIONS WERE RE-MADE PRIVATE AFTER TESTING

//int main(){
	// cout << "creating Trie for testing" << endl;
 //    Trie testTrie;

 //    //EDGE CASE
 //    cout << "contains AACCTTGG? (empty trie, should be 0): ";
 //    cout << testTrie.search("AACCTTGG") << endl;

 //    //BASE CASE
 //    cout << "inserting AACCTTGG" << endl;
 //    testTrie.insert("AACCTTGG");
    
 //    //BASE CASE
 //    cout << "contains AACCTTGG? (just inserted, should be 1): ";
 //    testTrie.search("AACCTTGG");

 //    //QUERY BASE CASE - 100%match
	// string closest1;
	// int percent1;
	// tie(closest1, percent1) = testTrie.query("AACCTTGG");
 //    cout << "closest to AACCTTGG and %match: " << closest1 << " "
 //    	 << percent1 << "%" << endl;

 //    //QUERY EDGE CASE  - partial match, shorter word
 //   	string closest2;
	// int percent2;
	// tie(closest2, percent2) = testTrie.query("AACCT");
 //    cout << "closest to AACCT and %match: " << closest2 << " "
 //    	 << percent2 << "%" << endl;

 //   	//QUERY EDGE CASE  - partial match, longer word
 //   	string closest3;
	// int percent3;
	// tie(closest3, percent3) = testTrie.query("AACCTTGGACTG");
 //    cout << "closest to AACCTTGGACTG and %match: " << closest3 << " "
 //    	 << percent3 << "%" << endl;

 //   	//QUERY EDGE CASE  - no match
 //   	string closest4;
	// int percent4;
	// tie(closest4, percent4) = testTrie.query("CC");
 //    cout << "closest to CC and %match: " << closest4 << " "
 //    	 << percent4 << "%" << endl;

 //   	//BASE CASE REMOVE
 //    cout << "removing AACCTTGG? (should be 1): " << testTrie.remove("AACCTTGG") << endl;

 //   	//EDGE CASE REMOVE
 //    cout << "removing ACTG? (should be 0): " << testTrie.remove("ACTG") << endl;

 //    //EDGE CASE NUMNODES - NO WORDS
 //    cout << "Num nodes: " << testTrie.numNodes(root) << endl;

 //    //EDGE CASE HEIGHT - NO NODES
 //    cout << "height: " << testTrie.height(root) << endl;

 //    //DELETETRIE EDGE CASE - NO NODES
 //    testTrie.deleteTrie()
 //    cout << "deleting empty trie; height: " << testTrie.height(root) << endl;

 //    //DGE CASE PRINT - NO WORDS
 //    cout << "words in trie (should be nothing): " << endl;
	// char charArray[testTrie.height(root)];
	// string newRef = "";
	// cout << testTrie.print(root, charArray, newRef, 0);

	// //BASE CASE ISEMPTY
	// cout << "is empty? (should be 1): " << testTrie.isEmpty(root) << endl;


 //    //INSERTING MORE FOR TESTING
 //    cout << "inserting AACAAA" << endl;
 //    testTrie.insert("AACAAA");
 //    cout << "inserting CAC" << endl;
 //    testTrie.insert("CAC");
 //    cout << "inserting TCAGGAC" << endl;
 //    testTrie.insert("TCAGGAC");
 //    cout << "inserting GGTTCCAA" << endl;
 //    testTrie.insert("GGTTCCAA");
 //    cout << "inserting CACACATTA" << endl;
 //    testTrie.insert("CACACATTA");
 //    cout << "inserting GGTTCGGGG" << endl;
 //    testTrie.insert("GGTTCGGGG");

 //    //BASE CASE NUMNODES - MANY WORDS
 //    cout << "Num nodes: " << testTrie.numNodes(root) << endl;

 //    //HEIGHT BASE CASE - EXISTS
 //    cout << "height (equal to longest string): " << testTrie.height(root) << endl;

 //    //PRINT BASE CASE
 //    cout << "words in trie: " << endl;
	// char charArray2[testTrie.height(root)];
	// string newReference = "";
	// cout << testTrie.print(root, charArray2, newReference, 0);

	// //EDGE CASE ISEMPTY
	// cout << "is empty? (should be 0): " << testTrie.isEmpty(root) << endl;

 //    //PREFIXQUERY BASE CASE - perfix exists
 //    cout << "words with CAC: " << testTrie.prefixQuery("CAC"); << endl;
    
 //    //PREFIXQUERY EDGE CASE  - prefix doesn't exist
 //    cout << "closest to AACCT (should be nothing): " 
 //         << testTrie.prefixQuery("GAG"); << endl;

 //   	//PREFIXQUERY EDGE CASE  - prefix too long
 //    cout << "closest to AACCTTGGACT (should be nothing): " 
 //         << testTrie.prefixQuery("GGTTCA"); << endl;

 //    //DELETETRIE BASE CASE
 //    testTrie.deleteTrie()
 //    cout << "deleting trie; new height: " << testTrie.height(root) << endl;

//	return 0;
//}