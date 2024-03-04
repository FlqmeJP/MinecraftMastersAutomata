import win32gui
from PIL import ImageGrab
import time
from tqdm import tqdm
import os
import datetime

LIMIT = 30
SLEEP = 5
date = datetime.datetime.now().strftime("%m%d")

os.makedirs("img", exist_ok=True)

for i in tqdm(range(1, LIMIT+1)):
    time.sleep(SLEEP)
    x0, y0, x1, y1 = win32gui.GetWindowRect(win32gui.GetForegroundWindow())
    im = ImageGrab.grab((x0, y0, x1, y1), all_screens=True)
    im.save(f"img/{date}_{str(i).zfill(3)}.png")