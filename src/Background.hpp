#pragma once
#include "C:\raylib\raylib\src\raylib.h"

class Background
{
    public:
        Background();
        ~Background();
        void loadInfo(const char * imagePath, Vector2 position, float scale);
        void Draw();
        void remove();
    private:
        Texture2D texture;
        Vector2 position;
        bool visible;
};