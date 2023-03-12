#include <stdio.h>
//a. Read a sequence of natural numbers (sequence ended by 0) and determine
//the number of 0 digits of the product of the read numbers.
//b. Given a vector of numbers, find the longest contiguous subsequence
//such that the sum of any two consecutive elements is a prime number.

int is_prime(int n){
//    checks if the number n is a prime number and return 1 if yes or 0 if not
    for (int i=2;i<=n/2;i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

void print_longest_subseq(int v[],int start,int end){
    //    prints the seq from start to end
    printf("The longest contiguous subseq is: ");
    for (int i=start;i<=end;i++){
        printf("%d ",v[i]);
    }
    printf("with length %d .\n",end-start+1);
}

void longest_seq(int n, int v[],int *startseq, int *endseq){
//looks for the longest contiguous subseq and prints it
//call function with start and end equal to 0
    if (n<=1){
        printf("Not enough elements!\n");
        return;
    }
    int maxlen=0;
    int len=1;
    int start;
    int end=0;
    int i=1;
    for (i;i<n;i++){
        if (is_prime(v[i-1]+v[i])){
            len+=1;
        }
        else{
            if(len>maxlen){
                maxlen=len;
                end=i-1;
            }
            len=1;
        }
    }
    if(len>maxlen){
        maxlen=len;
        end=i-1;
    }
    start=end-maxlen+1;
    //print_longest_subseq(v,start,end);
    *startseq=start;
    *endseq=end;
    printf("%d\n",start);
    printf("%d\n",end);
}


int read_vector(int v[]) {
//    reads a vector, having as the parameter the vector where we save the values we read. returns its length.
    int i = 0;
    while (1) {
        scanf("%d", &v[i]);
        if (v[i] == 0)
            break;
        i++;
    }
    return i;
}

int no_of_digits_of_0(int n){
//    returns the number of digits 0 in a number
    int no=0;
    while(n>0){
        if (n%10==0)
            no++;
        n/=10;
    }
    return no;
}

int product_of_vector(int v[],int n){
//    returns the product of a vector
    int p=1;
    for (int i=0;i<n;i++){
        p*=v[i];
    }
    return p;
}

void menu(){
//    prints the menu
    printf("1.read a vector.\n");
    printf("2.determine the number of 0 digits of the product of the read numbers.\n");
    printf("3.longest contiguous subsequence such that the sum of any two consecutive elements is a prime number.\n");
    printf("4.exit the program.\n");
}

int main() {
    int op;//operation chose by the user
    int v[100];//the vector
    int n=-1;//length of the vector
    while (1){
        menu();
        scanf("%d",&op);
        if (op == 1){
            n = read_vector(v);
            printf("Vector read!\n");
        }
        else{
            if(op==2) {
                if (n!=0) {
                    int no = no_of_digits_of_0(product_of_vector(v, n));
                    printf("The product of the vector has %d digits of 0.\n", no);
                }
                else{
                    printf("Empty vector!\n");
                }
            }
            else{
                if (op==3){
                    int a,b;
                    int start;
                    int end;
                    //printf("%d",&end);
                    longest_seq(n,v,&start,&end);
                    print_longest_subseq(v,start,end);
                }
                else{
                    if(op==4) {
                        return 0;
                    }
                    else{
                        printf("Invalid command!\n");
                    }
                }

            }

        }

    }
}
