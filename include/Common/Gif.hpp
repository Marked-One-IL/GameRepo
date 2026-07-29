#pragma once
#include <raylib.h>

namespace Common
{
    class Gif
    {
    public:
        Gif(const char *filename, float delay);
        ~Gif(void);

        void advance(void);
        void reset(void);
        void display(int x, int y);
        
    private:
        Texture2D m_texture;
        Image m_image;
        int m_totalFrames = 0;
        int m_currentFrame = 0;
        float m_delay;
        float m_timer = 0.0f;
    };
}