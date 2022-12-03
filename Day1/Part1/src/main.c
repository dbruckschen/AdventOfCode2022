#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 5000
#define MAX_LINE_LEN 8

int main(void) {
	FILE *fp = fopen("input.txt", "r");

	int current_biggest_calorie_count = 0;

	if(fp) {
		char input[MAX_ROWS][MAX_LINE_LEN];
		
		int current_elf_calorie_count = 0;
		for(int i = 0; i < MAX_ROWS; i++) {
			if(fgets(input[i], MAX_LINE_LEN, fp) == NULL) {
				break;
			}
			//printf("%s", input[i]);

			// zero means equal strings
			if(strcmp(input[i], "\n") != 0) {
				current_elf_calorie_count += atoi(input[i]);
			}
			else {
				if(current_elf_calorie_count > current_biggest_calorie_count) {
					current_biggest_calorie_count = current_elf_calorie_count;
				}
				current_elf_calorie_count = 0;
			}
			
		}
	}
	else {
		printf("fopen failed\n");
		return 0;
	}

	printf("The Elf with the most calories has a total of %d calories.\n", current_biggest_calorie_count);

	return 0;
}

