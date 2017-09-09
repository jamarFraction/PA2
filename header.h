#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

typedef struct duration {

	int minutes;
	int seconds;

} Duration;

typedef struct record {

	/*Artist – a string
	Album title – a string
	Song title – a string
	Genre – a string
	Song length - a struct Duration type consisting of seconds and minutes, both integers
	Number times played – an integer
	Rating – an integer(1 – 5)*/

	char* artist;
	char* albumTitle;
	char* songTitle;
	char* genre;
	Duration songLength;
	int numberOfPlays;
	int rating;

} Record;

typedef struct node{

	Record data;
	struct Node *next;
	struct Node *previous;


} Node;

Record processLine(char line[]);
Duration processDuration(char* stringDuration);