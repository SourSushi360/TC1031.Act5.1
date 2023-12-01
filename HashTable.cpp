/*  HashTable.cpp
    Jean Paul López Pándura
    
    última modificación: 29/11/2023
    Este código es la implementación y definición de las funciones declaradas en
    el header de HastTable */
#include "HashTable.hpp"

// Entry
  // constructor
  Entry::Entry(int key,std::string registro) {
    this->key = new int(key);
    this->registro[0] = registro;
  }
  Entry::Entry() {
    this->key = new int(0);
  }
  Entry::~Entry() {
    delete key;
  }
  // getters
  int Entry::getKey() {
    return this->key;
  }
  std::vector<std::string> Entry::getRegistro() {
    return *this->registro;
  }
  // setters
  void Entry::setKey(int key) {
    *this->key = key;
  }
  void Entry::addRegistro(std::string entry) {
    this->registro.push_back(entry);
  }
  // formato
  void Entry::print() {
    for (int i = 0;i < registro.size();i++) {
      std::cout << registro[i] << '\n';
    }
  }

// HashTable
  // constructor
  HashTable::HashTable(size_t size = 100) {
    *this->size = size;
    this->table[0] = new std::list<Entry>;
  }
  HashTable::~HashTable() {
    delete this->size;
    while (!this->table.empty()) {
      this->table.pop_back();
    }
  }
  // getters
  size_t HashTable::getSize() {
    return *this->size;
  }
  std::vector<std::string> get(int key) const {
    int index = hashFunction(key);
    for (Entry *u : table[index]) {
      if (u.getKey() == key) {
        return u.getRegistro();
      }
    }
    Entry *entrada;
    return entrada.getRegistro();
    delete entrada;
  }
  bool HashTable::isEmpty() {
    return !this->table.empty();
  }
  // hash
  size_t HashTable::hashFunction(int key) const {
    return key % table.size;
  }
  void HashTable::insert(std::string entrada) {
    std::istringstream stream(entrada);
    std::string mes,dia,hora,ip,mensaje;
    stream >> mes >> dia >> hora >> ip >> mensaje;
    int key = 0;
    int define_ip;
    std::getline(ip,define_ip,':');
    while (std::getline(define_ip,ip,'.')) {
      key += std::stoi(ip);
    }
    size_t index = hashFunction(key);
  }
  // formato
  void HashTable::print() {
    for (int i = 0;i < this->size;i++) {
      if (this->table[i] != nullptr) {
        std::cout << "Bucket " << i << ":\n";
        for (Entry *entrada : table[i]) {
          entrada->print();
        }
      }
    }
  }
