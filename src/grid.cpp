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
bool grid::iscelloutside(int row, int col){
    if (row >= 0 && row < num_rows&& col>= 0 && col<num_cols ){
        return false;
    }
    return true;
}
bool grid::is_cellempty(int row, int column){
    if(Grid[row][column] == 0){
        return true;
    }
    return false;
}
bool grid::isrowfull(int row){
    for (int column = 0; column<num_cols;column++){
        if (Grid[row][column] == 0){
            return false;
        }
    }
    return true;
}
void grid::clearrow(int row){
    for (int column = 0; column<num_cols;column++){
        Grid[row][column] = 0;
    }
}

void grid::MoveRowDown(int row,int numrows){
    for (int column = 0; column<num_cols;column++){
        Grid[row +numrows][column] = Grid[row][column];
         Grid[row][column] = 0;
    }
}
int grid::clearfullrows()
{
    int completd;
    for(int row = num_rows-1; row>=0;row--){
    if(isrowfull(row)){
        completd ++;
        clearrow(row);
    }
    else if(completd>0){
        MoveRowDown(row, completd);
        
    }
  }
  return completd;
}