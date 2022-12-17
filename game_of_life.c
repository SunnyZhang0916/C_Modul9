#include "game_of_life.h"

#include <stdio.h>
#include <stdlib.h>

void init_cells(field *map)
{
	map->cells = calloc(map->rows, sizeof(cell *));

	for (int r = 0; r < map->rows; r++){
		map->cells[r] = calloc(map->cols, sizeof(cell));
	}
}

void free_cells(field map)
{
	for (int r = 0; r < map.rows; r++){
		free(map.cells[r]);
	}
	free(map.cells);
}

void game_rule(field *map, int r, int c)
{
	int count = count_neighbors(map,r,c);

	if(map->cells[r][c].current == ALIVE){
		if(count < 2 || count > 3){
			map->cells[r][c].next = DEAD;
		}else{
			map->cells[r][c].next = ALIVE;
		}
	}else{
		if(count == 3){
			map->cells[r][c].next = ALIVE;
		}else{
			map->cells[r][c].next = DEAD;
		}
	}
}

int count_neighbors(field *map, int r, int c)
{
	int count = 0;

 	for(int x = r - 1; x <= r + 1; x++){
		for(int y = c -1; y <= c + 1; y++){
			if(x != r || y != c){
				if(cell_states(map,x,y) == ALIVE){
					count++;
				}
			}
		}
	}
	return count;
}

int cell_states(field *map, int r, int c)
{
	if(r >= 0 && r < map->rows && c >= 0 && c < map->cols){
		return map->cells[r][c].current;
	}else{
		return DEAD;
	}
}

void update_field(field *map)
{
	for(int r = 0; r < map->rows; r++){
		for(int c = 0; c < map->cols; c++){
			map->cells[r][c].current = map->cells[r][c].next;
		}
	}
}

void print_field(field *map) {
	for (int r = 0; r < map->rows; r++) {
		for (int c = 0; c < map->cols; c++) {
			putchar(map->cells[r][c].current == ALIVE ? 'X' : '.');
			putchar(c + 1 < map->cols ? ' ' : '\n');
		}
	}
}
