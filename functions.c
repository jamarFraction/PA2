#include "header.h"

Node *makeNode() {

	//making a doubly linked node
	Node *container;

	//allocate memory for the Node
	container = (Node *)malloc(sizeof(Node));

	//initialize the next and previous pointers before returning
	container->next = NULL;
	container->previous = NULL;

	//initailize the Record struct? may be back..

	return container;
}

Record processLine(char line[]) {

	char *currentValue, *currentDuration;
	char lineCopy[100] = "";
	Record tempRecord;
	char fullName[25];

	char *ptr; //needed for strtod

	//int needed for comparison for artist and line length
	int lineLength = strlen(line);

	//preserve the original line by copying the passed line to our local currentLine variable
	strcpy(lineCopy, line);






	//Artist
	//check must be made for artists with FIrst and Last name VS. Single moniker
	//get (or attempt to get) a token with quotation marks
	currentValue = strtok(lineCopy, "\"");

	//Artist goes by a single Moniker
	if (strlen(currentValue) == lineLength) {
		//single moniker name
	
		//testing
		//Resetting the line for use with strtok
		strcpy(lineCopy, line);

		//grab the single name
		currentValue = strtok(lineCopy, ",");

		//set the artist name
		tempRecord.artist = currentValue;

	}
	else {
		//Artist goes by a first and last name
		//set the artist name
		tempRecord.artist = currentValue;
	}





	//Album Title
	//get the album title
	currentValue = strtok(NULL, ",");

	//set the value in the record
	tempRecord.albumTitle = currentValue;



	
	//Song Title
	//get the song title
	currentValue = strtok(NULL, ",");

	//set the value in the record
	tempRecord.songTitle = currentValue;




	//Genre
	//get the genre
	currentValue = strtok(NULL, ",");

	//set the value in the record
	tempRecord.genre = currentValue;




	//Song Length
	//get the song duration
	//different variable being used here so as not to currupt the values
	//Setting the variable here but will not set the value into the record until after plays and rating
	currentDuration = strtok(NULL, ",");




	//Number of Plays
	currentValue = strtok(NULL, ",");

	//set the value in the record after casting (int <--- double)
	tempRecord.numberOfPlays = (int)strtod(currentValue, &ptr);




	//Rating
	//get the rating
	currentValue = strtok(NULL, ",");

	//set the value in the record after casting (int <--- double)
	tempRecord.rating = (int)strtod(currentValue, &ptr);
	



	//Duration part 2
	//send currentDuration to our processor function
	//set our tempRecord.duration values by setting it's value to 'Duration' type struct that will be returned*/
	tempRecord.songLength = processDuration(currentDuration);



	//return the Record struct
	return tempRecord;
}

Duration processDuration(char* stringDuration) {

	Duration tempDuration;
	int tempMinutes = 0, tempSeconds = 0;
	char *ptr, *stringDurationCOPY;

	char minutes[10];

	strcpy(minutes, stringDuration);

	stringDurationCOPY = minutes;

	//add a ":" to the end of the string. This will make tokenizing easier
	strcat(stringDurationCOPY, ":");

	//grab the minutes by casting (int <-- double) the token from stringDuration
	tempMinutes = (int)strtod(strtok(stringDurationCOPY, ":"), &ptr);

	//do the same for setting the seconds
	tempSeconds = (int)strtod(strtok(NULL, ":"), &ptr);

	//set the minutes and seconds values into the tempDuration that will be returned
	tempDuration.minutes = tempMinutes;
	tempDuration.seconds = tempSeconds;

	//return the Duration struct
	return tempDuration;

}