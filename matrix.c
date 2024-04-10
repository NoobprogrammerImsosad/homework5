#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void print_matrix(int row,int column,int **matrix);
void add_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix);
void subtraction_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix);
void transpose_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix);
void multiply_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix);
void free_matrix(int row,int column,int **matrix);
int main()
{
    printf("[----- [TaeYoungKim] [2021041005] -----]\n");
    int Arow,Acolumn,Brow,Bcolumn;//A,B의 행과 열 선언
    int **Amatrix,**Bmatrix;//이중 포인터로 A,B행렬 선언
    printf("input row , column of A: ");
    scanf("%d %d",&Arow,&Acolumn);
    printf("input row , column of B: ");
    scanf("%d %d",&Brow,&Bcolumn);//(a) 행렬 A와 B의 행(row)과 열(column)의 값을 입력 받는다. (scanf() 사용)
    Amatrix = (int**)malloc(sizeof(int*)*Arow);
    for(int i=0;i<Arow;i++)
    {
        Amatrix[i]=(int*)malloc(sizeof(int)*Acolumn);
    }//Amatrix 동적할당
    Bmatrix = (int**)malloc(sizeof(int*)*Brow);
    for(int i=0;i<Brow;i++)
    {
        Bmatrix[i]=(int*)malloc(sizeof(int)*Bcolumn);
    }//(b) 동적 메모리할당(dynamic memory allocation) 방식으로 행렬을 생성한다.
    srand(time(NULL));
    for(int i=0;i<Arow;i++)
    {
        for(int q=0;q<Acolumn;q++)
        {
            Amatrix[i][q] = (rand()%100);
        }
    }//시간을 인자로 하는 0~99의 랜덤값으로 Amatrix 채우기 
    for(int i=0;i<Brow;i++)
    {
        for(int q=0;q<Bcolumn;q++)
        {
            Bmatrix[i][q] = (rand())%100;
        }
    } //(c)random 값으로 행렬의 채운다.
    printf("A matrix\n");
    print_matrix(Arow,Acolumn,Amatrix);
    printf("\n B matrix\n");
    print_matrix(Brow,Bcolumn,Bmatrix);//(d) Print_Matrix - A와 B 행렬을 출력하는 함수를 구현한다. (print matrix() )
    add_matrix(Arow,Acolumn,Amatrix,Brow,Bcolumn,Bmatrix);//(e) Add Matrix - A + B를 구현한다. (addition matrix())
    subtraction_matrix(Arow,Acolumn,Amatrix,Brow,Bcolumn,Bmatrix);//(f) Subtract Matrix - A − B를 구현한다. (subtraction matrix())
    transpose_matrix(Arow,Acolumn,Amatrix,Brow,Bcolumn,Bmatrix);//(g) Transpose matrix a - A의 전치행렬 T를 구현한다. (transpose matrix())
    multiply_matrix(Arow,Acolumn,Amatrix,Brow,Bcolumn,Bmatrix);//(h) Multiply Matrix - A × B를 구현한다. (multiply matrix())
//(i) 모든 메뉴에서 연산이 끝나면, print matrix()를 사용하여 결과값을 프린트한다.
//(j) 연산이 종료되거나 프로그램을 종료할 때 할당했던 메모리를 해제 한다. (free matrix())
//(k) 함수명은 유지하되 함수의 인자는 자유롭게 지정한다*/
free_matrix(Arow,Acolumn,Amatrix);//Amatrix free
free_matrix(Brow,Bcolumn,Bmatrix);//Bmatrix free

    return 0;
}
void print_matrix(int row,int column,int **matrix){//행과 열, 이중 포인터 받아서 행렬 출력
    for(int i=0;i<row;i++)
    {
        for(int q=0;q<column;q++)
        {
            printf("%d  ",matrix[i][q]);
        }
        printf("\n");
    }
}
void add_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix){
    if(Arow==Brow&&Acolumn==Bcolumn)
    {
        int **addmatrix;
        addmatrix = (int**)malloc(sizeof(int*)*Arow);
        for(int i=0;i<Arow;i++)
        {
            addmatrix[i]=(int*)malloc(sizeof(int)*Acolumn);
        }//A와 B를 더한 행렬을 저장하기 위한 addmatrix 선언과 동적할당
        for(int i=0;i<Arow;i++)
        {
            for(int q=0;q<Acolumn;q++)
            {
                addmatrix[i][q]=Amatrix[i][q]+Bmatrix[i][q];
            }
        }//addmatrix 에 A+B 넣기
        printf("A+B\n");
        print_matrix(Arow,Acolumn,addmatrix);//addmatrix 출력
        free_matrix(Arow,Acolumn,addmatrix);//addmatrix free
    }
    else{
        printf("A and B have different numbers of rows and columns, so matrix addition cannot be performed.\n");//A와 B의 행과 열이 다른 경우 오류 출력.
    }
}
void subtraction_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix)
{
    if(Arow==Brow&&Acolumn==Bcolumn)
    {
        int **submatrix;
        submatrix = (int**)malloc(sizeof(int*)*Arow);
        for(int i=0;i<Arow;i++)
        {
            submatrix[i]=(int*)malloc(sizeof(int)*Acolumn);
        }//A와 B를 뺀 행렬을 저장하기 위한 submatrix 선언과 동적할당
        for(int i=0;i<Arow;i++)
        {
            for(int q=0;q<Acolumn;q++)
            {
                submatrix[i][q]=Amatrix[i][q]-Bmatrix[i][q];
            }
        }//submatrix 에 A-B 넣기
        printf("A-B\n");
        print_matrix(Arow,Acolumn,submatrix);//submatrix 출력
        free_matrix(Arow,Acolumn,submatrix);//submatrix free
    }
    else{
        printf("A and B have different numbers of rows and columns, so matrix subtraction cannot be performed.\n");////A와 B의 행과 열이 다른 경우 오류 출력.
    }
}
void transpose_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix)
{
    int **tpAmatrix;
        tpAmatrix = (int**)malloc(sizeof(int*)*Acolumn);
        for(int i=0;i<Acolumn;i++)
        {
            tpAmatrix[i]=(int*)malloc(sizeof(int)*Arow);
        }//A를 전치한 값을 저장할 행렬을 만들기 위해 이중 포인터 tpAmatrix 선언과 동적할당
    for(int i=0;i<Arow;i++)
    {
        for(int q=0;q<Acolumn;q++)
        {
            tpAmatrix[q][i] = Amatrix[i][q]; 
        }
    }//A를 전지한 값을 tpAmatrix에 집어넣기
    printf("Transpose of A\n");
    print_matrix(Acolumn,Arow,tpAmatrix);//tpAmatrix 출력
    free_matrix(Acolumn,Arow,tpAmatrix);//tpAmatrix free
    int **tpBmatrix;
        tpBmatrix = (int**)malloc(sizeof(int*)*Bcolumn);
        for(int i=0;i<Bcolumn;i++)
        {
            tpBmatrix[i]=(int*)malloc(sizeof(int)*Brow);
        }//B를 전치한 값을 저장할 행렬을 만들기 위해 이중 포인터 tpBmatrix 선언과 동적할당
    for(int i=0;i<Brow;i++)
    {
        for(int q=0;q<Bcolumn;q++)
        {
            tpBmatrix[q][i] = Bmatrix[i][q]; 
        }
    }//B를 전지한 값을 tpBmatrix에 집어넣기
    printf("Transpose of B\n");
    print_matrix(Bcolumn,Brow,tpBmatrix);//tpBmatrix 출력
    free_matrix(Bcolumn,Brow,tpBmatrix);//tpBmatrix free
}
void multiply_matrix(int Arow,int Acolumn,int **Amatrix,int Brow,int Bcolumn,int **Bmatrix){
    if(Acolumn==Brow)
    {
        int **mulmatrix;
        mulmatrix = (int**)malloc(sizeof(int*)*Arow);
        for(int i=0;i<Arow;i++)
        {
            mulmatrix[i]=(int*)malloc(sizeof(int)*Bcolumn);
        }//A*B 값을 저장할 행렬을 위해 이중포인터 mulmatrix 선언, 동적배열
        for(int i=0;i<Arow;i++)
        {
            for(int q=0;q<Bcolumn;q++)
            {
                for(int k=0;k<Acolumn;k++)
                {
                    mulmatrix[i][q] += Amatrix[i][k]*Bmatrix[k][q];
                }
            }
        }//A*B 값을 mulmatrix 에 대입
        printf("A*B\n");
        print_matrix(Arow,Bcolumn,mulmatrix);//mulmatrix 출력
        free_matrix(Arow,Bcolumn,mulmatrix);//mulmatrix free
    }
    else{
        printf("The number of columns in A does not match the number of rows in B, so matrix multiplication cannot be performed.\n");//A의 열과 B의 행이 같지 않을 경우 오류 출력
    }
}
void free_matrix(int row,int column,int **matrix)//동적할당한 2차원 배열 해체
{
    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}