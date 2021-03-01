#include<iostream>
#include<conio.h>
#include<dos.h> 
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void drawBorder(int x=0, int y=0){
	char v = 186; // vertical
    char h = 205; // horizontal
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 30;
    int height = 3;
     
    for( int i=1; i<=height; i++ ){
		for( int j=1; j<=width; j++ ){
	    	gotoxy(j+x,i+y);
	    	if( i==1 && j==1 ) cout<< tl;
			else if( i==height && j==1 ) cout<< bl;
	    	else if( i==1 && j==width ) cout<< tr;
			else if( i==height && j==width ) cout<< br;
			else if( i==1 || i==height ) cout<< h;
			else if( j==1 || j==width ) cout<< v;
		}
	}
}

void enc(char* temp, int length){
	for( int i=0; i<length/2; i++ ){
		 temp[i]++;
		 temp[length-1-i]++;
		 char stemp = temp[i];
		 temp[i] = temp[length-1-i];
		 temp[length-1-i] = stemp;
	}
}

void dec(char* temp, int length){
	for( int i=0; i<length/2; i++ ){
		 temp[i]--;
		 temp[length-1-i]--;
		 char stemp = temp[i];
		 temp[i] = temp[length-1-i];
		 temp[length-1-i] = stemp;
	}
}

void EncDec(char* type) {
    
 	char text[21]; 
	system("cls");
	
	cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
	cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t  ±±±±± "<<endl;
	cout<<"\t\t\t\t\t  ±   ± "<<endl;
	cout<<"\t\t\t\t\t±±±±±±±±±"<<endl;
	cout<<"\t\t\t\t\t±±±± ±±±±"<<endl;
	cout<<"\t\t\t\t\t±±±±±±±±±"<<endl; 
	
	cout<<endl;
	cout<<"\t\t\t\tENCRYPTION / DECRYPTION          "<<endl;
	cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±";
	cout<<"±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±"<<endl<<endl; 
	
	cout<<endl<<"\tEnter Text to "<<type<<": ";
	cin>> text;
	
	int length = strlen(text);
	
	gotoxy(8,14); 
	cout<<type<<"ing Text...";
	gotoxy(8,15); 
	for(int i=0; i<15; i++){
		cout<<(char)176;
		Sleep(100);
	}
	
	if( strcmp(type,"Encrypt")==0 ){
		enc(text, length);
	}else{
		dec(text, length);
	}
	
	drawBorder(7,17);
	
	gotoxy(10,19); 
	cout<<type<<"ed Text: "<< text;
	
	gotoxy(9,23); cout<<"Press any key to go back to Menu... ";
	getch(); 
 
}

int main()
{
	srand((unsigned) time(NULL));
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" ------------------------------------ "; 
		gotoxy(10,6); cout<<" |     ENCRYPTION / DECRYPTION      | "; 
		gotoxy(10,7); cout<<" ------------------------------------";
		gotoxy(10,9); cout<<"1. Encryption";
		gotoxy(10,10); cout<<"2. Decryption";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') EncDec("Encrypt");
		else if( op=='2') EncDec("Decrypt");
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}
