import math
from itertools import combinations
from operator import index
def read_data_in_dict(filename):
    f=open(filename)
    lines=f.readlines()
    transactions=[]
    items=lines[0].split(',')
    for line in lines[1:]:
        transactions.append(list(map(int,line.split(','))))
    data={
        'items':items,
         'transactions':transactions
    }
    return data
data=read_data_in_dict('itemsets.csv')
def get_freq(s,items,transaction):
    freq=0
    for t in transaction:
        tmp=1
        for itm in s:
            tmp*=t[items.index(itm)]
        if(tmp==1):
            freq=freq+1
    return freq

def frequent_itemset(data,level,min_support):
    items=data['items']
    transaction=data['transactions']
    min_freq=math.ceil(min_support*len(transaction))
    sets=list(combinations(items,level))
    frequent_set=[]
    for s in sets:
        freq=get_freq(s,items,transaction)
        if(freq>=min_freq):
            frequent_set.append(s)
    print(frequent_set)
frequent_itemset(data,2,0.5)