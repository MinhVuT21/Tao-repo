#include<iostream>
#include<iomanip>     //chinh do rong setw()
#include<vector>
#include<conio.h>		//thu vien de su dung getch(); 
#include<fstream>
#include<windows.h>
#include<stdlib.h>
//#include <bits/stdc++.h> //thu vien goi tat ca cac thu vien chuan 
using namespace std;

class ConNguoi {								//class connguoi
	private:
		string HoVaTen,GioiTinh;
	public:
		virtual void Nhap();
		virtual void Xuat();
		string getTen(){
			return HoVaTen;
		}
		string getGioiTinh(){
			return GioiTinh;
		}
};

void ConNguoi::Nhap(){
	cout << "Nhap Ho va ten: ";
	fflush(stdin);
	getline(cin, HoVaTen);
	cout << "Nhap Gioi Tinh: ";
	cin >> GioiTinh;
}

void ConNguoi::Xuat(){
	cout<<HoVaTen;
	cout<<setw(20);
	cout<<GioiTinh;
	cout<<setw(17);
}

class Diem {								//class diem
	private:
		float Toan,Van,Anh,dtb;
	public:
		float getDtb(){
			return dtb;
		};
		float Diemtb();
		void NhapD();
		void XuatD();
		string XepLoai();
		float getToan(){
			return Toan;
		};
		float getVan(){
			return Van;
		};
		float getAnh(){
			return Anh;
		};
		float getdtb(){
			return dtb;
		};
		string getXepLoai();				
};
string Diem::getXepLoai(){
	string ghi;
		if(dtb>=8.0){
        	ghi="Gioi";
        	return ghi;
    	}else if (dtb>=7){
        	ghi="Kha";
        	return ghi;
    	}else if (dtb>=5){
        	ghi="Trung binh";
        	return ghi;
    	}else{ 
        	ghi="Yeu";
        	return ghi;
    	}
}
string Diem::XepLoai(){
	double T = getDtb();
	
	if(T>=8.0)
        cout<<"Gioi";
    else if (T>=7)
        cout<<"Kha";
    else if (T>=5)
        cout<<"Trung binh";
    else   
        cout<<"Yeu";             
}

float Diem::Diemtb(){	
	this->dtb= (Toan+Van+Anh)/3;
}

void Diem::NhapD(){
	cout<<"Diem cua hoc sinh "<<endl;
	cout<<"Nhap diem Toan: ";
	cin>>Toan;
	cout<<"Nhap diem Van: ";
	cin>>Van;
	cout<<"Nhap diem Anh: ";
	cin>>Anh;
}


void Diem::XuatD(){
	cout<<Toan<<setw(10);
	cout<<Van<<setw(10);
	cout<<Anh<<setw(10);
	this->Diemtb();
	cout<<dtb<<setw(13);
	XepLoai();	
}


class SinhVien:public ConNguoi,public Diem {	//class SinhVien ke thua Diem, ke thua va su dung tinh chat da hinh voi ConNguoi
	private:
		string MSSV;
	public:
		void Nhap();
		void Xuat();
		string getMSSV(){
			return MSSV;
		};
};

void SinhVien::Nhap() {	
	ConNguoi::Nhap();
	cout << "Nhap MSSV: ";
	fflush(stdin);
	getline(cin, MSSV);
	Diem::NhapD();
}
void SinhVien::Xuat() {
	ConNguoi::Xuat();
	cout << MSSV;
	cout<<setw(20);
	Diem::XuatD();
}


//---------------------------------//
class QuanLySinhVien{								
	private:
		vector<SinhVien*>SV;
		int STT;
	public:
		void NhapDS();
		void XuatDS();
		void hienThiTenCot();
		void SapXepD();
		void XoaSV();
		void XoaDS();
		void TimKiemTen();
		void ghiFile();
		void docFile(); 
};
void QuanLySinhVien::ghiFile(){
	ofstream luufile;
	luufile.open("C:\\Users\\nguye\\OneDrive\\Desktop\\ghifilebtl.txt",ios::out);
	for(int i=0; i<SV.size(); i++){
		luufile << SV.at(i)->getTen()<<"\t";
		luufile << SV.at(i)->getGioiTinh()<<"\t";
		luufile << SV.at(i)->getMSSV()<<"\t";	
		luufile << SV.at(i)->getToan()<<"\t";
		luufile << SV.at(i)->getVan()<<"\t";
		luufile << SV.at(i)->getAnh()<<"\t";
		luufile << SV.at(i)->getdtb()<<"\t";
		luufile << SV.at(i)->getXepLoai();
		luufile << endl;
	}
	cout<<"Ghi danh sach vao file thanh cong!!!";
	luufile.close();
}
// //Ham doc file can public thuoc tinh va chi nhap duoc dong dau tien
//	void QuanLySinhVien::docFile(){
//	ifstream hienthifile;
//	hienthifile.open("C:\\Users\\nguye\\OneDrive\\Desktop\\ghifilebtl.txt",ios::in);
//	SinhVien *sv;
//	//for(int i=0; i<SV.size();i++){
//	sv=new SinhVien;
//	hienthifile>>sv->HoVaTen;
//	hienthifile>>sv->GioiTinh;
//	hienthifile>>sv->MSSV;
//	hienthifile>>sv->Toan;
//	hienthifile>>sv->Van;
//	hienthifile>>sv->Anh;
//	hienthifile>>sv->dtb;
//	SV.push_back(sv);	
//	//}
//	hienthifile.close();
//	system("Pause");
//	
//}

//TimKiemSinhVienTheoTen
void QuanLySinhVien::TimKiemTen(){
	string ten;
	cout<<"Nhap ten sinh vien can tim:";
	fflush(stdin);
	getline(cin,ten);	
	cout<<endl; 
	for(int i=0;i<SV.size();i++){ 
		STT=i;		          
		if(ten.compare(SV.at(i)->getTen())==0){
			hienThiTenCot();
			cout<<endl<<STT<<setw(20); 
			SV.at(i)->Xuat();
		}else{
		cout<<"Khong ton tai sinh vien trong danh sach!!!";
		}			
	}
}
//XoaToanBoDanhSach
void QuanLySinhVien::XoaDS(){
	SV.clear();
	cout<<"Xoa toan bo danh sach sinh vien thanh cong !!!";
}
//Xoa SV
void QuanLySinhVien::XoaSV(){
	int n;
	XuatDS();
	if(SV.size()==0){
			cout<<"				Danh sach hien dang trong !!!";
	}else{		
	cout<<endl<<"Nhap STT sinh vien can xoa: ";
	cin>>n;
	if(n >= SV.size() ){
		cout<<"Khong co sinh vien tai vi tri do";
	}else{
	SV.erase(SV.begin()+n);
	cout<<"Da xoa sinh vien thanh cong !!!";
	}
	}
}


//SapXep
void QuanLySinhVien::SapXepD(){
		if(SV.size()==0){
			cout<<"Danh sach trong, khong the sap xep!!!";
		}else{		
		    for(int i=0;i<SV.size()-1;i++){
                for(int j=i+1;j<SV.size();j++){
                    if(SV.at(i)->getdtb() < SV.at(j)->getdtb()){
                        SinhVien *t= SV.at(i);
                        SV.at(i)=SV.at(j);
                        SV.at(j)=t;
                    }
                }
            }
    	}
            XuatDS();
}

void QuanLySinhVien::hienThiTenCot() {
	cout<<"---------------------------------------------------------------------------------------------------------------";
	cout<<endl<<"STT"<<setw(12)<<"HoTen"<<setw(30)<< "GioiTinh "<<setw(13)<<"MSSV"<<setw(22)<< "Toan"<<setw(9)<<"Van"<<setw(10)<< "Anh"<< setw(14)<< "DiemTBC"<<setw(10)<<"XepLoai";
}

void QuanLySinhVien::NhapDS(){
			SinhVien *sv;
            int n;
            cout<<"Nhap so luong sinh vien muon them vao danh sach: ";
            cin>>n;
            for(int i=0;i<n;i++){
            	cout<<"--- Nhap sinh vien thu "<<i+1<<" muon them vao danh sach --- "<<endl;
                sv=new SinhVien;  	//tinh da hinh
                sv->Nhap();			// tinh da hinh 
                SV.push_back(sv);
                cout<<endl;
            }           
}

void QuanLySinhVien::XuatDS(){
            cout<<endl<<setw(70)<<"*******Danh sach sinh vien*******"<<endl;
            hienThiTenCot();
            for(int i=0; i<this->SV.size();i++){		// so sanh voi kich thuoc phan tu cua vector      
				STT=i;
				cout<<endl<<STT<<setw(20);     	
                this->SV.at(i)->Xuat();			//at(i) goi sinh vien tai vi tri i de xuat du lieu sinh vien tai i
                cout<<endl;	
            }
}

void menu(){
	QuanLySinhVien dssv;
	int luachon; 
	char sobatky; 
	do {
		cout<<"================= MENU ====================";
		cout<<endl<<"1. Nhap sinh vien vao danh sach.";
		cout<<endl<<"2. Hien thi danh sach sinh vien.";
		cout<<endl<<"3. Sap xep theo diem trung binh giam dan.";
		cout<<endl<<"4. Xoa sinh vien theo STT.";
		cout<<endl<<"5. Xoa toan bo danh sach sinh vien.";
		cout<<endl<<"6. Tim kiem sinh vien theo ten.";
		cout<<endl<<"7. Ghi ket qua vao file.";
		cout<<endl<<"8. Doc file.(chua hoan thien chuc nang)";
		cout<<endl<<"0. Thoat.";        
		cout<<"\n===============______======================"<<endl;
		cout<<endl<<"Ban chon?:\n "; 
		cin>>luachon; 
		
switch(luachon){
			case 0:
				exit(0);
				break;
			case 1: 
				dssv.NhapDS();
				break; 
			case 2:
				dssv.XuatDS(); 
				break;
			case 3:
				dssv.SapXepD();
				break;
			case 4:
				dssv.XoaSV();
				break;
			case 5:
				dssv.XoaDS();
				break;
			case 6:
				dssv.TimKiemTen();
				break;
			case 7:
				dssv.ghiFile();
				break;
//			case 8:
//				dssv.docFile();
//				break;
			default:
				cout<<"			Vui long chon lai chuc nang!!!";
				break;
		}
		cout<<endl<<"\n\nNhan enter de tiep tuc!";
		getch(); 
		system("cls");
	}while(luachon);
}
BOOL WINAPI SetConsoleTitle(
  _In_ LPCTSTR lpConsoleTitle
);
int main(){
	SetConsoleTitle("QuanLySinhVien");
	menu();
};
