import window
from player import *

def main():
    window.create(1000, 1000, "Game test", 60)
    p = Player(0, 0, "assets/my_pic.png")

    while window.is_open():
        window.update_keys()
        window.fill(255, 255, 255)

        # TODO: Move the picture via WASD. Good luck!

        p.show()
        window.update_frame()

    window.destroy()

if __name__ == "__main__":
    main()