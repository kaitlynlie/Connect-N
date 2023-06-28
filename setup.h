#include <stdbool.h>
#ifndef SETUP_H
  #define SETUP_H

  void board_input(int argc, char** argv, int* num_rows, int* num_columns, int* number_of_pieces_in_a_row_needed_to_win, char* blank, char* player_pieces, int len_player_pieces);
  char** create_board(int num_rows, int num_columns, char blank);
  void display_board(char** board, int num_rows, int num_columns);
  bool same_column(char** board, int row, int col, int number_of_pieces_in_a_row_needed_to_win);
  bool same_row(char** board, int row, int col, int number_of_pieces_in_a_row_needed_to_win);
  void destroy_board(char** board, int num_rows, int num_columns);

#endif
