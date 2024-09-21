#include"game.h"
#include<iostream>
Game::Game(){
    // grid Gridd ;
    GameOver = false;
    Grid = grid();
    blocks =GetAllBlocks();
    current_block = GetRandomBlock();
    next_block = GetRandomBlock();
    score =0;
    InitAudioDevice();
    music =LoadMusicStream("sound/music.mp3");
    rotatesound = LoadSound("sound/rotate.mp3");
    clearsound = LoadSound("sound/clear.mp3");
    PlayMusicStream(music);
}
Game::~Game(){
    UnloadMusicStream(music);
    UnloadSound(rotatesound);
    UnloadSound(clearsound);
    CloseAudioDevice();

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
    current_block.Draw(11, 11);
    next_block.Draw(270,270);
}

void Game::handel_input(){
    int keyprsessed = GetKeyPressed();
    if(GameOver && keyprsessed !=0){
        GameOver = false;

        reset();
    }
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
        updatescores(0, 1);
        break;
    case KEY_UP:
        rotate_block();
        break;
    }
   
}

void Game::move_block_left(){
    if(!GameOver){
    current_block.move(0,-1);
    if(isblockoutside() ||!blockfits()){
        current_block.move(0,1);
    }
    }
}
void Game::move_block_right() {
    if(!GameOver){
    current_block.move(0,1);

    if(isblockoutside()|| !blockfits()){
        current_block.move(0,-1);
    }
    }
}
void Game::move_block_down(){
    if(!GameOver){
    current_block.move(1,0);

    if(isblockoutside() || !blockfits()){
        current_block.move(-1,0);
        lockblock();
    }
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
    if(isblockoutside() || !blockfits()){
        current_block.undo_rotation();
    }
    else{
        PlaySound(rotatesound);
    }
}

void Game::lockblock(){
    std::vector<position> tiles = current_block.get_cell_Position();
    for (position item :tiles){
        Grid.Grid[item.row][item.column] = current_block.id;

    }
    current_block =next_block;
    if(blockfits()== false){
        GameOver = true;
    }
    next_block = GetRandomBlock();
    int rowscleared =Grid.clearfullrows();
    if (rowscleared >0){
        PlaySound(clearsound);
    }
    updatescores(rowscleared, 0);
}
bool Game::blockfits(){
    std::vector<position> tiles = current_block.get_cell_Position();

    for( position item: tiles){
        if(!Grid.is_cellempty(item.row, item.column)){
            return false;
        } 

    }
    return true;
}

void Game::reset(){
    Grid.initialize();
    blocks = GetAllBlocks();
    current_block =GetRandomBlock();
    next_block = GetRandomBlock();
    score =0;
}

void Game::updatescores(int linescleared ,int blocksmoved){
    switch (linescleared)
    {
    case 1:
    score += 100;
        break;
    case 2:
    score += 300;
        break;
    case 3:
    score += 500;
        break;        
    
    default:
        break;
    }
    score += blocksmoved;
}