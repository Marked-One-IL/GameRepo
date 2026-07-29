#pragma once
#include <raylib.h>

namespace Common
{
    class Png
    {
    public:
        Png(const char *filename);
        ~Png(void);

        void display(int x, int y);

    private:
        Texture2D m_texture;
    };
}