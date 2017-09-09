#include "header.h"

int main(int argc, char *argv[]) {

	FILE *infile = NULL;

	char line[100] = "", copyLine[100] = "";

	int option = 0;

	//Pointer to the list
	Node *list = NULL;

	//open the file for reading and writing
	infile = fopen("musicPlayList.csv", "r+");
	if (infile != NULL) {

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


			//(  1  ) Load
			if (option == 1) {

				Record tempRecord;

				//while loop needed for reading in all of the data
				//While the end of the file has not been reached, we will continue to loop
				while (!feof(infile)) {

					//pull the line into "line" variable from infile
					fgets(line, 100, infile);

					//preserve the original line
					strcpy(copyLine, line);

					//pass the line to our processLine function
					//processLine will accept a line as a parameter and return a Record struct
					tempRecord = processLine(copyLine);

					//insert the song record into the list
					insertSong(&list, tempRecord);
				}

				//print the list of songs
				printList(list);

				system("pause");
			}//(  2  ) Store
			else if (option == 2) {
				
				
			}//end of application
		} while (option != 11);

	}
	

	return 0;
}