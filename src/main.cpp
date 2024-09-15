#include <raylib.h>
#include"game.h"
int main()
{
  Color darkblue  ={44,44,127,250};
  InitWindow(300, 600, "tetris");
  SetTargetFPS(60);
  Game game ;

  while (WindowShouldClose() == false)
  {
    BeginDrawing();
      ClearBackground(darkblue);
      game.Draw();
    EndDrawing();
  }
    
  CloseWindow();
}