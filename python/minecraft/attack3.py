import time
import threading
from pynput.mouse import Controller, Button
from pynput.keyboard import KeyCode, Controller as KeyboardController

QUICK_ATTACK_KEY = KeyCode(char="q")  # 攻撃するキー
DOWN_KEY = KeyCode(char="j")
UP_KEY = KeyCode(char="c")
BACK_KEY = KeyCode(char="w")
RIGHT_KEY = KeyCode(char="k")
LEFT_KEY = KeyCode(char="h")

clicking = True  # プログラム開始時に有効
mouse = Controller()
keyboard = KeyboardController()

click_count = 0  # クリック回数をカウントする変数
exit_event = threading.Event()  # スレッド終了通知用のイベント

def clicker():
    global click_count
    while clicking:
        keyboard.press(QUICK_ATTACK_KEY)
        time.sleep(0.01)
        keyboard.release(QUICK_ATTACK_KEY)
        
        with click_count_lock:
            click_count += 1
            if click_count == 10:
                keyboard.press(RIGHT_KEY)
            if click_count == 30:
                keyboard.release(BACK_KEY)
                keyboard.release(RIGHT_KEY)
                keyboard.press(LEFT_KEY)
            if click_count == 70:
                keyboard.release(LEFT_KEY)
                keyboard.press(RIGHT_KEY)
            if click_count == 90:
                keyboard.release(RIGHT_KEY)
            if click_count == 100: #カウント回数は任意に決めて
                exit_event.set()  # メインスレッドに終了通知
                break

click_count_lock = threading.Lock()
click_thread = threading.Thread(target=clicker)
click_thread.daemon = True
keyboard.press(DOWN_KEY)
time.sleep(0.1)
keyboard.release(DOWN_KEY)
keyboard.press(BACK_KEY)
click_thread.start()
# メインスレッドが終了通知を受けるまで待機
exit_event.wait()
keyboard.press(UP_KEY)
time.sleep(0.05)
keyboard.release(UP_KEY)
