#include "Header.h"


// Hàm đọc từ file và lưu vào vector
vector<string> readFromFile(const string& filename)
{
    vector<string> words;
    ifstream file(filename);
    string word;

    if (file.is_open()) {
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    }
    else {
        gotoyx(6, 51);
        cout << "Cannot open file!" << endl;
    }

    return words;
}

// Thêm từ khóa vào bảng băm
void hashInsert(HashTable& ht, const string& word) 
{
    ht.table[word] = true;
}

// Xóa từ khóa khỏi bảng băm
void hashRemove(HashTable& ht, const string& word)
{
    if (ht.table.erase(word)) 
    {
        gotoyx(7, 31);
        color(11);
        cout << "Successfully removing \"" << word << "\" from map." << endl;
    }
    else 
    {
        gotoyx(7, 31);
        color(11);
        cout << "\"" << word << "\" does not exist in map." << endl;
    }
}

// Gợi ý từ khóa dựa trên prefix
vector<string> hashSuggest(HashTable& ht, const string& prefix, int k)
{
    vector<string> suggestions;

    for (const auto& pair : ht.table) 
    {

        // So sánh khi tìm kiếm prefix
        comparison_count++; // pair.first.find(prefix) == 0
        if (pair.first.find(prefix) == 0) {
            suggestions.push_back(pair.first);

            // So sánh kích thước của danh sách gợi ý với k
            comparison_count++; // suggestions.size() == k
            if (suggestions.size() == k) break;
        }
    }

    return suggestions;
}

// In danh sách từ khóa từ bảng băm
void printAll(HashTable ht) 
{
    for (const auto& pair : ht.table) {
        cout << pair.first << endl;
    }
}
