from tkinter import * 
expression = "" 
def press(num): 
 global expression  
 expression = expression + str(num)  
 equation.set(expression) 

def equalpress():  
   try: 
     global expression  
     total = str(eval(expression)) 
     equation.set(total) 
     expression = "" 
   except: 
     equation.set(" error ") 
     expression = "" 

def clear(): 
 global expression 
 expression = "" 
 equation.set("0")
if __name__ == "__main__": 
 gui = Tk() 
 gui.title("Calculator") 
 gui.geometry("270x150") 
 equation = StringVar() 
 expression_field = Entry(gui, textvariable=equation)  
 expression_field.grid(columnspan=4, ipadx=70) 
 clrscr = Button(gui, text=' C ', fg='black', bg='grey',  command=clear, height=1, width=7)  
 clrscr.grid(row=2, column=0) 
 squareRoot = Button(gui, text=' √ ', fg='black', bg='grey',  command=lambda: press('√'), height=1, width=7)  
 squareRoot.grid(row=2, column=1) 
 exponent = Button(gui, text=' x^y ', fg='black', bg='grey',  command=lambda: press('^'), height=1, width=7) 
 exponent.grid(row=2, column=2) 
 percent = Button(gui, text=' % ', fg='black', bg='grey',  command=lambda: press('%'), height=1, width=7)  
 percent.grid(row=2, column=3) 
 num1 = Button(gui, text=' 1 ', fg='black', 
 command=lambda: press(1), height=1, width=7)  
 num1.grid(row=3, column=0) 
 num2 = Button(gui, text=' 2 ', fg='black', 
 command=lambda: press(2), height=1, width=7) 
num2.grid(row=3, column=1) 
num3 = Button(gui, text=' 3 ', fg='black', 
 command=lambda: press(3), height=1, width=7)  
num3.grid(row=3, column=2) 
plus = Button(gui, text=' + ', fg='black', bg='grey',  command=lambda: press('+'), height=1, width=7) 
plus.grid(row=3, column=3) 
num4 = Button(gui, text=' 4 ', fg='black',
 command=lambda: press(4), height=1, width=7)  
num4.grid(row=4, column=0) 
num5 = Button(gui, text=' 5 ', fg='black', 
 command=lambda: press(5), height=1, width=7)  
num5.grid(row=4, column=1)  
num6 = Button(gui, text=' 6 ', fg='black', 
 command=lambda: press(6), height=1, width=7) 
num6.grid(row=4, column=2) 
minus = Button(gui, text=' - ', fg='black', bg='grey',  command=lambda: press("-"), height=1, width=7)  
minus.grid(row=4, column=3) 
num7 = Button(gui, text=' 7 ', fg='black', 
 command=lambda: press(7), height=1, width=7) 
num7.grid(row=5, column=0) 
num8 = Button(gui, text=' 8 ', fg='black', 
 command=lambda: press(8), height=1, width=7)  
num8.grid(row=5, column=1) 
num9 = Button(gui, text=' 9 ', fg='black', 
 command=lambda: press(9), height=1, width=7)  
num9.grid(row=5, column=2) 
multiply = Button(gui, text=' * ', fg='black', bg='grey',  command=lambda: press('*'), height=1, width=7)  
multiply.grid(row=5, column=3) 
num0= Button(gui, text=' 0 ', fg='black', 
 command=lambda: press(0), height=1, width=7) 
num0.grid(row=6, column=0) 
decimal= Button(gui, text=' . ', fg='black', 
 command=lambda: press('.'), height=1, width=7)  
decimal.grid(row=6, column=1) 
equals= Button(gui, text=' = ', fg='black', bg='orange',
 command=equalpress, height=1, width=7) 
equals.grid(row=6, column=2) 
divide= Button(gui, text=' / ', fg='black', bg='grey',  command=lambda: press('/'), height=1, width=7)  
divide.grid(row=6, column=3) 
 # start the GUI 
gui.mainloop() 
