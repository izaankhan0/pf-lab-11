#include<stdio.h>

struct Rectangle{
	int length;
	int width;
};

void area(struct Rectangle rectangle){
	int area = rectangle.length * rectangle.width;
	printf("Area is: %d\n", area);
}

void perimeter(struct Rectangle rectangle){
	int perimeter = (rectangle.length*2) + (rectangle.width*2);
	printf("Perimeter is: %d\n", perimeter);
}

void check(struct Rectangle rectangle){
	
	int width = rectangle.width;
	int height = rectangle.length;
	
	if (width >= 0 && width <= 20){
		printf("Width %d is fine\n", width);
	} else{
		printf("Width %d is NOT fine\n", width);
	}
	if (height >= 0 && height <= 20){
		printf("Height %d is fine\n", height);
	} else{
		printf("Height %d is NOT fine\n", height);
	}
	
}

void main(){
	struct Rectangle rect1;
    rect1.length = 10;
    rect1.width = 5;

    area(rect1);
    perimeter(rect1);
    check(rect1);

    struct Rectangle rect2;
    rect2.length = 25;
    rect2.width = 18;

    area(rect2);
    perimeter(rect2);
    check(rect2);

}