#if !defined(GAME_H)
#define GAME_H

#include"grid.h"
#include"blocks.cpp"
#include<random>
class Game
{
public:
    Game();
    void Draw();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
private:
std::vector<Block> blocks;
Block current_block;
Block next_block;
grid Grid;

};


#endif // GAME_H
