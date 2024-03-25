import pydirectinput

import time

################################
sleep_time = 0.01
################################

def clickLeft():
    pydirectinput.keyDown('n')
    time.sleep(0.25)
    pydirectinput.keyUp('n')
    pydirectinput.keyDown('3')
    time.sleep(sleep_time)
    pydirectinput.keyUp('3')
    pydirectinput.keyDown('e')
    time.sleep(0.5)
    pydirectinput.keyUp('e')
    pydirectinput.keyDown('1')
    time.sleep(sleep_time)
    pydirectinput.keyUp('1')
    pydirectinput.keyDown('c')
    time.sleep(0.25)
    pydirectinput.keyUp('c')

if __name__ == '__main__':
    clickLeft()