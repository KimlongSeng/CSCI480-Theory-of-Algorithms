#include "token.cpp"
#include "hashTable.cpp"
#include "heapsort.h"
#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int choice;
	char fname[30];
	char *word;
	bool readIn = false;
	while (choice != 0) {
		cout << endl;
		cout << "(1) Enter filename.txt to hash" << endl;
		cout << "(2) Find occurance of word in table" << endl;
		cout << "(3) Display 150 most common and least common words" << endl;
		cout << "(0) Quit program" << endl;
		cout << "Enter choice[0, 1, 2, 3]: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "Enter filename.txt : ";
			cin >> fname;
			if (openTokenFile(fname)) {
				readIn = true;
				auto start = chrono::steady_clock::now();
				while ((word = nextToken()))
					hashTableInsert(word);
				auto end = chrono::steady_clock::now();
				cout << "Time spend on hashing = "<< chrono::duration_cast<chrono::microseconds>(end - start).count()<< " microsecond"<<endl;
				cout << "Finished hashing" << endl;
				cout << endl;
				hashTableDump();

			cout << "******************************************************** "<< endl ;
			}
			break;
		case 2:
			if (!readIn) {
				cout << "Haven't hashed a file yet!" << endl;
				cout << "******************************************************** "<< endl ;
				break;
			}
			char temp[30];
			cout << "Enter word to find: ";
			cin >> temp;
			cout << endl;
			findWord(temp);
			break;
		case 3:
			if (!readIn) {
				cout << "Haven't hashed a file yet!" << endl;
				cout << "******************************************************** "<< endl ;
				break;
			}
			sortTable();
			cout << "150 most common used word printed to 'CommonUsedWord.txt'" << endl;
			cout << "150 most uncommon used word printed to 'UnCommonUsedWord.txt'" << endl;
			cout << "******************************************************** "<< endl;
			break;
		case 0:
			break;
		default:
			cout << "****** Please Enter option 0,1,2,3 ********" << endl;
			cout <<endl;
			break;
		}
	}
	return 0;
}