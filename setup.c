#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup.h"

// gets users input for board dimensions from the command line
void board_input(int argc, char** argv, int* num_rows, int* num_columns, int* number_of_pieces_in_a_row_needed_to_win, char* blank, char* player_pieces, int len_player_pieces) {
  int num_args_read = 0;
  if (argc == 4) {
    char should_not_be_read;
    num_args_read += sscanf(argv[1], "%d", num_rows); // reads string as int for rows
    num_args_read += sscanf(argv[2], "%d", num_columns); // reads string as int for columns
    num_args_read += sscanf(argv[3], "%d %c", number_of_pieces_in_a_row_needed_to_win, &should_not_be_read); // reads string as pieces in a row to win as int
  } else {
    if (num_args_read != 3) {
      if (argc > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win");
        exit(0);
      } else {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win");
        exit(0);
      }
    }
  }
}

// creates the board based on the users input
char** create_board(int num_rows, int num_columns, char blank) {
  char** board = calloc(num_rows, sizeof(*board));
  for (int i = 0; i < num_rows; ++i) {
    board[i] = calloc(num_rows, sizeof(*board[i]));
    for (int j = 0; j < num_columns; ++j) {
      board[i][j] = blank;
    }
  }
  return board;
}

// displays the board_input
// reference from Winter2021TicTacToe in Google Drive
void display_board(char** board, int num_rows, int num_columns) {
  for (int i = 0; i < num_rows; ++i) {
    if (i > 9) {
      printf(" %d ", abs(i - (num_rows - 1)));
    } else {
      printf("%s%d ", "", abs(i - (num_rows - 1))); // prints row number from bottom to top
    }
    for (int j = 0; j < num_columns; ++j) {
      printf("%c ", board[i][j]); // prints * for blank spots
    }
    printf("\n");
  }
  printf(" ");
  for (int i = 0; i < num_columns; ++i) {
    printf(" %d", i); // prints column numbers
  }
}

// checks if the pieces are in the same column
bool same_column(char** board, int row, int col, int number_of_pieces_in_a_row_needed_to_win) {
  int counter = 0;
  for (int i = 0; i < row - 1; ++i) {
    if ((board[i][col] == board[i + 1][col]) && (board[i][col] != '*')) {
      ++counter;
      if (counter >= number_of_pieces_in_a_row_needed_to_win - 1) {
        return true;
      }
    } else {
      counter = 0;
    }
  }
  return false;
}

// checks if pieces are in the same row
bool same_row(char** board, int row, int col, int number_of_pieces_in_a_row_needed_to_win) {
  int counter = 0;
  for (int i = 0; i < col - 1; ++i) {
    if ((board[row][i] == board[row][i + 1]) && (board[row][i] != '*')) {
      counter++;
      if (counter >= number_of_pieces_in_a_row_needed_to_win - 1) {
        return true;
      }
    } else {
      counter = 0;
    }
  }
  return false;
}

// destroys board
void destroy_board(char** board, int num_rows, int num_columns) {
  for (int i = 0; i < num_rows; ++i) {
    free(board[i]);
  }
  free(board);
}
