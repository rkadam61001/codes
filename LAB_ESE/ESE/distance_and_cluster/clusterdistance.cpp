#include<bits/stdc++.h>
using namespace std;
vector<vector<double>> getdistmatrix(vector<double>&x,vector<double>&y)
{
    vector<vector<double>>res;
    int m=x.size();
    for(int i=0;i<m;i++)
    {
        vector<double>row;
        for(int j=0;j<m;j++)
        {
            double sq=((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]));
            sq=sqrt(sq);
            row.push_back(sq);
        }
        res.push_back(row);
    }
    return res;
}
int main()
{
    fstream fin("inputcluster.csv",ios::in);
    vector<vector<string>>content;
    vector<string>row;
    string line;
    string word;
    if(fin.is_open())
    {
        while(getline(fin,line))
        {
            row.clear();
            stringstream s(line);
            while(getline(s,word,','))
            {
                row.push_back(word);
            }
            content.push_back(row);
        }
    }
    vector<double>x;
    vector<double>y;
    int n=content.size();
    for(int i=1;i<n;i++)
    {
        x.push_back(stod(content[i][0]));
        y.push_back(stod(content[i][1]));
    }
    double meanx;
    double meany;
    double totx=0;
    double toty=0;
    for(int i=0;i<x.size();i++)
    {
        totx+=x[i];
    }
    for(int i=0;i<y.size();i++)
    {
        toty+=y[i];
    }
    int sz=x.size();
    meanx=totx/sz;
    meany=toty/sz;
    x.push_back(meanx);
    y.push_back(meany);

    vector<vector<double>>distmatrix=getdistmatrix(x,y);
    ofstream fw("outputcluster.csv",ios::out);
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            cout<<distmatrix[i][j]<<"           ";
            fw<<distmatrix[i][j]<<",";
        }
        cout<<endl;
        fw<<endl;
    }
}
