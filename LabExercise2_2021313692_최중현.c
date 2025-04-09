#include<stdio.h>

int main()
{
	printf("(1) Circle\n(2) Rectangle\n(3) Triangle\n");
	
	int shape;	
	printf("Enter the shape: ");
	scanf("%d", &shape);
	
	float radius, width, height, area;
	switch(shape)
	{
		case 1: // Circle 
			printf("Enter the radius of the circle: ");
			scanf("%f", &radius);
			
			area = radius * radius * 3.14;
			printf("The area of the circle is %f.\n", area);
			break;
			
		case 2: // Rectangle
			printf("Enter the width of the rectangle: ");
			scanf("%f", &width);
			
			printf("Enter the height of the rectangle: ");
			scanf("%f", &height);
			
			area = width * height;
			printf("The area of the rectangle is %f.\n", area);
			break;
			
		case 3: // Triangle
			printf("Enter the width of the triangle: ");
			scanf("%f", &width);
			
			printf("Enter the height of the triangle: ");
			scanf("%f", &height);
			
			area = 0.5 * width * height;
			printf("The area of the triangle is %f.\n", area);
			break;
			
		default:
			break;
	}
	
	printf("<End of program>");
	return 0;
}
