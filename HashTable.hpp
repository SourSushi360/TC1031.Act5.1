/**************************************************************************
 * Encabezado de HashTable
 * Autor: Gerardo Rodríguez Hernández
 * Fecha: 24/11/2023
 * Descripcion:
 * El objetivo de esta actividad es crear una Tabla Hash
 **************************************************************************/

#ifndef HASHTABLE_h
#define HASHTABLE_h

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// Clase HashEntry para almacenar una entrada en la tabla hash
class HashEntry {
private:
    int key;
    int value;

public:
    // Constructor
    HashEntry(int k, int v) : key(k), value(v) {}
    ~HashEntry();

    // Métodos Accessors
    void setKey(int k);
    int getKey() const { return key; }
    int getValue() const { return value; }
    void setValue(int v) { value = v; }
};

class HashTable {
private:
    std::vector<std::list<HashEntry>> table;
    size_t size;

public:
    // Constructor
    HashTable(size_t initialSize = 10);
    ~HashTable();

    // Función de dispersión
    size_t hashFunction(int key) const;

    // Insertar un par clave-valor en la tabla hash
    void insert(int key, int value);

    // Obtener el valor asociado con una clave
    int get(int key) const;

    // Eliminar una entrada en la tabla hash
    void remove(int key);

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
