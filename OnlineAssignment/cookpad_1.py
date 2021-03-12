#! python
import sys

test=sys.argv[1]
f=open(test)
s=f.read()
nums=s.split(' ')

set_id=set(list(range(1,len(nums)+2)))

for num in nums:
    set_id.remove(int(num))
for rest in set_id:
    print(rest)