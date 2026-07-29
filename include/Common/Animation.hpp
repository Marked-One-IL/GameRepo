#pragma once
#include <raylib.h>

namespace Common
{
    class Animation
    {
    public:
        Animation(const char *filename, float delay);
        ~Animation(void);

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