/*
 * Description:  Implementation of Conway's Game of Life.
 * Author:       Sunny Zhang
 * CS username:  dv21szg
 * Date:         2022.03.18
 * Input:        To read the data from the file then to save the new data in the file.
 * Output:       Prints the game field in each step.
 * Limitations:  The files can't be read
 */
#include "game_of_life.h"
#include "game_of_life_file_handler.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	field map;
	FILE *in = NULL, *out = NULL;

	if (check_prog_params(argc, argv, &in, &out) != 0) {
		close_files(&in, &out);
		return 1;
	}

	if (load_config_from_file(&map, in) != 0) {
		close_files(&in, &out);
		return 1;
	}

	print_field(&map);
	printf("Select one of the following options:\n");
	printf("(enter) Step\n");
	printf("(any) Save and exit\n");

	while (getchar() == '\n') {

		for (int r = 0; r < map.rows; r++)
			for (int c = 0; c < map.cols; c++)
				game_rule(&map,r,c);

		update_field(&map);

		print_field(&map);
		printf("Select one of the following options:\n");
		printf("(enter) Step\n");
		printf("(any) Save and exit\n");
	}

	if (save_config_to_file(map, out) != 0) {
		close_files(&in, &out);
		return 1;
	}

	close_files(&in, &out);
	return 0;
}
