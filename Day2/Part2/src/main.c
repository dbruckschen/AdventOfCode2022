// Day 2 Part 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROUNDS 5000
#define SHAPES_PER_ROUND 2

#define MAX_LINE_LEN 5

enum Shapes {
	ROCK = 1,
	PAPER,
	SCISSORS,
};

enum Result {
	LOSE = 1, // X
	DRAW,  // Y 
	WIN  // Z
};

int main(void) {
	FILE *fp = fopen("input.txt", "r");
	
	if(fp) {
		int rounds[MAX_ROUNDS][SHAPES_PER_ROUND] = {0};
		int score = 0;
	
		for(int i = 0; i < MAX_ROUNDS; i++) {
			char current_line[MAX_LINE_LEN];
			if(fgets(current_line, MAX_LINE_LEN, fp) == NULL) {
				break;
			}

			// extract shapes and skip newlines etc.
			char m1 = current_line[0];
			char m2 = current_line[2];

			// convert A,B,C and X,Y,Z to 1,2,3
			rounds[i][0] = m1 - 64;
			rounds[i][1] = m2 - 87;

			enum Shapes choice = 0;

			switch(rounds[i][1]) {
			case LOSE:
				switch(rounds[i][0]) {
				case ROCK:
					choice = SCISSORS;
					break;
				case PAPER:
					choice = ROCK;
					break;
				case SCISSORS:
					choice = PAPER;
					break;
				}

				break;

			case DRAW:
				score += 3;

				switch(rounds[i][0]) {
				case ROCK:
					choice = ROCK;
					break;
				case PAPER:
					choice = PAPER;
					break;
				case SCISSORS:
					choice = SCISSORS;
					break;
				}
				break;

			case WIN:
				score += 6;

				switch(rounds[i][0]) {
				case ROCK:
					choice = PAPER;
					break;
				case PAPER:
					choice = SCISSORS;
					break;
				case SCISSORS:
					choice = ROCK;
					break;
				}
								
				break;
			}

			score += choice;

		}

		printf("score %d\n", score);
	}
	else {
		printf("couldn't read .txt file\n");
	}
	
	return 0;
}
