/*  HashTable.hpp
    Jean Paul López Pándura
    
    última actualización: 01/12/2023
    Archivo que define las funciones para hashtable */
#ifndef HASHTABLE_h
#define HASHTABLE_h

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

// Clase HashEntry para almacenar una entrada en la tabla hash
class HashEntry {
private:
    int ip;
    int repeticiones;

public:
  // Constructor
  HashEntry(int k, int v) : ip(k), repeticiones(v) {}

  // Métodos Accessors
  int getKey() const { return ip; }
  int getValue() const { return repeticiones; }
  void setValue(int v) { repeticiones = v; }
};

class HashTable {
private:
  std::vector<std::list<HashEntry>> table;
  size_t size;

public:
  // Constructor
  HashTable(size_t initialSize = 10);

  // Función de dispersión
  size_t hashFunction(int ip) const;

  // Insertar un par clave-valor en la tabla hash
  void insert(int ip, int repeticiones);

  // Obtener el valor asociado con una clave
  int get(int ip) const;

  // Eliminar una entrada en la tabla hash
  void remove(int ip);

  // Obtener el tamaño de la tabla hash
  size_t getSize() const;

  // Verificar si la tabla hash está vacía
  bool isEmpty() const;

  // Imprimir la tabla hash
  void printTable() const;

private:
  // Calcular el factor de carga de la tabla hash
  double loadFactor() const;

  // Función para volver a dispersar la tabla hash cuando la carga es demasiado alta
  void rehash();
};

#endif