#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "setup.h"
#include "game.h"

// sets up game with players and creating the board
// reference from Winter2021TicTacToe in Google Drive
void setup(int argc, char** argv, char*** board, int* num_rows, int* num_columns, int* number_of_pieces_in_a_row_needed_to_win, char* blank, char** player_pieces, int* current) {
  *player_pieces = calloc(2, sizeof(**player_pieces));
  (*player_pieces)[0] = 'X';
  (*player_pieces)[1] = 'O';
  board_input(argc, argv, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank, *player_pieces, 2);
  *board = create_board(*num_rows, *num_columns, *blank);
  *current = 0;
}

// player takes turn while the game is not gameover
// switches player_goes
// shows results once game is over
void play_game(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank, char* player_pieces, int player_turn, int counter) {
  do {
    player_takes_turn(board, num_rows, num_columns, blank, player_pieces[player_turn], player_turn + 1, counter);
    if(gameover(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank)) {
      break;
    }
    switch_players(&player_turn);
  } while (true);
  results(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank, player_turn + 1);
}

// displays board
// records the move from the player and displays on board
void player_takes_turn(char** board, int num_rows, int num_columns, char blank, char player_pieces, int player, int counter) {
  int row = 0, col = 0;
  display_board(board, num_rows, num_columns);
  printf("\n");
  record_move(board, &row, &col, num_rows, num_columns, blank, player);
  player_goes(board, row, col, num_rows, blank, player_pieces, counter);
}

// gets the move from the players
// reference from Winter2021TicTacToe in Google Drive
void record_move(char** board, int* row, int* col, int num_rows, int num_columns, char blank, int player) {
  int num_args_read;
  do {
    printf("Enter a column between %d and %d to play in: ", (num_rows - num_rows), num_columns - 1);
    num_args_read = scanf("%d", col);
  } while (!valid_move(num_args_read, board, *row, *col, num_rows, num_columns, blank));
}

// places the piece from the player on the board
void player_goes(char** board, int row, int col, int num_rows, char blank, char piece, int counter) {
  for (int i = num_rows - 1; i >= 0; --i) {
    if (board[i][col] == blank) {
      row = i;
      board[i][col] = piece;
      break;
    }
  }
}

// checks if the column entered is valid
// reference from Winter2021TicTacToe in Google Drive
bool valid_format (const int num_args_read, const int num_args_needed) {
  char character;
  bool good_format = num_args_read == num_args_needed;
  do {
    scanf("%c", &character);
    if (!isspace(character)) {
      good_format = false;
    }
  } while (character != '\n');
  return good_format;
}

// checks if number is in between the lower and higher column
bool inbetween(int number, int lower, int higher) {
  return number >= lower && number <= higher;
}

// checks if the column entered has valid format and is in between the int_columns
bool valid_move(int num_args_read, char** board, int row, int col, int num_rows, int num_columns, char blank) {
  return valid_format(num_args_read, 1) && inbetween(row, 0, num_rows - 1) && inbetween(col, 0, num_columns - 1) && board[row][col] == blank;
}

// switches the turns of the players
void switch_players(int* turn) {
  if (*turn == 0) {
    *turn = 1;
  } else {
    *turn = 0;
  }
}

// displays the results
// prints who won or if it was a tie game
void results (char** board, int num_rows, int num_cols, int number_of_pieces_in_a_row_needed_to_win, char blank, int player) {
  display_board(board, num_rows, num_cols);
  if (won(board, num_rows, num_cols, number_of_pieces_in_a_row_needed_to_win, blank)) {
    printf("\nPlayer %d Won!\n", player);
  } else {
    printf("\nTie game!");
  }
}

// displays if the game is over or not
// if the game has a winner or tied, the game is over
bool gameover(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  return won(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank) || tied(board, num_rows, num_columns, blank);
}

// displays if the game is won
// if the game has a horizontal, vertical, or diagonal win, the game is over
bool won(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  return horizontal(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank) || vertical(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank) || diagonal(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank);
}

// displays if the game is tied
// if the board is empty with no winner, then it's tied
bool tied(char** board, int num_rows, int num_columns, char blank) {
  for (int i = 0; i < num_rows; ++i) {
    for (int j = 0; j < num_columns; ++j) {
      if(board[i][j] == blank) {
        return false;
      }
    }
  }
  return true;
}

// checks if there is a horizontal win
bool horizontal(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  for (int i = 0; i < num_rows; ++i) {
    if (same_row(board, i, num_columns, number_of_pieces_in_a_row_needed_to_win)) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}

// checks if there is a vertical win
bool vertical(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  for (int i  = 0; i < num_columns; ++i) {
    if (same_column(board, num_rows, i, number_of_pieces_in_a_row_needed_to_win)) {
      return true;
    }
  }
  return false;
}

// checks if there is a right diagonal win
// slopes like '\'
bool left_diagonal(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  int counter = 0;
  for (int i = 0; i < num_columns - 1; ++i) {
    for (int j = 0; j < num_rows - 1; ++j) {
      if ((i + j + 1) > (num_columns - 1)) {
        continue;
      }
      if ((board[j][i + j] == board[j + 1][i + j + 1]) && (board[j][i + j] != blank)) {
        ++counter;
          if (counter >= number_of_pieces_in_a_row_needed_to_win - 1) {
            return true;
          }
          if ((j + 1) == (num_rows - 1) && (i + j + 1) == (num_columns - 1)) {
            ++counter;
            if (counter >= number_of_pieces_in_a_row_needed_to_win) {
              return true;
            }
          }
      } else {
        counter = 0;
      }
    }
  }
  return false;
}

// checks if there is a left diagonal win
// slopes like '/'
bool right_diagonal(char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  int counter = 0;
  for (int i = 0; i < num_columns - 1; ++i) {
    for(int j = num_rows - 1; j > 0; --j) {
      if((i + (num_rows - j)) > (num_columns - 1)) {
        continue;
      }
      if((board[j][i + (num_rows - j - 1)] == board[j - 1][i + (num_rows - j)]) && (board[j][i + (num_rows - j - 1)] != blank)) {
        ++counter;
        if (counter >= number_of_pieces_in_a_row_needed_to_win - 1) {
          return true;
        }
        if ((j - 1) == 0 && (i + (num_rows - j)) == (num_columns - 1)) {
          ++counter;
        }
        if (counter >= number_of_pieces_in_a_row_needed_to_win) {
          return true;
        }
      } else {
        counter = 0;
      }
    }
  }
  return false;
}

// checks if there is a diagonal win from the left or right
bool diagonal (char** board, int num_rows, int num_columns, int number_of_pieces_in_a_row_needed_to_win, char blank) {
  return right_diagonal(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank) || left_diagonal(board, num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win, blank);
}

// cleans up the board
void clean_up(char** board, int num_rows, int num_columns, char* player_pieces) {
  destroy_board(board, num_rows, num_columns);
  free(player_pieces);
}
