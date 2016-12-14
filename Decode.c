#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int text_bit_decode(const char* input, char *output)
{
	int length = strlen(input);
	int subcount = length/8;     //Number of substrings
	int bits[8];                  //storage for 1 byte
	int asciidec = 0;            // The representation of the ascii after conversion
	char ascii;                 // ascii character 
	printf("");
	int z = 0;                 //used for counting
	int x, a, b, y;
	char *tmpout = (char*)malloc(subcount*sizeof(char));
	for(b = 0; b<subcount; b++)     //Used to read the complete byte
	{
		for(a = 0; a < 8; a++)      //storing from bits[0] through bits[7]
		{
			bits[a] = (int) input[z] - 48;  
			z++;
		}
		
		int power[8];    
		int counter = 7;        //To count powers from 2^0, ends at 2^7
		for(x = 0; x < 8; x++)
		{
			power[x] = counter;  
			counter--;    //decrement counter every time
		}
		
		for(y = 0; y < 8; y++)    //to calculate asciidec
		{
			double a = bits[y];    //store the element from bits[] as "a"
			double b = power[y];    //store the lement from power[] as "b"
			
			asciidec += a* pow(b); 
		}
		
		ascii = asciidec;   //In order to represent actual character
		asciidec = 0;    //reseting for next iteration
		tmpout[b] = ascii;
	}
	output = tmpout;
	printf("%s\n",output);
	int outputsize = sizeof(output);
	return outputsize;
}

