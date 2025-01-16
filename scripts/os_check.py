import platform
import sys

def is_windows():
    return sys.platform.startswith('win32') or sys.platform.startswith('cygwin')

def is_linux():
    return sys.platform.startswith('linux')

def is_macos():
    return sys.platform.startswith('darwin')