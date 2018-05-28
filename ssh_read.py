import re
import subprocess
cmd="systemctl status sshd"
return_value=subprocess.check_output(cmd,shell=True)
print(len(return_value))
if re.search("loaded",return_value.decode("utf-8")):
    print("SSH service is running")
    if re.search("OpenBsd",return_value.decode("utf-8")):
        f=open("/var/log/auth.log","r")
        line=f.readline()
        while line:
            print(line)
            line=f.readline()
        f.close()