#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
void mot() {
	cout<<"-----------\n";
	cout<<"|         |\n";
	cout<<"|    o    |\n";
	cout<<"|         |\n";
	cout<<"-----------\n";
}
void hai() {
	cout<<"-----------\n";
	cout<<"|         |\n";
	cout<<"|  o  o   |\n";
	cout<<"|         |\n";
	cout<<"-----------\n";
}
void ba() {
	cout<<"-----------\n";
	cout<<"|         |\n";
	cout<<"|   o  o  |\n";
	cout<<"|    o    |\n";
	cout<<"-----------\n";
}
void bon() {
	cout<<"-----------\n";
	cout<<"|  o    o |\n";
	cout<<"|         |\n";
	cout<<"|  o    o |\n";
	cout<<"-----------\n";
}
void nam() {
	cout<<"-----------\n";
	cout<<"|  o    o |\n";
	cout<<"|    o    |\n";
	cout<<"|  o    o |\n";
	cout<<"-----------\n";
}
void sau() {
	cout<<"-----------\n";
	cout<<"|  o    o |\n";
	cout<<"|  o    o |\n";
	cout<<"|  o    o |\n";
	cout<<"-----------\n";
}
int random() {
	srand(time(NULL));
	int a=rand()%6+1;
	return a;
}
void result(int a[],int &ketqua) {
	srand(time(NULL));
	a[0]=rand()%6+1;
	a[1]=rand()%6+1;
	a[2]=rand()%6+1;
	for(int i=0; i<3; i++) {
		if(a[i]==1){
			mot();
			Sleep(1000);	
		}
		if(a[i]==2){
			hai();	
			Sleep(1000);	
		}
		if(a[i]==3){
			ba();
			Sleep(1000);		
		}
		if(a[i]==4){
			bon();
			Sleep(1000);		
		}
		if(a[i]==5){
			nam();
			Sleep(1000);		
		}
		if(a[i]==6){
			sau();
			Sleep(1000);		
		}
		ketqua+=a[i];
	}
}
void cuoc(int &tai,int &xiu) {
	cout<<"Cuoc tai:";
	cin>>tai;
	cout<<"\nCuoc xiu:";
	cin>>xiu;

}
void ketqua(int tai,int xiu,int ketqua,int &tien) {
	if(ketqua>10) {
		int temp=tai-xiu;
		tien=temp*2;
	}
	if(ketqua<=10) {
		int temp=xiu-tai;
		tien=temp*2;
	}
	if(tien==0) {
		cout<<"Hoa";
	}
	if(tien<0) {
		if(ketqua>10) {
			cout<<"Thua "<<xiu-tai*2<<" dong";
		} else {
			cout<<"Thua "<<tai-xiu*2<<" dong";
		}
	}
	if(tien>0) {
		cout<<"Thang "<<tien<<" dong";
	}
}
void menu(int a[],int tai,int xiu,int diem,int tien) {
	while(true) {
		cout<<"-----------------\n";
		cout<<"ENTER: Play\n";
		cout<<"Esc: Exit\n";
		cout<<"-----------------\n";
		while(true) {
			if(GetAsyncKeyState(VK_RETURN)) {
				cuoc(tai,xiu);
				result(a,diem);
				ketqua(tai,xiu,diem,tien);
				cout<<"\n----------------------\n";
				cout<<"\nENTER: Continue\n";
				cout<<"Esc: Exit\n";
				cout<<"----------------------\n";
				system("pause");
				system("cls");
				if(GetAsyncKeyState(VK_ESCAPE)) {
					break;
				}
			}
		}
	}
}
int main() {
	int a[3],diem=0,tien=0;
	int tai,xiu;
	menu(a,tai,xiu,diem,tien);
	return 0;
}