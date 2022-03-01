#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct matrix_t {
    double **mat;
    unsigned int nrow, ncol;
};

void initialize_matrix(struct matrix_t *mat,
                       unsigned int nrow,
                       unsigned int ncol)
{
    mat->nrow = nrow;
    mat->ncol = ncol;
    mat->mat = NULL;
    double *mat_content = (double *) malloc(sizeof(double) * nrow * ncol);
    mat->mat = (double **) malloc(sizeof(double *) * nrow);
    for (unsigned int i = 0; i < nrow; ++i) {
        mat->mat[i] = mat_content + i * ncol;
    }
    memset(mat_content, 0, sizeof(double) * nrow * ncol);
};

struct matrix_t matrix_mul(struct matrix_t *m1, struct matrix_t *m2)
{
    struct matrix_t res;
    if (m1->ncol != m2->nrow) {
        initialize_matrix(&res, 0, 0);
        return res;
    } else {
        initialize_matrix(&res, m1->nrow, m2->ncol);
        for (unsigned int i = 0; i < res.nrow; ++i) {
            for (unsigned int j = 0; j < res.ncol; ++j) {
                for (unsigned int k = 0; k < m1->ncol; ++k) {
                    res.mat[i][j] += m1->mat[i][k] * m2->mat[k][j];
                }
            }
        }
    }
    return res;
}

void destroy_matrix(struct matrix_t *mat)
{
    free(*mat->mat);
    free(mat->mat);
}

int main(int argc, const char *argv[])
{
    struct matrix_t mat1, mat2;
    if (argc < 2) {
        printf("Usage : ./mat_mul [dim]\n");
        exit(EXIT_FAILURE);
    }
    int dim = atoi(argv[1]);
    initialize_matrix(&mat1, dim, dim);
    initialize_matrix(&mat2, dim, dim);

    clock_t c1, c2;
    c1 = clock();
    struct matrix_t mat = matrix_mul(&mat1, &mat2);
    c2 = clock();

    printf("%d, %.3f\n", dim, (c2 - c1)/(double)CLOCKS_PER_SEC);

    
    /*
    printf(
        "Time consuming of multiplication of two matrics with dimensions are "
        "(%u, %u) and (%u, %u) is %.3f(sec)\n",
        mat1.nrow, mat1.ncol, mat2.nrow, mat2.ncol,
        (c2 - c1) / (double) CLOCKS_PER_SEC);
        */
    /*
    for(unsigned int i = 0; i < mat.nrow; ++i){
        for(unsigned int j = 0; j < mat.ncol; ++j){
            printf("%.3f ", mat.mat[i][j]);
        }
        printf("\n");
    }*/

    destroy_matrix(&mat1);
    destroy_matrix(&mat2);
    destroy_matrix(&mat);
    return 0;
}
