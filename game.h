#include <stdbool.h>
#ifndef GAME_H
  #define GAME_H

  void setup(int argc, char** argv, char*** board, int* num_rows, int* num_columns, int* number_of_pieces_in_a_row_needed_to_win, char* blank, char** player_pieces, int* current);
  void play_game(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank, char* player_pieces, int player_turn, int counter);
  void player_goes(char** board, int row, int col, int num_rows, char blank, char player_pieces, int counter);
  void player_takes_turn(char** board, int num_rows, int num_columns, char blank, char player_pieces, int player, int counter);
  void record_move(char** board, int* row, int* col, int num_rows, int num_columns, char blank, int player);
  void switch_players(int* turn);
  void results (char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank, int player);
  bool gameover(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool won(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool tied(char** board, int num_rows, int num_columns, char blank);
  bool horizontal(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool vertical(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool diagonal (char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool left_diagonal(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool right_diagonal(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank);
  bool valid_move(int num_args_read, char** board, int row, int col, int num_rows, int num_columns, char blank);
  void clean_up(char** board, int num_rows, int num_columns, char* player_pieces);

#endif
