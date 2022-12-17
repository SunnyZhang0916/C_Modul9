#include "game_of_life_file_handler.h"

#include <stdio.h>
#include <stdlib.h>

int check_prog_params(int argc, const char *argv[],
                      FILE **in_file_p, FILE **out_file_p)
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <input configuration file> <output configuration file>\n", argv[0]);
		return 1;
	}

	*in_file_p = fopen(argv[1], "r");

	/*if input file can't be opened, then return 1 to main*/
	if (*in_file_p == NULL) {
		fprintf(stderr, "Could not open the file: %s\n", argv[1]);
		return 1;
	}

	*out_file_p = fopen(argv[2], "w");

	if (*out_file_p == NULL) {
		fprintf(stderr, "Could not open the file: %s\n", argv[2]);
		return 1;
	}

	return 0;
}

void close_files(FILE **in, FILE **out)
{
	if (*in != NULL) {
		fclose(*in);
		*in = NULL;
	}

	if (*out != NULL) {
		fclose(*out);
		*out = NULL;
	}
}

int load_config_from_file(field *the_field, FILE *fp)
{
	if (fscanf(fp, "%d,%d", &the_field->rows, &the_field->cols) != 2) {
		fprintf(stderr, "Incorrect configuration file format\n");
		return 1;
	}

	init_cells(the_field);

	for (int r = 0; r < the_field->rows; r++){
		for (int c = 0; c < the_field->cols; c++){
			for (the_field->cells[r][c].current = fgetc(fp); the_field->cells[r][c].current != '0' && the_field->cells[r][c].current != '*'; ){
				the_field->cells[r][c].current = fgetc(fp);
			}
	  }
	}
	return 0;
}

int save_config_to_file(const field the_field, FILE *fp)
{
	fprintf(fp, "%d,%d\n", the_field.rows, the_field.cols);

	for (int r = 0; r < the_field.rows; r++) {
		for (int c = 0; c < the_field.cols; c++){
			fputc(the_field.cells[r][c].current, fp);
		}
		fputc('\n', fp);
	}
	free_cells(the_field);

	return 0;
}
