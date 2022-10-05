import cx_Freeze
import sys
import os 
base = None

if sys.platform == 'win32':
    base = "Win32GUI"

os.environ['TCL_LIBRARY'] = r"C:\Users\HP\AppData\Local\Programs\Python\Python38\tcl\tcl8.6"
os.environ['TK_LIBRARY'] = r"C:\Users\HP\AppData\Local\Programs\Python\Python38\tcl\tk8.6"

executables = [cx_Freeze.Executable("texteditor.py", base=base, icon="myicon.ico")]


cx_Freeze.setup(
    name = "Kraber Text Editor",
    options = {"build_exe": {"packages":["tkinter","os"], "include_files":["myicon.ico",'tcl86t.dll','tk86t.dll', 'icons']}},
    version = "0.01",
    description = "Tkinter Application",
    executables = executables
    )
