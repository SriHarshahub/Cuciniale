#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int text_bit_encode(const char* input,char* txt_out) 
{
    int x, z;
    float outlen;
	int asciinum;                         // to store the ASCII number of a character
	int length = strlen(input);
	char* bit_reversem = (char*) malloc(8*length*sizeof(char));    //dynamic memory allocation
    char* bitm = (char*) malloc(8*length*sizeof(char));
	
	for(x = 0; x < length; x++)
	{
		asciinum = input[x];        //for storing character in ascii num
		char* bit_reverse = (char*) malloc(8*sizeof(char));    
		char* bit = (char*) malloc(8*sizeof(char));
		
		int y = 0;    //counter
		
		while(asciinum != 1)    //continue until ascii == 1
		{
			if(asciinum % 2 == 0)    //if ascii is divisible by 2
			{
				bit_reverse[y] = '0';  
			}
			else if(asciinum % 2 == 1)    //if it isnt divisible by 2
			{
				bit_reverse[y] = '1'; 
			}
			asciinum /= 2;  
			y++;    //incrementing for next iteration
		}
		
		if(asciinum == 1)
		{
			bit_reverse[y] = '1';
			y++;
		}
		
		if(y < 7)  //add zeros untill end of 7 bits
		{
			for(; y < 7; y++)
			{
				bit_reverse[y] = '0';
			}
		}
		for(z = 0; z < 7; z++)  //placing the array in correct order
		{
			bit[z] = bit_reverse[6 - z];
		}
		bit[8]='\0';
		bitm = strcat(bitm,bit);
		txt_out = bitm;
		free(bit_reverse);
		free(bit);
	}
	printf("%s\n", txt_out);
	outlen = strlen(bitm)/8;
	free(bitm);
    return outlen;
    
}
