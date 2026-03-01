// QUESTAO 11

/*#include <stdio.h>
#include <stdlib.h>

int maior(int *v, int n);
int menor(int *v, int n);

int main() {
    int n;
    printf("Digite a quantidade de valores para guardar no vetor: \n");
    scanf("%d", &n);

    int *v = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) { 
        printf("Digite o valor do vetor %d: ",i+1);
        scanf("%d",&v[i]); 
    }

    printf("O maior valor dos vetores: %d\n",maior(v,n));
    printf("O menor valor dos vetores: %d\n",menor(v,n));


}


int maior(int *v, int n) {
    int maior = v[0];
    for(int i = 1 ; i < n; i++) 
        if (maior < v[i])
            maior = v[i];
    return maior;
}

int menor(int *v, int n) {
    int menor = v[0];
    for(int i = 0; i < n; i++)
        if(menor > v[i])
            menor = v[i];
    return menor;
}*/



// QUESTAO 12 
/* #include<stdio.h>
#include<stdlib.h>

float media(float* v, int n);
void leVetor(float* v, int n);
int acimaMedia(float* v, int n);

int main() {

    int n;
    printf("Digite a quantidade de valores para guardar no vetor: ");
    scanf("%d\n", &n);

    float *nums = (float*)malloc(n*sizeof(float));

    leVetor(nums, n);
    printf("Aqui esta a media dos numeros: %.2f\n",media(nums,n));
    printf("Quantidade de valores acima da media: %d", acimaMedia(nums,n));
    
}
void leVetor(float *v , int n) {
    for( int i = 0; i < n; i++) { 
        printf("Digite o valor do vetor %d: ",i+1);
        scanf("%f",&v[i]); 
    }

}

float media(float *v , int n) {
    float soma = 0;
    for(int i = 0; i < n ; i++)
        soma += v[i];
    float media = soma/(float)n;

    return media;

}

int acimaMedia(float *v , int n) {
    int cont = 0;
    for( int i = 0; i < n; i++) 
        if(v[i] > media(v,n))
            cont++;
    return cont;
} */

// QUESTAO 13

/*#include<stdio.h>
#include<stdlib.h>

float *leVetor(int n);
void verificaAloc(float *m);
void imprimeVetor(float *m,int n);
float produtoEscalar(float *m ,float *v,  int n);

int main() {
    int n;
    printf("Digite a quantidade de valores para guardar no vetor: ");
    scanf("%d", &n);

    float *m = leVetor(n);
    float *v = leVetor(n);
    printf("Imprimindo primeiro vetor: \n");
    imprimeVetor(m,n);
    printf("Imprimindo primeiro vetor: \n");
    imprimeVetor(v,n);
    printf("Aqui esta o produto escalar dos vetores: %.2f\n",produtoEscalar(m,v,n));

    return 0;
}

float *leVetor(int n) {
    float *m = (float*)malloc(n*sizeof(float));
    verificaAloc(m);

    for(int i = 0; i< n; i++) {
        printf("Digite o valor para guardar no vetor na posição %d: ",i+1);
        scanf("%f",&m[i]);
    }

    return m;
}

void verificaAloc(float *m) {    
    if(!m){
        printf("\nNão temos mais memória...");
        exit(1);
    }
}

void imprimeVetor(float *m,int n) {
    for(int i = 0 ; i < n; i++)
        printf("%.2f\n",m[i]);
}

float produtoEscalar(float *m ,float *v,  int n) {
    float aux = 0;
    for(int i = 0; i < n; i++) {
        aux += v[i] * m[i];
    }

    return aux;
}*/

// QUESTAO 15
#include <stdio.h>
#include <stdlib.h>

float *leVetor(int n);
float *vetorInterc(float *v1, int n1, float *v2, int n2);
void imprimirVetor(float *v , int n);
float *inversVector(float *v , int n);
float *positivoVector(float *v , int n);
float* somaVetor(float* v1 , float* v2 ,int n1 , int n2, int n);

int main() {
    int n1 =3;
    int n2 = 4;

    float *v1 = leVetor(n1);
    float *v2 = leVetor(n2);

    float *v3 = vetorInterc(v1 , n1, v2 , n2);
    printf("Imprimindo vetor: \n");
    imprimirVetor(v3,n1 + n2);

    float* s = somaVetor(v1, v2 , n1 , n2, n1+n2);
    float* i = inversVector(v1,n1);
    float* p = positivoVetor(v2,n2);
    
    free(v1);
    free(v2);
    free(v3);

    return 0;


}

float *leVetor(int n) {
    float *m = (float*)malloc(n*sizeof(float));
    verificaAloc(m);

    for(int i = 0; i< n; i++) {
        printf("Digite o valor para guardar no vetor na posição %d: ",i+1);
        scanf("%f",&m[i]);
    }

    return m;
}

float *vetorInterc(float *v1 ,int n1, float *v2, int n2) {
    int n3 = n1 + n2;
    float *v3 = (float*)malloc(n3*sizeof(float));
    verificaAloc(v3);
     
    int i = 0 , j = 0 , k = 0;

    while (i < n1 && j < n2) {
        v3[k++] = v1[i++];
        v3[k++] = v2[j++];
    }

    while (i < n1) {
        v3[k++] = v1[i++];
    }

    while (j < n2) {
        v3[k++] = v2[j++];
    }

    return v3;

}

void verificaAloc(float *m) {    
    if(!m){
        printf("\nNão temos mais memória...");
        exit(1);
    }
}

void imprimirVetor(float *v,int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", v[i]);
    printf("\n");
}


// FUNÇÃO QUESTAO 16

float *inversVector(float *v, int n) {
    float *novo = (float*)malloc(n*sizeof(float));
    verificaAloc(novo);

    for(int i = 0; i < n; i++)
        novo[i] = v[n-i-1];
    
    return novo;
}

// QUESTAO 18

float *positivoVetor(float* v , int n) {
    float *novo = (float*)malloc(n*sizeof(float));
    verificaAloc(novo);

    int i,j , cont = 0;

    for(i = 0 ; i < n; i++)
        if(v[i] > 0)
        cont++;
    
    for(i = 0 ; i < n; i++) {
        if(v[i] > 0) {
            novo[j] = v[i];
            j++;
        }
    }

    return novo;
}

// QUESTAO 17

float* somaVetor(float* v1 , float* v2 ,int n1 , int n2, int n) {
    int i;
    float* novo = (float*)malloc(n*sizeof(float));
    verificaAloc(n);

    for (i = 0; i < n ; i++) {
        float valor1 = (i < n1) ? v1[i] : 0.0;
        float valor2 = (i < n2) ? v2[i] : 0.0;

        novo[i] = valor1 + valor2;
    }

    return novo;
}

// ARRAYS UNIDIMENSIONAIS
