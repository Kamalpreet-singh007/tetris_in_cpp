#include"block.h"
#include<iostream>
Block::Block(){
    cell_size = 30;
    rotation_state = 0;
    colors =get_cell_colors();
    row_offset = 0;
    col_offset = 0;
}

void Block::Draw(int offsetx ,int offsety){
        std::vector<position>color_tiles = get_cell_Position();
        

        for(position item: color_tiles){
            DrawRectangle(item.column*cell_size+offsetx, item.row*cell_size+offsety, cell_size-1, cell_size-1, colors[id]);
        }
    }

void Block::move(int rows, int cols){
    row_offset += rows;
    col_offset += cols;
}

std::vector<position> Block::get_cell_Position(){
    std::vector<position>tiles = cells[rotation_state];
    std::vector<position> movedtiles;
    for(position item : tiles){
        position newpos = position(item.row + row_offset ,item.column + col_offset);
        movedtiles.push_back(newpos);
    }
    return movedtiles;
}

void Block::rotate(){
    rotation_state++;
    if ((rotation_state == (int)cells.size())){
        rotation_state =0;
    }
}
void Block::undo_rotation(){
    rotation_state --;
    if(rotation_state == -1){
        rotation_state=(int)cells.size()-1 ;
    }
}