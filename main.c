#include "header.h"

int main(int argc, char *argv[]) {

	FILE *infile = NULL;

	infile = fopen("musicPlayList.csv", "r+");
	if (infile != NULL) {

		printf("Ready to go!\n");

	}
	

	return 0;
}