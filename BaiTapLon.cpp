#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
struct ThucUong_st{
	char DoUong[50];
	int GiaSanPham;
	char size[5];
	int SoLuong;
};
typedef ThucUong_st THUCUONG;
void NhapThucUong(THUCUONG &tu);
void NhapDanhSachThucUong(THUCUONG tu[],int &SoLoai);
void XuatThucUong(THUCUONG &tu);
void XuatDanhSachThucUong(THUCUONG tu[], int SoLoai);
void ThemThucUong(THUCUONG tu[],int &SoLoai,THUCUONG &x,int k);
void XoaMotThucUong(THUCUONG tu[], int SoLoai);
void TimThucUong(THUCUONG tu[], int SoLoai, char c[]);
void hienthiThongtinTheoChieuNgang(THUCUONG tu[], int SoLoai);
void ThanhToan(THUCUONG tu[], int SoLoai);
void LuuFile(THUCUONG *tu, int SoLoai);
void NhapThucUong(THUCUONG &tu)
{
	fflush(stdin);
	printf ("\n   Chon thuc uong : ");
	gets(tu.DoUong);
	printf("\n   Gia cua thuc uong La:");
	scanf("%d",&tu.GiaSanPham);
	printf("\n   Cua hang co size m: la nho , l: la lon");
	printf("\n   Kich co thuc uong : ");
    scanf("%s",&tu.size);
	printf ("\n   So luong thuc uong la : ");
	scanf("%d",&tu.SoLuong);
}
void NhapDanhSachThucUong(THUCUONG tu[],int &SoLoai)
{
	printf("\n********** DANH SACH THUC UONG **********");
	for (int i=0; i<SoLoai; i++)
	{
		printf("\nThuc uong thu %d la: ",i+1);
		NhapThucUong(tu[i]);
	}
}
void XuatThucUong(THUCUONG &tu)
{
	printf ("\n   Ten thuc uong la: %s",tu.DoUong);	
	printf("\n    Gia thuc uong la : %d",tu.GiaSanPham);
	printf("\n    Kich co thuc uong la: %s",tu.size);
    printf("\n    So Luong thuc uong la : %d ",tu.SoLuong);
}
void XuatDanhSachThucUong(THUCUONG tu[], int SoLoai)
{
	for(int i=0; i<SoLoai ; i++)
	{
        printf("\nThuc uong thu %d la: ",i+1);
		XuatThucUong(tu[i]);
	}
}
void ThemThucUong(THUCUONG tu[],int &SoLoai,THUCUONG &x,int k)
{
	int i;
	for( i=SoLoai;i>k;i--)
	{
		tu[i]=tu[i-1];
	}
	tu[k]=x;
	SoLoai++;
}
void XoaMotThucUong(THUCUONG tu[], int SoLoai)
{
	char c[50];
	printf("\nCho biet ten do uong can xoa: ");
	fflush(stdin);
	gets(c);
	int bienLap,BienKT=0;
	for(int i=0 ; i<SoLoai ; i++)
	{
		if(strcmp(tu[i].DoUong,c)==0)
		{
			for (bienLap=i;bienLap<SoLoai;i++)
			{
				tu[bienLap]=tu[bienLap+1];
				SoLoai--;
			}
			printf("Da xoa xong");
			BienKT++;
		}
	}
	if(BienKT==0)
	{
		printf("Thuc uong ko ton tai");
	}
}
int TimThucUong(THUCUONG tu[], int SoLoai)
{
	fflush(stdin);
	char ten[50];
	for(int i=0;i<SoLoai;i++)
	{
		if(strcmp(tu[i].DoUong,ten)==0)
		{
			return i;
			break;
		}
	}
	return -1;
}
void SapXep(THUCUONG tu[], int SoLoai)
{
	int temp;
	for(int i=0;i<SoLoai-1;i++)
	{
		for(int j=i+1;j<SoLoai;j++)
		{
			if(tu[i].SoLuong < tu[j].SoLuong)
			{
				temp=tu[i].SoLuong;
				tu[i].SoLuong=tu[j].SoLuong;
				tu[j].SoLuong=temp;
			}
		}
	}
}
void hienthiThongtinTheoChieuNgang(THUCUONG tu[], int SoLoai)
{
	printf("	||%-20s ||%-20s ||%-20s ||%-30s \n", "DO UONG", "GIA SAN PHAM", "SIZE", "SO LUONG" );
	for (int i=0; i<SoLoai; i++)
	{
		printf("	||%-20s ||%-20d ||%-20s ||%-30d \n",tu[i].DoUong,tu[i].GiaSanPham,tu[i].size,tu[i].SoLuong);
	}
}
void ThanhToan(THUCUONG tu[], int SoLoai)
{
	int Tong=0;
	int s;
	SapXep(tu,SoLoai);
	int vt = 0;//vi tri bat dau dem;
	for(int i = vt; i<SoLoai; i = vt)
	{
		int dem = 1;
		int Tong = tu[i].SoLuong * tu[i].GiaSanPham;
		for(int j = vt + 1; j < SoLoai; j++)
		{
			if(tu[i].DoUong == tu[j].DoUong)
			{
				dem++;
				Tong = Tong + tu[j].SoLuong * tu[j].GiaSanPham;
			}
			else
			{
				break;
			}
		}
		if(dem>0)
		{
			printf("\nTien cua do uong %s la %d",tu[vt].DoUong,Tong);
			vt = vt + dem; //vi tri bat dau moi;
		}
	}
}
void LuuFile(THUCUONG *tu, int SoLoai,char fileName[]) 
{
	FILE* fp;
	fp = fopen (fileName,"w");
	int i;
	fprintf(fp,"||	TEN DO UONG      SO LUONG               SIZE                 GIA SAN PHAM     ||\n\n");
	for(i = 0; i < SoLoai; i++) 
	{
		THUCUONG x = tu[i];
		fprintf(fp, "||	%-16s %-22d %-20s %-16d ||\n\n",x.DoUong,x.SoLuong,x.size,x.GiaSanPham	);
	}
	fprintf(fp,"	---------------------------------------------------------------------------------------\n");
	fclose(fp);
}
void menu()
{
	THUCUONG tu;
	int k,SoLoai;
	char ten[50];
	char fileName[] = "thuc_uong.txt";
	int chon, flat=1;
	bool DaNhap = false;
	do
	{
		printf("\n\t	Nhap So luong loai Thuc Uong Can Dung: ");
		scanf("%d",&SoLoai);
	}
	while(SoLoai<=0);
	while(true && flat)
	{
		printf("                                                                     \n");
		printf("          --------------------------------------------------          \n");
		printf("        *                                                    *         \n");
		printf("       *                                                      *         \n");
		printf("      *                     QUAN LY QUAN COFFE                 *        \n");
		printf("     *             1. Nhap Thong Tin Do Uong.                   *         \n");
		printf("    *              2. Them Do Uong.                              *         \n");
		printf("    *              3. Xoa Do Uong.                               *         \n");
		printf("     *             4. Thong Ke Do Uong.                         *         \n");
		printf("      *            5. Thanh Toan.                              *        \n");
		printf("       *           6. Ghi File.                               *         \n");
		printf("         *         7. Thoat Chuong Trinh.                   *         \n");
		printf("           *                                              *         \n");
		printf("             *                                          *         \n");
		printf("               *--------------------------------------*         \n");
		printf(" ----------------------------------------------------------------------------\n");
		printf("	Ban Chon: ");
		scanf("%d",&chon);
		switch (chon)
		{
			case 1:
			{
				THUCUONG tu[100];
     			printf ("\n\tNhap Thong Tin Thuc Uong");
				NhapDanhSachThucUong(tu,SoLoai);
				XuatDanhSachThucUong(tu,SoLoai);
				DaNhap = true;
				break;
			}
			case 2:
			{
				if(DaNhap)
				{
					THUCUONG x;
					NhapThucUong(x);
					THUCUONG tu[100];
					ThemThucUong(tu,SoLoai,x,k);
					printf("\ndanh sach thuc uong sau khi them la :");
					XuatDanhSachThucUong(tu,SoLoai);
				}
				else 
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho thuc uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
				break;
			}
			case 3:
			{
				if(DaNhap)
				{
					THUCUONG tu[100];
					XoaMotThucUong(tu,SoLoai);
					break;
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho thuc uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
					break;
			}
			case 4:{
				if(DaNhap)
				{
					printf("\n\tnhap ten thuc uong can tim: ");
					fflush(stdin);
					gets(ten);
					THUCUONG tu[100];
					int b=TimThucUong(tu,SoLoai);
					if(TimThucUong(tu,SoLoai)==-1)
						printf("\nKhong tim thay thuc uong: %s",ten);
					else
						printf("\nTim thay thuc uong thu %d",b+1);
					}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho thuc uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
				break;
			}
			case 5:
			{
				if (DaNhap)
				{
					THUCUONG tu[100];
			  	    
			  	    hienthiThongtinTheoChieuNgang(tu,SoLoai);
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
				break;
			}
			case 6:
			{
				if (DaNhap){
					THUCUONG tu[100];
					ThanhToan(tu,SoLoai);
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
				break;
			}
			case 7:
			{
				if (DaNhap)
				{
					THUCUONG tu[100];
					LuuFile(tu,SoLoai,fileName);
					printf ("	Luu File Thanh Cong");
				}
				else
				{
					printf("	LUU Y: Quy Khach Nen Nhap thong tin cho do uong truoc!\n");
					printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				}
				break;
			}
			case 8:
			{
				flat = 0;
				break;
			}
			default: 
			{
				printf("\nKhong co chuc nang nay");
				printf("\t\t\t    MOI QUY KHACH CHON LAI\n");
				break;
			}
		}
	}
}
int main()
{
	system("Color 72");
	printf ("\nCHAO MUNG QUY KHACH DEN VOI COFFEE IT CUA CHUNG TOI CHUC QUY KHACH NGON MIENG !\n ");
	menu();
}

