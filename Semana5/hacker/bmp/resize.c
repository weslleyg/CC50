/****************************************************************************
 * copy.c
 *
 * CC50
 * Pset 5
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"


int
main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: resize f infile outfile\n");
        return 1;
    }

    // remember filenames
    int value = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    BITMAPFILEHEADER bfCopy = bf;
    BITMAPINFOHEADER biCopy = bi;

    biCopy.biWidth = bi.biWidth * value;
    biCopy.biHeight = bi.biHeight * value;

    int nPadding = (4 - (biCopy.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    biCopy.biSizeImage = (biCopy.biWidth * sizeof(RGBTRIPLE) + nPadding) * abs(biCopy.biHeight);
    bfCopy.bfSize = biCopy.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

     // write outfile's BITMAPFILEHEADER
    fwrite(&bfCopy, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biCopy, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    RGBTRIPLE triple;
    RGBTRIPLE *line = malloc(biCopy.biWidth * sizeof(RGBTRIPLE));

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for(int l = 0; l < value; l++) {
                line[j * value + l] = triple; 
            }
        }
        fseek(inptr, padding, SEEK_CUR);
        // // write padding to outfile
        for (int k = 0; k < value; k++) {
            fwrite(line, biCopy.biWidth * 3, 1, outptr);
            for(int h = 0; h < nPadding; h++) {
                fputc(0x00, outptr);
            }
        }
    }
    free(line);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
