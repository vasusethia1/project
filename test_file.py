import re
import os
list_number=['10','22','44','55','66','77']
statinfo=os.stat("/var/log/hids.log")
pos=statinfo.st_size
if pos==0:
    f=open("/var/log/hids.log","w+")
    for port_open in list_number:
        str="\n"+port_open
        f.write(str)
        f.close()
else:
    for port_open in list_number:
        f = open("/var/log/hids.log", "r+")
        my_regex = r"\b" + re.escape(port_open) + r"\b"
        read_data=f.read()
        if re.search(my_regex,read_data):
            continue
        else:
            f.seek(len(read_data))
            write_data="\n"+port_open
            f.write(write_data)
        f.close()

port_list=[]



