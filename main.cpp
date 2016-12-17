#include <iostream>
#include <vector>
#include <algorithm>

#define SUCCESS 0
#define FAILURE 1
#define ERROR -1
using namespace std;


class Interval{
    public:
	int begin;
	int end;
};


int get_intervals(vector<Interval>& iv);
int print_intervals(vector<Interval>& iv);
int print_visual_intervals(vector<Interval>& iv);
int sort_intervals(vector<Interval>& iv);
int merge_intervals(vector<Interval>& iv);
bool sort_helper(Interval i, Interval j);


int main(){
     vector<Interval> iv;  
     int q = SUCCESS;  
     while(q == SUCCESS){
        q = get_intervals(iv);
     }	
     merge_intervals(iv);
     print_intervals(iv);
}

int get_intervals(vector<Interval>& iv){
	cout << "Please Enter an interval." << endl;
	int first,last;
	cout << "Beginning point: ";
	cin >> first;
	cout << "End point: ";
	cin >> last;
	if(cin.fail() || first > last){
	   cout << "Invalid interval " << endl;
	   return ERROR;
	}
	Interval k;
	k.begin = first;
	k.end = last;
	iv.push_back(k);
        return SUCCESS;
}

int print_intervals(vector<Interval>& iv){
	for(int i = 0; i < iv.size(); i++){
	   cout << "[" << iv[i].begin << "," << iv[i].end << "]" << endl;
	}
	return SUCCESS;

}

int print_visual_intervals(vector<Interval>& iv){
	return SUCCESS;
}

int merge_intervals(vector<Interval>& iv){
	if(iv.size()==1) return SUCCESS;
	sort_intervals(iv);
	for(int i=1; i<iv.size();){
	     if(iv[i].begin >= iv[i-1].begin && iv[i].begin <= iv[i-1].end){
		  if(iv[i-1].end < iv[i].end){
		       iv[i-1].end = iv[i].end;
		  }
		iv.erase(iv.begin()+i);
	     }else{
		  i++;
	     }
	}
	return SUCCESS;
}

bool sort_helper(Interval i, Interval j){
	return i.begin < j.begin;
}

int sort_intervals(vector<Interval>& iv){
	sort(iv.begin(),iv.end(),sort_helper);
	return SUCCESS;
}
