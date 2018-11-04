from tkinter import *
import tkinter as tk
from tkinter import messagebox
import mysql.connector
import os,sys


DB_HOST = 'localhost'
DB_USER = 'root'
DB_PASSWORD = '1234'
DB_NAME = 'users'

def test12():
    print("test")

def Create_Acount():
    username = I_Username.get()
    print(username)
    password = I_Password.get()
    print(password)
    mydb = mysql.connector.connect(user=DB_USER, password=DB_PASSWORD,
                              host=DB_HOST,
                              database=DB_NAME)
    cur = mydb.cursor()
    New_user="INSERT INTO users (username,password) VALUES (%s, %s)"
    val = (username,password)
    cur.execute(New_user, val)
    mydb.commit()
    messagebox.showinfo( "Acount", "Acount created")
    mydb.close()

def Log_In():
    username = I_Username.get()
    print(username)
    password = I_Password.get()
    print(password)
    mydb = mysql.connector.connect(user=DB_USER, password=DB_PASSWORD,
                              host=DB_HOST,
                              database=DB_NAME)
    cur = mydb.cursor()
    cur.execute("SELECT username FROM users WHERE username = %s", (username,))
    row = cur.fetchone()
    if row is None:
        messagebox.showinfo( "Acount", "username not found")
    else:
        cur.execute("SELECT username FROM users WHERE password = %s", (password,))
        row = cur.fetchone()
        if row is None:
            messagebox.showinfo( "Acount", "password does not match with username")
        else:
            messagebox.showinfo( "Acount", "Logged in")
    mydb.close()

top=tk.Tk()

tk.Label(top, text="Easy village").grid(column=1, row=0)
L2 = tk.Label(top, text="Username").grid(column=0, row=1)
I_Username = tk.Entry(top)
I_Username.grid(row=1, column=1, sticky=W)
L3 = tk.Label(top, text="Password").grid(column=0, row=2)
I_Password = tk.Entry(top)
I_Password.grid(column=1, row=2)
tk.Button(top, text ="Submit",command = Create_Acount).grid(column=0, row=3)
tk.Button(top, text ="Log in",command = Log_In).grid(column=1, row=3)


top.mainloop()



#p1 = threading.Thread(target=proc1)
#p2 = threading.Thread(target=proc2)
#p1.start()
#p2.start()
