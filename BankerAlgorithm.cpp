#include <bits/stdc++.h>

using namespace std;

void calc_need(int n,int m,vector<vector<int>> &maxi,vector<vector<int>> &alloc,vector<vector<int>> &need){
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            temp.push_back(maxi[i][j]-alloc[i][j]);
            //cout<<need[i][j]<<" ";

        }
        need.push_back(temp);
        //cout<<endl;
    }
}

void print_need(int n,int m,vector<vector<int>> &need){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
}

void cin_matrix_two(int n,int m,vector<vector<int>> &vec){
    int val;
    for(int i=0;i<n;i++){
        vector <int> temp;
        for(int j=0;j<m;j++){

            cin>>val;
            temp.push_back(val);
        }
        vec.push_back(temp);
    }
}
void cin_matrix_one(int m,vector<int> &vec){
    int val;
    for(int j=0;j<m;j++){

        cin>>val;
        vec.push_back(val);
    }
}

void assign_vec_into_vec_two(vector<vector<int>> &vec1,vector<vector<int>> &vec2){
    for(int i=0;i<vec1.size();i++){
        vec2.push_back(vec1.at(i));
    }
}

void assign_vec_into_vec_one(vector<int> &vec1,vector<int>&vec2){
    for(int i=0;i<vec1.size();i++){
        vec2.push_back(vec1[i]);
    }
}

bool req_greater_than_need(int p,int m,vector<int> &request,vector<vector<int>> &need){
//request[i]>need[p][i]

    if(request>need.at(p)){
        return true;
    }

    return false;
}

bool req_greater_than_available(int p,int m,vector<int> &request,vector<int> &available){
    for(int i=0;i<m;i++){
        if(request[i]>available[i]){
            return true;
        }
    }
    return false;
}



bool check_safety(int n,int m,vector<int> &available,vector<vector<int>> &need,vector<vector<int>> &alloc){
//safety algorithm
//work=available

    vector<int> work;
    vector<bool> finish;
    vector<int> pind;  //n*1
    int count;
    int flag=1;
    int num=0;

    int fold=1,fcount=-1; //no. of false in finish array

    for(int j=0;j<m;j++){
        work.push_back(available[j]);
    }

//finish=false

    for(int j=0;j<n;j++){
        finish.push_back(false);
    }

//find i such that finish=false and need<=work
    while(fold!=fcount&&fcount!=0){
        flag=1;
        for(int i=0;i<n;i++){
            int j;
            count=0;
            for( j=0;j<m;j++){
                if(need[i][j]<=work[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count==m &&finish[i]==false){

                //work=work+allocation
                for(int u=0;u<m;u++){
                    work[u]+=alloc[i][u];
                }
                finish[i]=true;
                pind.push_back(i);

            }

        }

        //if all finish = true then the system is in safe state
        fold=fcount;
        fcount=0;
        for(int a=0;a<n;a++){

            if(finish[a]==false){
                flag=0;
                fcount++;
            }
        }


    }



//print if the system is in safe state or not
    if(flag){
        cout<<"System is in safe state and the sequence of processes are :"<<"<";
        for(int i=0;i<n;i++){
            cout<<"P"<<pind[i]<<" ";
        }
        cout<<">"<<endl;
        return true;
    }
    else{
        cout<<"System is not in safe state"<<endl;
        return false;
    }
}


void resource_request(int n,int m,int p,vector<int> &request,vector<vector<int>> &need,vector<int> &available,vector<vector<int>> &alloc){
    //Resource-request Algorithm for a process

//request<=need
    int reqflag=1;

    if(req_greater_than_need(p,m,request,need)){
        reqflag=0;
        cout<<"Error: process has exceeded its maximum claim"<<endl;

    }

    if(reqflag){

        if(req_greater_than_available(p,m,request,available)){
            reqflag=0;
            cout<<"Error: wait since the resources is not available"<<endl;
        }

        if(reqflag){

            vector<vector<int>> tryalloc ;  //n*m
            vector<vector<int>> tryneed ;    //n*m
            vector<int> tryavailable;     //1*m
            vector<int>trypind ;


            assign_vec_into_vec_two(need,tryneed);
            assign_vec_into_vec_one(available,tryavailable);
            assign_vec_into_vec_two(alloc,tryalloc);


            for(int j=0;j<m;j++){
                tryneed[p][j]=need[p][j]-request[j];
                tryavailable[j]=available[j]-request[j];
                tryalloc[p][j]=alloc[p][j]+request[j];
            }



            //check if safe the resources are allocated to pi

            bool check=check_safety(n,m,tryavailable,tryneed,tryalloc);
            if(check){
                cout<<"So,The resource can be allocated to P"<<p<<endl;
                assign_vec_into_vec_two(tryneed,need);
                assign_vec_into_vec_one(tryavailable,available);
                assign_vec_into_vec_two(tryalloc,alloc);
            }
            else{
                cout<<"So,The resource cannot be allocated to P"<<p<<endl;
            }
        }
    }
}


int main()
{
    int n;
    int m;
    int count;
    int flag=1;
    int num=0;
    int ind=0;
    int fold=1,fcount=0; //no. of false in finish array
    cout<<"Please Enter (n) Number of processes"<<endl;
    cin>>n;
    cout<<"Please Enter (m) Number of Resources"<<endl;
    cin>>m;

    vector<vector<int>> alloc;  //n*m
    vector<vector<int>> maxi;    //n*m
    vector<vector<int>> need ;    //n*m
    vector<int> available;     //1*m
    vector<int> work;  //1*m
    vector<bool> finish;
    vector<int> pind;  //n*1
    vector<int> request;   //1*m
    int p;


    //inputs

    cout<<"Please Enter values of allocation matrix"<<endl;
    cin_matrix_two(n,m,alloc);


    cout<<"Please Enter values of max matrix"<<endl;
    cin_matrix_two(n,m,maxi);


    cout<<"Please Enter values of available matrix"<<endl;
    cin_matrix_one(m,available);



//Outputs
//need matrix

    cout<<"The value of need matrix is : "<<endl;
    calc_need(n,m,maxi,alloc,need);
    print_need(n,m,need);





    while(true){
        cout<<"Choose safestate or immediaterequest ? otherwise enter exit"<<endl;
        string check;
        cin>>check;
        string checklow="";
        //check value in lower case
        for(int k=0;k<check.length();k++){
            checklow+=tolower(check[k]);
        }

        if(checklow=="exit"){
            break;
        }

        if(checklow=="safestate"){
            //safe algorithm
            check_safety(n,m,available,need,alloc);
        }

        //enter immediate request to check request by one of the processes if it can be granted
        if(checklow=="immediaterequest"){
            cout<<"please enter the process :"<<endl;
            cin>>p;
            cout<<"please enter the request :"<<endl;
            cin_matrix_one(m,request);


            // Grant request vector to check if it is safe or not
            //Resource-request Algorithm for a process
            resource_request(n,m,p,request,need,available,alloc);
        }

    }




}


