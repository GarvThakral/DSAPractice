class Solution:
    def firstUniqChar(self, s: str) -> int:
        hashmap = {}
        for i in s:
            if(i in hashmap):
                hashmap[i]+=1
            else:
                hashmap[i] = 1
        print(hashmap)
        index = None
        for i,j in hashmap.items():
            if(j == 1):
                index = i
                break
        for i,j in enumerate(s):
            print(i,j)
            print(index)
            if(j == index):
                return i 
        return -1
