# hw6 The N Queens Problem
Adrian Curless, Tim Goon, Patrick Houlihan

## nqueen_solver.cpp

A C++ program that uses backtracking to find the first solution to the Queens Problem with a board size of n = [4, 100].

## queens.cpp

A C++ program that uses backtracking to find the all solutions to the Queens Problem with a board size of n = [4, 20].

Questions:

1. The position (1, 6, 8, 3, 5, 0, 0, 0) should cause isLegalPosition to return false
Position 1 and position 5 share a diagonal.
2. The next legal position will always be on a new row because queens can capture
across the row.
3. Our solution to the 8-queens problem is not the first. {2, 4, 6, 8, 3, 1, 7, 5} is
the first solution.
4. We need increased efficiency, because the number of solutions exponentially increases as n
increases.

More details on the 2 programs can be found in "BacktrackingAndThe_n-QueensProblem_WPI-1.pdf".
