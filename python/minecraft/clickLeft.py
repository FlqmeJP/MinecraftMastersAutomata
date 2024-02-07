import time
import threading
from pynput.mouse import Controller, Button
from pynput.keyboard import Listener, KeyCode, Controller as KeyboardController

TOGGLE_KEY = KeyCode(char="t")　# プログラムの有効、無効を設定
QUICK_ATTACK_KEY = KeyCode(char="q") # 攻撃するキー

clicking = False
mouse = Controller()
keyboard = KeyboardController()

def clicker():
    while True:
        if clicking:
            # 必要に応じてキー間の遅延をカスタマイズできます
            keyboard.press(QUICK_ATTACK_KEY)
            time.sleep(0.01)  # 必要に応じてこの遅延を調整してください
            keyboard.release(QUICK_ATTACK_KEY)

def toggle_event(key):
    if key == TOGGLE_KEY:
        global clicking
        clicking = not clicking

click_thread = threading.Thread(target=clicker)
click_thread.start()

with Listener(on_press=toggle_event) as listener:
    listener.join()
