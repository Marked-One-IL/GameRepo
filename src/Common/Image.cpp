#include <Common/Image.hpp>
#include <cassert>

Common::Image::Image(const char *filename)
{
    this->m_texture = LoadTexture(filename); assert(this->m_texture.id != 0);
}
Common::Image::~Image(void)
{
    UnloadTexture(this->m_texture);
}

void Common::Image::display(int x, int y)
{
    DrawTexture(this->m_texture, x, y, WHITE);
}