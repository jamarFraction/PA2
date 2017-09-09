#include "header.h"

int main(int argc, char *argv[]) {

	FILE *infile = NULL;

	char line[100] = "", copyLine[100] = "";

	int option = 0;

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
			printf("MENU\n1. Load\n2. Store\n3. Display\n");
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

					//create a node with the information gathered from the line

				}

				
				


			}//(  2  ) Store
			else if (option == 2) {
				
				
			}//end of application
		} while (option != 11);

	}
	

	return 0;
}