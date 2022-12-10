#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RUCKSACKS 300
#define RUCKSACK_SIZE 128

struct rucksack {
	char first_compartment[RUCKSACK_SIZE];
	char second_compartment[RUCKSACK_SIZE];

	char compartment_shared_item;
};

int calculate_priority_sum(struct rucksack *sacks, int num_rucksacks) {
	int sum = 0;
	for(int i = 0; i < num_rucksacks; i++) {
		if(sacks[i].compartment_shared_item >= 'A' && sacks[i].compartment_shared_item <= 'Z') {
			sum += sacks[i].compartment_shared_item - 38;
		}
		else if(sacks[i].compartment_shared_item >= 'a' && sacks[i].compartment_shared_item <= 'z') {
			sum +=  sacks[i].compartment_shared_item - 96;
		}
	}

	return sum;
}

int main(void) {
	FILE *fp;
	fopen_s(&fp, "input.txt", "r");
	//fopen_s(&fp, "debug.txt", "r");

	int num_rucksacks = 0;
	struct rucksack rucksacks[NUM_RUCKSACKS];
	
	if(!fp) {
		printf("couldn't read .txt file, terminate programm\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < NUM_RUCKSACKS; i++) {
		char line[RUCKSACK_SIZE];
				
		if(fgets(line, RUCKSACK_SIZE, fp) == NULL) {
			break;
		}
		size_t len = strlen(line);
		size_t comp_len = len/2;
		memcpy(rucksacks[i].first_compartment, line, comp_len);
		memcpy(rucksacks[i].second_compartment, line+comp_len, comp_len);

		bool found_shared_item = false;
		for(int c1 = 0; c1 < comp_len && !found_shared_item; c1++) {
			char current_item_c1 = rucksacks[i].first_compartment[c1];
			
			for(int c2 = 0; c2 < len/2; c2++) { 
				if(current_item_c1 == rucksacks[i].second_compartment[c2]) {
					// found the shared item for both compartments
					rucksacks[i].compartment_shared_item = current_item_c1;
					found_shared_item = true;
					break;
				}
			}
		}
		
		num_rucksacks++;
	}

	int prio_sum = calculate_priority_sum(rucksacks, num_rucksacks);
	printf("%d\n", prio_sum);

	return 0;
}


