#include<stdio.h>
int main(){
    char city[100];
    printf("Enter the name of the city: ");
    fgets(city, sizeof(city), stdin);
    FILE *C = fopen("city.txt", "w");
    if (C == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(C, "%s", city);
    fclose(C);
    printf("City name saved to city.txt\n");

    
    return 0;
}