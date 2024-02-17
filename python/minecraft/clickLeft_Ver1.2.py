import time
import threading
from pynput.mouse import Controller, Button
from pynput.keyboard import KeyCode, Controller as KeyboardController

QUICK_ATTACK_KEY = KeyCode(char="q")  # 攻撃するキー

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
            if click_count == 120: #カウント回数は任意に決めて
                print("120回クリックされたのでプログラムを終了します。")
                exit_event.set()  # メインスレッドに終了通知
                break

click_count_lock = threading.Lock()
click_thread = threading.Thread(target=clicker)
click_thread.daemon = True
click_thread.start()

# メインスレッドが終了通知を受けるまで待機
exit_event.wait()

print("メインスレッドが終了します。")
