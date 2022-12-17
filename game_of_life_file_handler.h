#ifndef GAME_OF_LIFE_FILE_HANDLER_H
#define GAME_OF_LIFE_FILE_HANDLER_H

#include "game_of_life.h"
#include <stdio.h>

/*
 * Description: To check the program about if the
 *              call to the program has the right number of
 *              parameters. Then open the input and output files.
 * Input:       The parameters to the program and two pointers to file
 *              pointers.
 * Output:      Returns 0 when the files are correctly opened.
 *              Returns 1 as failure.
 */
int check_prog_params(int argc, const char *argv[],
                      FILE **in_file_p, FILE **out_file_p);

/*
 * Description: If it doesn't have any problem to open the file then
 *              close the file to avoid memory leak
 * Input:       The file of input and output
 * Output:      To let the both pointers be NULL.
 */
void close_files(FILE **in, FILE **out);

/*
 * Description: To load a configuration of the field structure from a
 *              file. It is the responsiblity of the caller to
 *              deallocate the dynamically allocated memory in the field
 *              structure through a call to the function destroy_field.
 *              The file pointed to by fp is closed.
 * Input:       A pointer to where the created field structure should be
 *              assigned and a file pointer to the file with the initial
 *              configuration.
 * Output:      Returns 0 on success, the field structure is created
 *              with the configuration from the file.
 *              Returns a non-zero value on failure.
 */
int load_config_from_file(field *the_field, FILE *fp);

/* Description: To save the current configuration of the field to a
*               specified file. The file pointed to by fp is closed.
* Input:        The field structure and a file pointer to the file
*               where the final configuration should be saved.
* Output:       Returns 0 on success, the current configuration in the
*               field is written to the file.
*               Returns a non-zero value on failure.
*/
int save_config_to_file(const field the_field, FILE *fp);

#endif // GAME_OF_LIFE_FILE_HANDLER_H
