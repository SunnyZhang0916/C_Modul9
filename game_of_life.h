#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define ALIVE '*'
#define DEAD '0'

/*
 * Description: A data struct for cell which including the
                current situation and the next times.
 */
typedef struct
{
	char current;
	char next;
} cell;

/*
 * Description:  A data struct for field for 2D array with rows
                 and cols
 */
typedef struct
{
	int rows;
	int cols;
	cell **cells; // 2D array
} field;

/*
 * Description: To initial memorry allocation for 2D array
 * Input:       a pointer to a struct for game field data
 */
void init_cells(field *map);

/*
 * Description: To deallocate 2D array
 * Input:       a struct for game field data
 */
void free_cells(field map);

/*
 * Description: To follow the game rules.
 * Input:       a pointer to a struct for game field data and
 *              the current position of rows and column.
 */
void game_rule(field *map, int r, int c);

/*
 * Description: To count the neighbors who are alive.
 * Input:       a pointer to a struct for game field data and
 *              the current position of rows and column.
 * Output:      The numbers of alive neighbors.
 */
int count_neighbors(field *map, int r, int c);

/*
 * Description: To declare the status of the cell.
 * Input:       a pointer to a struct for game field data and
 *              the current position of rows and column.
 * Output:      The status of the cell.
 */
int cell_states(field *map, int r, int c);

 /* Description: To update the current status of the world
  * Input:       a pointer to a struct for game field data
  */
void update_field(field *map);

/*
 * Description: To print out the current status of the world.
 * Input:       a pointer to a struct for game field data
 */
void print_field(field *map);

#endif // GAME_OF_LIFE_H
