/*

	Occupancy Timings
		Average of 5 for 50% occupancy: 0.093633
		Average of 5 for 70% occupancy: 0.100896
		Average of 5 for 80% occupancy: 0.105635
	
*/
const int TABLE_SIZE = 4000;

void hashTableInsert(char *word);
void hashTableDump();
int hashFunction(char* word);
void findWord(char *word);

void sortTable();