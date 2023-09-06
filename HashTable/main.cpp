// main.cpp : Defines the entry point for the console application.

/*
Program Name: Hash Table
Date: 2022-12-02
Author: Arsal Hussain sah210004
Module Purpose
This program helps understand the use of hash tables and with linear probing open addressing, locates those within hash table.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

// Defaults in solution folder
string inputFileNameStr = "namesids.txt";

//define namePair using C++  pair template class (2 strings - first & last name)
typedef pair<string, string> namePair;

//define stl::hash function for namePair keys
namespace std {

    template <> class hash <namePair> {
    public:
        size_t operator() (const namePair& namePair) const {
            return hash<string>() (namePair.first) ^ hash<string>() (namePair.second);
        }//size_t operator()
    };//class hash

}//namespace std


void displayHashTableLookupResult(pair<string, string> namePair, unordered_map<pair<string, string>, unsigned int>& hashTable) {

    stringstream stringStreamObj;

    stringStreamObj << setw(20) << left << namePair.first << setw(20) << left << namePair.second;
    cout << stringStreamObj.str();
    if (hashTable[namePair])
        cout << setw(29) << left << hashTable[namePair] << endl;
    else
        cout << "There is not a hash table entry for this name pair" << endl;

};


int main(int argc, char* argv[]) {

    //define hashTable as namepair keys and integer value identifications (open address linear probe)
    unordered_map<namePair, unsigned int> hashTable;

    //Put in the hash table the namePair keys and associated number ids from text file
    ifstream inputFileStreamObj;

    // $$ Check if file can be opened
    inputFileStreamObj.open(inputFileNameStr, ios::in);
    if (inputFileStreamObj.fail())
    {
        cout << "File could not bw opened !" << endl << "Press enter key once or twice to exit." << endl;
        exit(EXIT_FAILURE);
    }
    string   firstName, lastname;
    unsigned id;

    while (inputFileStreamObj)
    {
        inputFileStreamObj >> firstName >> lastname >> id;
        hashTable[namePair(firstName, lastname)] = id;
    }
    
    for (pair<namePair, unsigned int> element : hashTable)
    {
        cout << setw(20) << left << element.first.first;
        cout << setw(20) << left << element.first.second;
        cout << setw(20) << left << element.second << endl;
    }
    cout << endl << endl;

    //$$ look up 6 ids in hash table, 2 of each are not in the table
    displayHashTableLookupResult(namePair("Robyn", "Fenty"), hashTable);
    displayHashTableLookupResult(namePair("Aubrey", "Graham"), hashTable);
    displayHashTableLookupResult(namePair("Jerry", "Mathers"), hashTable);
    displayHashTableLookupResult(namePair("Betty", "Boop"), hashTable);
    displayHashTableLookupResult(namePair("Natasha", "Romanoff"), hashTable);
    displayHashTableLookupResult(namePair("Stefani", "Germanotta"), hashTable);
    displayHashTableLookupResult(namePair("Barry", "Soetoro"), hashTable);
    displayHashTableLookupResult(namePair("Stephanie", "Clifford"), hashTable);
    displayHashTableLookupResult(namePair("Monica", "Knavs"), hashTable);
    displayHashTableLookupResult(namePair("Curtis", "Jackson"), hashTable);
    displayHashTableLookupResult(namePair("Rihanna", "Knowles"), hashTable);
    displayHashTableLookupResult(namePair("Marion", "Morrison"), hashTable);
    displayHashTableLookupResult(namePair("Gal", "Varsano"), hashTable);

    

    cout << "Press enter key once or twice to end.";
    cin.ignore(); cin.get();

    return EXIT_SUCCESS;
}

