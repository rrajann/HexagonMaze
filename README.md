# HexagonMaze

This was a project for one of my Computer Science courses: Algorithms and Data Strucutures.

## Structure
The main idea of the HexagonMaze is to first create a Hexagon grid composed of only hexagons. The hexagon's locations are dictated through hex coordinates, which are based on the q and r plane. Given the origin being the center of the hexagon grid, the q plane crosses from NW to SE of the origin, while the r plane crosses from W to E of the origin. Each hexagon has 6 possible neighbours: N, NW, NE, S, SW, SE. For hexagons that are on the edge of the grid, some of their neighbours with be null. Similiarly, each hexagon can also have 6 possible links, which indicates a path between the two hexagons. 

## Construction
A Hexagon board is represented by a HashMap between a pair of integers (coordinates q and r) and the HexCell on that coordinate. When a HexBoard is constructed, it receives a parameter representing the radius of the board. The ``create_board()`` function does this by first creating a square, then removing the HexCells whose coordinates do not fit the given radius of the board. The maze itself is created through a stack-based implementation of DFS, as shown in ``generate_maze()``, and the solution for the maze is generated through a revised implementation of Dijstras algorithm for an equally weighed graph, as seen in ``solve_maze()``.

## Challenges
The main challenge of this project was creating the algorithm that generated the maze, and an algorithm to store a solution of the maze in a field for each instance of the HexBoard class. The ``generate_maze`` was especially a problem, as the solution had to be the longest path from the ``start_coord`` to an edge. There are many methods to solving ``generate_maze``, but the way it was solved in this program was to first recognize that this HexBoard was simply a graph with equally weighed edges. Thus, it would be possible to create a pseudo spanning tree by picking a random edge for each cell, and keep traversing that branch of the tree until an edge cell has been reached. In other words, this was a DFS problem. Upon realising that, a stack-based DFS was implemented. 
