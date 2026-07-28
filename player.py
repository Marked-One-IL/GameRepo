import window

class Player:
    _JUMP = 20

    def __init__(self, x, y, filename):
        self._x = x
        self._y = y
        self._image = window.load_image(filename)

    def move_up(self):
        self._y -= Player._JUMP

    def move_down(self):
        self._y += Player._JUMP

    def move_left(self):
        self._x -= Player._JUMP

    def move_right(self):
        self._x += Player._JUMP

    def show(self):
        window.show_image(self._image, self._x, self._y)