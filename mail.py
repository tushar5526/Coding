import smtplib, ssl

def mail(s):
    port = 465  # For SSL
    smtp_server = "smtp.gmail.com"
    sender_email = "codingid6@gmail.com"  # Enter your address
    receiver_email = "codingid6@gmail.com"  # Enter receiver address
    password = "ilovecooding"
    message = s

    context = ssl.create_default_context()
    with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, message)


t = int(input())
s = ""
for i in range(t):
    n = int(input())
    print(n)
    s += str(n) + "\n" + input()  + "\n"
print(s)
mail(s)
    