import pydirectinput

import time

################################
sleep_time = 0.8
################################

def moveDash():
    pydirectinput.keyDown('w')
    pydirectinput.keyDown('z')
    time.sleep(sleep_time)
    pydirectinput.keyUp('w')
    pydirectinput.keyUp('z')

if __name__ == '__main__':
    moveDash()