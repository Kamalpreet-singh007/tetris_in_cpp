#include"block.h"
#include<iostream>
Block::Block(){
    cell_size = 30;
    rotation_state = 0;
    colors =get_cell_colors();
    row_offset = 0;
    col_offset = 0;
}

void Block::Draw(){
        std::vector<position>color_tiles = get_cell_Position();
        

        for(position item: color_tiles){
            DrawRectangle(item.row*cell_size+1, item.column*cell_size+1, cell_size-1, cell_size-1, colors[id]);
        }
    }

void Block::move(int rowss, int colss){
    row_offset += rowss;
    col_offset += colss;
    std::cout<<"row offset"<<row_offset<<std::endl<<"col offset"<<col_offset;
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

