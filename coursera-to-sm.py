# Write your code here :-)

import re

f = open("coursera text.txt", "r+") #bow ties are cool and so is the face of boe

regexObj = re.compile(r'Play video starting at \d* minute(s)? \d* second(s)? and follow transcript\d*:\d*')

file = f.read()

#print(file)

matchObjList = regexObj.sub(" ", file)

# print(type(matchObj))

#for matchObj in matchObjList:
    #print(matchObj)
    #.(matchObj, " ")

print(matchObjList)
#print(file)

f.close()

with open("coursera text.txt", "a") as g:
    g.write("\n\n\n\n\n\n\n" + matchObjList)

