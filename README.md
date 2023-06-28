# Connect-N

A classic twist on Connect 4, this terminal based game has a variable number of checkers that can be matched in a row, not only 4.

## Running the Game

Make sure to `cd` into the source and run: 

`make`

Then, to run the game, you must specifiy the rows, columns, and number of checkers that can be matched in a row. So, you will run something like this:

`./connectn.out number_of_rows number_of_columns number_of_pieces_in_a_row_to_win`

This could look like this:

`./connectn.out 5 5 4`

Then, you will be prompted to choose a column to play in, taking turns with another player.
