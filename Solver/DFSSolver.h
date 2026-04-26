//
// Created by Paras Dhumne on 02-06-2024.
//

#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:

    vector<RubiksCube::MOVE> moves;
    int max_search_depth;

//    DFS code to find the solution (helper function)
    bool dfs(int dep) {
// BASE CASE CHECKED TO SEE IF CUBE IS ALREADY SOLVED
        if (rubiksCube.isSolved()) return true;
//        CHECKING IF WE HAVE ALREADY EXCEEDED THE MAXIMUM DEPTH SEARCH THAT CAN BE DONE
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
//            PERFORM ALL THE MOVES
//           RubiksCube::MOVE(i) will actually typecast i into the enum format which we have created
            rubiksCube.move(RubiksCube::MOVE(i));
//            THIS SIMPLY PERFORMS THE MOVE .move function
            moves.push_back(RubiksCube::MOVE(i));
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};


#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H
