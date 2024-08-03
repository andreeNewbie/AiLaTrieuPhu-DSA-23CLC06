#pragma once
#include "C:\raylib\raylib\src\raylib.h"

class Background
{
    public:
        Background(const char * imagePath, Vector2 position, float scale);
        ~Background();
        void Draw();
        void remove();
    private:
        Texture2D texture;
        Vector2 position;
        bool visible;
};