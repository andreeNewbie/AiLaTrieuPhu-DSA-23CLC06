#include "Button.hpp"

Button::Button(const char * imagePath, Vector2 imagePosition, float scale)
{
    Image image = LoadImage(imagePath);

    int originalWidth = image.width;
    int originalHeight = image.height;

    int newWidth = int(originalWidth * scale);
    int newHeight = int(originalHeight * scale);

    ImageResize(&image, newWidth, newHeight);

    texture = LoadTextureFromImage(image);
    position = imagePosition;
    visible = true;
}

Button::~Button()
{
    UnloadTexture(texture);
}

void Button::Draw()
{
    if (visible)
        DrawTextureV(texture, position, WHITE);
}

void Button::remove()
{
    visible = false;
}
bool Button::isPress(Vector2 mousePos, bool mousePressed)
{
    Rectangle rect = {position.x, position.y, float(texture.width), float(texture.height)};
    if(CheckCollisionPointRec(mousePos, rect) && mousePressed)
        return true;
    return false;
}