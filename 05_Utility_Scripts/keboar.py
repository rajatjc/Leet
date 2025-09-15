import keyboard
import time

def press_key(key):
    keyboard.press(key)
    keyboard.release(key)

try:
    while True:
        press_key('g')
        time.sleep(0.8)
except KeyboardInterrupt:
    print("Stopped by the user")
