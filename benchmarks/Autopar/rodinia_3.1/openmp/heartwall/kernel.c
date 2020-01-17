//===============================================================================================================================================================================================================
//===============================================================================================================================================================================================================
//	KERNEL FUNCTION
//===============================================================================================================================================================================================================
//===============================================================================================================================================================================================================
#include "define.c"
#include <omp.h> 

void kernel(public_struct public,private_struct private)
{
//======================================================================================================================================================
//	COMMON VARIABLES
//======================================================================================================================================================
  int ei_new;
  float *d_in;
  int rot_row;
  int rot_col;
  int in2_rowlow;
  int in2_collow;
  int ic;
  int jc;
  int jp1;
  int ja1;
  int ja2;
  int ip1;
  int ia1;
  int ia2;
  int ja;
  int jb;
  int ia;
  int ib;
  float s;
  int i;
  int j;
  int row;
  int col;
  int ori_row;
  int ori_col;
  int position;
  float sum;
  int pos_ori;
  float temp;
  float temp2;
  int location;
  int cent;
  int tMask_row;
  int tMask_col;
  float largest_value_current = 0;
  float largest_value = 0;
  int largest_coordinate_current = 0;
  int largest_coordinate = 0;
  float fin_max_val = 0;
  int fin_max_coo = 0;
  int largest_row;
  int largest_col;
  int offset_row;
  int offset_col;
  float in_final_sum;
  float in_sqr_final_sum;
  float mean;
  float mean_sqr;
  float variance;
  float deviation;
  float denomT;
  int pointer;
  int ori_pointer;
  int loc_pointer;
  int ei_mod;
//======================================================================================================================================================
//	GENERATE TEMPLATE
//======================================================================================================================================================
// generate templates based on the first frame only
  if (public . frame_no == 0) {
// update temporary row/col coordinates
    pointer = private . point_no * public . frames + public . frame_no;
    private . d_tRowLoc[pointer] = private . d_Row[private . point_no];
    private . d_tColLoc[pointer] = private . d_Col[private . point_no];
// pointers to: current frame, template for current point
    d_in = &private . d_T[private . in_pointer];
// update template, limit the number of working threads to the size of template
    for (col = 0; col <= public . in_mod_cols - 1; col += 1) {
      for (row = 0; row <= public . in_mod_rows - 1; row += 1) {
// figure out row/col location in corresponding new template area in image and give to every thread (get top left corner and progress down and right)
        ori_row = private . d_Row[private . point_no] - 25 + row - 1;
        ori_col = private . d_Col[private . point_no] - 25 + col - 1;
        ori_pointer = ori_col * public . frame_rows + ori_row;
// update template
        d_in[col * public . in_mod_rows + row] = public . d_frame[ori_pointer];
      }
    }
  }
//======================================================================================================================================================
//	PROCESS POINTS
//======================================================================================================================================================
// process points in all frames except for the first one
  if (public . frame_no != 0) {
//====================================================================================================
//	INPUTS
//====================================================================================================
//==================================================
//	1) SETUP POINTER TO POINT TO CURRENT FRAME FROM BATCH
//	2) SELECT INPUT 2 (SAMPLE AROUND POINT) FROM FRAME			SAVE IN d_in2			(NOT LINEAR IN MEMORY, SO NEED TO SAVE OUTPUT FOR LATER EASY USE)
//	3) SQUARE INPUT 2									SAVE IN d_in2_sqr
//==================================================
// pointers and variables
// (1 to n+1)
    in2_rowlow = private . d_Row[private . point_no] - public . sSize;
    in2_collow = private . d_Col[private . point_no] - public . sSize;
// work
    for (col = 0; col <= public . in2_cols - 1; col += 1) {
      for (row = 0; row <= public . in2_rows - 1; row += 1) {
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + in2_rowlow - 1;
        ori_col = col + in2_collow - 1;
        temp = public . d_frame[ori_col * public . frame_rows + ori_row];
        private . d_in2[col * public . in2_rows + row] = temp;
        private . d_in2_sqr[col * public . in2_rows + row] = temp * temp;
      }
    }
//==================================================
//	1) GET POINTER TO INPUT 1 (TEMPLATE FOR THIS POINT) IN TEMPLATE ARRAY				(LINEAR IN MEMORY, SO DONT NEED TO SAVE, JUST GET POINTER)
//	2) ROTATE INPUT 1									SAVE IN d_in_mod
//	3) SQUARE INPUT 1									SAVE IN d_in_sqr
//==================================================
// variables
    d_in = &private . d_T[private . in_pointer];
// work
    for (col = 0; col <= public . in_mod_cols - 1; col += 1) {
      for (row = 0; row <= public . in_mod_rows - 1; row += 1) {
// rotated coordinates
        rot_row = public . in_mod_rows - 1 - row;
        rot_col = public . in_mod_rows - 1 - col;
        pointer = rot_col * public . in_mod_rows + rot_row;
// execution
        temp = d_in[pointer];
        private . d_in_mod[col * public . in_mod_rows + row] = temp;
        private . d_in_sqr[pointer] = temp * temp;
      }
    }
//==================================================
//	1) GET SUM OF INPUT 1
//	2) GET SUM OF INPUT 1 SQUARED
//==================================================
    in_final_sum = 0;
    
#pragma omp parallel for private (i) reduction (+:in_final_sum)
    for (i = 0; i <= public . in_mod_elem - 1; i += 1) {
      in_final_sum = in_final_sum + d_in[i];
    }
    in_sqr_final_sum = 0;
    
#pragma omp parallel for private (i) reduction (+:in_sqr_final_sum)
    for (i = 0; i <= public . in_mod_elem - 1; i += 1) {
      in_sqr_final_sum = in_sqr_final_sum + private . d_in_sqr[i];
    }
//==================================================
//	3) DO STATISTICAL CALCULATIONS
//	4) GET DENOMINATOR T
//==================================================
// gets mean (average) value of element in ROI
    mean = in_final_sum / public . in_mod_elem;
    mean_sqr = mean * mean;
// gets variance of ROI
    variance = in_sqr_final_sum / public . in_mod_elem - mean_sqr;
// gets standard deviation of ROI
    deviation = (sqrt(variance));
    denomT = (sqrt(((float )(public . in_mod_elem - 1)))) * deviation;
//====================================================================================================
//	1) CONVOLVE INPUT 2 WITH ROTATED INPUT 1					SAVE IN d_conv
//====================================================================================================
// work
    for (col = 1; col <= public . conv_cols; col += 1) {
// column setup
      j = col + public . joffset;
      jp1 = j + 1;
      if (public . in2_cols < jp1) {
        ja1 = jp1 - public . in2_cols;
      }
       else {
        ja1 = 1;
      }
      if (public . in_mod_cols < j) {
        ja2 = public . in_mod_cols;
      }
       else {
        ja2 = j;
      }
      for (row = 1; row <= public . conv_rows; row += 1) {
// row range setup
        i = row + public . ioffset;
        ip1 = i + 1;
        if (public . in2_rows < ip1) {
          ia1 = ip1 - public . in2_rows;
        }
         else {
          ia1 = 1;
        }
        if (public . in_mod_rows < i) {
          ia2 = public . in_mod_rows;
        }
         else {
          ia2 = i;
        }
        s = 0;
// getting data
        
#pragma omp parallel for private (jb,ib,ja,ia) reduction (+:s) firstprivate (jp1,ia1,ia2)
        for (ja = ja1; ja <= ja2; ja += 1) {
          jb = jp1 - ja;
          
#pragma omp parallel for private (ib,ia) reduction (+:s) firstprivate (ip1,jb)
          for (ia = ia1; ia <= ia2; ia += 1) {
            ib = ip1 - ia;
            s = s + private . d_in_mod[public . in_mod_rows * (ja - 1) + ia - 1] * private . d_in2[public . in2_rows * (jb - 1) + ib - 1];
          }
        }
        private . d_conv[(col - 1) * public . conv_rows + (row - 1)] = s;
      }
    }
//====================================================================================================
//	LOCAL SUM 1
//====================================================================================================
//==================================================
//	1) PADD ARRAY										SAVE IN d_in2_pad
//==================================================
// work
    for (col = 0; col <= public . in2_pad_cols - 1; col += 1) {
      for (row = 0; row <= public . in2_pad_rows - 1; row += 1) {
// execution
// do if has numbers in original array
        if (row > public . in2_pad_add_rows - 1 && row < public . in2_pad_add_rows + public . in2_rows && col > public . in2_pad_add_cols - 1 && col < public . in2_pad_add_cols + public . in2_cols) {
          ori_row = row - public . in2_pad_add_rows;
          ori_col = col - public . in2_pad_add_cols;
          private . d_in2_pad[col * public . in2_pad_rows + row] = private . d_in2[ori_col * public . in2_rows + ori_row];
        }
         else 
// do if otherwise
{
          private . d_in2_pad[col * public . in2_pad_rows + row] = 0;
        }
      }
    }
//==================================================
//	1) GET VERTICAL CUMULATIVE SUM						SAVE IN d_in2_pad
//==================================================
    
#pragma omp parallel for private (sum,pos_ori,ei_new,position)
    for (ei_new = 0; ei_new <= public . in2_pad_cols - 1; ei_new += 1) {
// figure out column position
      pos_ori = ei_new * public . in2_pad_rows;
// loop through all rows
      sum = 0;
      
#pragma omp parallel for private (position) firstprivate (pos_ori)
      for (position = pos_ori; position <= pos_ori + public . in2_pad_rows - 1; position = position + 1) {
        private . d_in2_pad[position] = private . d_in2_pad[position] + sum;
        sum = private . d_in2_pad[position];
      }
    }
//==================================================
//	1) MAKE 1st SELECTION FROM VERTICAL CUMULATIVE SUM
//	2) MAKE 2nd SELECTION FROM VERTICAL CUMULATIVE SUM
//	3) SUBTRACT THE TWO SELECTIONS						SAVE IN d_in2_sub
//==================================================
// work
    for (col = 0; col <= public . in2_sub_cols - 1; col += 1) {
      for (row = 0; row <= public . in2_sub_rows - 1; row += 1) {
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_pad_cumv_sel_rowlow - 1;
        ori_col = col + public . in2_pad_cumv_sel_collow - 1;
        temp = private . d_in2_pad[ori_col * public . in2_pad_rows + ori_row];
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_pad_cumv_sel2_rowlow - 1;
        ori_col = col + public . in2_pad_cumv_sel2_collow - 1;
        temp2 = private . d_in2_pad[ori_col * public . in2_pad_rows + ori_row];
// subtraction
        private . d_in2_sub[col * public . in2_sub_rows + row] = temp - temp2;
      }
    }
//==================================================
//	1) GET HORIZONTAL CUMULATIVE SUM						SAVE IN d_in2_sub
//==================================================
    
#pragma omp parallel for private (sum,pos_ori,ei_new,position)
    for (ei_new = 0; ei_new <= public . in2_sub_rows - 1; ei_new += 1) {
// figure out row position
      pos_ori = ei_new;
// loop through all rows
      sum = 0;
      
#pragma omp parallel for private (position) firstprivate (pos_ori)
      for (position = pos_ori; position <= pos_ori + public . in2_sub_elem - 1; position = position + public . in2_sub_rows) {
        private . d_in2_sub[position] = private . d_in2_sub[position] + sum;
        sum = private . d_in2_sub[position];
      }
    }
//==================================================
//	1) MAKE 1st SELECTION FROM HORIZONTAL CUMULATIVE SUM
//	2) MAKE 2nd SELECTION FROM HORIZONTAL CUMULATIVE SUM
//	3) SUBTRACT THE TWO SELECTIONS TO GET LOCAL SUM 1
//	4) GET CUMULATIVE SUM 1 SQUARED						SAVE IN d_in2_sub2_sqr
//	5) GET NUMERATOR									SAVE IN d_conv
//==================================================
// work
    for (col = 0; col <= public . in2_sub2_sqr_cols - 1; col += 1) {
      for (row = 0; row <= public . in2_sub2_sqr_rows - 1; row += 1) {
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_sub_cumh_sel_rowlow - 1;
        ori_col = col + public . in2_sub_cumh_sel_collow - 1;
        temp = private . d_in2_sub[ori_col * public . in2_sub_rows + ori_row];
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_sub_cumh_sel2_rowlow - 1;
        ori_col = col + public . in2_sub_cumh_sel2_collow - 1;
        temp2 = private . d_in2_sub[ori_col * public . in2_sub_rows + ori_row];
// subtraction
        temp2 = temp - temp2;
// squaring
        private . d_in2_sub2_sqr[col * public . in2_sub2_sqr_rows + row] = temp2 * temp2;
// numerator
        private . d_conv[col * public . in2_sub2_sqr_rows + row] = private . d_conv[col * public . in2_sub2_sqr_rows + row] - temp2 * in_final_sum / public . in_mod_elem;
      }
    }
//====================================================================================================
//	LOCAL SUM 2
//====================================================================================================
//==================================================
//	1) PAD ARRAY										SAVE IN d_in2_pad
//==================================================
// work
    for (col = 0; col <= public . in2_pad_cols - 1; col += 1) {
      for (row = 0; row <= public . in2_pad_rows - 1; row += 1) {
// execution
// do if has numbers in original array
        if (row > public . in2_pad_add_rows - 1 && row < public . in2_pad_add_rows + public . in2_rows && col > public . in2_pad_add_cols - 1 && col < public . in2_pad_add_cols + public . in2_cols) {
          ori_row = row - public . in2_pad_add_rows;
          ori_col = col - public . in2_pad_add_cols;
          private . d_in2_pad[col * public . in2_pad_rows + row] = private . d_in2_sqr[ori_col * public . in2_rows + ori_row];
        }
         else 
// do if otherwise
{
          private . d_in2_pad[col * public . in2_pad_rows + row] = 0;
        }
      }
    }
//==================================================
//	2) GET VERTICAL CUMULATIVE SUM						SAVE IN d_in2_pad
//==================================================
//work
    
#pragma omp parallel for private (sum,pos_ori,ei_new,position)
    for (ei_new = 0; ei_new <= public . in2_pad_cols - 1; ei_new += 1) {
// figure out column position
      pos_ori = ei_new * public . in2_pad_rows;
// loop through all rows
      sum = 0;
      
#pragma omp parallel for private (position) firstprivate (pos_ori)
      for (position = pos_ori; position <= pos_ori + public . in2_pad_rows - 1; position = position + 1) {
        private . d_in2_pad[position] = private . d_in2_pad[position] + sum;
        sum = private . d_in2_pad[position];
      }
    }
//==================================================
//	1) MAKE 1st SELECTION FROM VERTICAL CUMULATIVE SUM
//	2) MAKE 2nd SELECTION FROM VERTICAL CUMULATIVE SUM
//	3) SUBTRACT THE TWO SELECTIONS						SAVE IN d_in2_sub
//==================================================
// work
    for (col = 0; col <= public . in2_sub_cols - 1; col += 1) {
      for (row = 0; row <= public . in2_sub_rows - 1; row += 1) {
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_pad_cumv_sel_rowlow - 1;
        ori_col = col + public . in2_pad_cumv_sel_collow - 1;
        temp = private . d_in2_pad[ori_col * public . in2_pad_rows + ori_row];
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_pad_cumv_sel2_rowlow - 1;
        ori_col = col + public . in2_pad_cumv_sel2_collow - 1;
        temp2 = private . d_in2_pad[ori_col * public . in2_pad_rows + ori_row];
// subtract
        private . d_in2_sub[col * public . in2_sub_rows + row] = temp - temp2;
      }
    }
//==================================================
//	1) GET HORIZONTAL CUMULATIVE SUM						SAVE IN d_in2_sub
//==================================================
    
#pragma omp parallel for private (sum,pos_ori,ei_new,position)
    for (ei_new = 0; ei_new <= public . in2_sub_rows - 1; ei_new += 1) {
// figure out row position
      pos_ori = ei_new;
// loop through all rows
      sum = 0;
      
#pragma omp parallel for private (position) firstprivate (pos_ori)
      for (position = pos_ori; position <= pos_ori + public . in2_sub_elem - 1; position = position + public . in2_sub_rows) {
        private . d_in2_sub[position] = private . d_in2_sub[position] + sum;
        sum = private . d_in2_sub[position];
      }
    }
//==================================================
//	1) MAKE 1st SELECTION FROM HORIZONTAL CUMULATIVE SUM
//	2) MAKE 2nd SELECTION FROM HORIZONTAL CUMULATIVE SUM
//	3) SUBTRACT THE TWO SELECTIONS TO GET LOCAL SUM 2
//	4) GET DIFFERENTIAL LOCAL SUM
//	5) GET DENOMINATOR A
//	6) GET DENOMINATOR
//	7) DIVIDE NUMBERATOR BY DENOMINATOR TO GET CORRELATION	SAVE IN d_conv
//==================================================
// work
    for (col = 0; col <= public . conv_cols - 1; col += 1) {
      for (row = 0; row <= public . conv_rows - 1; row += 1) {
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_sub_cumh_sel_rowlow - 1;
        ori_col = col + public . in2_sub_cumh_sel_collow - 1;
        temp = private . d_in2_sub[ori_col * public . in2_sub_rows + ori_row];
// figure out corresponding location in old matrix and copy values to new matrix
        ori_row = row + public . in2_sub_cumh_sel2_rowlow - 1;
        ori_col = col + public . in2_sub_cumh_sel2_collow - 1;
        temp2 = private . d_in2_sub[ori_col * public . in2_sub_rows + ori_row];
// subtract
        temp2 = temp - temp2;
// diff_local_sums
        temp2 = temp2 - private . d_in2_sub2_sqr[col * public . conv_rows + row] / public . in_mod_elem;
// denominator A
        if (temp2 < 0) {
          temp2 = 0;
        }
        temp2 = (sqrt(temp2));
// denominator
        temp2 = denomT * temp2;
// correlation
        private . d_conv[col * public . conv_rows + row] = private . d_conv[col * public . conv_rows + row] / temp2;
      }
    }
//====================================================================================================
//	TEMPLATE MASK CREATE
//====================================================================================================
// parameters
    cent = public . sSize + public . tSize + 1;
    pointer = public . frame_no - 1 + private . point_no * public . frames;
    tMask_row = cent + private . d_tRowLoc[pointer] - private . d_Row[private . point_no] - 1;
    tMask_col = cent + private . d_tColLoc[pointer] - private . d_Col[private . point_no] - 1;
//work
    
#pragma omp parallel for private (ei_new)
    for (ei_new = 0; ei_new <= public . tMask_elem - 1; ei_new += 1) {
      private . d_tMask[ei_new] = 0;
    }
    private . d_tMask[tMask_col * public . tMask_rows + tMask_row] = 1;
//====================================================================================================
//	1) MASK CONVOLUTION
//	2) MULTIPLICATION
//====================================================================================================
// work
// for(col=1; col<=public.conv_cols; col++){
    for (col = 1; col <= public . mask_conv_cols; col += 1) {
// col setup
      j = col + public . mask_conv_joffset;
      jp1 = j + 1;
      if (public . mask_cols < jp1) {
        ja1 = jp1 - public . mask_cols;
      }
       else {
        ja1 = 1;
      }
      if (public . tMask_cols < j) {
        ja2 = public . tMask_cols;
      }
       else {
        ja2 = j;
      }
// for(row=1; row<=public.conv_rows; row++){
      for (row = 1; row <= public . mask_conv_rows; row += 1) {
// row setup
        i = row + public . mask_conv_ioffset;
        ip1 = i + 1;
        if (public . mask_rows < ip1) {
          ia1 = ip1 - public . mask_rows;
        }
         else {
          ia1 = 1;
        }
        if (public . tMask_rows < i) {
          ia2 = public . tMask_rows;
        }
         else {
          ia2 = i;
        }
        s = 0;
// get data
        
#pragma omp parallel for private (jb,ib,ja,ia) reduction (+:s) firstprivate (jp1,ia1,ia2)
        for (ja = ja1; ja <= ja2; ja += 1) {
          jb = jp1 - ja;
          
#pragma omp parallel for private (ib,ia) reduction (+:s) firstprivate (ip1)
          for (ia = ia1; ia <= ia2; ia += 1) {
            ib = ip1 - ia;
            s = s + private . d_tMask[public . tMask_rows * (ja - 1) + ia - 1] * 1;
          }
        }
        private . d_mask_conv[(col - 1) * public . conv_rows + (row - 1)] = private . d_conv[(col - 1) * public . conv_rows + (row - 1)] * s;
      }
    }
//====================================================================================================
//	MAXIMUM VALUE
//====================================================================================================
//==================================================
//	SEARCH
//==================================================
    fin_max_val = 0;
    fin_max_coo = 0;
    for (i = 0; i <= public . mask_conv_elem - 1; i += 1) {
      if (private . d_mask_conv[i] > fin_max_val) {
        fin_max_val = private . d_mask_conv[i];
        fin_max_coo = i;
      }
    }
//==================================================
//	OFFSET
//==================================================
// convert coordinate to row/col form
// (0-n) row
    largest_row = (fin_max_coo + 1) % public . mask_conv_rows - 1;
// (0-n) column
    largest_col = (fin_max_coo + 1) / public . mask_conv_rows;
    if ((fin_max_coo + 1) % public . mask_conv_rows == 0) {
      largest_row = public . mask_conv_rows - 1;
      largest_col = largest_col - 1;
    }
// calculate offset
// compensate to match MATLAB format (1-n)
    largest_row = largest_row + 1;
// compensate to match MATLAB format (1-n)
    largest_col = largest_col + 1;
    offset_row = largest_row - public . in_mod_rows - (public . sSize - public . tSize);
    offset_col = largest_col - public . in_mod_cols - (public . sSize - public . tSize);
    pointer = private . point_no * public . frames + public . frame_no;
    private . d_tRowLoc[pointer] = private . d_Row[private . point_no] + offset_row;
    private . d_tColLoc[pointer] = private . d_Col[private . point_no] + offset_col;
  }
//======================================================================================================================================================
//	COORDINATE AND TEMPLATE UPDATE
//======================================================================================================================================================
// if the last frame in the bath, update template
  if (public . frame_no != 0 && public . frame_no % 10 == 0) {
// update coordinate
    loc_pointer = private . point_no * public . frames + public . frame_no;
    private . d_Row[private . point_no] = private . d_tRowLoc[loc_pointer];
    private . d_Col[private . point_no] = private . d_tColLoc[loc_pointer];
// update template, limit the number of working threads to the size of template
    for (col = 0; col <= public . in_mod_cols - 1; col += 1) {
      for (row = 0; row <= public . in_mod_rows - 1; row += 1) {
// figure out row/col location in corresponding new template area in image and give to every thread (get top left corner and progress down and right)
        ori_row = private . d_Row[private . point_no] - 25 + row - 1;
        ori_col = private . d_Col[private . point_no] - 25 + col - 1;
        ori_pointer = ori_col * public . frame_rows + ori_row;
// update template
        d_in[col * public . in_mod_rows + row] = ((public . alpha * d_in[col * public . in_mod_rows + row]) + (1.00 - public . alpha) * public . d_frame[ori_pointer]);
      }
    }
  }
}
//===============================================================================================================================================================================================================
//===============================================================================================================================================================================================================
//	END OF FUNCTION
//===============================================================================================================================================================================================================
//===============================================================================================================================================================================================================
