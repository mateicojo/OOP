#include <stdio.h>

void print_vector(int n,int v[]){
    for (int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
}

int read_vector(int v[]){
    printf("Enter the elements of your vector and type 0 to stop reading values.");
    int i=0;
    int a[100];
    scanf("%d", &a[i]);
    while(a[i]!=0){
        i++;
        scanf("%d", &a[i]);
    }
    v=a;
    print_vector(i,v);
    return i;
}

int no_of_digits_of_0(int n){
    int no=0;
    while(n>0){
        if (n%10==0)
            no++;
        n/=10;
    }
    return no;
}

int product_of_vector(int v[],int n){
    int p=1;
    for (int i=0;i<n;i++){
        p*=v[i];
    }
    return p;
}

int main() {
    int op;//operation chose by the user
    int v[100];//the vector
    int n=-1;//length of the vector
    while (1){
        printf("1.read a vector.\n");
        printf("2.determine the number of 0 digits of the product of the read numbers.\n");
        printf("3.longest contiguous subsequence such that the sum of any two consecutive elements is a prime number.\n");
        printf("4.exit the program.\n");
        scanf("%d",&op);
        if (op == 1){
            n = read_vector(v);
        }
        if(op==2) {
            if (n!=-1) {
                int no = no_of_digits_of_0(product_of_vector(v, n));
                printf("The product of the vector has %d digits equal to 0.\n", no);
            }
            else{
                printf("Empty vector!");
            }
        }
        if (op==3){
        }
        if(op==4) {
            return 0;
        }
    }
}
