/*  HashTable.cpp
    Jean Paul López Pándura
    
    última modificación: 29/11/2023
    Este código es la implementación y definición de las funciones declaradas en
    el header de HastTable */
#include "HashTable.hpp"

// Constructor de HashEntry
HashEntry::HashEntry(int k, int v) {
}
HashEntry::~HashEntry(){
  delete this->key;
  delete this->value;
    
}

int HashEntry::getKey() const {
    // Retorna key
  return this->key;
}

int HashEntry::getValue() const {
    // Retorna value
  return this->value;
}

int HashEntry::setKey(int k){
    // Retorna key
  this->key = k;
}


void HashEntry::setValue(int v) {
    // Asigna v a value
  this->value = v;
}

// Constructor de HashTable
HashTable::HashTable(size_t initialSize) : table(initialSize), size(0) {
    // Inicializa table con initialSize listas vacías
    // Inicializa size con 0
    this->table= 
    this->size = 0;
}

size_t HashTable::hashFunction(int key) const {
    // Retorna key % tamaño de table

    return key % table.size();
}

void HashTable::insert(int key, int value) {
    // Obtiene el índice usando hashFunction
    // Para cada entrada en la lista correspondiente:
        // Si la clave ya existe:
            // Actualiza el valor
            // Sale del bucle
    // Crea una nueva entrada con key y value y la agrega a la lista
    // Incrementa size
    // Si loadFactor > 0.75:
        // Llama a rehash

    int index = hashFunction(key);
    HashEntry* entry = new HashEntry::HashEntry(key, value);
      if (table[index].getKey() == 0) {
        table[index] = entry;
        size++;
      } 
      else {
        HashEntry* current = table[index].next;
        while (current != nullptr) {
          if (current->getKey() == key) {
            current->setValue(value);
            break;
          }
          current = current->next;
        }
        if (current == nullptr) {
          current = entry;
          table[index].next = current;
          size++;
        }
        if (loadFactor() > 0.75) {
          rehash();
        }
      }
  }

int HashTable::get(int key) const {
    // Obtiene el índice usando hashFunction
      int index = hashFunction(key);
      for(HashEntry u: table[index]){
      if (u.getKey() == key) {
        return u.getValue();
      }
      return 0;
      }
}
    // Para cada entrada en la lista correspondiente:
        // Si la clave coincide:
            // Retorna el valor asociado
    // Retorna 0 (clave no encontrada)
}

void HashTable::remove(int key) {
    // Obtiene el índice usando hashFunction
    int index = hashFunction(key);
    for(HashEntry u: table[index]){
      if (u.getKey() == key) {
        u.setValue(0);
        size--;
      }
    }
    // Para cada entrada en la lista correspondiente:
        // Si la clave coincide:
            // Elimina la entrada
            // Decrementa size
            // Sale del bucle
}

size_t HashTable::getSize() const {
   return this->size;
    // Retorna size
}

bool HashTable::isEmpty() const {
    // Retorna true si size es 0, false en caso contrario
  if (this->size == 0) {
    return true;
  }
  return false;
}

void HashTable::printTable() const {
    // Para cada lista en table:
        // Imprime "Bucket i: " donde i es el índice de la lista
        // Para cada entrada en la lista:
            // Imprime la entrada
        // Imprime una nueva línea
  for (int i = 0; i < table.size(); i++) {
      std::cout<<"Bucket "<<i<<": ";
      for(HashEntry u: table[i]){
        std::cout<<u.getValue()<<" ";
      }
      std::cout<<"\n";
  }
}


double HashTable::loadFactor() const {
    // Retorna size / tamaño de table como un double
  return 
}

void HashTable::rehash() {
    // Crea una nueva tabla del doble de tamaño
    // Para cada entrada en la tabla existente:
        // Obtiene el nuevo índice usando el nuevo tamaño
        // Agrega la entrada a la lista correspondiente en la nueva tabla
    // Asigna la nueva tabla a table
}
