import pandas

def correlation(A,B):
    count_A=0
    count_B=0
    countA_B=0  
    n=len(A)
    for i in range(n):
        if(A[i] and B[i]):
             countA_B+=1
        if A[i]==1:
            count_A+=1
        if B[i]==1:
         count_B+=1
    prob_A=count_A/n
    prob_B=count_B/n
    probA_B=countA_B/n
    ans=probA_B/(prob_A*prob_B)
    return ans
data=pandas.read_csv("correlation.csv")
A=data['A'].tolist()
B=data['B'].tolist()
C=data['C'].tolist()
print("Corelation of A and B:",correlation(A,B))
print("Corelation of B and C:",correlation(B,C))
print("Corelation of A and C:",correlation(A,C))

