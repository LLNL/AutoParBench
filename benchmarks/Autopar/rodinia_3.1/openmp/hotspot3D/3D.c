#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h> 
#include <math.h> 
#include <sys/time.h>
#include <string.h>
#define STR_SIZE (256)
#define MAX_PD	(3.0e6)
/* required precision in degrees	*/
#define PRECISION	0.001
#define SPEC_HEAT_SI 1.75e6
#define K_SI 100
/* capacitance fitting factor	*/
#define FACTOR_CHIP	0.5
/* chip parameters	*/
#include <omp.h> 
float t_chip = 0.0005;
float chip_height = 0.016;
float chip_width = 0.016;
/* ambient temperature, assuming no package at all	*/
float amb_temp = 80.0;

void fatal(char *s)
{
  fprintf(stderr,"Error: %s\n",s);
}

void readinput(float *vect,int grid_rows,int grid_cols,int layers,char *file)
{
  int i;
  int j;
  int k;
  FILE *fp;
  char str[256];
  float val;
  if ((fp = fopen(file,"r")) == 0) 
    fatal("The file was not opened");
  for (i = 0; i <= grid_rows - 1; i += 1) {
    for (j = 0; j <= grid_cols - 1; j += 1) {
      for (k = 0; k <= layers - 1; k += 1) {
        if (fgets(str,256,fp) == ((void *)0)) 
          fatal("Error reading file\n");
        if (feof(fp)) 
          fatal("not enough lines in file");
        if (sscanf(str,"%f",&val) != 1) 
          fatal("invalid file format");
        vect[i * grid_cols + j + k * grid_rows * grid_cols] = val;
      }
    }
  }
  fclose(fp);
}

void writeoutput(float *vect,int grid_rows,int grid_cols,int layers,char *file)
{
  int i;
  int j;
  int k;
  int index = 0;
  FILE *fp;
  char str[256];
  if ((fp = fopen(file,"w")) == 0) 
    printf("The file was not opened\n");
  for (i = 0; i <= grid_rows - 1; i += 1) {
    for (j = 0; j <= grid_cols - 1; j += 1) {
      for (k = 0; k <= layers - 1; k += 1) {
        sprintf(str,"%d\t%g\n",index,vect[i * grid_cols + j + k * grid_rows * grid_cols]);
        fputs(str,fp);
        index++;
      }
    }
  }
  fclose(fp);
}

void computeTempCPU(float *pIn,float *tIn,float *tOut,int nx,int ny,int nz,float Cap,float Rx,float Ry,float Rz,float dt,int numiter)
{
  float ce;
  float cw;
  float cn;
  float cs;
  float ct;
  float cb;
  float cc;
  float stepDivCap = dt / Cap;
  ce = cw = stepDivCap / Rx;
  cn = cs = stepDivCap / Ry;
  ct = cb = stepDivCap / Rz;
  cc = (1.0 - (2.0 * ce + 2.0 * cn + 3.0 * ct));
  int c;
  int w;
  int e;
  int n;
  int s;
  int b;
  int t;
  int x;
  int y;
  int z;
  int i = 0;
  do {
    for (z = 0; z <= nz - 1; z += 1) {
      for (y = 0; y <= ny - 1; y += 1) {
        for (x = 0; x <= nx - 1; x += 1) {
          c = x + y * nx + z * nx * ny;
          w = (x == 0?c : c - 1);
          e = (x == nx - 1?c : c + 1);
          n = (y == 0?c : c - nx);
          s = (y == ny - 1?c : c + nx);
          b = (z == 0?c : c - nx * ny);
          t = (z == nz - 1?c : c + nx * ny);
          tOut[c] = tIn[c] * cc + tIn[n] * cn + tIn[s] * cs + tIn[e] * ce + tIn[w] * cw + tIn[t] * ct + tIn[b] * cb + dt / Cap * pIn[c] + ct * amb_temp;
        }
      }
    }
    float *temp = tIn;
    tIn = tOut;
    tOut = temp;
    i++;
  }while (i < numiter);
}

float accuracy(float *arr1,float *arr2,int len)
{
  float err = 0.0;
  int i;
  
#pragma omp parallel for private (i) reduction (+:err)
  for (i = 0; i <= len - 1; i += 1) {
    err += (arr1[i] - arr2[i]) * (arr1[i] - arr2[i]);
  }
  return (float )(sqrt((err / len)));
}

void computeTempOMP(float *pIn,float *tIn,float *tOut,int nx,int ny,int nz,float Cap,float Rx,float Ry,float Rz,float dt,int numiter)
{
  float ce;
  float cw;
  float cn;
  float cs;
  float ct;
  float cb;
  float cc;
  float stepDivCap = dt / Cap;
  ce = cw = stepDivCap / Rx;
  cn = cs = stepDivCap / Ry;
  ct = cb = stepDivCap / Rz;
  cc = (1.0 - (2.0 * ce + 2.0 * cn + 3.0 * ct));
{
    int count = 0;
    float *tIn_t = tIn;
    float *tOut_t = tOut;
    printf("%d threads running\n",(omp_get_num_threads()));
    do {
      int z;
      for (z = 0; z <= nz - 1; z += 1) {
        int y;
        for (y = 0; y <= ny - 1; y += 1) {
          int x;
          for (x = 0; x <= nx - 1; x += 1) {
            int c;
            int w;
            int e;
            int n;
            int s;
            int b;
            int t;
            c = x + y * nx + z * nx * ny;
            w = (x == 0?c : c - 1);
            e = (x == nx - 1?c : c + 1);
            n = (y == 0?c : c - nx);
            s = (y == ny - 1?c : c + nx);
            b = (z == 0?c : c - nx * ny);
            t = (z == nz - 1?c : c + nx * ny);
            tOut_t[c] = cc * tIn_t[c] + cw * tIn_t[w] + ce * tIn_t[e] + cs * tIn_t[s] + cn * tIn_t[n] + cb * tIn_t[b] + ct * tIn_t[t] + dt / Cap * pIn[c] + ct * amb_temp;
          }
        }
      }
      float *t = tIn_t;
      tIn_t = tOut_t;
      tOut_t = t;
      count++;
    }while (count < numiter);
  }
  return ;
}

void usage(int argc,char **argv)
{
  fprintf(stderr,"Usage: %s <rows/cols> <layers> <iterations> <powerFile> <tempFile> <outputFile>\n",argv[0]);
  fprintf(stderr,"\t<rows/cols>  - number of rows/cols in the grid (positive integer)\n");
  fprintf(stderr,"\t<layers>  - number of layers in the grid (positive integer)\n");
  fprintf(stderr,"\t<iteration> - number of iterations\n");
  fprintf(stderr,"\t<powerFile>  - name of the file containing the initial power values of each cell\n");
  fprintf(stderr,"\t<tempFile>  - name of the file containing the initial temperature values of each cell\n");
  fprintf(stderr,"\t<outputFile - output file\n");
  exit(1);
}

int main(int argc,char **argv)
{
  if (argc != 7) {
    usage(argc,argv);
  }
// *testFile;
  char *pfile;
  char *tfile;
  char *ofile;
  int iterations = atoi(argv[3]);
  pfile = argv[4];
  tfile = argv[5];
  ofile = argv[6];
//testFile = argv[7];
  int numCols = atoi(argv[1]);
  int numRows = atoi(argv[1]);
  int layers = atoi(argv[2]);
/* calculating parameters*/
  float dx = chip_height / numRows;
  float dy = chip_width / numCols;
  float dz = t_chip / layers;
  float Cap = (0.5 * 1.75e6 * t_chip * dx * dy);
  float Rx = (dy / (2.0 * 100 * t_chip * dx));
  float Ry = (dx / (2.0 * 100 * t_chip * dy));
  float Rz = dz / (100 * dx * dy);
// cout << Rx << " " << Ry << " " << Rz << endl;
  float max_slope = (3.0e6 / (0.5 * t_chip * 1.75e6));
  float dt = (0.001 / max_slope);
// *pCopy;
  float *powerIn;
  float *tempOut;
  float *tempIn;
  float *tempCopy;
//    float *d_powerIn, *d_tempIn, *d_tempOut;
  int size = numCols * numRows * layers;
  powerIn = ((float *)(calloc(size,sizeof(float ))));
  tempCopy = ((float *)(malloc(size * sizeof(float ))));
  tempIn = ((float *)(calloc(size,sizeof(float ))));
  tempOut = ((float *)(calloc(size,sizeof(float ))));
//pCopy = (float*)calloc(size,sizeof(float));
  float *answer = (float *)(calloc(size,sizeof(float )));
// outCopy = (float*)calloc(size, sizeof(float));
  readinput(powerIn,numRows,numCols,layers,pfile);
  readinput(tempIn,numRows,numCols,layers,tfile);
  memcpy(tempCopy,tempIn,size * sizeof(float ));
  struct timeval start;
  struct timeval stop;
  float time;
  gettimeofday(&start,((void *)0));
  computeTempOMP(powerIn,tempIn,tempOut,numCols,numRows,layers,Cap,Rx,Ry,Rz,dt,iterations);
  gettimeofday(&stop,((void *)0));
  time = ((stop . tv_usec - start . tv_usec) * 1.0e-6 + stop . tv_sec - start . tv_sec);
  computeTempCPU(powerIn,tempCopy,answer,numCols,numRows,layers,Cap,Rx,Ry,Rz,dt,iterations);
  float acc = accuracy(tempOut,answer,numRows * numCols * layers);
  printf("Time: %.3f (s)\n",time);
  printf("Accuracy: %e\n",acc);
  writeoutput(tempOut,numRows,numCols,layers,ofile);
  free(tempIn);
  free(tempOut);
  free(powerIn);
  return 0;
}
