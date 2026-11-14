#include<raylib.h>
#include<iostream>
using namespace std;

int main(){
    int counter = 0;
    InitWindow(1080, 700, "ShooterCpp");
    InitAudioDevice();
    Music bgm1 = LoadMusicStream("audio/bg1.mp3");
    int animFrames = 0;
    Image logo = LoadImage("assets/logo.png");
    Image animImage = LoadImageAnim("assets/background.gif", &animFrames);
    Texture2D logotex = LoadTextureFromImage(logo);
    Texture2D animTexture = LoadTextureFromImage(animImage);
    unsigned int nextFrameDataOffset = 0;
    int currentAnimFrame = 0;
    int frameCounter = 0;
    int frameDelay = 8;
    int colorFlag = 0;
    Rectangle destRec = {0.0f, 0.0f, 1080.0f, 700.0f };
    Vector2 origin = { 0.0f, 0.0f };
    SetMusicVolume(bgm1, 0.7f);
    PlayMusicStream(bgm1);
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(bgm1);
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames) currentAnimFrame = 0;
            nextFrameDataOffset = animImage.width * animImage.height * 4 * currentAnimFrame;

            // Update the GPU texture with the raw pixel data of the next frame
            UpdateTexture(animTexture, ((unsigned char *)animImage.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        BeginDrawing();
        if(counter <= 300){
            ClearBackground(BLACK);
            DrawText("A GAME BY", 1080/2 - 80, 700/2 - 50, 30, WHITE);
            EndDrawing();
            counter++;
            continue;
        }
        if(counter >= 300 && counter <= 600){
            ClearBackground(BLACK);
            DrawText("TALHA ASIF", 1080/2 - 200, 700/2 - 50, 70, YELLOW);
            EndDrawing();
            counter++;
            continue;
        }
        ClearBackground(BLUE);
        //DrawTexture(animTexture, 1080 / 2 - animTexture.width / 2, 700 / 2 - animTexture.height / 2, WHITE);
        DrawTexturePro(animTexture, (Rectangle){ 0.0f, 0.0f, (float)animTexture.width, (float)animTexture.height },  destRec, origin, 0.0f, WHITE);
        DrawTexture(logotex, 400, 60, WHITE);
        DrawText("PRESS P TO START", 400, 600, 30, colorFlag%10 == 0 ? YELLOW : WHITE);
        EndDrawing();
        if(colorFlag >= 100){
            colorFlag = 0;
        }
        colorFlag++;
    }
    UnloadMusicStream(bgm1);
    UnloadTexture(logotex);
    UnloadTexture(animTexture);
    UnloadImage(logo);
    UnloadImage(animImage); 
    
    CloseAudioDevice();
    CloseWindow();
}