#include <raylib.h>
#include <cstdlib>
#pragma once
using namespace std;

int main()
{
    int counter = 0;
    InitWindow(1080, 700, "ShooterCpp");
    InitAudioDevice();
    Music bgm1 = LoadMusicStream("audio/bg1.mp3");
    int animFrames = 0;
    Image logo = LoadImage("assets/logo.png");
    Image naruto = LoadImage("assets/naruto.png");
    Image naruto1 = LoadImage("assets/narutoR1.png");
    Image naruto2 = LoadImage("assets/narutoR2.png");
    Image narutoAttack1 = LoadImage("assets/narutoP1.png");
    Image narutoAttack2 = LoadImage("assets/narutoP2.png");
    Image narutoPunch1 = LoadImage("assets/narutoP3.png");
    Image narutoPunch2 = LoadImage("assets/narutoP4.png");
    Image narutoDied = LoadImage("assets/narutoKO.png");

    Image sasuke = LoadImage("assets/sasuke.png");
    Image sasuke1 = LoadImage("assets/sasukeR1.png");
    Image sasuke2 = LoadImage("assets/sasukeR2.png");
    Image sasukeAttack1 = LoadImage("assets/sasukeP1.png");
    Image sasukeAttack2 = LoadImage("assets/sasukeP2.png");
    Image sasukePunch1 = LoadImage("assets/sasukeP3.png");
    Image sasukePunch2 = LoadImage("assets/sasukeP4.png");
    Image sasukeDied = LoadImage("assets/sasukeKO.png");

    Texture2D narutoTex = LoadTextureFromImage(naruto);
    Texture2D narutoTex1 = LoadTextureFromImage(naruto1);
    Texture2D narutoTex2 = LoadTextureFromImage(naruto2);
    Texture2D narutoFight1 = LoadTextureFromImage(narutoAttack1);
    Texture2D narutoFight2 = LoadTextureFromImage(narutoAttack2);
    Texture2D narutoPunchAttack1 = LoadTextureFromImage(narutoPunch1);
    Texture2D narutoPunchAttack2 = LoadTextureFromImage(narutoPunch2);
    Texture2D narutoDiedTex = LoadTextureFromImage(narutoDied);

    Texture2D sasukeTex = LoadTextureFromImage(sasuke);
    Texture2D sasukeTex1 = LoadTextureFromImage(sasuke1);
    Texture2D sasukeTex2 = LoadTextureFromImage(sasuke2);
    Texture2D sasukeFight1 = LoadTextureFromImage(sasukeAttack1);
    Texture2D sasukeFight2 = LoadTextureFromImage(sasukeAttack2);
    Texture2D sasukePunchAttack1 = LoadTextureFromImage(sasukePunch1);
    Texture2D sasukePunchAttack2 = LoadTextureFromImage(sasukePunch2);
    Texture2D sasukeDiedTex = LoadTextureFromImage(sasukeDied);
    
    int p1Health = 10;
    int p2Health = 10;
    int p1AttackCooldown = 0;
    int p2AttackCooldown = 0;
    
    int i = 0, j = 1;
    int x = 0, y = 1;
    int p1x = 50;
    int p1y = 350;
    int p2x = 800;
    int p2y = 350;
    
    bool jumpP1 = false;
    bool jumpP2 = false;
    bool fallingP1 = false;
    bool fallingP2 = false;
    
    Image animImage = LoadImageAnim("assets/background.gif", &animFrames);
    Texture2D logotex = LoadTextureFromImage(logo);
    Texture2D animTexture = LoadTextureFromImage(animImage);
    unsigned int nextFrameDataOffset = 0;
    int currentAnimFrame = 0;
    int frameCounter = 0;
    int frameDelay = 8;
    int colorFlag = 0;
    bool gameStart = false;
    Rectangle destRec = {0.0f, 0.0f, 1080.0f, 700.0f};
    Vector2 origin = {0.0f, 0.0f};
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
            if (currentAnimFrame >= animFrames)
                currentAnimFrame = 0;
            nextFrameDataOffset = animImage.width * animImage.height * 4 * currentAnimFrame;

            // Update the GPU texture with the raw pixel data of the next frame
            UpdateTexture(animTexture, ((unsigned char *)animImage.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        BeginDrawing();
        if (!gameStart)
        {
            if (counter <= 300)
            {
                ClearBackground(BLACK);
                DrawText("A GAME BY", 1080 / 2 - 80, 700 / 2 - 50, 30, WHITE);
                EndDrawing();
                counter++;
                continue;
            }
            if (counter >= 300 && counter <= 600)
            {
                ClearBackground(BLACK);
                DrawText("TALHA ASIF", 1080 / 2 - 200, 700 / 2 - 50, 70, YELLOW);
                EndDrawing();
                counter++;
                continue;
            }
            ClearBackground(BLUE);
            // DrawTexture(animTexture, 1080 / 2 - animTexture.width / 2, 700 / 2 - animTexture.height / 2, WHITE);
            DrawTexturePro(animTexture, (Rectangle){0.0f, 0.0f, (float)animTexture.width, (float)animTexture.height}, destRec, origin, 0.0f, WHITE);
            DrawTexture(logotex, 400, 60, WHITE);
            DrawText("PRESS P TO START", 400, 580, 30, colorFlag % 10 == 0 ? YELLOW : WHITE);
            if (IsKeyDown(KEY_P))
            {
                gameStart = true;
                counter = 0;
            }
        } else {
            if(counter <= 200){
                counter++;
                ClearBackground(Color{255, 0, 0, 50});
                DrawText("FIGHT!", 1080/2 - 100, 700/2 - 50, 50, WHITE);
                EndDrawing(); continue;
            }
            DrawTexturePro(animTexture, (Rectangle){0.0f, 0.0f, (float)animTexture.width, (float)animTexture.height}, destRec, origin, 0.0f, WHITE);
            if (p1Health <= 0 || p2Health <= 0)
            {
                if (p1Health <= 0)
                {
                    DrawTexture(narutoDiedTex, p1x, p1y, WHITE);
                    DrawTextureEx(sasukeTex, {(float)p2x, (float)p2y}, 0.0f, (float)narutoTex.height / sasukeTex.height, WHITE);
                }
                else
                {
                    DrawTexture(narutoTex, p1x, p1y, WHITE);
                    DrawTextureEx(sasukeDiedTex, {(float)p2x, (float)p2y}, 0.0f, (float)narutoTex.height / sasukeDiedTex.height, WHITE);
                }

                const char *winnerText = p1Health <= 0 ? "Sasuke won" : "Naruto won";
                DrawText(winnerText, 1080 / 2 - MeasureText(winnerText, 50) / 2, 80, 50, YELLOW);
                DrawText(TextFormat("Naruto: %d", p1Health), 40, 25, 24, WHITE);
                DrawRectangle(40, 55, 300, 20, DARKGRAY);
                DrawRectangle(40, 55, p1Health * 30, 20, GREEN);
                DrawText(TextFormat("Sasuke: %d", p2Health), 740, 25, 24, WHITE);
                DrawRectangle(740, 55, 300, 20, DARKGRAY);
                DrawRectangle(740, 55, p2Health * 30, 20, RED);
                EndDrawing();
                continue;
            }

            if (p1AttackCooldown > 0) p1AttackCooldown--;
            if (p2AttackCooldown > 0) p2AttackCooldown--;

            if(IsKeyDown(KEY_D)){
                if(p1x <= p2x) p1x+=10;
            }
            if(IsKeyDown(KEY_A)){
                if(p1x >= 0)p1x-=10;
            }
            if(IsKeyDown(KEY_SPACE)){
                jumpP1 = true;
            }

            if(jumpP1){
                if(p1y <= 80){
                    fallingP1 = true;
                    jumpP1 = false;
                } else {
                    p1y-=20;

                }
            }
            if(fallingP1){
                p1y += 50;
                if(p1y >= 350){
                    fallingP1 = false;
                }
            }
            
            if(IsKeyDown(KEY_D) || IsKeyDown(KEY_A)){
                if(i%10 == 0){
                    j++;
                }
                if(j % 2 == 0){
                    DrawTexture(narutoTex1, p1x, p1y, WHITE);
                } else {
                    DrawTexture(narutoTex2, p1x, p1y, WHITE);
                } i++;
            } else if(IsKeyDown(KEY_R)){
                if(i%10 == 0){
                    j++;
                }
                if(j % 2 == 0){
                    DrawTexture(narutoPunchAttack1, p1x, p1y, WHITE);
                } else {
                    DrawTexture(narutoPunchAttack2, p1x, p1y, WHITE);
                } i++;

                if(abs(p2x - p1x) <= 200 && p1AttackCooldown == 0 && p2Health > 0){
                    p2Health -= 1;
                    if (p2Health < 0) p2Health = 0;
                    p1AttackCooldown = 20;
                }
            } else if(IsKeyDown(KEY_F)){
                if(i%10 == 0){
                    j++;
                }
                if(j % 2 == 0){
                    DrawTexture(narutoFight1, p1x, p1y, WHITE);
                } else {
                    DrawTexture(narutoFight2, p1x, p1y, WHITE);
                } i++;
                if(abs(p2x - p1x) <= 200 && p1AttackCooldown == 0 && p2Health > 0){
                    p2Health -= 2;
                    if (p2Health < 0) p2Health = 0;
                    p1AttackCooldown = 20;
                }
            } else {
                if(p1Health > 0){
                    DrawTexture(narutoTex, p1x, p1y, WHITE);
                } else {
                    DrawTexture(narutoDiedTex, p1x, p1y, WHITE);
                }
                i = 0; j = 0;
            }

            //______________________________________________

            if(IsKeyDown(KEY_J)){
                if(p2x >= p1x) p2x-=10;
            }
            if(IsKeyDown(KEY_L)){
                if(p2x <= 900)p2x+=10;
            }
            if(IsKeyDown(KEY_ENTER)){
                jumpP2 = true;
            }

            if(jumpP2){
                if(p2y <= 80){
                    fallingP2 = true;
                    jumpP2 = false;
                } else {
                    p2y-=20;

                }
            }
            if(fallingP2){
                p2y += 50;
                if(p2y >= 350){
                    fallingP2 = false;
                }
            }
            
            if(IsKeyDown(KEY_L) || IsKeyDown(KEY_J)){
                if(x%10 == 0){
                    y++;
                }
                if(y % 2 == 0){
                    DrawTextureEx(sasukeTex1, {(float)p2x, (float)p2y}, 0.0f, (float)narutoTex1.height / sasukeTex1.height, WHITE);
                } else {
                    DrawTextureEx(sasukeTex2, {(float)p2x, (float)p2y}, 0.0f, (float)narutoTex2.height / sasukeTex2.height, WHITE);
                } x++;
            } else if(IsKeyDown(KEY_LEFT_BRACKET)){
                if(x%10 == 0){
                    y++;
                }
                if(y % 2 == 0){
                    DrawTextureEx(sasukePunchAttack1, {(float)p2x, (float)p2y}, 0.0f, (float)narutoPunchAttack1.height / sasukePunchAttack1.height, WHITE);
                } else {
                    DrawTextureEx(sasukePunchAttack2, {(float)p2x, (float)p2y}, 0.0f, (float)narutoPunchAttack2.height / sasukePunchAttack2.height, WHITE);
                } x++;
                if(abs(p2x - p1x) <= 200 && p2AttackCooldown == 0 && p1Health > 0 && p2Health > 0){
                    p1Health -= 1;
                    if (p1Health < 0) p1Health = 0;
                    p2AttackCooldown = 20;
                }
            } else if(IsKeyDown(KEY_RIGHT_BRACKET)){
                if(x%10 == 0){
                    y++;
                }
                if(y % 2 == 0){
                    DrawTextureEx(sasukeFight1, {(float)p2x, (float)p2y}, 0.0f, (float)narutoFight1.height / sasukeFight1.height, WHITE);
                } else {
                    DrawTextureEx(sasukeFight2, {(float)p2x, (float)p2y}, 0.0f, (float)narutoFight2.height / sasukeFight2.height, WHITE);
                } x++;
                if(abs(p2x - p1x) <= 200 && p2AttackCooldown == 0 && p1Health > 0 && p2Health > 0){
                    p1Health -= 2;
                    if (p1Health < 0) p1Health = 0;
                    p2AttackCooldown = 20;
                }
            } else {
                if(p2Health > 0){
                    DrawTextureEx(sasukeTex, {(float)p2x, (float)p2y}, 0.0f, (float)narutoTex.height / sasukeTex.height, WHITE);
                } else {
                    DrawTextureEx(sasukeDiedTex, {(float)p2x, (float)p2y+100}, 0.0f, (float)narutoDiedTex.height / sasukeDiedTex.height, WHITE);
                }
                x = 0; y = 0;
            }
            DrawText(TextFormat("Naruto: %d", p1Health), 40, 25, 24, WHITE);
            DrawRectangle(40, 55, 300, 20, DARKGRAY);
            DrawRectangle(40, 55, p1Health * 30, 20, GREEN);
            DrawText(TextFormat("Sasuke: %d", p2Health), 740, 25, 24, WHITE);
            DrawRectangle(740, 55, 300, 20, DARKGRAY);
            DrawRectangle(740, 55, p2Health * 30, 20, RED);
        }
        EndDrawing();
        if (colorFlag >= 100)
        {
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