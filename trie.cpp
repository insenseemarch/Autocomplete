#include "Header.h"


void trieInsert(Trie &trie, const string& word)
{
    TrieTree* subNode = trie.root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!subNode->node[index])
        {
            subNode->node[index] = new TrieTree();
        }
        subNode = subNode->node[index];
    }
    subNode->isEndOfWord = true;
}

void suggestHelper(TrieTree* subNode, string prefix, vector<string>& results, int k)
{
    // Đếm so sánh trong điều kiện đầu
    comparison_count++; // results.size() >= k
    if (results.size() >= k)
    {
        return;
    }

    // Đếm so sánh khi kiểm tra isEndOfWord
    comparison_count++;
    if (subNode->isEndOfWord)
    {
        results.push_back(prefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        comparison_count++; // i < ALPHABET_SIZE
        comparison_count++; // subNode->node[i]
        if (subNode->node[i])
        {
            suggestHelper(subNode->node[i], prefix + char(i + 'a'), results, k);
        }
    }
}

vector<string> trieSuggest(Trie& trie, const string& prefix, int k)
{
    TrieTree* subNode = trie.root;
    for (char c : prefix)
    {
        int index = c - 'a';
        // Đếm so sánh khi kiểm tra subNode->node[index]
        comparison_count++;
        if (!subNode->node[index])
        {
            return {};
        }
        subNode = subNode->node[index];
    }

    vector<string> results;
    suggestHelper(subNode, prefix, results, k);
    return results;
}

void loadFromFile(Trie& trie, const string& filename)
{
    fstream file;
    file.open(filename, ios::in);
    if (!file)
    {
        cerr << "Can not look up in a dictionary based on: " << filename << endl;
        return;
    }

    string word;
    while (getline(file, word))
    {
        if (!word.empty())
        {
            trieInsert(trie, word);
        }
    }

    file.close();
}

// Xóa từ khóa khỏi Trie
bool removeHelper(TrieTree* subNode, const string& word, int depth)
{
    if (!subNode) return false;

    if (depth == word.size())
    {
        // Đánh dấu từ này không phải là từ kết thúc
        if (subNode->isEndOfWord)
            subNode->isEndOfWord = false;

        // Kiểm tra nếu nút này có nút con nào không
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (subNode->node[i])
                return false; // Không xóa nếu còn nút con
        }

        // Không còn nút con, trả về true để xóa nút
        return true;
    }

    int index = word[depth] - 'a';
    if (removeHelper(subNode->node[index], word, depth + 1)) {
        delete subNode->node[index];
        subNode->node[index] = nullptr;

        // Kiểm tra nếu nút hiện tại không phải kết thúc từ và không còn con
        return !subNode->isEndOfWord && isEmpty(subNode);
    }

    return false;
}

void trieRemove(Trie& trie, const string& word)
{
    //bool result = trieSearch(trie.root, word, 0);
    if (!trieSearch(trie.root, word, 0))
    {
        gotoyx(7, 31);
        color(11);
        cout << "\"" << word << "\" does not exist in trie tree." << endl;
        return;
    }
    else
    {
        removeHelper(trie.root, word, 0);
        gotoyx(7, 31);
        color(11);
        cout << "Successfully removing \"" << word << "\" from trie tree." << endl;
    }
}

// Kiểm tra nút có trống không
bool isEmpty(TrieTree* subNode)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (subNode->node[i])
            return false;
    }
    return true;
}

bool trieSearch(TrieTree* subNode, const string& word, int depth) 
{
    if (!subNode) return false;

    if (depth == word.size()) {
        return subNode->isEndOfWord;
    }

    int index = word[depth] - 'a';
    if (!subNode->node[index]) return false;

    return trieSearch(subNode->node[index], word, depth + 1);
}
