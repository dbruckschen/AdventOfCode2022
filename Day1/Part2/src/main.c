#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 5000
#define MAX_LINE_LEN 8

// if n is bigger than any of the 3 elements of the num array returns it's index, otherwise -1
int number_bigger_than_array_element(int n, int num[3]) {
	for(int i = 0; i < 3; i++) {
		if(n > num[i]) {
			return i;
		}
	}

	return -1;
}

// sort the array in ascending order
void sort_array_asc(int *a, int len) {
	bool sorted = false;

	while(!sorted) {
		sorted = true;
		for(int i = 0; i < len-1; i++) {
			if(a[i] > a[i+1]) {
				int tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				sorted = false;
			}
		}
	}
}

int main(void) {
	FILE *fp = fopen("input.txt", "r");

	int current_top3_elf_calorie_count[3] = {0};

	if(fp) {
		char input[MAX_ROWS][MAX_LINE_LEN];

		int current_elf_calorie_count = 0;
		for(int i = 0; i < MAX_ROWS; i++) {
			if(fgets(input[i], MAX_LINE_LEN, fp) == NULL) {
				break;
			}

			// zero means equal strings
			if(strcmp(input[i], "\n") != 0) {
				current_elf_calorie_count += atoi(input[i]);
			}
			else {

				int index = number_bigger_than_array_element(current_elf_calorie_count, current_top3_elf_calorie_count);
				if(index != -1) {
					current_top3_elf_calorie_count[index] = current_elf_calorie_count;
					sort_array_asc(current_top3_elf_calorie_count, 3);
				}
				current_elf_calorie_count = 0;
			}
			
		}
	}
	else {
		printf("fopen failed\n");
		return 0;
	}

	int total_elves_calories = 0;
	for(int i = 0; i < 3; i++) {
		printf("#%d elf calorie count: %d.\n", i, current_top3_elf_calorie_count[i]);
		total_elves_calories += current_top3_elf_calorie_count[i];
	}

	printf("total calories of the top 3 elves: %d\n", total_elves_calories);

	return 0;
}

