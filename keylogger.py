from pynput import keyboard
import socket

# our network
ESP32_IP = "192.168.1.15"  # ESP32 ip
PORT = 12345

# tcp connection
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((ESP32_IP, PORT))

def on_press(key):
    try:
        sock.sendall(key.char.encode('utf-8'))
    except AttributeError:
        # speciel key ( Shift, Ctrl, Alt)
        sock.sendall(str(key).encode('utf-8'))

def on_release(key):
    if key == keyboard.Key.esc:
        return False

# listen to keyboard
with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()

# closing connection
sock.close()