# Write your code here :-)
# code that surrounds some selected text
# with certain open parens and close parens
import math, time, pyperclip, re, threading, sys

boi = '1'

surrounder = input()

#token = re.compile(r'.*boi.*').search(surrounder).group()
token = re.compile(r'.*'+boi+'.*').search(surrounder).group()

left = ""
right = ""

if token == None:
    left = surrounder[: math.floor(len(surrounder) / 2)]
    right = surrounder[math.floor(len(surrounder) / 2) :]
else:
    left = token[:token.find(boi)]
    right = token[token.find(boi)+len(boi):]

varies = True
def pasta():
    interrupt = input()
    if len(interrupt):
        print("stopping script!")
        varies = False
        #threadObj2.stop()

def potatoes():
    print("hi!")
    while(varies):
        inputtext = pyperclip.waitForNewPaste()
        print(inputtext)
        linesre = re.compile(r'(.*$)*')
        listie = linesre.findall(inputtext)
        print(listie == None)
        hmm = ""
        #hmm += listie.group()
        for thing in listie:
            print(thing)
            hmm += left + thing[:-2] + right + thing[-2:]
        pyperclip.copy(hmm)
        time.sleep(2)

threadObj = threading.Thread(target=potatoes)
threadObj.start()
time.sleep(15)
threadObj2 = threading.Thread(target=pasta)
threadObj2.start()

#print(token)
#bois



#inputtext = ""
#def pasta():
#    inputtext = pyperclip.waitForNewPaste()
#    pyperclip.copy(left + inputtext + right)
#    print(left + inputtext + right)

#threadObj = threading.Thread(target=pasta)
#threadObj.start()









#When called on a regex that has groups,
#such as (\d\d\d)-(\d\d\d)-(\d\d\d\d),
#the method findall() returns a list of tuples of strings
#(one string for each group),
#such as [('415', '555', '9999'), ('212', '555', '0000')].
