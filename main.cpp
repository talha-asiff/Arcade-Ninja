#include<raylib.h>
#include<iostream>
using namespace std;

int main(){
    InitWindow(1080, 700, "ShooterCpp");

    int animFrames = 0;
    Image animImage = LoadImageAnim("assets/background.gif", &animFrames);
    Texture2D animTexture = LoadTextureFromImage(animImage);
    unsigned int nextFrameDataOffset = 0;
    int currentAnimFrame = 0;
    int frameCounter = 0;
    int frameDelay = 8;
    Rectangle destRec = {0.0f, 0.0f, 1080.0f, 700.0f };
    Vector2 origin = { 0.0f, 0.0f };
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
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
        ClearBackground(BLUE);
        //DrawTexture(animTexture, 1080 / 2 - animTexture.width / 2, 700 / 2 - animTexture.height / 2, WHITE);
        DrawTexturePro(
        animTexture, 
        (Rectangle){ 0.0f, 0.0f, (float)animTexture.width, (float)animTexture.height },  destRec, origin, 0.0f, WHITE
    );
       
        EndDrawing();
    }
    
}