import pydirectinput

import time

################################
sleep_time = 0.01
################################

def clickLeft_long():
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('s')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyDown('q')
    time.sleep(sleep_time)
    pydirectinput.keyUp('q')
    pydirectinput.keyUp('s')
    
if __name__ == '__main__':
    clickLeft_long()
