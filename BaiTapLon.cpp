#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[28];
    char category[25];
    int price;
    int year;
} car_st;

void InputData (car_st  arr[3]){
    for (int i = 0; i<3; i++){
        printf("\nEnter data of car %d: \n", i+1);
        printf("+ Name: ");
        gets(arr[i].name);
        printf("+ Category: ");
        gets(arr[i].category);
        printf("+ Price: ");
        scanf("%d", arr[i].price);
        printf("+ Year: ");
        scanf("%d", arr[i].year);
        fflush(stdin);  
    }
}

void displayHeader(){
    printf("\n");
    printf("%-3s ||", "No");
    printf("%-28s ||", "Name");
    printf("%-25s ||", "Category");
    printf("%-8s ||", "Price");
    printf("%-4s ||", "Year");
    printf("\n");
}
void displayRow (car_st arr[3], int index){
    printf("%03d ||", index + 1);
    printf("%-28s ||", arr[index].name);
    printf("%-25s ||", arr[index].category);
    printf("%-8d ||", arr[index].price);
    printf("%-4d ||\n", arr[index].year);
}
void swap (car_st *car1, car_st *car2){
    car_st temp = *car1;
    *car1 = *car2;
    *car2 = temp;
}
void sortDisplay (car_st arr[3]){
    int i, j;
    for (i = 0; i < 2; i++){
        for (j = i + 1; i < 3; j++){
            if (strcmp( arr[i].category, arr[j].category) > 0){
                swap ( &arr[i], &arr[j]);
            }else if (strcmp( arr[i].category, arr[j].category) == 0){
                if (arr[i].price > arr[j].price){
                    swap ( &arr[i], &arr[j]);
                }
            }
        }
    }
    // Print table
    displayHeader();
        for (i = 0; i < 3; i++){
            displayRow (arr, i);
    }
    // Find min year, max year
    int minYear = arr[0].year, maxYear = arr[0].year;
        for (i = 1; i < 3; i++){
            if (arr[i].year < minYear) minYear = arr[i].year;
            if (arr[i].year > maxYear) maxYear = arr[i].year;
    }
    // Count statistic
    int* statistic = (int*)calloc(maxYear + 1, sizeof(int));
        for(i = 0; i < 3; i++) {
		    int yearValue = arr[i].year;
		    statistic[yearValue] += 1;
	}
    // Print statistic
    printf("\n");
    for (i = minYear; i <= maxYear; i++){
        if (statistic[i] == 1){
            printf("The year of %d has %d car\n", i, statistic[i]);
        }
        else if (statistic[i] > 1){
            printf("The year of %d has %d car\n", i, statistic[i]);
        }
    }
    printf("\n");
    free(statistic);
}
void searchDisplay(car_st arr[3]){
    // Nhap tu ban phim
    char category[10];
    printf("\nEnter category for search : ");
    gets(category);
    printf("\n");

    // Tim kiem
    int i = 0, count = 0;
	for (i = 0; i < 3; i++) {
		if (strcmp(arr[i].category, category) == 0) {
			displayRow(arr, i);
			count++;
		}
	}
	if (count == 0) {
		printf("\nThere are no car of this category\n");
	}
}
void saveToFile(car_st *p)
{
	FILE *fp = fopen("car.dat", "wb");

	int i;
	for (i = 0; i < 3; i++) {
		fwrite(p + i, sizeof(car_st), 1, fp);
	}

	fclose(fp);
}

int main(){
    car_st carList[3];
    int entry;
    while(1){
        // Menu
        printf("\n");
        printf("1. Input data of car\n");
        printf("2. Sort, display details information and statistic of all cars\n");
        printf("3. Find the car of category\n");
        printf("4. Save to binary file car.dat\n");
        printf("5. Exit\n");
        // Nhap 1 so tuong ung voi menu:
        printf("\nEnter a number from 1 to 5: ");
		while(1) {
			if(!scanf("%d", &entry) || entry < 1 || entry > 5) {
				fflush(stdin);
				printf("Enter a number from 1 to 5: ");
			} else {
				fflush(stdin);
				break;
			}
		}
        // Xu ly lua chon
		if (entry == 1) {
			InputData(carList);
		} else if (entry == 2) {
			sortDisplay(carList);
		} else if (entry == 3) {
			searchDisplay(carList);
		} else if (entry == 4) {
			saveToFile(carList);
		} else {
			break;
		}
	}

	return 0;
    }


