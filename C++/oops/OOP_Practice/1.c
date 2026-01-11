#include<stdio.h>

struct vector{
    int x1;
    int y1;
    int x2;
    int y2;
};

void vector_addition(struct vector v){
    int x = v.x1 + v.x2;
    int y = v.y1 + v.y2;
    printf("Resultant vector after addition is : <%d, %d>\n", x, y);
}

void vector_subtraction(struct vector v){
    int x = v.x1 - v.x2;
    int y = v.y1 - v.y2;
    printf("Resultant vector after subtraction is : <%d, %d>\n", x, y);
}

void position_vector(struct vector v){
    printf("Position vector: <%d, %d>\n", v.x2 - v.x1, v.y2 - v.y1);
}

void increment_vector(struct vector *v){
    v->x1 += 1;
    v->y1 += 1;
    v->x2 += 1;
    v->y2 += 1;
    printf("Vectors after incrementing by 1 are : <%d, %d> and <%d, %d>\n", v->x1, v->y1, v->x2, v->y2);
}

int main(){
    struct vector v;
    v.x1 = 2;
    v.y1 = 3;
    v.x2 = 4;
    v.y2 = 5;

    vector_addition(v);
    vector_subtraction(v);
    position_vector(v);
    increment_vector(&v);

    return 0;
}