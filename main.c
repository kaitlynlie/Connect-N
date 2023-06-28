#include "setup.h"
#include "game.h"

int main (int argc, char** argv) {
  int num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, len_player_pieces = 0, current = 0, player_turn = 0, counter = 0;
  char blank = '*';
  char** board;
  char* player_pieces = "XO";
  board_input(argc, argv, &num_rows, &num_columns, &number_of_pieces_in_a_row_needed_to_win, &blank, player_pieces, len_player_pieces); // reference from Winter2021TicTacToe in Google Drive
  board = create_board(num_rows, num_columns, blank);
  setup(argc, argv, &board, &num_rows, &num_columns, &number_of_pieces_in_a_row_needed_to_win, &blank, &player_pieces, &current);
  play_game(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank, player_pieces, player_turn, counter);
  clean_up(board, num_rows, num_columns, player_pieces);
  return 0;
}
