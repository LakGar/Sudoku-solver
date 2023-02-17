# Sudoku-solver
A command line C++ Sudoku solver is a program that allows the user to input a Sudoku puzzle and outputs the completed grid once the puzzle is solved. This program is hosted on GitHub and can be easily downloaded and used on any local machine.

The program is written in C++ and uses a backtracking algorithm to solve the Sudoku puzzle. The input Sudoku puzzle is taken in as a 2D array through the command line. The program then proceeds to solve the puzzle by attempting to fill in each empty cell with a number, and then checking whether the grid remains a valid Sudoku puzzle. If the grid remains valid, the program moves on to the next empty cell and repeats the process. If the grid becomes invalid at any point, the program backtracks to the previous cell and tries a different number.

The completed Sudoku grid is then outputted to the command line in a user-friendly format. The program is designed to handle both easy and difficult Sudoku puzzles, with the backtracking algorithm able to solve even the most complex of puzzles in a reasonable amount of time.
