import pygame

_fps_cap = 0
_canvas = None
_keys = None
_clock = pygame.time.Clock()

def create(width, height, title, fps_cap):
    global _canvas, _fps_cap

    pygame.init()
    if width == 0 and height == 0:
        _canvas = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
    else:
        _canvas = pygame.display.set_mode((width, height))
    
    pygame.display.set_caption(title)
    _fps_cap = fps_cap

def destroy():
    pygame.quit()

def is_open():
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            return False
    return True

def update_keys():
    global _keys

    _keys = pygame.key.get_pressed()

def is_pressed(key):
    global _keys

    return _keys[ord(key.lower())]

def fill(r, g, b):
    global _canvas

    _canvas.fill((r, g, b))

def update_frame():
    global _clock, _fps_cap

    pygame.display.flip()
    _clock.tick(_fps_cap)

def load_image(filename):
    return pygame.image.load(filename)

def show_image(image, x, y):
    global _canvas

    _canvas.blit(image, (x, y))