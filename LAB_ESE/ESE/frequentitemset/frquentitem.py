import math
import csv
from itertools import combinations
def read_data_in_dict(filename):
    f = open(filename)
    lines = f.readlines()
    transactions = []
    items = lines[0].split(',') #string to list
    for line in lines[1:]:
        transactions.append(list(map(int,line.split(',')))) # take multiple line in list 
    data ={
        'items':items,
        'transactions':transactions  #mapping key val
    }
    #print(data)
    return data
data=read_data_in_dict('itemsets.csv') #function call
def get_freq(s,items,transactions):
    freq=0
    for t in transactions:
        temp=1
        for item in s:
            #print(items.index(item))
            print(t[items.index(item)])
            temp*=t[items.index(item)]
        if temp==1:
            freq+=1  
    return freq
def frequent_itemsets(data,level,min_support):
    items = data['items']
    #print(items) ['a', 'b', 'c', 'd', 'e', 'f\n']
    transactions = data['transactions']
    #print(transactions)[[1, 0, 1, 1, 0, 0], [0, 0, 0, 1, 1, 0],
    #  [0, 1, 1, 1, 0, 0], [1, 1, 0, 0, 1, 1], [1, 0, 1, 1, 0, 1]]
    min_freq = math.ceil(min_support*len(transactions))
    #print(min_freq)->3
    sets = list(combinations(items,level)) #combines item with lenght of level level 2-->a,b a,c so on
   # print(sets) #[('a', 'b'), ('a', 'c'), ('a', 'd'), ('a', 'e'), ('a', 'f\n'), ('b', 'c'), ('b', 'd'), ('b', 'e'), ('b', 'f\n'),
   #  ('c', 'd'), ('c', 'e'), ('c', 'f\n'), ('d', 'e'), ('d', 'f\n'), ('e', 'f\n')]
    frequent_sets = []
    for s in sets:
        freq=get_freq(s,items,transactions)
        if freq>=min_freq:
            frequent_sets.append(s)
    print(frequent_sets)
    with open('output.csv', 'w') as csvfile: 
    # creating a csv writer object 
         csvwriter = csv.writer(csvfile) 
        
    # writing the fields 
         csvwriter.writerow(frequent_sets) 
        
    # writing the data rows 
    return frequent_sets
frequent_itemsets(data,2,0.5)