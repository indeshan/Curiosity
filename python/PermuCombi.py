from itertools import permutations
sentence = "password reset successful"
for sent in permutations(sentence.split()):
    sentenseList = [' '.join(sent) for sent in permutations(sentence.split())]
sentenseList.remove(sentence)  #Removes original sentence
print(sentenseList)

