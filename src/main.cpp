#include <raylib.h>
#include"game.h"
double last_update_time;
bool EventTriggered(double interval){
  double current_time = GetTime();
  if(current_time- last_update_time >=interval){
    last_update_time = current_time;
    return true;
  }
  return false;
}
int main()
{
  Color darkblue  ={44,44,127,250};
  InitWindow(300, 600, "tetris");

  SetTargetFPS(60);
  Game game ;

  while (WindowShouldClose() == false)
  {
    game.handel_input();
    if(EventTriggered(0.3)){
      game.move_block_down();
    }
    BeginDrawing();
      ClearBackground(darkblue);
      game.Draw();
    EndDrawing();
  }
    
  CloseWindow();
}