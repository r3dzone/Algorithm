N = input()
word = [];
for i in range(int(N)):
    word += [input()]

word = set(word)
word = list(word)
word.sort()
word.sort(key=len)
    
for i in word:
    print(i)