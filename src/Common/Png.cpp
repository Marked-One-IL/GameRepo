#include <Common/Png.hpp>

Common::Png::Png(const char *filename)
{
    Image image = LoadImage(filename);
    this->m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
}
Common::Png::~Png(void)
{
    UnloadTexture(this->m_texture);
}

void Common::Png::display(int x, int y)
{
    DrawTexture(this->m_texture, x, y, WHITE);
}