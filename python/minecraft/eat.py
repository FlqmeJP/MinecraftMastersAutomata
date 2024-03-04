import pydirectinput

import time

################################
sleep_time = 0.01
################################

def clickLeft():
    pydirectinput.keyDown('2')
    time.sleep(sleep_time)
    pydirectinput.keyUp('2')
    pydirectinput.keyDown('e')
    time.sleep(2)
    pydirectinput.keyUp('e')
    pydirectinput.keyDown('1')
    time.sleep(sleep_time)
    pydirectinput.keyUp('1')

if __name__ == '__main__':
    clickLeft()