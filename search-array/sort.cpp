#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    infile.open("RanNum.txt");
    string Num[1000000];
    int count;

    while (infile.eof())
    {
        infile >> Num[count];
        count++;
    }
    
    return 0;
}