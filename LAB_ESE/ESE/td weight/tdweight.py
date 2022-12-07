import pandas as pd
import csv
df=pd.read_csv('tdweight.csv',names=['A','B'])
data=df.values.tolist()
c1_tot=0
c2_tot=0
r1_tot=0
r2_tot=0
for i in range(3):
    for j in range(2):
        if(i==1):
            r1_tot=r1_tot+int(data[i][j])
        if(i==2):
            r2_tot=r2_tot+int(data[i][j])
        if(j==0 and i>0):
            c1_tot=c1_tot+int(data[i][j])
        if(j==1 and i>0):
            c2_tot=c2_tot+int(data[i][j])

print('r1_tot:',r1_tot)
print('r2tot:',r2_tot)
print('c1_tot:',c1_tot)
print('c1_tot:',c2_tot)
set=[]
for i in range(3):
    for j in range(2):
        if(i==1):
            no=int(data[i][j])
            print("t weight for"+ str(no) +"is:",(float(no/r1_tot)*100))
            set.append((float(no/r1_tot)*100))

        if(i==2):
            no=int(data[i][j])
            print("t weight for"+str(no)+"is :",(float(no/r2_tot)*100))
            set.append((float(no/r2_tot)*100))
        if(j==0 and i>0):
            no=int(data[i][j])
            print("d weight for"+str(no)+"is:",float(no/c1_tot)*100)
            set.append(float(no/c1_tot)*100)
        if(j==1 and i>0):
            no=int(data[i][j])
            print("d weight for"+str(no)+"is:",float(no/c2_tot)*100)
            set.append(float(no/c2_tot)*100)

with open('output.csv', 'w') as csvfile: 
    # creating a csv writer object 
         csvwriter = csv.writer(csvfile) 
        
    # writing the fields 
         csvwriter.writerow(set) 
        
    # writing the data rows 



