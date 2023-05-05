# HexagonMaze

This was a project for one of my Computer Science courses: Algorithms and Data Strucutures.

## Structure
The main idea of the HexagonMaze is to first create a Hexagon grid composed of only hexagons. The hexagon's locations are dictated through hex coordinates, which are based on the q and r plane. Given the origin being the center of the hexagon grid, the q plane crosses from NW to SE of the origin, while the r plane crosses from W to E of the origin. Each hexagon has 6 possible neighbours: N, NW, NE, S, SW, SE. For hexagons that are on the edge of the grid, some of their neighbours with be null. Similiarly, each hexagon can also have 6 possible links, which indicates a path between the two hexagons. 

## Construction
A Hexagon board is represented by a HashMap between a pair of integers (coordinates q and r) and the HexCell on that coordinate. When a HexBoard is constructed, it receives a parameter representing the radius of the board. The ``create_board()`` function does this by first creating a square, then removing the HexCells whose coordinates do not fit the given radius of the board. The maze itself is created through a stack-based implementation of DFS, as shown in ``generate_maze()``, and the solution for the maze is generated through a revised implementation of Dijstras algorithm for an equally weighed graph.
