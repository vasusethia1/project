import smtplib
from email.mime.text import MIMEText
def send_mail_message(port_number,time_date_stamp):
    smtp_server_addr='stmp.gmail.com'
    smpt_server_port=465
    username="test@gmail.com"
    password="jio123"
    sender="vasu.sethia@gmail.com"
    receiver="admin@gmail.com"
    msg=MIMEText("Alert Port:",port_number,"has been opened at ",time_date_stamp)
    msg['Subject']='Alert'
    msg['From']=sender
    msg['To']=receiver
    server=smtplib.SMTP_SSL(smtp_server_addr,smtp_server_port)
    server.login(username,password)
    server.sendmail(sender,receiver,msg.decode())
    server.quit()
