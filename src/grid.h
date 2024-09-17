#if !defined(GRID_H)
#define GRID_H
#include<iostream>
#include<vector>
#include"colors.h"
#include<raylib.h>
class grid
{
public:
    // constructor and destructor
    grid();
    // ~grid();
    // grid array
    int Grid [20][10];
    void initialize();
    void print();
    void draw();
    bool is_cellempty(int row, int column);
    bool iscelloutside(int row, int col);
    bool isrowfull(int row);
    void clearrow(int row);
    void MoveRowDown(int row, int numrows);
    int clearfullrows();

private:
    int num_cols;
    int num_rows;
    int cell_size;
    // bool isrowfull(int row);
    std::vector<Color>colors;



};

#endif // GRID_H
