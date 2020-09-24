#include <stdio.h>
#include <stdlib.h>

struct product {
    char * name;
    int inventory;
    float price;
};

struct product* create_product(char* name, int inventory, float price) {
  product * temp = (product *) malloc(sizeof(product));
  temp->name = name;
  temp->inventory = inventory;
  temp->price = price;
  return temp;
}

void free_product(struct product * product){
    free(product);
}


int main(){
    product * temp;
    char name[20] = "Secretlab Chair";
    temp = create_product(name, 1, 389.99);
    printf("Name: %s", temp->name);
    //puts(temp->name);
    printf("Inventory: %i\nPrice: %.2f\n", temp->inventory, temp->price);
    free_product(temp);
    printf("Name: 12345678\ttest\n");
    printf("Name: 123456789\ttest\n");
    printf("Name: 1234567890\ttest\n");
    return 0;
}

