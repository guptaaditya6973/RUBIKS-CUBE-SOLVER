# Rubik's Cube Solver

A high-performance C++ implementation of a Rubik's Cube solver supporting multiple cube representations and advanced search algorithms.

## Overview

This project provides an efficient solver for the Rubik's Cube using different algorithmic approaches and cube data representations. It includes multiple solving strategies ranging from simple graph search algorithms to advanced heuristic-based methods optimized for performance.

## Features

- **Multiple Cube Representations**
  - 3D Array representation
  - 1D Array representation
  - Bitboard representation (compact bit-level storage)

- **Advanced Solving Algorithms**
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Iterative Deepening Depth-First Search (IDDFS)
  - Iterative Deepening A* (IDA*)

- **Pattern Database Support**
  - Corner permutation pattern databases
  - Heuristic-guided search optimization
  - Nibble array compression for memory efficiency

- **Flexible Move System**
  - 18 standard moves (6 faces × 3 move variations)
  - Support for face rotations (normal, prime/inverted, double moves)

## Architecture

```
Rubiks-Cube-Solver/
├── Model/                      # Cube representation implementations
│   ├── RubiksCube.h           # Base class with common functionality
│   ├── RubiksCube3dArray.cpp  # 3D array representation
│   ├── RubiksCube1dArray.cpp  # 1D array representation
│   └── RubiksCubeBitboard.cpp # Bitboard representation
├── Solver/                     # Solving algorithms
│   ├── DFSSolver.h            # Depth-First Search implementation
│   ├── BFSSolver.h            # Breadth-First Search implementation
│   ├── IDDFSSolver.h          # Iterative Deepening DFS
│   └── IDAstarSolver.h        # IDA* with heuristics
├── PatternDatabases/           # Heuristic database generation
│   ├── PatternDatabase.h/cpp   # Base pattern database
│   ├── CornerPatternDatabase.h/cpp
│   ├── CornerDBMaker.h/cpp    # Tool for generating corner databases
│   ├── PermutationIndexer.h    # Permutation encoding/decoding
│   ├── NibbleArray.h/cpp       # Memory-efficient 4-bit storage
│   └── math.h/cpp              # Utility math functions
├── Databases/                  # Pre-computed pattern databases
│   └── cornerDepth5V1.txt     # Corner permutation database
├── CMakeLists.txt             # Build configuration
└── main.cpp                   # Entry point and examples
```

## Requirements

- C++14 or higher
- CMake 3.20+
- macOS, Linux, or Windows with a modern C++ compiler

## Building the Project

### Prerequisites
Ensure you have CMake and a C++ compiler installed:
- macOS: `brew install cmake`
- Linux: `sudo apt install cmake`
- Windows: Download from [cmake.org](https://cmake.org)

### Build Steps

```bash
# Navigate to the project directory
cd Rubiks-Cube-Solver-master

# Create and navigate to build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .

# Run the executable
./rubiks_cube_solver
```

## Usage

The main entry point is in `main.cpp`. Basic usage:

```cpp
#include "Model/RubiksCube3dArray.cpp"
#include "Solver/IDDFSSolver.h"

RubiksCube3dArray cube;

// Check if solved
if (cube.isSolved()) {
    cout << "Cube is solved!" << endl;
}

// Perform moves
cube.u();   // Up face clockwise
cube.r();   // Right face clockwise
cube.f();   // Front face clockwise

// Print cube state
cube.print();
```

## Algorithms

### Depth-First Search (DFS)
- Explores all possible states to a maximum depth
- Memory efficient but may not find optimal solutions
- Best for bounded search problems

### Breadth-First Search (BFS)
- Guarantees finding the shortest solution
- Explores states level by level
- More memory intensive than DFS

### Iterative Deepening DFS (IDDFS)
- Combines DFS efficiency with BFS optimality
- Incrementally increases search depth
- Suitable for large search spaces

### IDA* (Iterative Deepening A*)
- Uses heuristics from pattern databases
- Combines optimality with efficiency
- Best performance for Rubik's Cube solving

## Performance Considerations

- **Bitboard Representation**: Most compact and fastest for move generation
- **Pattern Databases**: Significantly speed up heuristic-based searches
- **Corner Database**: Pre-computed permutation costs for pruning

## Cube State Representation

### Standard Face Notation
- **U** - Up
- **L** - Left
- **F** - Front
- **R** - Right
- **B** - Back
- **D** - Down

### Move Notation
- Base move (e.g., `U`) - 90° clockwise
- Prime move (e.g., `U'`) - 90° counter-clockwise
- Double move (e.g., `U2`) - 180°

The project supports all 18 possible moves: 6 faces × 3 variations each.

## Example: Solving a Cube

```cpp
RubiksCube3dArray cube;
IDDFSSolver<RubiksCube3dArray, hash<RubiksCube3dArray>> solver;

// Find solution
solver.solve(cube);

// Get solution moves
// (Implementation details in Solver header files)
```

## Contributing

Contributions are welcome! Areas for improvement:
- Performance optimizations for solver algorithms
- Additional pattern databases (edge permutations, etc.)
- Visualization/UI components
- Parallel solving strategies

## License

This project is provided as-is for educational purposes.

## Authors

- Created by Paras Dhumne (June 2024)

## References

- Rubik's Cube permutation group theory
- Pattern database heuristics in AI search
- IDA* and other optimal search algorithms