// Secret Vault
#include <iostream>
#include <list>

using namespace std;

class Vault{
    private:
        int capacity;
        list<string> storage;

    public:
        Vault(int capacity) : capacity(capacity), storage() {}

        void AddItem(string item){
            if (!IsFull()){
                storage.push_back(item);
            }
        }

        void RemoveItem(string item){
            storage.remove(item);
        }

        bool ContainsItem(string item){
            for (string search : storage){
                if (search == item)
                {
                    return true;
                }
                
            }
            return false;
        }

        bool IsFull(){
            return storage.size() >= capacity;
        }

        void print() {
            for (string item : storage) {
                cout << item << endl;
            }
        }
};



int main()
{
    int capacity, query;
    cin >> capacity;
    cin >> query;

    Vault vault(capacity);

    while (query--){
        int option;

        cin >> option;
        if (option == 1){
            string item;
            cin >> item;
            vault.AddItem(item);
        }
        else if (option == 2){
            string item;
            cin >> item;
            vault.RemoveItem(item);
        }
        else if (option == 3){
            string item;
            cin >> item;
            cout  << vault.ContainsItem(item) << endl;
        }
        else if (option == 4){
            cout << vault.IsFull() << endl;
        }
    }



}