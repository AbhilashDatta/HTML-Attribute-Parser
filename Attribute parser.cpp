#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print_nest(map<string, vector<string>> nest){
    map<string, vector<string>>::iterator itr;
    for(itr = nest.begin();itr!=nest.end();itr++){
        cout<<"Tag: "<<itr->first<<" is under ";
        for(auto i:itr->second) cout<<i<<" ";
        cout<<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    cin>>n>>q;
    string line[n];
    getchar();
    map<string,int> tag_status;
    for(int i=0;i<n;i++){
        getline(cin,line[i]);
    }
    map<string , vector<map<string, string>>> attr;

    //for(int i=0;i<n;i++) cout<<line[i]<<endl;
    map<string, vector<string>> nest;
    for(int i=0;i<n;i++){
        if(line[i][1]=='/'){
            int j = 2;
            string tag = "";
            while(line[i][j]!='>'){
                tag += line[i][j];
                j++;
            }
            tag_status[tag] = 0;
            //cout<<"tag "<<tag<<" is switched off\n";
            map<string,int>::iterator itr;
            for(itr = tag_status.begin();itr!=tag_status.end();itr++){
                if(itr->second==1){
                    //cout<<itr->first<<" ";
                    nest[tag].push_back(itr->first);
                }
            }
            //cout<<endl;
            continue;
        }
        
        int j = 1;
        string tag = "";
        while(line[i][j]!=' ' && line[i][j]!='>'){
            tag += line[i][j];
            j++;
        }
        //cout<<tag<<endl;
        tag_status[tag] = 1;
        if(line[i][j]=='>'){
            map<string,string> m;
            attr[tag].push_back(m);
            continue;
        }
        j++;
        while(j<line[i].size()){
            string attr_name = "";
            for(;line[i][j]!=' ';j++){
                attr_name += line[i][j]; 
            }
            //cout<<x<<endl;
            j = j + 4;
            string attr_val = "";
            for(;line[i][j]!='"';j++){
                attr_val +=line[i][j];
            }
            //cout<<y<<endl;
            map<string,string> m;
            m[attr_name] = attr_val;
            attr[tag].push_back(m);
            if(line[i][j+1]=='>') break;
            else j = j+2;
        }
    }
    //print_nest(nest);

    //Query Handling

    string query[q];
    
    for(int i=0;i<q;i++){
        cin>>query[i];
        vector<string> path;
        int j = 0;
        string s = "";
        for(;j<query[i].size();j++){
            if(query[i][j]=='.'){
                path.push_back(s);
                //cout<<s<<endl;
                s = "";
                continue;
            }
            if(query[i][j]=='~'){
                path.push_back(s);
                //cout<<s<<endl;
                break;
            }
            s += query[i][j];
        }
        //cout<<s<<endl;
        j++; 
        string x = "";
        for(;query[i][j]!='\0';j++){
            x+= query[i][j];
        }
        //cout<<x<<endl;
        
        string final_tag = path[path.size()-1];
        path.pop_back();
        //cout<<final_tag<<endl;
        int flag = 0;
        //for(auto i:nest[final_tag]) cout<<i<<" ";
        //cout<<endl;
        vector<string> nested_path = nest[final_tag];
        if(nested_path!=path){
            cout<<"Not Found!\n";
            continue;
        }

        vector<map<string,string>> vec = attr[final_tag];
        for(int k=0;k<vec.size();k++){
            map<string,string > ::iterator itr;
            itr = vec[k].begin(); 
            if(itr->first==x){
                cout<<itr->second<<endl;
                break;
            }
            if(k==vec.size()-1){
                cout<<"Not Found!\n";
                break;
            }
        }      
    }
    return 0;
}
