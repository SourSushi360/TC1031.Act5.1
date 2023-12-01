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
        std::vector<std::string> getRegistro();
        /* cambia el valor de key con el valor dado */
        void setKey(int key);
        /* agrega una entrada a registro */
        void addRegistro(std::string registro);
        /* imprime el registro */
        void print();
};
class HashTable {
    private:
        int size;
        std::vector<Entry> *table;
    public:
        /* constructor */
        HashTable(std::string line);
        /* destructor */
        ~HashTable();
        
        /* recibe una llave e inserta una entrada a la tabla */
        void insert(int key);
        /* recibe una llave y elimina una entrada de la tabla */
        void remove(int key);
        /* modifica una llave para hacerla un índice */
        int hashFunction(int key);
        /* muestra todos los valores en el hash */
        void print();
};
#endif