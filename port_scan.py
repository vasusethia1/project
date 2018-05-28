import socket
import os
import re
import smpt_mail
from datetime import datetime
port_open_list=[]
def connect_port(target_address,target_port):
   try:
    socket_desc=socket.socket()
    socket_desc.connect((target_address,target_port))
    port_open_list.append(str(target_port))
    socket_desc.close()
   except:
       return
def add_to_file():
    statinfo = os.stat("/var/log/hids.log")
    pos = statinfo.st_size
    if pos == 0:
        f = open("/var/log/hids.log","w+")
        for port_open in port_open_list:
            str = port_open+"\n"
            f.write(str)
            f.close()
    else:
        for port_open in port_open_list:
            f = open("/var/log/hids.log", "r+")
            my_regex = r"\b" + re.escape(port_open) + r"\b"
            read_data = f.read()
            if re.search(my_regex, read_data):
                continue
            else:
                f.seek(len(read_data))
                smpt_mail.send_mail_message(port_open,str(datetime.now()))
                write_data = port_open+"\n"
                f.write(write_data)
            f.close()
if __name__ == '__main__':
    port_list=[80,22,21,23,445]
    for port in port_list:
        connect_port('127.0.0.1',port)
    add_to_file()

