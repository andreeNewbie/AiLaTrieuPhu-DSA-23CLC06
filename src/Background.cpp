#include "Background.hpp"

Background::Background(const char * imagePath, Vector2 imagePosition, float scale)
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

Background::~Background()
{
    UnloadTexture(texture);
}

void Background::remove()
{
    visible = false;
}
void Background::Draw()
{
    if (visible)
        DrawTextureV(texture, position, WHITE);
}