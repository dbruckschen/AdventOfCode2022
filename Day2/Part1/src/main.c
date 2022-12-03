// Day 2 Part 1

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

int main(void) {
	FILE *fp = fopen("input.txt", "r");
	
	int rounds[MAX_ROUNDS][SHAPES_PER_ROUND] = {0};
	int score = 0;

	if(fp) {
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

			// points for the shape
			score += rounds[i][1];

			// points for draw
			if(rounds[i][0] - rounds[i][1] == 0) {
				score += 3;
			}
			else {
				switch(rounds[i][1]) {
				case ROCK:
					if(rounds[i][0] == SCISSORS) {
						score += 6;
					}
					break;

				case PAPER:
					if(rounds[i][0] == ROCK) {
						score += 6;
					}
					break;

				case SCISSORS:
					if(rounds[i][0] == PAPER) {
						score += 6;
					}
					break;
				}
			}
		}
		printf("score %d\n", score);
	}
	else {
		printf("couldn't read .txt file\n");
	}
	
	return 0;
}
