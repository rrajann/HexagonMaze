#include "HexBoard.h"

#include <iostream>

#include "queue.h"
#include "stack.h"

HexBoard::HexBoard(int radius) {
    /**
     * @todo Your code here!
     */
     this->radius = radius;
     create_board();
     configure_cells();
}

void HexBoard::create_board() {

     for (int q = -radius+1; q <= radius-1; q++) {
        for (int r = -radius+1; r <= radius-1; r++) {
            if (!(abs(q+r) > radius-1)) {
            cells[{q,r}] = new HexCell(q,r);
            }
        }
     }     
}

void HexBoard::configure_cells() {
    /**
     * @todo Your code here!
     */

     for (auto kv : cells) {
         pair<int, int> coord = kv.first;
         vector<pair<int, int>> possible_neighbours = get_neigh_coords(coord);

         for (int i = 0; i < 6; i++) {
             pair<int, int> coordinate = possible_neighbours[i];
             
             if (cells.find(coordinate) != cells.end()) {
                 kv.second->neighbours[i] = cells[coordinate];
             } else{
                 kv.second->neighbours[i] = NULL;
             }
         }
     }

}

void HexBoard::generate_maze(pair<int, int> start_coord, double branch_prob) {
    this->start_coord = start_coord;
    Stack<pair<int, int>> stack;
    map<pair<int, int>, bool> visited;

    HexCell* a = cells[{start_coord}];
    longest_path_dist = 0;
    end_coord = start_coord;
    int temp = 0;

    stack.push(start_coord);
    visited[start_coord] = true;

     while(!stack.isEmpty()) {
        HexCell* curr_cell = cells[{stack.peek()}];
        //temp = curr_cell->path_dist_from_start;
        HexCell* neigh_cell = chooseNeighbour(curr_cell, visited, branch_prob);

        if (neigh_cell == NULL) {
            stack.pop();
            temp--;
        } else {
            temp++;
            neigh_cell->path_dist_from_start = temp;
            neigh_cell->link(curr_cell);
            visited[{neigh_cell->q, neigh_cell->r}] = true;
            if (temp > longest_path_dist) {
                longest_path_dist = temp;
            }
            if (neigh_cell->is_edge() && neigh_cell->path_dist_from_start > cells[end_coord]->path_dist_from_start) {
                end_coord = {neigh_cell->q, neigh_cell->r};
            }
            stack.push({neigh_cell->q, neigh_cell->r});
        }
    }
}

void HexBoard::solve_maze() {

    /*
    1. Create a stack that contains the path so far (Stack<pair<int, int>> path)
    2. Push the starting HexCell into the stack
    
    3. While the stack != empty:
        a. HexCell* curr_cell = cells[path.peek()];
        b. Push all of curr_cells links' coordinates to the path
        c. If curr_cell does not have any links, path.pop();
        d. If curr_cell coords = end_coord, break

    4. Put the path stack in solution field (keep in mind order);
    */

    Stack<pair<int, int>> path;
    map<HexCell*, bool> visited;
    path.push(end_coord);

    while (!path.isEmpty()) {
        HexCell* curr_cell = cells[path.peek()];
        visited[curr_cell] = true;
        int num = 0;

        for (int i = 0; i < 6; i++) {

            HexCell* link = curr_cell->links[i];

            if (link != NULL && visited.find(link) == visited.end()) {
                path.push({link->q, link->r});
                num++;
            }
        }

        if (curr_cell->q == start_coord.first && curr_cell->r == start_coord.second) break;
        else if (num == 0) path.pop();
    }

    for (int i = cells[end_coord]->path_dist_from_start; i >= 0; i--) {
        solution.push_back(path.pop());
    }

    // while (!path.isEmpty()) {
    //     solution.push_back(path.pop());
    // }
}