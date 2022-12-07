#include<bits/stdc++.h>
using namespace std;

double calcEntropy(int y,int n)
{
    if(y==0||n==0)
    return 0;
    double s_entropy=-(y/(float)(y+n))*(log2(y/(float)(y+n)));
    s_entropy=s_entropy+(-(n/(float)(y+n))*(log2(n/(float)(y+n))));
    return s_entropy;
}
double calcgain(map<string,pair<int,int>>tmp,double s_entropy,int total)
{
 for(auto itr=tmp.begin();itr!=tmp.end();++itr)
 {
    double p_entropy=calcEntropy(itr->second.second,itr->second.first);
    double mul=(itr->second.second+itr->second.first);
    mul=mul/total;
    s_entropy-=((mul)*p_entropy);
 }
 return s_entropy;
}
int main()
{
    fstream file("tennis.csv",ios::in);
    string line,word;
    vector<string>row;
    vector<vector<string>>content;
    if(file.is_open())
    {
        //cout<<"ete";
        while(getline(file,line))
        {
            row.clear();
            stringstream s(line);
            while(getline(s,word,','))
            {
                //cout<<word<<endl;
                row.push_back(word);
            }
            content.push_back(row);
        }
    }
    map<string,pair<int,int>>outlook;
    map<string,pair<int,int>>Temp;
    map<string,pair<int,int>>Humidity;
    map<string,pair<int,int>>Wind;
    int cnty=0;
    int cntn=0;
    for(int i=1;i<content.size();i++)
    {
        if(content[i][content[i].size()-1]=="no")
        {

            cntn++;
            outlook[content[i][1]].second+=1;
            Temp[content[i][2]].second+=1;
            Humidity[content[i][3]].second+=1;
            Wind[content[i][4]].second+=1;
        }
        else{
                cnty++;
                 outlook[content[i][1]].first=1;
                Temp[content[i][2]].first+=1;
                Humidity[content[i][3]].first+=1;
                Wind[content[i][4]].first+=1;

        }
    }
    double parent_entropy=calcEntropy(cnty,cntn);
    cout<<parent_entropy<<endl;
    int n=content.size();
    double child_entropy=calcgain(outlook,parent_entropy,n-1);
    cout<<child_entropy<<endl;
      child_entropy=calcgain(Temp,parent_entropy,n-1);
    cout<<child_entropy<<endl;
    child_entropy=calcgain(Humidity,parent_entropy,n-1);
    cout<<child_entropy<<endl;
    child_entropy=calcgain(Wind,parent_entropy,n-1);
    cout<<child_entropy<<endl;
}
