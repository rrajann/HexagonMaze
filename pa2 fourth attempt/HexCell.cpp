#include "HexCell.h"

#include <cmath>

HexCell::HexCell(int Q, int R) {
    q = Q;
    r = R;
    path_dist_from_start = 0;

    for (int i = 0; i < 6; i++) {
        links[i] = NULL;
    }
    for (int i = 0; i < 6; i++) {
        neighbours[i] = NULL;
    }
}

void HexCell::link(HexCell* cell) {
    if (cell == NULL) {
        return;
    }
    if (distance(cell) > 1) {
        return;
    }

    links[get_neighbour_side(cell)] = cell;
    cell->links[cell->get_neighbour_side(this)] = this;
}

int HexCell::get_neighbour_side(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */

    if (distance(cell) > 1) {
        return NULL;
    }
     
     int qDiff = cell->q - q;
     int rDiff = cell->r - r;

     if (qDiff == 0) {
         if (rDiff > 0) {
             return 3;
         } else {
             return 0;
         }
     } else if (rDiff == 0) {
         if (qDiff > 0) {
             return 2;
         } else {
             return 5;
         }
     } else if (qDiff > 0) {
         return 1;
     } else { 
         return 4;
     }
}

bool HexCell::is_linked(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    if (cell == NULL) return false;
    for (int i = 0; i < 6; i++) {
        if (links[i] == cell) {
            return true;
        }
    }
    return false;
}

int HexCell::distance(const HexCell* cell) const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    if (cell->q == q) {
        return abs(cell->r - r);
    }
    if (cell->r == r) {
        return abs(cell->q - q);
    }
    if (cell->r <= 0 && cell->q <= 0 && r >= 0 && q >= 0) {
        return abs(cell->q - q) + abs(cell->r - r);
    }
    if (r <= 0 && q <= 0 && cell->r >= 0 && cell->q >= 0) {
        return abs(cell->q - q) + abs(cell->r - r);
    }
    if (abs(cell->q - q) >= abs(cell->r - r)) {
        return abs(cell->q - q);
    }
    return abs(cell->r - r);
}

bool HexCell::is_edge() const {
    /**
     * @todo Your code here! You will need to replace the following line.
     */
    for (int i = 0; i < 6; i++) {
        if (neighbours[i] == NULL) {
            return true;
        }
    }
    return false;
}