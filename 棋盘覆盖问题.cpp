#include<iostream>
#include<bits/stdc++.h> //调用万能头文件 
using namespace std;
int n,r,l,t=0;
long long board[105][105]; //定义棋盘的最大大小 
void ChessBoard(int tr,int tc,int dr,int dc,int size){
	int s,t1;   //t1表示本次覆盖所使用的骨牌型号 
	if(size==1) return;  //棋盘只有一个方格且为特殊方格 
	t1=++t;
	s=size/2;   //划分棋盘 
	if(dr<tr+s&&dc<tc+s)  //特殊方格在左上角子棋盘中 
	ChessBoard(tr,tc,dr,dc,s); //递归处理子棋盘 
	else{
		board[tr+s-1][tc+s-1]=t1; //用t1号骨牌覆盖右下角，再递归处理子棋盘 
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	if(dr<tr+s&&dc>=tc+s)  //特殊方格在右上角子棋盘中 
	ChessBoard(tr,tc+s,dr,dc,s);  //递归处理子棋盘
	else{
		board[tr+s-1][tc+s]=t1;//用t1号骨牌覆盖左下角，再递归处理子棋盘 
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
		if(dr>=tr+s&&dc<tc+s)  //特殊方格在左下角子棋盘中 
	ChessBoard(tr+s,tc,dr,dc,s); //递归处理子棋盘
	else{
		board[tr+s][tc+s-1]=t1;
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);//用t1号骨牌覆盖右上角，再递归处理子棋盘 
	}
		if(dr>=tr+s&&dc>=tc+s)  //特殊方格在右下角子棋盘中 
	ChessBoard(tr+s,tc+s,dr,dc,s); //递归处理子棋盘
	else{
		board[tr+s][tc+s]=t1;
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);//用t1号骨牌覆盖左上角，再递归处理子棋盘 
	}
}
int main(){
	cin>>n>>r>>l;
	ChessBoard(0,0,r,l,n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
		cout<<left<<setw(5)<<board[i][j];
		if(i<n-1)
		cout<<endl;
	}
	return 0;
}