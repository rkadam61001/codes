import math
from itertools import combinations
from itertools import permutations
import csv
file = open('output.csv', 'w', newline ='')
def read_data_in_dict(filename):
    f = open(filename)
    lines = f.readlines()
    transactions = []
    items = lines[0].split(',')
    for line in lines[1:]:
        transactions.append(list(map(int,line.split(','))))
    data ={
        'items':items,
        'transactions':transactions
    }
    return data


def frequent_itemsets(data,level,min_support):
    items = data['items']
    transactions = data['transactions']
    min_freq = math.ceil(min_support*len(transactions))
    sets = list(combinations(items,level))
    frequent_sets = []
    for s in sets:
        freq=get_freq(s,items,transactions)
        if freq>=min_freq:
            frequent_sets.append(s)
    return frequent_sets
        



def get_freq(s,items,transactions):
    freq=0
    for t in transactions:
        temp=1
        for item in s:
            temp*=t[items.index(item)]
        if temp==1:
            freq+=1  
    return freq

file = open('output.csv', 'w', newline ='')

def generate_rule(data,min_support,min_confidence):
    items = data['items']
    transactions = data['transactions']
    for l in range(2,len(data['items'])+1):
        frequent_set = frequent_itemsets(data,l,min_support)
        for s in frequent_set:
            freq_s = get_freq(s,items,transactions)
            _s_permute = list(permutations(s))
            print(_s_permute)
            for _s in _s_permute:
                file = open('output.csv', 'w', newline ='')
                for i in range(0,len(_s)-1):
                    x = _s[0:i+1]
                    y = _s[i+1:]
                    freq_x = get_freq(x,items,transactions)
                    c = freq_s/freq_x
                    if c >= min_confidence:
                        print(x,' -> ',y,'confidence is ',c)
                        file = open('output.csv', 'w', newline ='')
 
                        with file:
    # identifying header 
                            header = ['Rule', 'Confidence']
                            writer = csv.DictWriter(file, fieldnames = header)
    # writing data row-wise into the csv file
                            writer.writeheader()
                            writer.writerow({'Rule' : str(x)+'->'+str(y),
                     'Confidence': str(c)})
                    
                   
data = read_data_in_dict('itemsets.csv')


generate_rule(data,0.5,0.4)