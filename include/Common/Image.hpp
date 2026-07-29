#pragma once
#include <raylib.h>

namespace Common
{
    class Image
    {
    public:
        Image(const char *filename);
        ~Image(void);

        void display(int x, int y);

    private:
        Texture2D m_texture;
    };
}