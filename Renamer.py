
import os
def renamer(path, do_not_rename,not_extension,rename_extension):
    os.chdir(path)
    files = os.listdir(path)
    no = 1
    with open(do_not_rename) as not_rename:
        not_rename = not_rename.read() #es file me un files ke naam likhe hai jinko rename nhi krna hai
        not_ren = not_rename.split('\n') # jinko rename nhi krna hai unki list mil gyi
    for file in files:
        if os.path.splitext(file)[1] == not_extension:
            print(f"don't have permission of renaming this extension file\n so we dont't able to rename {file}")
        elif os.path.splitext(file)[0] in not_ren:
            print(f"r'we don't have permission to rename {file}'")
        else:
            os.rename(file,f'{no}.{rename_extension}')
        no+=1

while True:
    path = input('Enter full path')
    dont_rename= input('enter path of text file which contians name of files you do not want to rename')
    not_extension = input('enter extension you do not want to rename')
    rename_extension = input('enter extension  in which you want to rename these files')

    try:
        renamer(path, dont_rename,not_extension,rename_extension)
        print('done')

    except:
        print("Enter carefully again")
         
    kdk = input('enter e for exit')
    j = kdk.capitalize()
    print(j)
