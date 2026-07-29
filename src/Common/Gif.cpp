#include <Common/Gif.hpp>

Common::Gif::Gif(const char *filename, float delay) :
    m_delay(delay)
{
    this->m_image = LoadImageAnim(filename, &this->m_totalFrames);
    ImageFormat(&this->m_image, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    this->m_texture = LoadTextureFromImage(this->m_image);
}
Common::Gif::~Gif(void)
{
    UnloadTexture(this->m_texture);
    UnloadImage(this->m_image); 
}

void Common::Gif::advance(void)
{
    this->m_timer += GetFrameTime();

    if (this->m_timer < this->m_delay) {
        return;
    }
    this->m_timer = 0.0f;
    this->m_currentFrame++;

    if (this->m_currentFrame >= this->m_totalFrames) {
        this->m_currentFrame = 0;
    }
    UpdateTexture(this->m_texture, (unsigned char*)this->m_image.data + this->m_currentFrame * this->m_image.width * this->m_image.height * 4);
}
void Common::Gif::reset(void)
{
    this->m_timer = 0.0f;
    this->m_currentFrame = 0;
    UpdateTexture(this->m_texture, (unsigned char*)this->m_image.data);
}

void Common::Gif::display(int x, int y)
{
    DrawTexture(this->m_texture, x, y, WHITE);
}