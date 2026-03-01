// QUESTAO 8

/*#include <stdio.h>
#include <stdlib.h>

int l = 3;
int c = 3;
int l1 = 3;
int c1 = 3;
int l2 = 3;
int c2 = 3;

void matrizLibera(float **m, int linhas );
void matrizVerifica(float **m);
float **matrizCria(int l , int c);
void matrizLe(float **m,int l , int c);
float **matrizTrans(float **m, int l , int c);
float **matrizSoma(float **m,float **t,int l , int c);
float **matrizMultiEscalar(float **m, int l , int c , int n);
float **matrizMulti(float **m ,int l1, int c1, float **t, int l2, int c2);


int main () {

    int l = 3;
    int c = 3;
    int l1 = 3;
    int c1 = 3;
    int l2 = 3;
    int c2 = 3;
    int n =2;


    printf("INICIALIZANDO A MATRIZ COM 0.0\n");\
    float **m = matrizCria(l,c);
    matrizLe(m,l,c);

    float **t = matrizTrans(m,l,c);

    float **s = matrizSoma(m,t,l,c);

    float **u =  matrizMultieSCALAR(m,l,c,n);

    float **v = matrizCria(l,c);
    matrizLe(v,l,c);

    float **matrizMulti(m,l1,c1,v,l2,n2);

    matrizLibera(m, l);
    matrizLibera(t, c);
    matrizLibera(s, l);
    matrizLibera(u, l);
    matrizLibera(v, l);

    if (multi != NULL) {
        matrizLibera(multi, l1);
    }

    return 0;


}


//QUESTAO 08
void matrizLibera(float **m, int linhas ) {
    for(int i = 0; i < linhas; i++)
        free(m[i]);
    free(m);


}

//QUESTAO 09 ***** ALOCA INICIALIZANDO COM 0.0
float **matrizCria(int l , int c) { 
    float **m = (float**)malloc(l*sizeof(float*));   
    matrizVerifica(m);
    for(int i = 0; i < l; i++)
        m[i] = (float*)calloc(c,sizeof(float));         //(float*)malloc(c*sizeof(float))
    
    return m;


}

void matrizVerifica(float **m) {
    if (m == NULL) {
        printf("Erro na alocacao do vetor de ponteiros.\n");
        exit(1);
    }

}

// QUESTAO 10
void matrizLe(float **m,int l , int c) {
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++) {
            printf("valor %d %d: ",i+1,j+1);
            scanf("%f",&m[i][j]);
        }
    }
}

// QUESTAO 11
float **matrizTrans(float **m, int l , int c) {
    float **t = matrizCria(l ,c );
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            t[j][i] = m[i][j];

    return t;
}

//QUESTAO 12            
float **matrizSoma(float **m,float **t,int l , int c) {
    float **s = matrizCria(l,c);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            s[i][j] = m[i][j] + t[j][i];            // SOMANDO COMA  TRANSPOTA 

    return s;
}

// QUESTAO 13
float **matrizMultiEscalar(float **m, int l , int c , int n) {
    float **u = matrizCria(l,c);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            u[i][j] = n*m[i][j];
            
    return u;
}

// QUESTAO 14
float **matrizMulti(float **m ,int l1, int c1, float **t, int l2, int c2) {
    if(c1 != l2) {
        printf("Essa multiplicação nao é possivel...");
        return NULL;
    }

    float **y = matrizCria(l1, c2);         // propriedade matematica -- Se A(mxn) por B(nxp) = R(mxp)
    for(int i = 0; i < l1; i++)
        for(int j = 0; j < c2; j++)
            for(int k = 0; k < c1; k++)
                y[i][j] += m[i][k] *t[k][j];
        
    return y;

}*/

//QUESTAO 15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **matrizCria(int l, int c);
void matrizImprimi(float **m , int l , int c);
void matrizLibera(float **m, int l);
void matrizAleatoria(float **matriz, int l, int c);

int main() {
    srand(time(NULL));
    
    int l , c;
    printf("Digite o numero de linhas: ");
    scanf("%d",&l);
    printf("\nDigite o numero de colunas: ");
    scanf("%d",&c);

    float **mat = matrizCria(l,c);
    printf("...");
    matrizAleatoria(mat,l,c);
    matrizImprimi(mat,l,c);
    matrizLibera(mat,l);

    return 0;
    
}

float **matrizCria(int l , int c) {
    float **mat = (float**)malloc(l*sizeof(float*));
    if(!mat) {
        printf("Nao foi possivel alocar as linhas...");
        exit(1);
    }
    for(int i = 0; i < l; i++) 
        mat[i] = (float*)calloc(c,sizeof(float));
    return mat;
}


void matrizAleatoria(float **mat, int l, int c) {
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            mat[i][j] = (float)(rand() % 10);
}

void matrizImprimi(float **mat, int l , int c) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void matrizLibera(float **mat, int l ) {
    if (mat == NULL) {
        printf("matriz vazia...");
        exit(2);
    }


    for(int i = 0; i < l; i++)

        free(mat[i]);
    
    free(mat);
}




// ARRAYS BIDIMENSIONAIS