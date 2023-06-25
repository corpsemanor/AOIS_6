#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Entry {
    std::string keyword;
    std::string data;
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::vector<Entry>> table;

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    int hashFunction(const std::string& keyword) {
        int hash = 0;
        for (char ch : keyword) {
            hash += ch;
        }
        return hash % TABLE_SIZE;
    }

    void insert(const std::string& keyword, const std::string& data) {
        int hash = hashFunction(keyword);
        table[hash].push_back({ keyword, data });
    }

    void search(const std::string& keyword) {
        int hash = hashFunction(keyword);
        bool found = false;
        for (const Entry& entry : table[hash]) {
            if (entry.keyword == keyword) {
                std::cout << "Keyword: " << entry.keyword << std::endl;
                std::cout << "Data: " << entry.data << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No information found for the keyword: " << keyword << std::endl;
        }
    }

    void remove(const std::string& keyword) {
        int hash = hashFunction(keyword);
        for (auto it = table[hash].begin(); it != table[hash].end(); ++it) {
            if (it->keyword == keyword) {
                table[hash].erase(it);
                std::cout << "Entry with keyword '" << keyword << "' removed from the table." << std::endl;
                return;
            }
        }
        std::cout << "No entry found with the keyword: " << keyword << std::endl;
    }

    void printTable() {
        std::cout << "Hash Table:" << std::endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Index " << i << ": ";
            for (const Entry& entry : table[i]) {
                std::cout << "[" << entry.keyword << ", " << entry.data << "] ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert("Football", "A team sport played with a round ball between two teams of 11 players.");
    hashTable.insert("Basketball", "A team sport played on a rectangular court between two teams of 5 players.");
    hashTable.insert("Tennis", "A racket sport played individually against a single opponent or between two teams of two players each.");
    hashTable.insert("Swimming", "A water-based sport performed by moving the body through water using limbs.");

    hashTable.printTable();
    std::cout << std::endl;

    std::cout << "Searching for keyword 'Football':" << std::endl;
    hashTable.search("Football");
    std::cout << std::endl;

    std::cout << "Searching for keyword 'Basketball':" << std::endl;
    hashTable.search("Basketball");
    std::cout << std::endl;

    std::cout << "Searching for keyword 'Hockey':" << std::endl;
    hashTable.search("Hockey");
    std::cout << std::endl;

    hashTable.remove("Tennis");

    hashTable.printTable();

    return 0;
}






