#include <iostream>
#include<conio.h>
#include<iomanip>  
#include<string.h>  
  
using namespace std;

int jsoal,bts,option,u,top;
string siswalain;
char namedos[30],matkul[30];

struct kunci_soal{
	char key, jwb;
	};
	
struct data_mahasiswa{
	char nama[30],kls[30],nim[30];
	float salah ,benar , nilai;
	}mhs[100];
	
float totaln (float nb, float ns, float total);

void welcome();
void welcomedosen();
void homekunci();
void homesiswa();
void homeoutsiswa();
void homeoption();
void homeoutrank();
void homeoutnim();
void search();
void proses();



main(){
	welcome();
	
	home:

	welcomedosen();
	
 	cout<<"\t\tNAMA MATA PERLAJARAN : ";cin>>matkul;
 	cout<<"\t\tJUMLAH SOAL          : ";cin>>jsoal;
 	cout<<"\t\tNAMA GURU            : ";cin>>namedos;
 	
	struct kunci_soal kunci[jsoal];
	bts=1;
	
	for(int k=1 ; k<=bts;){
		homekunci();
		for(int i=1; i<= jsoal ; i++){
			cout<<"\nKUNCI JAWABAN "<<i<<" : ";cin>>kunci[i].key;}
			
awal:
	
			homesiswa();
			cout<<"\n\t\tMasukan Nama Mahasiswa  : ";cin>>mhs[k].nama;
			cout<<"\t\tMasukan NIM Mahasiswa   : ";cin>>mhs[k].nim; 
			cout<<"\t\tDari Kelas              : ";cin>>mhs[k].kls;
			
			system("cls");
			
			cout<<"\n\n\t=============================================================\n";
			cout<<"\tKUNCI JAWABAN "<<"          \t||"<<" JAWABAN DARI "<<mhs[k].nama<<endl;
			cout<<"\t=============================================================";
			
		for(int j=1; j<=jsoal; j++){
			cout<<"\n\tKUNCI JAWABAN "<<j<<" : "<<kunci[j].key;cout<<"\t\t||  Jawaban : ";cin>>kunci[j].jwb;
			
			if(kunci[j].jwb == kunci[j].key){
				cout<<"\t\t\t\t\t\t\t\tBENAR";
				mhs[k].benar+=1;}
				
			if(kunci[j].jwb != kunci[j].key){
				cout<<"\t\t\t\t\t\t\t\tSALAH";
				mhs[k].salah+=1;}
				
				mhs[k].nilai = totaln(mhs[k].benar,mhs[k].salah,mhs[k].nilai);}
			cout<<endl<<endl;
			
				cout<<"\n\t=============================================================\n";
				cout<<"\t||   Apakah akan memasukan Jawaban Siswa Lain ? [ya/no]    ||\n";
				cout<<"\t=============================================================\n";
				cout<<"\t\t\t\t\t";cin>>siswalain;
				
			 	if(siswalain=="ya" || siswalain=="YA" || siswalain=="Ya"){
				 	bts+=1;
				 	if(bts==100){
				 		cout<<"\n\n\t\tMaaf data sudah mencapai 99";
				 		goto output;
					 }
				 	k++;
				 	goto awal;}
				 	
				else{goto output;}
			 }
			 
			 
output:
	
		homeoutsiswa();  
		
		for(int r=1; r<=bts; r++){ 
		cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;
		cout<<"|"<<setiosflags(ios::right)<<setw(3)<<r;
		cout<<setiosflags(ios::right)<<setw(18)<<mhs[r].nama;
		cout<<setiosflags(ios::left)<<setw(15)<<mhs[r].nim;
		cout<<setiosflags(ios::left)<<setw(13)<<mhs[r].kls;
		cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].benar;
		cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].salah;
		cout<<setiosflags(ios::left)<<setw(10)<<mhs[r].nilai<<"  |"<<endl;
		cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;
	}
	
	cout<<"===============================================================================";
	homeoption();
	
	cout<<"\t\t\t\t\t\t";cin>>option;
	
	switch(option){
		case 1: {system("cls"); goto sortrank;
			break;}
			
		case 2: {
				system("cls"); goto sortnim;
			break;}
			
		case 3: {
				system("cls"); goto home;
			break;}
			
		case 4: {
				system("cls"); goto search;
			break;}
			
		default: system("cls"); goto out; }
		
		
		
sortrank:
		
	homeoutrank();
	homeoption();
	
	 cout<<"\t\t\t\t\t\t";cin>>option;
	 
	switch(option){
		case 1: {system("cls"); goto sortrank;
			break;}
			
		case 2: {
				system("cls"); goto sortnim;
			break;}
			
		case 3: {
				system("cls"); goto home;
			break;}
			
		case 4: {
				system("cls"); goto search;
			break;}
			
		default: system("cls"); goto out; }
		
	getch();
	
	
sortnim:
	
	homeoutnim();
	homeoption();
	
	cout<<"\t\t\t\t\t\t";cin>>option;
	
	switch(option){
		case 1: {system("cls"); goto sortrank;
			break;}
			
		case 2: {
				system("cls"); goto sortnim;
			break;}
			
		case 3: {
				system("cls"); goto home;
			break;}
			
		case 4: {
				system("cls"); goto search;
			break;}
			
		default: system("cls"); goto out; }
		
	getch();
	
	
search:
	search();
	proses();
	homeoutnim();
	homeoption();
	
	cout<<"\t\t\t\t\t\t";cin>>option;
	switch(option){
		case 1: {system("cls"); goto sortrank;
			break;}
			
		case 2: {
				system("cls"); goto sortnim;
			break;}
			
		case 3: {
				system("cls"); goto home;
			break;}
			
		case 4: {
				system("cls"); goto search;
			break;}
			
		default: system("cls"); goto out; }
	getch();
out:;

}



float totaln (float nb, float ns, float total){
	float x;
	x=(nb*10)/(nb+ns)*10;
	return x;}
	
void welcome(){
	for(int y=1; y<=100; y++){
		if(y%5==1){
			system("cls");
			system("color a");
		}
		
		else if(y%5==2){
			system("cls");
			system("color b");
		}
		
		else if(y%5==3){
			system("cls");
			system("color c");
		}
		
		else if(y%5==4){
			system("cls");
			system("color d");
		}
		
		else if(y%5==0){
			system("cls");
		}
		
	cout<<"\n\n\n\n\n";
	cout<<"\t\t=================================================\n";
	cout<<"\t\t||               SELAMAT DATANG                ||\n";
	cout<<"\t\t||                     DI                      ||\n";
	cout<<"\t\t||      MULTICHOICE CORRECTION SYSTEM          ||\n";
	cout<<"\t\t=================================================";
	
	if(y==100){system("cls"); system("color a");}
	}	
};

void welcomedosen(){system("cls");
	cout<<"\n"<<"*untuk penggunaan space mengunakan ( _ )\n";
	cout<<" agar data dapat ditampilkan utuh\n\n\n";
	cout<<"\t\t===================================================\n";
	cout<<"\t\t||                SELAMAT DATANG                 ||\n";
	cout<<"\t\t||               Bpk/Ibu PENGAJAR                ||\n";
	cout<<"\t\t===================================================\n";
};

void homekunci(){
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\t\t=================================================\n";
	cout<<"\t\t||               SILAHKAN INPUT                ||\n";
	cout<<"\t\t||               KUNCI JAWABAN                 ||\n";
	cout<<"\t\t=================================================\n";
};

void homesiswa(){system("cls");
	cout<<"\n"<<"*untuk penggunaan space mengunakan (_)\n";
	cout<<" agar data dapat ditampilkan utuh\n\n\n";
	cout<<"\t\t===================================================\n";
	cout<<"\t\t||               SILAHKAN INPUT                  ||\n";
	cout<<"\t\t||               DATA MAHASISWA                  ||\n";
	cout<<"\t\t===================================================";
};

void homeoutsiswa(){system("cls");
	cout<<"\n\n\n";
	cout<<"===============================================================================\n";
	cout<<"|                                    NILAI HASIL                              |\n";
	cout<<"|	                              MAHASISWA                               |\n";
	cout<<"===============================================================================\n";
	cout<<"| NO |       NAMA       |     NIM     |    KELAS    | BENAR | SALAH |  NILAI  |\n";
	cout<<"|    |   ------------   |  ---------  |   -------   | ----- | ----- |  AKHIR  |\n";
	cout<<"===============================================================================\n";
};

void homeoption(){
				cout<<"\n\n\t\t ==============================================\n";
				cout<<"\t\t<       1.    URUTKAN BERDASARKAN RANKING      >\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t<       2.    URUTKAN BERDASARKAN NAMA         >\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t<       3.    KEMBALI KE AWAL PROGRAM          >\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t<       4.    PENCARIAN DATA MAHASISWA         >\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t ==============================================\n";
				cout<<"\t\t<       5.    UNTUK MENUTUP PROGRAM            >\n";
				cout<<"\t\t ==============================================\n";
};

void homeoutrank(){
	int u;
	u=bts;
	
	system("cls");

	//PROSES PENGURUTAN:

for(int j=1;j<=bts+1;j ++){
 	for(int k=1;k<u;k++){
 		if (mhs[k].nilai < mhs[k+1].nilai){
		mhs[100]=mhs[k];
		mhs[k]=mhs[k+1];
		mhs[k+1]=mhs[100];}
	}}
	
	//HEADER
	
	cout<<"\n\n\n";
	cout<<"===============================================================================\n";
	cout<<"|                                 SORTING HASIL                               |\n";
	cout<<"|	                 MAHASISWA BERDASARKAN RANGKING                       |\n";
	cout<<"===============================================================================\n";
	cout<<"| NO |       NAMA       |     NIM     |    KELAS    | BENAR | SALAH |  NILAI  |\n";
	cout<<"|    |   ------------   |  ---------  |   -------   | ----- | ----- |  AKHIR  |\n";
	cout<<"===============================================================================\n";
	
	//OUTPUT:
	
	for(int r=1; r<=bts; r++){ 
		cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;
		cout<<"|"<<setiosflags(ios::right)<<setw(3)<<r;
		cout<<setiosflags(ios::right)<<setw(18)<<mhs[r].nama;
		cout<<setiosflags(ios::left)<<setw(15)<<mhs[r].nim;
		cout<<setiosflags(ios::left)<<setw(13)<<mhs[r].kls;
		cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].benar;
		cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].salah;
		cout<<setiosflags(ios::left)<<setw(10)<<mhs[r].nilai<<"  |"<<endl;
		cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;}
		cout<<"===============================================================================";
	cin.get();
};

void homeoutnim(){
	int u;
	u=bts;
	system("cls");

	//PROSES PENGURUTAN:

for(int j=1;j<=bts;j++){
 	for(int k=1;k<u;k++){
 		if (mhs[k].nama[0] > mhs[k+1].nama[0]){ 
		mhs[100]=mhs[k];
		mhs[k]=mhs[k+1];
		mhs[k+1]=mhs[100];}
	}
}
	
	cout<<"\n\n\n";
	cout<<"===============================================================================\n";
	cout<<"|                                 SORTING HASIL                               |\n";
	cout<<"|	                   MAHASISWA BERDASARKAN NAMA                         |\n";
	cout<<"===============================================================================\n";
	cout<<"| NO |       NAMA       |     NIM     |    KELAS    | BENAR | SALAH |  NILAI  |\n";
	cout<<"|    |   ------------   |  ---------  |   -------   | ----- | ----- |  AKHIR  |\n";
	cout<<"===============================================================================\n";
	
	//OUTPUT:
	
	for(int r=1; r<=bts; r++){ 
		cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;
		cout<<"|"<<setiosflags(ios::right)<<setw(3)<<r;
		cout<<setiosflags(ios::right)<<setw(18)<<mhs[r].nama;
		cout<<setiosflags(ios::left)<<setw(15)<<mhs[r].nim;
		cout<<setiosflags(ios::left)<<setw(13)<<mhs[r].kls;
		cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].benar;
		cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].salah;
		cout<<setiosflags(ios::left)<<setw(10)<<mhs[r].nilai<<"  |"<<endl;
		cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;}
		cout<<"===============================================================================";
		
	cin.get();
};

void search(){
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\t\t=================================================\n";
	cout<<"\t\t||                 PENCARIAN                   ||\n";
	cout<<"\t\t||               DATA MAHASISWA                ||\n";
	cout<<"\t\t=================================================\n";
};

void proses(){
	
	string nimsrc;
	string option;
	;
	
awal:
			cout<<endl;
			cout<<"\t\t|| Masukan Nim Mahasiswa yang dicari : \n";
			cout<<"\t\t|| ";
			cin>>nimsrc;
			string nima;
			for(int r=1; r<=bts; r++ ){
				string nima=mhs[r].nim;
				if(nima==nimsrc){
					cout<<endl<<endl<<"Data Ada : \n\n";
					cout<<"\n";
					cout<<"===============================================================================\n";
					cout<<"|                                  PENCARIAN                                  |\n";
					cout<<"|	                         DATA MAHASISWA                               |\n";
					cout<<"===============================================================================\n";
					cout<<"| NO |       NAMA       |     NIM     |    KELAS    | BENAR | SALAH |  NILAI  |\n";
					cout<<"|    |   ------------   |  ---------  |   -------   | ----- | ----- |  AKHIR  |\n";
					cout<<"===============================================================================\n";
					cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;
					cout<<"|"<<setiosflags(ios::right)<<setw(3)<<r;
					cout<<setiosflags(ios::right)<<setw(18)<<mhs[r].nama;
					cout<<setiosflags(ios::left)<<setw(15)<<mhs[r].nim;
					cout<<setiosflags(ios::left)<<setw(13)<<mhs[r].kls;
					cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].benar;
					cout<<setiosflags(ios::left)<<setw(8)<<mhs[r].salah;
					cout<<setiosflags(ios::left)<<setw(10)<<mhs[r].nilai<<"  |"<<endl;
					cout<<"|\t\t\t\t\t\t\t\t\t      |"<<endl;
					cout<<"===============================================================================";
					break;
				}}
				cout<<"\n\nApakah ingin mencoba lagi ? [ya/no] :";cin>>option;
					if(option=="ya"|| option=="Ya" || option=="YA"){
						system("cls");
						search();
						goto awal;}
				}
