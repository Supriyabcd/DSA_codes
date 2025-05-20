#include<iostream>
#include<vector>
#include<list>
using namespace std;

//hashtable with chaining
class HashTable{
    private:
    //number of buckets
        static const int TABLE_SIZE = 100;
    //hashtable->array of lists
        vector<list<pair<int, int>>>table;
    //hash function to map keys to indices
        int hashFunction(int key){
            return key % TABLE_SIZE;
        }

    public:
        //Constructor to initialize the hashtable
        HashTable(){
            table.resize(TABLE_SIZE);
        }

        void insert(int key, int value){
            int index = hashFunction(key);
            table[index].push_back(make_pair(key, value));

        }

        int search(int key){
            int index = hashFunction(key);
            for (auto& pair : table[index]){
                if (pair.first == key){
                    return pair.second;
                }
            }
            return -1; //key not found
        }

        void remove(int key){
            int index = hashFunction(key);
            table[index].remove_if([&key](const pair<int, int>& pair){
                return pair.first == key;
            });
            cout << key << "is deleted" << endl;
        }
};

int main()
{
    HashTable ht;

    int choice, key, value;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search " << endl;
        cout << "3. Delete " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: cout << "Enter the key and value : " ;
                cin >> key >> value;
                ht.insert(key, value);
            break;
        case 2: cout << "Enter the key : ";
                cin >> key;
                if (ht.search(key) == -1)
                    cout << "Not present in the hash table." << endl;
                else
                    cout << "Value at " << key << " = " << ht.search(key) <<endl;
            break;
        case 3: cout << "Enter the key : " ;
                cin >> key;
                ht.remove(key);      
            break;
        case 0: cout << "Exiting..." <<endl;
            exit(0);
            break;
        default: cout << "Invalid choice. Please try again." << endl;
            break;
        }
    
    }
    return 0;
}