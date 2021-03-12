#! python
import sys
import json
import requests

def http_post(url,data_json):
    jdata = json.dumps(data_json)
    req = requests.post(url, jdata)

    # convert response to dict
    re= json.loads(req.text)
    return re['remaining']


url='https://r3k3audez7.execute-api.ap-northeast-1.amazonaws.com/Prod/coffeepot/'


start=0
end=180

data={"minutes":0}
while start!=end :
    mid=int((start+end)/2)
    data['minutes']=mid
    resp=http_post(url,data)
    if resp==0 :
        end=mid
    else:
        start=mid+1
print(start)