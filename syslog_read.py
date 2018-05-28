import re
f=open("/var/log/syslog","r",encoding="utf-8")
line=f.readline()
while line:
    if(re.search(r'(May\s\d{1,2}\s+\d{1,2}:\d{1,2}:\d{1,2})',line)):
        a=re.search(r'(May\s\d{1,2}\s+\d{1,2}:\d{1,2}:\d{1,2})',line)
        print(a.group(1))
    line=f.readline()
f.close()
