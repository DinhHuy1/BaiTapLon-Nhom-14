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
void nhapN( XE a[], int SoLoai);
void xuat(XE xe);
void xuatN( XE a[], int SoLoai);
void SapXepvaHienThi (XE a[], int SoLoai);
void TimXeTheoLoai (XE a[], int SoLoai);
void ThemXe(XE a[] ,int &SoLoai, XE &x, int k);
void XoaMotXe(XE a[], int SoLoai);
void xuatFile(XE a[], int SoLoai, char fileName[]);
int Menu();
int main(){
	car_st carList[10];
	system("color 0A");
	Menu();
}

void NhapDuLieu (XE &xe){
        printf("\n+ Ten: ");
		fflush(stdin);
        gets (xe.Ten);
        printf("\n+ TheLoai: ");
        gets (xe.TheLoai);
        printf("\n+ GiaTien: ");
        scanf ("%d", &xe.GiaTien);
        printf("\n+ Nam: ");
        scanf ("%d", &xe.Nam);
        fflush(stdin);
}

void nhapN( XE a[], int SoLoai){
    printf("\n____________________________________\n");
    for(int i = 0; i < SoLoai; ++i){
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

void xuatN( XE a[], int SoLoai){
    printf("\n____________________________________\n");
    for(int i = 0;i < SoLoai; ++i){
        printf("\nThong tin XE thu %d:", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}


void SapXepvaHienThi (XE a[], int SoLoai){
    // Sap xep cac xe theo nam tu A-> Z
    int i,j;
    XE tmp;
    for(int i = 0;i < SoLoai;++i){
        for(int j = i+1; j < SoLoai; ++j){
            if(a[i].Nam < a[j].Nam){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    // Hien Thi Thong Tin
    printf("	||%-20s ||%-20s ||%-20s ||%-30s \n", "Ten", "The Loai", "Gia Tien", "Nam" );
	for (int i=0; i<SoLoai; i++)
	{
		printf("	||%-20s ||%-20d ||%-20s ||%-30d \n",a[i].Ten, a[i].TheLoai, a[i].GiaTien, a[i].Nam);
	}
    
}

void TimXeTheoLoai (XE a[], int SoLoai){
    // Nhap tu bàn phím
    char TheLoai[10];
    printf("\nNhap the loai can tim : ");
    fflush(stdin);
    gets(TheLoai);
    printf("\n");
    
    // Tìm kiem
    int i = 0, dem = 0;
	for (i = 0; i < SoLoai; i++) {
		if (strcmp(a[i].TheLoai, TheLoai) == 0) {
			xuatN(a, SoLoai);
			dem++;
		}
	}
	if (dem == 0) {
		printf("\nKhong co chiec xe thuoc the loai nay\n");
	}
}

void ThemXe(XE a[] ,int &SoLoai, XE &x, int k){
	int i;
	for( i = SoLoai; i > k ;i--)
	{
		a[i]=a[i-1];
	}
	a[k]=x;
	SoLoai++;
}

void XoaMotXe(XE a[], int SoLoai){
	char c[50];
	printf("\nCho biet ten xe can xoa: ");
	fflush(stdin);
	gets(c);
	int bienLap,BienKT=0;
	for(int i=0 ; i < SoLoai ; i++)
	{
		if(strcmp(a[i].Ten,c)==0)
		{
			for (bienLap=i; bienLap < SoLoai; i++)
			{
				a[bienLap]=a[bienLap+1];
				SoLoai--;
			}
			printf("Da xoa xong");
			BienKT++;
		}
	}
	if(BienKT==0)
	{
		printf("Xe ko ton tai");
	}
}

void xuatFile(XE a[], int SoLoai, char fileName[]){
    FILE * fp;
    fp = fopen(fileName,"w");
    fprintf(fp,"||	TEN      THE LOAI               GIA TIEN                 NAM     ||\n\n");
    for(int i = 0; i < SoLoai; i++){
    	XE x = a[i];
        fprintf(fp, "||	%-16s %-22d %-20s %-16d ||\n\n", x.Ten, x.TheLoai, x.GiaTien, x.Nam);
    }
    fprintf(fp,"	---------------------------------------------------------------------------------------\n");
    fclose(fp);
}
int Menu(){
	int key;
    char fileName[] = "DSXE.txt";
    int SoLoai,x,k,n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong XE: "); scanf("%d", &n);
    }while(n <= 0);
    XE a[n];
while(true){
        system("cls");
        printf(" \n\n\n\n\n\n");
        printf("                                **********************************************\n");
        printf("                                *        CHUONG TRINH QUAN LY XE             *\n");
        printf("                                *      1. Nhap danh sach xe                  *\n");
        printf("                                *      2. Xuat danh sach xe                  *\n");
        printf("                                *      3. Sap xep va hien thi danh sach xe   *\n");
        printf("                                *      4. Them xe                            *\n");
        printf("                             	*      5. Xoa mot xe                         *\n");
        printf("                             	*      6. Xuat DS XE ra file                 *\n");
        printf("                             	*      7. Tim kiem thong tin xe              *\n");
        printf("                                *      0. Thoat                              *\n");
        printf("                                **********************************************\n");
        printf("                                ****         Nhap lua chon cua ban        ****\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS xe!");
                nhapN(a, SoLoai);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS xe!");
                    xuatN(a,SoLoai);
                }else{
                    printf("\nNhap DS XE truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep va hien thi!");
                    SapXepvaHienThi(a, SoLoai);
                    xuatN(a, SoLoai);
                }else{
                    printf("\nNhap DS XE truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    XE x;
					NhapDuLieu(x);
					XE a[100];
					ThemXe(a,SoLoai,x,k);
					printf("\nDanh sach xe sau khi them la :");
					xuatN(a, SoLoai);
                }else{
                    printf("\nNhap DS XE truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon xoa xe!");
                    XoaMotXe(a, SoLoai);	
                }else{
                    printf("\nNhap DS XE truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
                if(daNhap){
                    printf("\nBan da chon xuat DS XE ra file!");
                    xuatFile(a, SoLoai, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nGhi DSSV thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 7:
            	if(daNhap){
            		printf("\nBan da chon tim kiem thong tin xe");
            		TimXeTheoLoai(a, SoLoai);
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
