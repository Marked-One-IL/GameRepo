import window

class Player:
    _JUMP = 20

    def __init__(self, x, y, filename):
        self.x = x
        self.y = y
        self._image = window.load_image(filename)

    def move_up(self):
        self.y -= Player._JUMP

    def move_down(self):
        self.y += Player._JUMP

    def move_left(self):
        self.x -= Player._JUMP

    def move_right(self):
        self.x += Player._JUMP

    def show(self):
        window.show_image(self._image, self.x, self.y)