import time
import threading
from pynput.mouse import Controller, Button
from pynput.keyboard import Listener, KeyCode, Controller as KeyboardController

QUICK_ATTACK_KEY = KeyCode(char="q")  # 攻撃するキー

clicking = True  # プログラム開始時に有効にする
mouse = Controller()
keyboard = KeyboardController()

def clicker():
    while True:
        if clicking:
            # 必要に応じてキー間の遅延をカスタマイズできます
            keyboard.press(QUICK_ATTACK_KEY)
            time.sleep(0.01)  # 必要に応じてこの遅延を調整してください
            keyboard.release(QUICK_ATTACK_KEY)

click_thread = threading.Thread(target=clicker)
click_thread.start()

click_thread.join()
