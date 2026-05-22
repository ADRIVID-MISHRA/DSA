import time
import pyautogui

# =========================================
# TEXT TO TYPE
# =========================================
text_to_type = """osdfoaofij"""

# =========================================
# WAIT BEFORE STARTING
# =========================================
print("Auto typing will start in 10 seconds...")
time.sleep(10)

# =========================================
# START TYPING
# =========================================
pyautogui.write(text_to_type, interval=0.03)

print("Done typing.")