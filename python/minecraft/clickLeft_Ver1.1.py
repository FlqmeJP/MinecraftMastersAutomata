import time
import threading
from pynput.mouse import Controller, Button
from pynput.keyboard import Listener, KeyCode, Controller as KeyboardController

QUICK_ATTACK_KEY = KeyCode(char="q")  # 攻撃するキー
EXIT_KEY = KeyCode.from_char('esc')  # 終了するキー

clicking = True  # プログラム開始時に有効にする
mouse = Controller()
keyboard = KeyboardController()

def clicker():
    while True:
        if clicking:
            keyboard.press(QUICK_ATTACK_KEY)
            time.sleep(0.01)  
            keyboard.release(QUICK_ATTACK_KEY)

def on_press(key):
    global clicking
    if key == EXIT_KEY:
        clicking = False

click_thread = threading.Thread(target=clicker)
click_thread.start()

with Listener(on_press=on_press) as listener:
    listener.join()

# プログラムが終了したときの後処理などを行う
