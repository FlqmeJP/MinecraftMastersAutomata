import pydirectinput

import time

################################
sleep_time = 2
################################

def moveDash():
    pydirectinput.keyDown('w')
    pydirectinput.keyDown('z')
    time.sleep(sleep_time)
    pydirectinput.keyUp('w')
    pydirectinput.keyUp('z')

if __name__ == '__main__':
    moveDash()