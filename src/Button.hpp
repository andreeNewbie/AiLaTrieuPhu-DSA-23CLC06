#pragma once
#include "/Users/huynick/Documents/raylib/src/raylib.h"

class Button
{
    public:
        Button();
        void loadInfo(const char *imagePath, Vector2 position, float scale);
        ~Button();
        void Draw();
        void remove();
        bool isPress(Vector2 mousePos, bool mousePressed);
    private:
        Texture2D texture;
        Vector2 position;
        bool visible;
};
