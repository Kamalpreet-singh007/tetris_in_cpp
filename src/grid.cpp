#include<iostream>
#include"grid.h"

grid::grid(){
    num_rows = 20;
    num_cols = 10;
    cell_size = 30;
    initialize();
    colors = get_cell_colors();
}

void grid::initialize(){
    for (int row =0;row<num_rows;row++){
        for(int col =0;col<num_cols;col++){
            Grid[row][col] = 0;
        }
    }
}
void grid::print(){
    for (int row =0;row<num_rows;row++){
        for(int col =0;col<num_cols;col++){
            std::cout<<Grid[row][col]<<"";
        }
        std::cout<<std::endl;
    }
}

void grid::draw(){
    for (int row =0;row<num_rows;row++){
        for(int col =0;col<num_cols;col++){
            int cell_value =Grid[row][col] ;
            DrawRectangle(col*cell_size+1, row*cell_size+1, cell_size-1, cell_size-1, colors[cell_value]);
        }
    }

}
