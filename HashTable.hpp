/*  HashTable.hpp
    Jean Paul López Pándura
    
    última actualización: 01/12/2023
    Archivo que define las funciones para hashtable */
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
class Entry {
    private:
        /* la dirección IP pasada a int */
        int *key;
        /* un vector de strings con el registro de las veces que
        aparece en la bitácora */
        std::vector<std::string> registro;
    public:
        /* constructor */
        Entry(int key,std::string registro);
        /* constructor default */
        ~Entry();
        /* destructor */
        ~Entry();
        /* regresa el valor de key */
        int getKey();
        /* recibe un int que es usado como índice
        regresa el valor en la posición dada dentro del vector registro */
        std::string getRegistro(int indice);
        /* cambia el valor de key con el valor dado */
        void setKey(int key);
        /* agrega una entrada a registro */
        void addRegistro(std::string registro);
        /* imprime el registro */
        void print();
};
class HashTable {
    private:
        size_t *size;
        std::vector<std::list<Entry>*> table;
    public:
        /* constructor */
        HashTable(size_t size = 100);
        /* destructor */
        ~HashTable();
        /* regresa el tamaño de la tabla */
        size_t getSize();
        /* verifica si la tabla está vacía */
        bool isEmpty();
        /* imprime la tabla hash */
        void print();
        /* inserta una nueva entrada a la tabla */
        void insert(std::string entrada);
        /* elimina una entrada en la tabla usando su key */
        void remove(int key);
        /* función de dispersión */
        size_t hashFunction(int key) const;
        /* regresa la entrada asociada con una llave */
        std::vector<std::string> get(int key) const;
};
#endif