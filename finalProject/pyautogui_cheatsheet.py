import pyautogui

pyautogui.position()  # current mouse x and y
pyautogui.size()  # current screen resolution width and height
pyautogui.onScreen(x, y)  # True if x & y are within the screen.

# Set up a 2.5 second pause after each PyAutoGUI call:
pyautogui.PAUSE = 2.5

# When fail-safe mode is True, moving the mouse to the
# upper-left will raise a pyautogui.FailSafeException
# that can abort your program
pyautogui.FAILSAFE = True

# move mouse to XY coordinates over num_second seconds
# The None value can be passed for a coordinate to mean 
# “the current mouse cursor position”
pyautogui.moveTo(x, y, duration=num_seconds)
# move mouse relative to its current position
pyautogui.moveRel(xOffset, yOffset, duration=num_seconds)

pyautogui.dragTo(x, y, duration=num_seconds)  # drag mouse to XY
# drag mouse relative to its current position
pyautogui.dragRel(xOffset, yOffset, duration=num_seconds)

# The button keyword argument can be 'left', 'middle', or 'right'.
pyautogui.click(x=moveToX, y=moveToY, clicks=num_of_clicks, interval=secs_between_clicks, button='left')

# O bien,
pyautogui.rightClick(x=moveToX, y=moveToY)
pyautogui.middleClick(x=moveToX, y=moveToY)
pyautogui.doubleClick(x=moveToX, y=moveToY)
pyautogui.tripleClick(x=moveToX, y=moveToY)

# Positive scrolling will scroll up, negative scrolling will scroll down:
pyautogui.scroll(amount_to_scroll, x=moveToX, y=moveToY)

pyautogui.mouseDown(x=moveToX, y=moveToY, button='left')
pyautogui.mouseUp(x=moveToX, y=moveToY, button='left')

# The full list of key names is in pyautogui.KEYBOARD_KEYS.
pyautogui.typewrite('Hello world!\n', interval=secs_between_keys)

pyautogui.hotkey('ctrl', 'c')  # ctrl-c to copy
pyautogui.hotkey('ctrl', 'v')  # ctrl-v to paste

pyautogui.keyDown(key_name)
pyautogui.keyUp(key_name)

pyautogui.alert('This displays some text with an OK button.')
pyautogui.confirm('This displays text and has an OK and Cancel button.')
pyautogui.prompt('This lets the user type in a string and press OK.')
'This is what I typed in.'

# returns (left, top, width, height) of first place it is found
pyautogui.locateOnScreen('looksLikeThis.png')
pyautogui.locateCenterOnScreen('looksLikeThis.png')  # returns center x and y

# The locate functions are slow