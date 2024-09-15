#include"game.h"
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