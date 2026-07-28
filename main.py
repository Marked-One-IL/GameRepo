import window
from player import *

def main():
    window.create(0, 0, "Game test", 60)
    p = Player(0, 0, "assets/my_pic.png")

    while window.is_open():
        window.update_keys()
        window.fill(255, 255, 255)

        if window.is_pressed('w'):
            p.move_up()
        if window.is_pressed('s'):
            p.move_down()
        if window.is_pressed('a'):
            p.move_left()
        if window.is_pressed('d'):
            p.move_right()

        p.show()
        window.update_frame()

    window.destroy()

if __name__ == "__main__":
    main()