#pragma once
#ifndef _HEADER_H_

#include <iostream>
#include <windows.h> // Console screen format
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <map>
#include <conio.h>


using namespace std;

extern int comparison_count;

// graphic.cpp
void gotoyx(int y, int x);
string borderHelloScreen(int y, int x, int max_y, int max_x);
void color(int color);
int getThingColor(string c);
void helloScreen();
void start();
void menu();
void drawFrame(int max_y, int max_x);
void hashSetting();
void radixSetting();
void trieSetting();

// hash.cpp
vector<string> readFromFile(const string& filename);
struct HashTable 
{
   map<string, bool> table;

};
void hashInsert(HashTable& ht, const string& word);
void hashRemove(HashTable& ht, const string& word);
vector<string> hashSuggest(HashTable& ht, const string& prefix, int k);
void printAll(HashTable ht);
 // Biến toàn cục để đếm phép gán

// radix.cpp
//extern const int ALPHABET_SIZE;
const int ALPHABET_SIZE = 26;

struct RadixTreeNode
{
    map<string, RadixTreeNode*> children;
    bool isEndOfWord;

    RadixTreeNode() : isEndOfWord(false) {}
};
void radixInsert(RadixTreeNode* root, const string& word);
void collectWords(RadixTreeNode* node, const string& prefix, vector<string>& results, int k);
vector<string> radixSuggest(RadixTreeNode* root, const string& prefix, int k);
void radixAddKeyword(RadixTreeNode* root, const string& word);
bool radixRemove(RadixTreeNode* node, const string& word, int depth = 0);
void deleteKeyword(RadixTreeNode* root, const string& word);
bool radixSearch(RadixTreeNode* node, const string& word, int depth);

// trie.cpp
struct TrieTree
{
    TrieTree* node[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieTree()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            node[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

struct Trie
{
    TrieTree* root;

    Trie()
    {
        root = new TrieTree();
    }
};

void trieInsert(Trie& trie, const string& word);
void suggestHelper(TrieTree* subNode, string prefix, vector<string>& results, int k);
vector<string> trieSuggest(Trie& trie, const string& prefix, int k);
void loadFromFile(Trie& trie, const string& filename);
bool removeHelper(TrieTree* subNode, const string& word, int depth);
void trieRemove(Trie& trie, const string& word);
bool isEmpty(TrieTree* subNode);
bool trieSearch(TrieTree* subNode, const string& word, int depth);



#endif
