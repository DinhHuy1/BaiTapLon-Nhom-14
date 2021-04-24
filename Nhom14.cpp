#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
	char Ten[28];
	char TheLoai[25];
	int GiaTien;
	int Nam;
} car_st;
void NhapDuLieu (car_st arr[3]){
    int i;
    for (i = 0; i < 3; i++){
        printf("\nNhap du lieu cua tung chiec xe %d:\n", i +1);
        printf("+ Ten: ");
        gets (arr[i].Ten);
        printf("+ TheLoai: ");
        gets (arr[i].TheLoai);
        printf("+ GiaTien: ");
        scanf ("%d", &arr[i].GiaTien);
        printf("+ Nam: ");
        scanf ("%d", &arr[i].Nam);
        fflush(stdin);
    }
}

void ToaDoBangIn()
{
	printf("\n");
	printf("%-3s ||", "No");
	printf("%-28s ||", "Ten");
	printf("%-25s ||", "TheLoai");
	printf("%-8s ||", "GiaTien");
	printf("%-4s ||", "Nam");
	printf("\n");
}

void HangIn (car_st arr[3], int mucluc)
{
	printf("%03d ||", mucluc + 1);
	printf("%-28s ||", arr[mucluc].Ten);
	printf("%-25s ||", arr[mucluc].TheLoai);
	printf("%-8d ||", arr[mucluc].GiaTien);
	printf("%-4d ||\n", arr[mucluc].Nam);
}

void HoanDoi (car_st *car1, car_st *car2)
{
	car_st temp = *car1;
	*car1 = *car2;
	*car2 = temp;
}
void SapXep (car_st arr[3]){
    // Sap xep cac xe theo the loai từ A-> Z
    int i,j;
    for (i = 0; i < 2; i++){
        for (j = i + 1; j < 3; j++){
            if(strcmp(arr[i].TheLoai, arr[j].TheLoai) > 0){
                HoanDoi (&arr[i], &arr[j]);
            } else if(strcmp(arr[i].TheLoai, arr[i].TheLoai) == 0){
                if(arr[i].GiaTien > arr[j].GiaTien){
                    HoanDoi (&arr[i], &arr[j]);
                }
            }
        }
    }
    // Xuat ra bang in
    ToaDoBangIn();
	for(i = 0; i < 3; i++) {
		HangIn(arr, i);
	}
}
void ThongKevaHienThi (car_st arr[3]){
	// Tim minYear, maxYear
	int i;
    int minYear = arr[0].Nam, maxYear = arr[0].Nam;
    for (i = 1; i < 3; i++){
        if(arr[i].Nam < minYear) minYear = arr[i].Nam;
        if(arr[i].Nam > maxYear) maxYear = arr[i].Nam;
    }
    // Ðem so lieu thong ke
    int* thongke = (int*)calloc(maxYear + 1, sizeof(int));
	for(i = 0; i < 3; i++) {
		int yearValue = arr[i].Nam;
		thongke[yearValue] += 1;
	}

    // Xuat so lieu thong ke
    printf("\n");
    for (i = minYear; i <= maxYear; i++){
        if(thongke[i] == 1){
            printf("Nam %d có %d chiếc xe\n", i, thongke[i]);
        }
        else if (thongke[i] > 1){
             printf("Nam %d có %d chiếc xe\n", i, thongke[i]);
        }
    }
    printf("\n");
	free(thongke);
}

void TimXeTheoLoai (car_st arr[3]){
    // Nhap tu ban phim
    char TheLoai[10];
    printf("\nNhap the loai can tim : ");
    gets(TheLoai);
    printf("\n");
    
    // Tim kiem
    int i = 0, dem = 0;
	for (i = 0; i < 3; i++) {
		if (strcmp(arr[i].TheLoai, TheLoai) == 0) {
			HangIn(arr, i);
			dem++;
		}
	}
	if (dem == 0) {
		printf("\nKhong co chiec xe thuoc the loai nay\n");
	}
}

void saveToFile (car_st *p)
{
	FILE *fp = fopen("car.dat", "wb");

	int i;
	for (i = 0; i < 3; i++) {
		fwrite(p + i, sizeof(car_st), 1, fp);
	}

	fclose(fp);
}
void SetColor(WORD color){ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

int main(){
    car_st carList[3];
    int entry;
    while(1) {
		// Menu
		SetColor(10);
		system("cls");
		printf(" \n\n\n\n\n\n");
		printf("                                ******************************************************************\n");
        printf("                                *                 CHUONG TRINH QUAN LY XE HOI                    *\n");
        printf("                                *      1. Nhap du lieu cua tung chiec xe                         *\n");
        printf("                                *      2. Sap xep thong tin                                      *\n");
        printf("                                *      3. Thong ke va hien thi thong tin chi tiet                *\n");
        printf("                                *      4. Tim chiec xe theo the loai                             *\n");
        printf("                                *      5. Ghi vao tap tin nhi phan car.dat                       *\n");
        printf("                                *      6. Thoat                                                  *\n");
        printf("                                ******************************************************************\n");

		// Nhap 1 so tương ung voi menu:
		printf("\nNhap mot so tu 1 den 6 : ");
		while(1) {
			if(!scanf("%d", &entry) || entry < 1 || entry > 6) {
				fflush(stdin);
				printf("Nhap mot so tu 1 den 6 : ");
			} else {
				fflush(stdin);
				break;
			}
		}

		// Xu ly lua chon
		if (entry == 1) {
			NhapDuLieu (carList);
		} else if (entry == 2) {
			SapXep (carList);
		} else if (entry == 3) {
			ThongKevaHienThi (carList);
		} else if (entry == 4) {
			TimXeTheoLoai (carList);
		} else if (entry == 5) {
			saveToFile (carList);
		} else {
			break;
		}
	}

	return 0;
}