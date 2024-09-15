#if !defined(GAME_H)
#define GAME_H

#include"grid.h"
#include"block.h"
#include"blocks.cpp"
#include<random>
class Game
{
public:
    Game();
    grid Grid;

    //drwing feild and blocks
    void Draw();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();


    //input handeling
    void handel_input();
    void move_block_left();
    void move_block_right();
    void move_block_down();
    void rotate_block();

private:
std::vector<Block> blocks;
Block current_block;
Block next_block;
bool isblockoutside();

};


#endif // GAME_H
