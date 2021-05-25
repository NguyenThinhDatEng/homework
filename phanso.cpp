#include<iostream>
using namespace std;



bool create_2arr(int ***arr,int x,int y){

    *arr = new int*[x];

    if(*arr == NULL) return false;

    for(int i=0;i<x;i++){

        (*arr)[i]= new int[y];

        if((*arr)[i]==NULL) return false;

    }

    return true;

}

bool create_3arr(int ****arr,int x,int y,int z){

    *arr = new int**[x];

    if(*arr==NULL) return false;

    for(int i=0;i<x;i++){

        if(create_2arr( &((*arr)[i]),y,z)==0){

            return false;

        }

    }

    return true;

}

bool create_4arr(int *****arr,int x,int y,int z,int t){

    *arr = new int***[x];

    if(*arr==NULL) return false;

    for(int i=0;i<x;i++){

        if(create_3arr( &((*arr)[i]),y,z,t) == 0) return false;

    }

    return true;

}



void inp_2arr(int **arr,int x,int y){

    for(int i=0;i<x;i++)

        for(int j=0;j<y;j++)

            cin>>arr[i][j];

}

void inp_3arr(int ***arr,int x,int y,int z){

    for(int i=0;i<x;i++)

        inp_2arr(arr[i],y,z);

}

void inp_4arr(int ****arr,int x,int y,int z,int t){

    for(int i=0;i<x;i++)

        inp_3arr(arr[i],y,z,t);

}

int main(){

    int ***arr3D=NULL, ****arr4D=NULL;

    int x=2,y=2,z=2,t=2;

    if(create_3arr(&arr3D,x,y,z)==0) cout<<"khong du bo nho de cap phat"<<endl;

    else cout<<"Cap phat thanh cong"<<endl;

    if(create_4arr(&arr4D,x,y,z,t)==0) cout<<"khong du bo nho de cap phat"<<endl;

    else cout<<"Cap phat thanh cong"<<endl;



    cout<<"Nhap du lieu"<<endl;

    inp_3arr(arr3D,x,y,z);

    inp_4arr(arr4D,x,y,z,t);

    return 0;

}
