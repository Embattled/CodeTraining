#! python
import sys

material=set()
for i in range(1,len(sys.argv)):
    material.add(sys.argv[i])

recipes=dict()
recipename=[]

with open('recipes.txt', 'r') as openfile:
  for _, data in enumerate(openfile):
      s=data.split(':')
      recipes[s[0]]=s[1].strip().split(' ')
      recipename.append(s[0])

def search(index,restm:set,nowrecipes:list):
    if(index==len(recipename)):

        for _,needm in recipes.items():
            check=True
            for m in needm:
                if m not in restm:
                    check = False
                    break
            if check:
                return
        print(', '.join(nowrecipes))
        return 
    
    search(index+1,restm.copy(),nowrecipes.copy())
    for m in recipes[recipename[index]]:
        if m in restm:
            restm.remove(m)
        else:
            return
    nowrecipes.append(recipename[index])
    search(index+1,restm,nowrecipes)

search(0,material,[])


# print(recipes)


