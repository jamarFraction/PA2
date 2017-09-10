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

	char artist[50];
	char albumTitle[50];
	char songTitle[50];
	char genre[10];
	Duration songLength;
	int numberOfPlays;
	int rating;

} Record;

typedef struct node{

	Record data;
	struct Node *next;
	struct Node *previous;


} Node;


Node *makeNode(Record passedRecord);
Record processLine(char line[]);
Duration processDuration(char* stringDuration);
void insertSong(Node **list, Record songRecord);
void printList(Node *list);
void store(Node *list, FILE *outfile);
void displaySongs(Node *list);
void displaySongsByArtist(Node *list, char* artistName);