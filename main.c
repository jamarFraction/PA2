#include "header.h"

int main(int argc, char *argv[]) {

	FILE *dataFile = NULL;

	char line[100] = "", copyLine[100] = "";

	int option = 0;

	//Pointer to the list
	Node *list = NULL;

	//open the file for reading and writing
	dataFile = fopen("musicPlayList.csv", "r");
	if (dataFile != NULL) {

		printf("Ready to go!\nPress enter..");
		getchar();


		//Start Digital Music Manager
		do {
			option = 0;
			system("cls");

			printf("Digital Music Manager\n");
			printf("MENU\n(1.) Load\n(2.) Store\n(3.) Display\n(4.) Insert\n(5.) Delete\n(6.) Edit\n(7.) Sort\n(8.) Rate\n(9.) Play\n(10.) Shuffle\n(11.) Exit\n");
			printf("Note: Only current functionality of: (1) load, (2) store, (3) display, (6) edit, (8) rate, (9) play, and (11) exit\n");
			scanf("%d", &option);


			
			if (option == 1) {
				//(  1  ) Load
				Record tempRecord;

				//while loop needed for reading in all of the data
				//While the end of the file has not been reached, we will continue to loop
				while (!feof(dataFile)) {

					//pull the line into "line" variable from infile
					fgets(line, 100, dataFile);

					//preserve the original line
					strcpy(copyLine, line);

					//pass the line to our processLine function
					//processLine will accept a line as a parameter and return a Record struct
					tempRecord = processLine(copyLine);

					//insert the song record into the list
					insertSong(&list, tempRecord);
				}

				//close the file
				fclose(dataFile);

				//print the list of songs
				printList(list);

				system("pause");
			}
			else if (option == 2) {
				//(  2  ) Store
				//The “store” command writes the current records, in the dynamic
				//doubly linked list, to the musicPlayList.csv file. The store will completely
				//overwrite the previous contents in the file.
				dataFile = fopen("musicPlayList.csv", "w");

				store(list, dataFile);
				
				fclose(dataFile);
			}
			else if (option == 3) {
				//( 3 ) Display

			}
			//end of application
		} while (option != 11);

	}
	

	return 0;
}