import random

def getInt():
    return random.randint(1,100)

def reinforce(success:int,drop=0,broke=0):
    rn=getInt()

    if(rn<=success):
        return 1
    elif drop!= 0 and rn <= (success+drop):
        return -1
    elif broke!=0 and  rn <= (success+drop+broke):
        return -2
    else:
        return 0

succlist=[10,7,5,3,1]
droplist=[0,15,15,15,15]
brokelist=[5,5,5,5,5]

def sim_reinforce():
    lv=0
    broketime=0
    reintimes=0
    while lv<5:

        reintimes+=1
        res=reinforce(succlist[lv]+5,droplist[lv],brokelist[lv])
        if res==-2:
            broketime+=1
        else:
            lv+=res
    return reintimes,broketime

rt,bt=sim_reinforce()
print("Cost {} reinforce and broke {} times.".format(rt,bt))