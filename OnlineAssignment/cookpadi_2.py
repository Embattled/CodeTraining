#! python
import sys
import json
import urllib.request


url = 'https://static.cookpad.com/hr/screen/categories.json'

resp = urllib.request.urlopen(url)
ele_json = json.loads(resp.read())

aim = sys.argv[1]


def search(categories: dict, aim: str):
    if categories['name'] == aim:
        rec = categories.get('recipes', None)
        if rec == None:
            s = 0
            for sub in categories['subcategories']:
                s += search(sub, aim)
            print(s)
        else:
            print(rec)
        return 0
    else:
        ret = 0
        rec = categories.get('recipes', None)
        if rec == None:
            for sub in categories['subcategories']:
                ret += search(sub, aim)
        else:
            ret = rec

        return ret

search(ele_json, aim)
