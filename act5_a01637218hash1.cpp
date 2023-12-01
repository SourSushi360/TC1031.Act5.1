#include <iostream>
#include <list>
#include <cmath>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

class HashTable {
    private:
        int capacity;
        int prime;
        int prime2;
        list<int> *chainingTable;
        list<int> *quadraticTable;
        int collisionsChain;
        int collisionsQ;

    public:
        HashTable(int V){
            int size = getPrime(V);
            this -> capacity = size;
            chainingTable = new list<int>[capacity];
            quadraticTable = new list<int>[capacity];

            srand(time(NULL));

            int num = ((rand() + 1)^2) + capacity;
            prime = getPrime(num);
            prime2 = getPrime(2*num) % capacity;
        };
        ~HashTable() {
            delete[] chainingTable;
            delete[] quadraticTable;
            cout << "Destructor called" << endl;
        };
        bool checkPrime(int n);
        int getPrime(int n);

        void insertItemChaining(int key);
        void insertItemQuadratic(int data);
        void deleteItemC(int key);
        void deleteItemQ(int key);
        int hashFunctionC(int key);
        int hashFunctionQ(int data, int attempt);
        void displayHashC();
        void displayHashQ();

        int getCollisionsC() const;
        int getCollisionsQ() const;

};


bool HashTable::checkPrime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    int sqr = sqrt(n);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int HashTable::getPrime(int n) {
    if (n % 2 == 0) {
        n++;
    }
    while (!checkPrime(n)) {
        n += 2;
    }
    return n;
}

void HashTable::insertItemChaining(int data) {
    int index = hashFunctionC(data);

    // Chaining
    if (chainingTable[index].size() > 0) {
        collisionsChain++;
    }
    chainingTable[index].push_back(data);
    
}

void HashTable::insertItemQuadratic(int data) {
    // Quadratic probing
        int attempt = 0;
        int index = hashFunctionQ(data, attempt);

        while (!quadraticTable[index].empty()) {
            collisionsQ++;
            attempt++;
            index = hashFunctionQ(data, attempt);
            break;

        }
        quadraticTable[index].push_back(data);
    
    
}

void HashTable::deleteItemC(int key) {
    int index = hashFunctionC(key);
    chainingTable[index].remove(key);   
}

void HashTable::deleteItemQ(int key) {
    int attempt = 0;
    int index = hashFunctionQ(key, attempt);
    quadraticTable[index].remove(key);
}

int HashTable::hashFunctionC(int key) {
    return ((prime * prime2/key) % 5);
}

int HashTable::hashFunctionQ(int key, int attempt) {
    return ((prime * prime2/key + 2*attempt + attempt^2) % 5);
}

void HashTable::displayHashC() {
    for (int i = 0; i < capacity; i++) {
        cout << "table[" << i<< "]";
        for (auto x : chainingTable[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
}

void HashTable::displayHashQ() {
    for (int i = 0; i < capacity; i++) {
        cout << "table[" << i<< "]";
        for (auto x : quadraticTable[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
}

int HashTable::getCollisionsC() const {
    return collisionsChain;
    }

int HashTable::getCollisionsQ() const {
    return collisionsQ;
    }

int main() {
    int data[] = {166, 78, 133, 244, 64};
    int size = sizeof(data) / sizeof(data[0]);

    HashTable h(size);
    for (int i = 0; i < size; i++) {
        h.insertItemChaining(data[i]);
    }


    cout << endl << "Chaining" << endl;
    h.displayHashC();
    cout << endl;
    ///h.deleteItemC(78);
    //h.displayHashC();

    cout << "Quadratic" << endl;

    for (int i = 0; i < size; i++) {
        h.insertItemQuadratic(data[i]);
    }
    h.displayHashQ();
    cout << endl;
    //h.deleteItemQ(244);
    //h.displayHashQ();}

    cout << "Collisions in Chaining: " << h.getCollisionsC() << endl;
    cout << "Collisions in Quadratic: " << h.getCollisionsQ() << endl;
    return 0;
}