#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct car_st{
	char Ten[28];
	char TheLoai[25];
	int GiaTien;
	int Nam;
};
typedef car_st XE;

void NhapDuLieu (car_st &xe);
void nhapN( XE a[], int n);
void xuat(XE xe);
void xuatN( XE a[], int n);
void HoanDoi (XE *car1, XE *car2);
void SapXep (XE a[], int n);
void TimXeTheoLoai (XE a[], int n);
void xuatFile(XE a[], int n, char fileName[]);
int Menu();
int main(){
	car_st carList[10];
	system("color 0A");
	Menu();
}

void NhapDuLieu (XE &xe){
        printf("\n+ Ten: ");
        gets (xe.Ten);
        printf("\n+ TheLoai: ");
        gets (xe.TheLoai);
        printf("\n+ GiaTien: ");
        scanf ("%d", &xe.GiaTien);
        printf("\n+ Nam: ");
        scanf ("%d", &xe.Nam);
        fflush(stdin);
}

void nhapN( XE a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i < n; ++i){
        printf("\nNhap Xe thu %d:", i+1);
        NhapDuLieu(a[i]);
    }
    printf("\n____________________________________\n");
}

void xuat(XE xe){
    printf("\nTen Xe: %s", xe.Ten);
    printf("\nThe Loai: %s", xe.TheLoai);
    printf("\nGia Tien: %d", xe.GiaTien);
    printf("\nNam San Xuat: %d", xe.Nam);
}

void xuatN( XE a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n; ++i){
        printf("\nThong tin XE thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}


void SapXep (XE a[], int n){
    // Sap xep cac xe theo nam tu A-> Z
    int i,j;
    XE tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].Nam > a[j].Nam){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void TimXeTheoLoai (XE a[], int n){
    // Nhap tu bàn phím
    char TheLoai[10];
    printf("\nNhap the loai can tim : ");
    gets(TheLoai);
    printf("\n");
    
    // Tìm kiem
    int i = 0, dem = 0;
	for (i = 0; i < n; i++) {
		if (strcmp(a[i].TheLoai, TheLoai) == 0) {
			xuatN(a, n);
			dem++;
		}
	}
	if (dem == 0) {
		printf("\nKhong co chiec xe thuoc the loai nay\n");
	}
}

void xuatFile(XE a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen(fileName,"w");
    fprintf(fp, "%20s%5s%5d%10d\n", "Ten Xe","The Loai", "Gia Tien", "Nam");
    for(int i = 0; i < n; i++){
        fprintf(fp, "%20s%5s%5d%10d\n", a[i].Ten,a[i].TheLoai, a[i].GiaTien, a[i].Nam);
    }
    fclose(fp);
}
int Menu(){
	int key;
    char fileName[] = "DSXE.txt";
    int n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong XE: "); scanf("%d", &n);
    }while(n <= 0);
    XE a[n];
while(true){
        system("cls");
        printf(" \n\n\n\n\n\n");
        printf("                                ****************************************\n");
        printf("                                *        CHUONG TRINH QUAN LY XE       *\n");
        printf("                                *      1. Nhap danh sach xe            *\n");
        printf("                                *      2. Xuat danh sach xe            *\n");
        printf("                                *      3. Sap xep danh sach xe         *\n");
        printf("                                *      4. Xuat DS xe ra file           *\n");
        printf("                             	*      5. Tim kiem xe                  *\n");
        printf("                                *      0. Thoat                        *\n");
        printf("                                ****************************************\n");
        printf("                                **       Nhap lua chon cua ban        **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS xe!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS xe!");
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS XE truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep XE theo the loai!");
                    SapXep(a, n);
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS XE truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon xuat DS XE!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nGhi DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
            	if(daNhap){
            		printf("\nBan da chon tim kiem thong tin xe");
            		TimXeTheoLoai(a, n);
            	}else{
            		printf("\nNhap DS SV truoc!!!!");
				}
				printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
