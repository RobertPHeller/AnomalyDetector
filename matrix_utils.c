#include <stdio.h>
#include <math.h>
#include "matrix_utils.h"

//===========================================================
// This file holds utility functions for dealing with vectors
// and matrices.  The idea is to be able to reuse common matrix
// operations.  I will name the utils analogously to their names
// in Matlab.
// In this version I make everything col major.

//-----------------------------------------------------
void print_matrix(const float* A, int m, int n) {
  // prints matrix as 2-dimensional table -- this is how we
  // usually think of matrices.  Note:  This version assumes
  // col major matrices.
   int i, j;
   for (i = 0; i < m; i++) {      // Rows
      for (j = 0; j < n; j++) {   // Cols
          printf("%8.4f ", A[i + j*m]);  // Print entire row
      }
      printf("\n");
   }
}


//-----------------------------------------------------
void print_matrix_linear(const float* A, int m, int n) {
  // Prints matrix as one long, linear object.
  int i;
  for (i = 0; i < m*n; i++) {
    printf("%8.4e\n", A[i]);
  }
}


//-----------------------------------------------------
int lindex(int m, int n, int i, int j) {
  // Function returning the linear index into matrix of
  // dimensions m, n.  The macro defined in the header file can
  // be buggy, particularly if used more than once
  // in an expression -- use this function
  // to be sure you're getting correct behavior.
  // Assumes row-major indexing (C-style).
  return j + i*n;
}


//-----------------------------------------------------
void eye(int m, int n, float *A) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        A[i*m+j] = 1.0f;
      } else {
        A[i*m+j] = 0.0f;
      }
    }
  }
}

//-----------------------------------------------------
void zeros(int m, int n, float *A) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      A[i*m+j] = 0.0f;
    }
  }
}

//-----------------------------------------------------
void linspace(float x0, float x1, int N, float *v) {
  // Returns vector v with N values from x0 to x1
  int i;
  float dx;

  dx = (x1-x0)/(N-1);
  for (i = 0; i < N; i++) {
    v[i] = x0 + i*dx;
  }
}


//-----------------------------------------------------
int maxeltf(int N, float *u) {
  // Given float vector u with N elements, return the
  // index of the largest element.
  // This is a dumb linear search O(N).  But for small N
  // it's quick and dirty.  For large N I should write a
  // binary search.
  int i, imax;
  float umax;

  umax = -INFINITY;

  for (i = 0; i < N; i++) {
    if (u[i] > umax) {
      umax = u[i];
      imax = i;
    }
  }
  return imax;
}



