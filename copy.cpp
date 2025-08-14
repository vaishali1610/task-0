#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main (){
    string src ="source.csv";
    string dest= "destination.csv";
    ifstream file1(src, ios::binary | ios::ate);
    streamsize size1 = file1.tellg(); //tellg returns the current position
    //  Case 1: source and destination are same
    if(src==dest)
     cout << "source and destination could not be same";
    // Case 2: A does not exist
    if(!file1.is_open())
        cout<< "Source does not exist";
    // Case 3: A exists but it is empty
    else if(size1==0){
     cout << "source file is empty";
     return 1;
    }
    // Proceeding with b
    ifstream file2(dest, ios::binary | ios::ate);
    streamsize size2= file2.tellg();
    // Case 4: B does not exist -> create a new file or B exists and empty -> add the data
    if(!file2.is_open() || size2==0){
    file1.seekg(0,ios::beg);
  ofstream file2(dest, ios::binary);
  file2 << file1.rdbuf();
        }
}



