from tkinter import *
from tkinter import font,filedialog,messagebox,ttk
import os
from tkinter import colorchooser

root=Tk()
root.title("Kraber Text Editor")
root.iconbitmap("myicon.ico")
root.geometry("1400x795")
# root.minsize(width=1400,height=795)
# root.maxsize(width=1400,height=795)

open_status_file=False
tool_check=False
status_check=False
selected=False
text_changed=False
bg_col = ["#f38181", "#21094e", "#e4fbff", "#233e8b"]
fg_col = ["#fce38a", "#a5e1ad", "#7868e6", "#ffffc7"]

def myfind(text):
    if text:
        pos='1.0'
        matches=0
        while True:
            pos=my_text.search(text,pos,stopindex=END)
            if not pos:
                break
            endpos=f"{pos}+{len(text)}c" # this will update the index of endpos properly if used without c at the end then it will give an error
            my_text.tag_add("match",pos,endpos)
            matches+=1
            pos=endpos
            my_text.tag_config("match",foreground="red",background="yellow")
    messagebox.showinfo("Find Results",f"{matches} number of Entries found!")

def myreplace(textf,textr):
    chars=my_text.get(1.0,END)
    char2=chars.replace(textf,textr)
    print(char2)
    my_text.delete(1.0,END)
    my_text.insert(1.0,char2)
    if char2 != chars:
        messagebox.showinfo("Find And Replace","Text replaced Successfully!")
    else:
        messagebox.showinfo("Find And Replace","No Matches were found to replace your text")


def find_and_replace():
    win2=Toplevel()
    win2.title("Find and Replace")
    win2.iconbitmap("icons/find.ico")
    win2.geometry("500x450")
    win2.resizable(0,0)

    # Find Section
    find_label_frame=ttk.LabelFrame(win2,text="Find")
    find_label_frame.pack(padx=20,pady=20)

    find_label=ttk.Label(find_label_frame,text="Enter Your Keyword Here: ",font=("Helvetica",12))
    find_label.grid(row=0,column=0,padx=20,pady=20)

    find_entry=ttk.Entry(find_label_frame,font=("Helvetica",12))
    find_entry.grid(row=0,column=1,pady=20,padx=(0,20))

    find_button=ttk.Button(find_label_frame,text="Find",command=lambda:myfind(find_entry.get()))
    find_button.grid(row=1,column=0,columnspan=2,padx=10,pady=10)

    # Find and Replace Section
    find_and_replace_label_frame=ttk.Labelframe(win2,text="Find and Replace")
    find_and_replace_label_frame.pack(padx=20,pady=20)

    find_and_replace_label1=ttk.Label(find_and_replace_label_frame,text="Enter Your Keyword Here: ",font=("Helvetica",12))
    find_and_replace_label1.grid(row=0,column=0,padx=20,pady=20)

    find_and_replace_entry1=ttk.Entry(find_and_replace_label_frame,font=("Helvetica",12))
    find_and_replace_entry1.grid(row=0,column=1,padx=(0,20),pady=20)

    find_and_replace_button1=ttk.Button(find_and_replace_label_frame,text="Find",command=lambda:myfind(find_and_replace_entry1.get()))
    find_and_replace_button1.grid(row=1,column=0,columnspan=2,padx=10,pady=10)

    find_and_replace_label2=ttk.Label(find_and_replace_label_frame,text="Enter Your Text to Replace: ",font=("Helvetica",12))
    find_and_replace_label2.grid(row=2,column=0,padx=20,pady=20)

    find_and_replace_entry2=ttk.Entry(find_and_replace_label_frame,font=("Helvetica",12))
    find_and_replace_entry2.grid(row=2,column=1,padx=(0,20),pady=20)

    find_and_replace_button2=ttk.Button(find_and_replace_label_frame,text="Replace",command=lambda:myreplace(find_and_replace_entry1.get(),find_and_replace_entry2.get()))
    find_and_replace_button2.grid(row=3,column=0,columnspan=2,padx=10,pady=10)

    win2.mainloop()

def update_status(event):
    global text_changed
    if my_text.edit_modified():
        chars=len(my_text.get(1.0,"end-1c"))
        words=len(my_text.get(1.0,"end-1c").split(" "))
        status_bar.config(text=f"Characters: {chars}  Words: {words}")
        text_changed=True
    my_text.edit_modified(False) # this line is required for updation in status bar
    
def about():
    messagebox.showinfo("Kraber Text Editor","This is very cool text editor Enjoy!")

def new_file():
    global open_status_file
    open_status_file=False
    # Deleting the previous content
    my_text.delete(1.0,END)
    # Changing the root title
    root.title("Untitled -- Kraber Text Editor")

def open_file():
    global open_status_file
    file_name=filedialog.askopenfilename(initialdir=os.getcwd(),title="Choose a Text File",filetypes=(("Text Files","*.txt"),("Python Files","*.py"),("C++ Files","*.cpp"),("All Files","*.*")))
    if file_name:
        open_status_file=file_name
        # Deleting the previous content
        my_text.delete(1.0, END)
        # Changing the root title
        root.title(f"{os.path.basename(file_name)} -- Kraber Text Editor")
        #opening the file, reading it's content and putting it into text box
        with open(file_name,'r') as f:
            my_text.insert(END,f.read())
    
def save_as():
    global text_changed
    # asking for file to get saved
    file_name = filedialog.asksaveasfilename(initialdir=os.getcwd(), title="Save As", defaultextension=".*", filetypes=(("Text File", "*.txt"), ("Python File", "*.py"), ("C++ File", "*.cpp")))
    if file_name:
        text_changed=False
        # Changing the root title
        root.title(f"{os.path.basename(file_name)} -- Kraber Text Editor")
        # Saving the file or writing the content into the file
        with open(file_name,"w") as f:
            f.write(my_text.get(1.0,END))
        status_bar.config(text=f"{status_bar['text']}  -- saved ✓")
        messagebox.showinfo("Save","Saved your file Successfully!")

def save():
    global open_status_file,text_changed
    text_changed=False
    if open_status_file:
        # Changing the root title
        root.title(f"{os.path.basename(open_status_file)} -- Kraber Text Editor")
        # Saving the file or writing the content into the file
        with open(open_status_file, "w") as f:
            f.write(my_text.get(1.0, END))
        status_bar.config(text=f"{status_bar['text']}  -- saved ✓")
    else:
        save_as()

def cut(event):
    global selected
    if event:
        selected=root.clipboard_get()
    else:
        if my_text.selection_get():
            selected=my_text.selection_get()
            my_text.delete("sel.first","sel.last")
            root.clipboard_clear()
            root.clipboard_append(selected)

def copy(event):
    global selected
    if event:
        selected=root.clipboard_get()
    else:
        if my_text.selection_get():
            selected = my_text.selection_get()
            root.clipboard_clear()
            root.clipboard_append(selected)

def paste(event):
    global selected
    if event:
        selected=root.clipboard_get()
    else:
        if selected:
            position=my_text.index(INSERT)
            my_text.insert(position,selected)

# Bold function
def bold_it():
    bold_font=font.Font(my_text,my_text.cget("font"))
    bold_font.config(weight=font.BOLD)
    
    my_text.tag_configure("bold",font=bold_font)
    curr_font=my_text.tag_names("sel.first")

    if "bold" in curr_font:
        my_text.tag_remove("bold","sel.first","sel.last")
    else:
        my_text.tag_add("bold","sel.first","sel.last")

# Italic function
def italic_it():
    italic_font=font.Font(my_text,my_text.cget("font"))
    italic_font.config(slant="italic")

    my_text.tag_configure("italic",font=italic_font)
    curr_font=my_text.tag_names("sel.first")

    if "italic" in curr_font:
        my_text.tag_remove("italic","sel.first","sel.last")
    else:
        my_text.tag_add("italic","sel.first","sel.last")

# Underline function
def underline_it():
    underline_font=font.Font(my_text,my_text.cget("font"))
    underline_font.config(underline=True)

    my_text.tag_configure("underline",font=underline_font)
    curr_font = my_text.tag_names("sel.first")

    if "underline" in curr_font:
        my_text.tag_remove("underline", "sel.first", "sel.last")
    else:
        my_text.tag_add("underline", "sel.first", "sel.last")

# font color selected text
def font_color_sel():
    my_color = colorchooser.askcolor()[1]
    if my_color:
        try:
            color_font=font.Font(my_text,my_text.cget("font"))
            curr_color=my_text.tag_names("sel.first")

            my_text.tag_configure("colored",foreground=my_color,font=color_font)
            if "colored" in curr_color:
                my_text.tag_remove("colored","sel.first","sel.last")
            else:
                my_text.tag_add("colored", "sel.first", "sel.last")
       
        except Exception:
            my_text.configure(fg=my_color)

# font color for all text
def font_color():
    my_color = colorchooser.askcolor()[1]
    if my_color:
        my_text.configure(fg=my_color)

# background color
def bg_color():
    my_color = colorchooser.askcolor()[1]
    if my_color:
        my_text.configure(bg=my_color)

def theme(e):
    global bg_col,fg_col
    my_text.configure(bg=bg_col[e],fg=fg_col[e])

def font_changer(e):
    new_font=font_style.get()
    print(new_font)
    my_text.configure(font=(new_font,font_size_box.get()))


def show_status_bar():
    global status_check
    if status_check:
        my_scrollx.pack_forget()
        status_bar.pack()
        my_scrollx.pack(fill=X,side=BOTTOM)
        view_menu.entryconfigure(0, label=" Status Bar  ✓")
        status_check=False
    else:
        status_bar.pack_forget()
        view_menu.entryconfigure(0,label=" Status Bar")
        status_check=True

def show_tool_bar():
    global tool_check
    if tool_check:
        main_frame.pack_forget()
        tool_bar.pack(fill=X, side=TOP)
        main_frame.pack(fill=BOTH,expand=1)
        view_menu.entryconfigure(1, label=" Tool Bar  ✓")
        tool_check=False
    else:
        tool_bar.pack_forget()
        view_menu.entryconfigure(1,label=" Tool Bar")
        tool_check=True
    
def clear_all():
    my_text.delete(1.0,END)
    update_status(1)

def font_sizer(event):
    my_text.configure(font=(font_style.get(),font_size_box.get()))

def left_align():
    content=my_text.get(1.0,"end")
    my_text.delete(1.0, END)
    my_text.tag_configure("left",justify=LEFT)
    my_text.insert(INSERT,content,'left') # here INSERT specifies that our text will get inserted where the cursor is active

def center_align():
    content=my_text.get(1.0,END)
    my_text.delete(1.0,END)
    my_text.tag_configure("center",justify=CENTER)
    my_text.insert(INSERT,content,'center')

def right_align():
    content=my_text.get(1.0,END)
    my_text.delete(1.0,END)
    my_text.tag_configure("right",justify=RIGHT)
    my_text.insert(INSERT,content,'right')

def myquit():
    global text_changed
    if text_changed:
        response=messagebox.askyesnocancel("Exit","Do you want to save your file before quitting?")
        if response==True:
            save()
            root.quit()
        elif response==False:
            root.quit()
    else:
        root.quit()

#Importing images
bold_img = PhotoImage(file="icons/bold.png")
italic_img = PhotoImage(file="icons/italic.png")
underline_img = PhotoImage(file="icons/underline.png")
new_img=PhotoImage(file="icons/new.png")
open_img=PhotoImage(file="icons/open.png")
save_img=PhotoImage(file="icons/save.png")
saveas_img=PhotoImage(file="icons/save_as.png")
cut_img=PhotoImage(file="icons/cut.png")
copy_img=PhotoImage(file="icons/copy.png")
paste_img=PhotoImage(file="icons/paste.png")
exit_img=PhotoImage(file="icons/exit.png")
find_img=PhotoImage(file="icons/find.png")
status_bar_img=PhotoImage(file="icons/status_bar.png")
tool_bar_img=PhotoImage(file="icons/tool_bar.png")
clear_all_img=PhotoImage(file="icons/clear_all.png")
undo_img=PhotoImage(file="icons/undo.png")
redo_img=PhotoImage(file="icons/redo.png")
left_align_img=PhotoImage(file="icons/align_left.png")
right_align_img=PhotoImage(file="icons/align_right.png")
center_align_img=PhotoImage(file="icons/align_center.png")

# Tool Bar Frame
tool_bar=ttk.Frame(root)
tool_bar.pack(fill=X,side=TOP)

# font styles
font_family=font.families()
print(font_family)
font_style = ttk.Combobox(tool_bar,values=font_family,width=30,state="readonly")
font_style.set("Comic Sans MS")
font_style.grid(row=0, column=0, padx=10, pady=3)

# font size
font_size=[i for i in range(1,101)]
font_size_box=ttk.Combobox(tool_bar,values=font_size,width=4,state="readonly")
font_size_box.set("14")
font_size_box.grid(row=0,column=1,pady=3,padx=10)

# Bold Button
bold_btn=Button(tool_bar,image=bold_img,borderwidth=0,command=bold_it)
bold_btn.grid(row=0,column=2,pady=3,padx=10)

# Italic Button
italic_btn=Button(tool_bar,image=italic_img,borderwidth=0,command=italic_it)
italic_btn.grid(row=0, column=3,pady=3,padx=10)

# Underline Button
underline_btn = Button(tool_bar, image=underline_img, borderwidth=0,command=underline_it)
underline_btn.grid(row=0, column=4, pady=3, padx=10)

# Left align Button 
left_align_btn = Button(tool_bar,image=left_align_img,borderwidth=0,command=left_align)
left_align_btn.grid(row=0, column=5, pady=3, padx=10)

# Center align Button
center_align_btn = Button(tool_bar, image=center_align_img, borderwidth=0,command=center_align)
center_align_btn.grid(row=0, column=6, pady=3, padx=10)

# Right align Button
right_align_btn = Button(tool_bar,image=right_align_img,borderwidth=0,command=right_align)
right_align_btn.grid(row=0,column=7,pady=3,padx=(10,1330))

# Main Frame
main_frame=ttk.Frame(root)
main_frame.pack(fill=BOTH)


# Creating text area (wrap="none" means we can extend our words now horizontally also)
my_text=Text(main_frame,height=27,width=200,font=("Comic Sans Ms",14),selectbackground="yellow",selectforeground="black",undo=True,wrap="none")

#scroll frame
scroll_frame=ttk.Frame(main_frame)

my_scrolly=ttk.Scrollbar(main_frame,command=my_text.yview)
my_scrollx=ttk.Scrollbar(scroll_frame,command=my_text.xview,orient=HORIZONTAL)
my_text.configure(yscrollcommand=my_scrolly.set,xscrollcommand=my_scrollx.set)
my_scrolly.pack(side=RIGHT,fill=Y)

# Status Bar
status_frame=ttk.Frame(main_frame,borderwidth=0)
status_frame.pack(fill=X, side=BOTTOM)
status_bar=ttk.Label(status_frame,text="Status Bar")
status_bar.pack(pady=(1,3))

my_scrollx.pack(fill=X)
scroll_frame.pack(fill=X,side=BOTTOM)
my_text.pack(fill=BOTH)

# Creating Menus
my_menu=Menu(root,tearoff=0)
root.config(menu=my_menu)

# File Menu
file_menu=Menu(my_menu,tearoff=0)
my_menu.add_cascade(menu=file_menu,label="File")
file_menu.add_command(image=new_img,command=new_file,label=" New",compound=LEFT)
file_menu.add_command(label=" Open",command=open_file,image=open_img,compound=LEFT)
file_menu.add_separator()
file_menu.add_command(label=" Save",command=save,image=save_img,compound=LEFT)
file_menu.add_command(label=" Save As",command=save_as,image=saveas_img,compound=LEFT)
file_menu.add_separator()
file_menu.add_command(label=" Exit",command=myquit,image=exit_img,compound=LEFT)

#Edit Menu
edit_menu=Menu(my_menu,tearoff=0)
my_menu.add_cascade(label="Edit",menu=edit_menu)
edit_menu.add_command(label=" Cut",command=lambda:cut(False),accelerator="Ctrl+X",image=cut_img,compound=LEFT)
edit_menu.add_command(label=" Copy",command=lambda:copy(False),accelerator="Ctrl+C",image=copy_img,compound=LEFT)
edit_menu.add_command(label=" Paste",command=lambda:paste(False),accelerator="Ctrl+V",image=paste_img,compound=LEFT)
edit_menu.add_separator()
edit_menu.add_command(label=" Undo",accelerator="Ctrl+Z",command=my_text.edit_undo,image=undo_img,compound=LEFT)
edit_menu.add_command(label=" Redo",accelerator="Ctrl+Y",command=my_text.edit_redo,image=redo_img,compound=LEFT)
edit_menu.add_separator()
edit_menu.add_command(label=" Clear All",image=clear_all_img,compound=LEFT,command=clear_all)
edit_menu.add_command(label=" Find and Replace",command=find_and_replace,image=find_img,compound=LEFT)

# Color Menu
color_menu=Menu(my_menu,tearoff=0)
my_menu.add_cascade(label="Color",menu=color_menu)
color_menu.add_command(label="Selected Text Color",command=font_color_sel)
color_menu.add_command(label="All Text Color",command=font_color)
color_menu.add_command(label="Background",command=bg_color)
color_menu.add_separator()
theme_menu=Menu(color_menu,tearoff=0)
color_menu.add_cascade(label="Theme",menu=theme_menu)
theme_menu.add_command(label="Cool Red",command=lambda:theme(0))
theme_menu.add_command(label="Dark",command=lambda:theme(1))
theme_menu.add_command(label="Light", command=lambda: theme(2))
theme_menu.add_command(label="Cool Blue", command=lambda: theme(3))

# View Menu
view_menu=Menu(my_menu,tearoff=0)
my_menu.add_cascade(menu=view_menu,label="View")
view_menu.add_command(label=" Status Bar   ✓",command=show_status_bar,image=status_bar_img,compound=LEFT)
view_menu.add_command(label=" Tool Bar     ✓",command=show_tool_bar,image=tool_bar_img,compound=LEFT)

# Help Menu
help_menu=Menu(my_menu,tearoff=0)
my_menu.add_cascade(label="Help",menu=help_menu)
help_menu.add_command(label="About",command=about)

# Bindings to the function
my_text.bind("<<Modified>>",update_status)
root.bind("<Control-Key-x>",cut)
root.bind("<Control-Key-c>",copy)
root.bind("<Control-Key-v>",paste)
font_style.bind("<<ComboboxSelected>>",font_changer)
font_size_box.bind("<<ComboboxSelected>>",font_sizer)

root.mainloop()
