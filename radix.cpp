#include "Header.h"

void radixInsert(RadixTreeNode* root, const string& word)
{
    RadixTreeNode* current = root;
    string remaining = word;

    while (!remaining.empty())
    {
        bool matched = false;
        for (auto it = current->children.begin(); it != current->children.end(); ++it)
        {
            string edge = it->first;
            size_t match_len = 0;

            while (match_len < edge.size() && match_len < remaining.size() && edge[match_len] == remaining[match_len])
            {
                ++match_len;
            }

            if (match_len > 0)
            {
                if (match_len == edge.size())
                {
                    current = it->second;
                    remaining = remaining.substr(match_len);
                }
                else
                {
                    RadixTreeNode* newNode = new RadixTreeNode();
                    newNode->children[edge.substr(match_len)] = it->second;
                    it->second = newNode;
                    current->children[edge.substr(0, match_len)] = newNode;
                    current->children.erase(it);
                    newNode->children[remaining.substr(match_len)] = new RadixTreeNode();
                    newNode->children[remaining.substr(match_len)]->isEndOfWord = true;
                    return;
                }
                matched = true;
                break;
            }
        }

        if (!matched)
        {
            current->children[remaining] = new RadixTreeNode();
            current->children[remaining]->isEndOfWord = true;
            return;
        }
    }

    current->isEndOfWord = true;
}


void collectWords(RadixTreeNode* node, const string& prefix, vector<string>& results, int k)
{
    comparison_count++;
    if (results.size() >= k) return;

    comparison_count++;
    if (node->isEndOfWord) results.push_back(prefix);

    for (auto& child : node->children) {
        collectWords(child.second, prefix + child.first, results, k);
    }
}

vector<string> radixSuggest(RadixTreeNode* root, const string& prefix, int k)
{
    RadixTreeNode* current = root;
    string remaining = prefix;

    while (!remaining.empty()) {
        bool matched = false;
        for (auto& child : current->children)
        {
            const string& edge = child.first;
            if (edge.compare(0, remaining.size(), remaining) == 0)
            {
                comparison_count++;
                current = child.second;
                remaining.clear();
                matched = true;
                break;
            }
            else if (remaining.compare(0, edge.size(), edge) == 0)
            {
                comparison_count++;
                current = child.second;
                remaining = remaining.substr(edge.size());
                matched = true;
                break;
            }
        }
        if (!matched) return {};
    }

    vector<string> results;
    collectWords(current, prefix, results, k);
    return results;
}

bool radixSearch(RadixTreeNode* node, const string& word, int depth) 
{
    if (!node) return false;

    if (depth == word.size()) 
    {
        return node->isEndOfWord;
    }

    string currentEdge;
    RadixTreeNode* child = nullptr;
    for (auto& childPair : node->children) {
        if (word.substr(depth, childPair.first.size()) == childPair.first) 
        {
            currentEdge = childPair.first;
            child = childPair.second;
            break;
        }
    }

    if (!child) return false;

    return radixSearch(child, word, depth + currentEdge.size());
}


void radixAddKeyword(RadixTreeNode* root, const string& word)
{
    radixInsert(root, word);
}



bool radixRemove(RadixTreeNode* node, const string& word, int depth)
{
    if (!node) return false;

    if (depth == word.size())
    {
        if (!node->isEndOfWord) return false;
        node->isEndOfWord = false;
        return node->children.empty();
    }

    string currentEdge;
    RadixTreeNode* child = nullptr;
    for (auto& childPair : node->children)
    {
        if (word.substr(depth, childPair.first.size()) == childPair.first)
        {
            currentEdge = childPair.first;
            child = childPair.second;
            break;
        }
    }

    if (!child) return false;

    bool shouldDeleteChild = radixRemove(child, word, depth + currentEdge.size());

    if (shouldDeleteChild)
    {
        delete child;
        node->children.erase(currentEdge);
        return node->children.empty() && !node->isEndOfWord;
    }

    return false;
}

void deleteKeyword(RadixTreeNode* root, const string& word)
{
    //radixRemove(root, word);
    if (!radixSearch(root, word, 0))
    {
        gotoyx(7, 31);
        color(11);
        cout << "\"" << word << "\" does not exist in radix tree." << endl;
        return;
    }
    else
    {
        radixRemove(root, word);
        gotoyx(7, 31);
        color(11);
        cout << "Successfully removing \"" << word << "\" from radix tree." << endl;
    }
}
