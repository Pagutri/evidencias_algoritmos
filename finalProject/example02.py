# This program presses the 7 key if you have the
# galculator open

import pyautogui

button7location = pyautogui.locateOnScreen('key7.png')
button7x, button7y = pyautogui.center(button7location)
# clicks the center of where the 7 button was found
pyautogui.click(button7x, button7y)

# This is a more compact way of doing the same
x, y = pyautogui.locateCenterOnScreen('key7.png')
pyautogui.click(x, y)

# These “locate” functions are fairly expensive;
# they can take a full second to run. The best way
# to speed them up is to pass a region argument 
# (a 4-integer tuple of (left, top, width, height)) 
# to only search a smaller region of the screen instead
# of the full screen