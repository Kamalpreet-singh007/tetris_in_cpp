#include"game.h"
#include<iostream>
Game::Game(){
    // grid Gridd ;
    
    Grid = grid();
    blocks =GetAllBlocks();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Tblock(), Zblock()};
}

void Game::Draw(){
    Grid.draw();
    current_block.Draw();
}

void Game::handel_input(){
    int keyprsessed = GetKeyPressed();

    switch (keyprsessed)
    {
    case KEY_LEFT:
        move_block_left();
        break;
    case KEY_RIGHT:
        move_block_right();
        break;
    case KEY_DOWN:
        move_block_down();
        break;
    case KEY_UP:
        rotate_block();
        break;
    }
   
}

void Game::move_block_left(){
    current_block.move(0,-1);
    if(isblockoutside()){
        current_block.move(0,1);
    }
}
void Game::move_block_right(){
    current_block.move(0,1);

    if(isblockoutside()){
        current_block.move(0,-1);
    }
}
void Game::move_block_down(){
    current_block.move(1,0);

    if(isblockoutside()){
        current_block.move(-1,0);
    }
}

bool Game::isblockoutside(){
    std::vector<position> tiles = current_block.get_cell_Position();
    for(position item :tiles){
        if(Grid.iscelloutside(item.row, item.column)){
            return true;
        }
        
    }return false;
}
void Game::rotate_block(){
    current_block.rotate();
    if(isblockoutside()){
        current_block.undo_rotation();
    }
}

