#include <iostream>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Graph{
    public:
    list<int> *adj;
    int V;
    
    Graph(int V){
        this->V=V;
        adj = new list<int>[V];
    }

    void add(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

	void remove(int a,int b){
	list<int>::iterator i
        = find(adj[a].begin(), adj[a].end(), b);
    *i = -1;
    list<int>::iterator j
        = find(adj[b].begin(), adj[b].end(), a);
    *j = -1;
    
    
    
	}

	
	bool isdone(){
			list<int>::iterator ii;
			for(int i=0;i<V;i++){
				for(ii=adj[i].begin();ii!=adj[i].end();ii++){
					if(*ii!=-1){
						return false;
					}
				}
			}
			return true;
	}
	
	bool isthere(int find,int inse,vector<int> v){
		list<int>::iterator i;
        vector<int>::iterator j;
        for(i=adj[inse].begin();i!=adj[inse].end();i++){
        	if(find==*i){
        		return true;
			}
			int h=*i;
			j=std::find(v.begin(),v.end()+1,h);
				if(j-v.begin()>v.size()){
				continue;
		}
			v.push_back(h);
			isthere(find,h,v);
		}
		return false;
	}
	
	
    bool valid(int a,int b){
    	int a1=a;
    	int b1=b;
    	bool fin;
        list<int>::iterator i;
        vector<int> v;
        	v.push_back(a);
        	for(i=adj[a].begin();i!=adj[a].end();i++){
			if(*i==-1||*i==b1){
				continue;
			}
			int h=*i;
			fin=isthere(h,b,v);
			if(fin==true){
				break;
			}
		
	}
			return fin;
    }
    
 
    
    void eulerp(int a){
    	if(isdone()){
    		return;
		}
		list<int>::iterator i;
		list<int>::iterator j;
			int b;int b1;
		int oo;	int co=0;
			for(j=adj[a].begin();j!=adj[a].end();j++){
			if(*j==-1){
				continue;
			}
			if(*j!=-1){
				oo=*j;
			}
		 co++;	
		}
		
		
		if(co==1){
			b=oo;
			remove(a,b);
			cout<<a<<"to"<<b<<"  ";
			return eulerp(b);
		}
		else if(co==2){
			b=oo;
			remove(a,b);
			cout<<a<<"to"<<b<<"  ";
			return eulerp(b);
		}
		else{
		for(i=adj[a].begin();i!=adj[a].end();i++){
			if(*i==-1){
				continue;
			}
			
			 b=*i;
			 b1=*i;
			bool check=valid(a,b);
			if(check){
				cout<<a<<"to"<<b<<"  ";
				remove(a,b);
				break;
			}
		}
		return eulerp(b1);
    }}

    void eulerc(int a){
if(isdone()){
    		return;
		}
		list<int>::iterator i;
		list<int>::iterator j;
			int b;int b1;
		int oo;	int co=0;
			for(j=adj[a].begin();j!=adj[a].end();j++){
			if(*j==-1){
				continue;
			}
			if(*j!=-1){
				oo=*j;
			}
		 co++;	
		}
		
		
		if(co==1){
			b=oo;
			remove(a,b);
			cout<<a<<"to"<<b<<"  ";
			return eulerp(b);
		}
		
		else{
		if(adj[a].size()==1){
			cout<<a<<"to"<<b<<"  ";
		}
		for(i=adj[a].begin();i!=adj[a].end();i++){
			if(*i==-1){
				continue;
			}
			
			 b=*i;
			 b1=*i;
			bool check=valid(a,b);
			if(check){
				cout<<a<<"to"<<b<<"  ";
				remove(a,b);
				break;
			}
		}
		return eulerc(b1);
    }
    }
};



int main(){
//    Graph graph(5);
//    int sc=5;
//    graph.add(0,1);
//    graph.add(0, 4);
//    graph.add(1,2);
//    graph.add(2,3);
//    graph.add(3,4);
  Graph graph(6);
    int sc=6;
    graph.add(0,1);
    graph.add(0,4);
    graph.add(0,5);
    graph.add(1,2);
    graph.add(1,3);
    graph.add(2,3);
    graph.add(4,5);
//      Graph graph(6);
//    int sc=6;
//graph.add(0,1);
//graph.add(1,2);
//graph.add(1,5);
//graph.add(2,3);
//graph.add(3,4);
//graph.add(4,5);
//graph.add(0,1);
//graph.add(0,4);
//graph.add(1,2);
//graph.add(2,3);
//graph.add(3,4);
//  Graph graph(3);
//    int sc=3;
// graph.add(0, 1);
//    graph.add(1, 2);
//    graph.add(2, 0);
    int c=0;
    for(int i=0;i<sc;i++){
    	if(graph.adj[i].size()%2!=0){
    		c++;
		}
	}
	if(c>2){
		cout<<"No Euler Path or Circuit Possible"<<endl;
		exit(0);
	}
	cout<<"Enter 2 for euler circuit and 1 for euler path"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
    	c=0;
    	    for(int i=0;i<sc;i++){
    	if(graph.adj[i].size()%2!=0){
    		c=i;
		}}
    graph.eulerp(c);}
    else if(choice==2){
	if(c>0){
		cout<<"No euler circuit possible"<<endl;
		exit(0);
	}
	else
    graph.eulerc(0);}


}


