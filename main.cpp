#include "HashTable.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

void print(const string &ip, const HashTable &ipCount) {
    int connectionCount = ipCount.get(stoi(ip));
    int accessCount = 0;
    if (connectionCount != -1) {
        cout << "Colitions: " << connectionCount << '\n';
        cout << "Log entries:" << '\n';
        // abre bitacora
        ifstream logFile("bitacora3.txt");
        if (logFile.is_open()) {
            string logEntry;
            while (getline(logFile, logEntry)) {
                if (logEntry.find(ip) != string::npos) {
                    cout << logEntry << '\n';
                    accessCount++;
                }
            }
            // cierra bitácora
            logFile.close();
        }
    }
    cout << "Number of accesses in log: " << accessCount << endl;
}
void parseLogEntry(const string &logEntry, HashTable &ipCount) {
    istringstream iss(logEntry);
    string dat, tim, ip, message;
    iss >> dat >> tim >> ip >> message;
    if (!ip.empty()) {
        int currentConnections = ipCount.get(stoi(ip));
        currentConnections++;
        ipCount.insert(stoi(ip), currentConnections);
    }
}

// inicia main
int main() {
    HashTable table;
    ifstream registro("bitacora3.txt");
    if (registro.is_open()) {
        string linea;
        while (getline(registro, linea)) {
            parseLogEntry(linea, table);
        }
        registro.close();
    } else {
        cerr << "Unable to open log file." << endl;
        return 1;
    }
    string ipToSearch;
    cout << "Enter the IP address to search for: ";
    getline(cin, ipToSearch);
    print(ipToSearch, table);

    return 0;
}