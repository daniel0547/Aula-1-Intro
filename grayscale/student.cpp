#include <iostream>
#include "rgb.h"

using namespace std;

void process_image_parallel(struct rgb *input_image,
    unsigned char *output_image,
    size_t rows,
    size_t cols)
{
   	#pragma omp parallel for
	for(int ij = 0; ij < rows*cols; ij++)
	{
	int i = ij / rows;
	int j = ij % cols;
		output_image[ij]=.299f * input_image[ij].red + .587f * input_image[ij].green + .114f * input_image[ij].blue;
	}
}
