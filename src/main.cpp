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
  InitWindow(500,620, "tetris");

  SetTargetFPS(60);

  Font font  = LoadFontEx("Font/monogram.ttf",6,0,0);
  Game game ;

  while (WindowShouldClose() == false)
  {
    UpdateMusicStream(game.music);
    game.handel_input();
    if(EventTriggered(0.3)){
      game.move_block_down();
    }
    BeginDrawing();
      ClearBackground(darkBlue);
      DrawTextEx(font,"Score", {360,15},38,2,WHITE );
      DrawTextEx(font,"Next", {365,175},38,2,WHITE );
      if(game.GameOver){
      DrawTextEx(font,"Game", {350,420},50,2,RED );
      DrawTextEx(font,"Over !", {350,480},50,2,RED );
      DrawTextEx(font,"Enter To Restart", {315,570},20,2,WHITE );

      }
      DrawRectangleRounded({320,55,170,80},0.3,6,lightBlue);

      char scorestext[10];
      sprintf(scorestext,"%d",game.score);
      Vector2 textsize = MeasureTextEx(font,scorestext,38,2);

      DrawTextEx(font,scorestext, {320+(170-textsize.x)/2,65},38,2,WHITE );
      DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
      game.Draw();
    EndDrawing();
  }
    
  CloseWindow();
}