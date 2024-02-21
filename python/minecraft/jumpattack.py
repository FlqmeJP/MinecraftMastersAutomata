import pydirectinput

import time

################################
sleep_time = 0.2
################################

def clickLeft():
    pydirectinput.keyDown('space')
    time.sleep(sleep_time)
    pydirectinput.keyUp('space')
    pydirectinput.keyDown('q')
    time.sleep(0.1)
    pydirectinput.keyUp('q')


if __name__ == '__main__':
    clickLeft()