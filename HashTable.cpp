/*  HashTable.cpp
    Jean Paul López Pándura
    
    última modificación: 29/11/2023
    Este código es la implementación y definición de las funciones declaradas en
    el header de HastTable */
#include "HashTable.hpp"
// Construye una tabla de dispersión (HashTable) con un tamaño inicial.
HashTable::HashTable(size_t initialSize) : size(0) {
  table.resize(initialSize);
}
// Función de dispersión que calcula el índice en la tabla para una clave dada.
size_t HashTable::hashFunction(int ip) const {
  return ip % table.size();
}
// Inserta un par clave-valor en la tabla de dispersión y realiza rehash si es necesario.
void HashTable::insert(int ip, int repeticiones) {
  size_t index = hashFunction(ip);
  auto& bucket = table[index];

  for (auto& hashEntry : bucket) {
    if (hashEntry.getKey() == ip) {
      hashEntry.setValue(repeticiones);
      return;
    }
  }
  bucket.push_back(HashEntry(ip, repeticiones));
  size = size+1;
  if (loadFactor() > 0.75) {
    rehash();
  }
}
// Obtiene el valor asociado a una clave en la tabla de dispersión.
int HashTable::get(int ip) const {
  size_t index = hashFunction(ip);
  const auto& bucket = table[index];
  for (const auto& hashEntry : bucket) {
    if (hashEntry.getKey() == ip) {
      return hashEntry.getValue();
    }
  }

  return -1;
}
// Elimina una entrada asociada a una clave en la tabla de dispersión y realiza rehash si es necesario.
void HashTable::remove(int ip) {
  size_t index = hashFunction(ip);
  auto& bucket = table[index];
  bucket.remove_if([ip](const HashEntry& hashEntry) {
    return hashEntry.getKey() == ip;
  }); size = size - 1;
  if (loadFactor() < 0.25 && table.size() > 10) {
    rehash();
  }
}
// Obtiene el tamaño actual de la tabla de dispersión.
size_t HashTable::getSize() const {
  return size;
}
// Verifica si la tabla de dispersión está vacía.
bool HashTable::isEmpty() const {
  return size == 0;
}
// Imprime la tabla de dispersión y sus elementos.
void HashTable::printTable() const {
  for (int i = 0; i < table.size(); ++i) {
    cout << "Bucket " << i << ": ";
    for (const auto& hashEntry : table[i]) {
      cout << "[" << hashEntry.getKey() << ":" << hashEntry.getValue() << "] ";
    }
    cout << endl;
  }
}
// Calcula el factor de carga de la tabla de dispersión.
double HashTable::loadFactor() const {
  double result = static_cast<double>(size) / table.size();

  return result;
}
// Realiza la rehashing de la tabla de dispersión, duplicando su tamaño y redistribuyendo las entradas.
void HashTable::rehash() {
  size_t size = table.size() * 2;
  vector<list<HashEntry>> newTable(size);
  for (const auto& bucket : table) {
    for (const auto& hashEntry : bucket) {
      size_t index = hashEntry.getKey() % size;
      newTable[index].push_back(hashEntry);
    }
  }
  table = move(newTable);
}