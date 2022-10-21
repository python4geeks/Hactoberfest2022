// MADE BY - VINAYAK CHACHRA
// ROLLNO. - 191210061


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
#define WHITE   255
#define BLACK   0
#define THRESHOLD   120
#define MAX_PIXEL   255

void imageBlur();
void writeImage(const char *imgName,
                unsigned char *header,
                unsigned char *colorTable,
                unsigned char *buf,
                int bitDepth,
                int imgSize);
void getImageDetail(height,width,maximum);
void imageSepia();
void grayToBinary() ;
void colorToGray();
void ChangeDetection();
void ImageMorphing();
void meanGray(sum);

int main()
{     int choice ;

    const char newimgName[]="images/cameraman_copy.bmp";

    FILE *origianl_file = fopen("images/cameraman.bmp","rb"); //  OPEN A FILE FOR READ OPERATION
    if(origianl_file == NULL)
    {
        printf("Unable to open file\n");
    }
    unsigned char header[54]; // THE BITMAP HAS 54 BYTES IMAGE HEADER
    unsigned char colorTable[1024]; // AND 1024BYTER COLOR TABLE
    for(int i =0;i<54;i++)
    {
        header[i] = fgetc(origianl_file);  //COPYING THE INFO ABOUT IMAGE TO OUR HEADER FILE
    }
    int width = *(int *)&header[18];  // FIRSTLY IT IS TAKING ADDRESS OF WIDTH TYPECATING IT TO INTEGER AND THEN POINTING TO THE VALUE AT THAT ADDRESS
    int height = *(int *)&header[22]; //FIRSTLY IT IS TAKING ADDRESS OF HEIGHT TYPECATING IT TO INTEGER AND THEN POINTING TO THE VALUE AT THAT ADDRESS
    int bitDepth = *(int *)&header[28];// FIRSTLY IT IS TAKING ADDRESS OF BITDEPTH TYPECATING IT TO INTEGER AND THEN POINTING TO THE VALUE AT THAT ADDRESS
    int imgSize = height * width;


    if(bitDepth<=8)
    {
      fread(colorTable,sizeof(unsigned char), 1024,origianl_file); // READING VALUE FROM ORIGINAL_FILE AND COPYING IT TO COLOR TABLE
    }

     unsigned char buf[width][height];
   fread(buf,sizeof(unsigned char),(height*width), origianl_file);// READING VALUE FROM ORIGINAL_FILE AND COPYING IT TO BUFF

  do
{ printf("TO COPY THE IMAGE PRESS                      1)\n");
  printf("TO REFLECT THE IMAGE PRESS                   2)\n");
  printf("TO ROTATE THE IMAGE PRESS                    3)\n");
  printf("TO ADD NEGATIVE FILTER TO THE IMAGE PRESS    4)\n");
  printf("TO CROP THE IMAGE PRESS                      5)\n");
  printf("TO SHRINK THE IMAGE PRESS                    6)\n");
  printf("TO INLARGE THE IMAGE PRESS                   7)\n");
  printf("TO ADD THE IMAGE PRESS                       8)\n");
  printf("TO SUBTRACT THE IMAGE PRESS                  9)\n");
  printf("TO TRANSLATE THE IMAGE PRESS                10)\n");
  printf("TO CONVERT RGB TO GRAYSCALE IMAGE PRESS     11)\n");
  printf("TO GRAYSCALE IMAGE TO BINARY  IMAGE PRESS   12)\n");
  printf("FOR SEPIA FILTER  PRESS                     13)\n");
  printf("TO BLUR THE IMAGE PRESS                     14)\n");
  printf("TO CHANGE THE PIXEL VALUE OF IMAGE PRESS    16)\n");
  printf("TO KNOW THE PIXEL VALUE OF THE IMAGE PRESS  15)\n");
  printf("FOR INFO ABOUT  IMAG PRESS                  17)\n");
  printf("TO KNOW THE AVERAGE GRAY VALUE OF THE IMAGE PRESS  18)\n");
  printf("TO EXIT THE MENU PRESS                      0)\n");
  printf("your choice");
  scanf("%d",&choice);
  switch (choice)
{
    case 1: {
                      writeImage(newimgName,header,colorTable,buf,bitDepth,imgSize);
                      printf("OPERATION IS SUCCESSFULL!\n");
    }
        break;
    case 2: {
                   FILE *duplicate_file =fopen("images/cameraman_reflect2.bmp","wb");
             fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
             fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
             unsigned char out_buffer[width][height];
             int x1 , y1 ;
             for(int x =0;x<width;x++)
              {
                for(int y = 0;y<height;y++)
                 {
                   x1 =  x ;
                     y1 = height - y  ;
                      out_buffer[x1][y1] = buf[x][y]; }}

 fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
 for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      out_buffer[x][y] = '\0';
        }
    }
   rewind(origianl_file);
   rewind(duplicate_file);
   fclose(duplicate_file);
   printf("OPERATION IS SUCCESSFULL!\n");
             }
   break;
  case 3 :{
   int x1 , y1 ;
   FILE *duplicate_file =fopen("images/cameramanrotate.bmp","wb");
   int selected;
   fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
   fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
   unsigned char out_buffer[width][height];
   float h , val;
   printf("ENTER THE ANGLE");
   scanf("%f",&h) ;
   val = PI / 180;
    for(int x =0;x<width;x++)
    {
      for(int y =0;y<height;y++)
       {   if (h<=90 && h>=0)
         {
           x1 = x*cos(h*val) + y*sin(h*val) ;
           y1 = height -1*x*sin(h*val ) + y*cos(h*val) ;
         }
         else
         if (h>=90 && h<=180)
            {
             x1 = width +  x*cos(h*val) + y*sin(h*val) ;
             y1 = height -1*x*sin(h*val ) + y*cos(h*val) ;
            }
            else
              if (h>=180 && h<=270)
              {
             x1 = x*cos(h*val) + y*sin(h*val)*(-1) ;
             y1 = height -1*x*sin(h*val ) + y*cos(h*val)*(-1)
              ;
              }
             out_buffer[x1][y1] = buf[x][y];   } }
   fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
       for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      out_buffer[x][y] = '\0';
        }
    }
   rewind(origianl_file);
   rewind(duplicate_file);
   fclose(duplicate_file);
   printf("OPERATION IS SUCCESSFULL!\n");
  }         break;
 case 4 :{
                 FILE *duplicate_file =fopen("images/cameraman_negative.bmp","wb");
                          fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
               fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
            unsigned char out_buffer[width][height];
    int x1 , y1 ;
for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      x1 = x ;
      y1 = y  ;
      out_buffer[x1][y1] = 255 - buf[x][y];
    }
   }
  fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
  rewind(origianl_file);
  rewind(duplicate_file);
  fclose(duplicate_file);
  for(int x =0;x<width;x++)
   {
     for(int y = 0;y<height;y++)
      {
        out_buffer[x][y] = '\0';
         }
       }
       printf("OPERATION IS SUCCESSFULL!\n");
    }
     break ;
   case 5 : {
           FILE *duplicate_file =fopen("images/cameraman_crop.bmp","wb");
           fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
           fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
           int l,r,d,u;
      unsigned char out_buffer[width][height];
      printf("How much you want to cut from left side: ");
      scanf("%d",&l);
      printf("How much you want to cut from right side: ");
      scanf("%d",&r);
      printf("How much you want to cut from upper side: ");
      scanf("%d",&u);
      printf("How much you want to cut from down side: ");
      scanf("%d",&d);
int x1,y1;
      for(int x=l;x<=width-r ;x++ )
      {
          for(int y=d ;y<=height-u;y++)
          {
              x1=x ;
              y1=y ;
            out_buffer[x1][y1]=buf[x][y];
          }
      }
           fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
           for(int x =0;x<width;x++)
           {
            for(int y = 0;y<height;y++)
             {
              out_buffer[x][y] = '\0';
             }
            }
   rewind(origianl_file);
   rewind(duplicate_file);
   fclose(duplicate_file);
   printf("OPERATION IS SUCCESSFULL!\n");
  }
  break ;
   case 6 : {
             FILE *duplicate_file =fopen("images/cameraman_shrink.bmp","wb");
             fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
             fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
             unsigned char out_buffer[width][height];
             int x1 , y1,s1,s2 ;
             printf("ENTER THE VALUE OF X AND Y THAT HAS TO BE DECREASED THE TIMES OF IMAGE");
             scanf("%d",&s1);
             scanf("%d",&s2);
             for(int x =0;x<width;x++)
              {
               for(int y = 0;y<height;y++)
                {
                  x1 = x/s1 ;
                  y1 = y/s2  ;
                  out_buffer[x1][y1] = buf[x][y];
                }
              }
             fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
             for(int x =0;x<width;x++)
           {
            for(int y = 0;y<height;y++)
             {
              out_buffer[x][y] = '\0';
             }
            }
             rewind(origianl_file);
             rewind(duplicate_file);
             fclose(duplicate_file);
             printf("OPERATION IS SUCCESSFULL!\n");
             }
              break ;
   case 7 : {
              FILE *duplicate_file =fopen("images/cameraman_inlarge.bmp","wb");
              fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
              fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
              unsigned char out_buffer[width][height];
              int x1 , y1,s1,s2 ;
              printf("ENTER THE VALUE OF X AND Y THAT HAS TO BE INCREASED THE TIMES OF IMAGE");
              scanf("%d",&s1);
              scanf("%d",&s2);
              for(int x =0;x<width;x++)
               {
                 for(int y = 0;y<height;y++)
                  {
                   x1 = x*s1 ;
                   y1 = y*s2  ;
                   out_buffer[x1][y1] = buf[x][y];
                  }
                }
   fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
   for(int x =0;x<width;x++)
           {
            for(int y = 0;y<height;y++)
             {
              out_buffer[x][y] = '\0';
             }
            }
   fclose(duplicate_file);
   rewind(origianl_file);
   rewind(duplicate_file);
   printf("OPERATION IS SUCCESSFULL!\n");
  }
  break ;
   case 8 : { ImageMorphing();
    printf("OPERATION IS SUCCESSFULL!\n");
  }
  break ;
    case 9 : {          ChangeDetection();
      printf("OPERATION IS SUCCESSFULL!\n");
  }
  break ;
   case 10: {
      FILE *duplicate_file =fopen("images/cameraman_translate.bmp","wb");
                          fwrite(header,sizeof(unsigned char),54,duplicate_file); // IT IS READING VALUE FROM HEADER AND WRITING IT TO DUPLICATE_FILE
               fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
            unsigned char out_buffer[width][height];
        for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      out_buffer[x][y] = '\0';
        }
    }
    int x1 , y1 ;
     float s1,s2;
    printf("TRANSLATION IN X DIRECTION");
    scanf("%f",&s1) ;
        printf("TRANSLATION IN Y DIRECTION");
    scanf("%f",&s2) ;
for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      x1 = x + s1 ;
      y1 = y +s2  ;
      out_buffer[x1][y1] = buf[x][y];
        }
    }
  fwrite(out_buffer,sizeof(unsigned char),imgSize,duplicate_file);
   rewind(origianl_file);
   rewind(duplicate_file);
   fclose(duplicate_file);
      for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      out_buffer[x][y] = '\0';
          }
    }
    printf("OPERATION IS SUCCESSFULL!\n");
  }
  break ;
case 11: {  colorToGray();
  printf("OPERATION IS SUCCESSFULL!\n");
    }
  break ;
  case 12: {  grayToBinary() ;
    printf("OPERATION IS SUCCESSFULL!\n");
    }
  break ;
  case 13: {
                imageSepia();
                printf("OPERATION IS SUCCESSFULL!\n");
              }
  break ;
case 14: {      imageBlur();
  printf("OPERATION IS SUCCESSFULL!\n");
    }
  break ;
case 15: {  int r,c;
          printf("ENTER THE VALUE OF ROW AND COLUMN RESPECTIVELY WHERE YOU WANT TO FIND THE PIXEL VALUE\n");
               scanf("%d",&r);
               scanf("%d",&c);
               printf("PIXEL VALUE IS : %d\n", buf[r][c]);
    }
  break ;
  case 16: {
       int r,c,p;
          printf("ENTER THE VALUE OF ROW AND COLUMN RESPECTIVELY WHERE YOU WANT TO CHANGE THE PIXEL VALUE\n");
               scanf("%d",&r);
               scanf("%d",&c);
               printf("ENTER THE NEW PIXEL VALUE\n");
               scanf("%d",&p);
               printf("OLD PIXEL VALUE IS : %d\n", buf[r][c]);
               buf[r][c] = p ;
               printf("NEW PIXEL VALUE IS : %d\n", buf[r][c]);
    }
  break ;
  case 17: {    int maximum ;
              maximum = buf[0][0];
  for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {     if (maximum<buf[x][y])
    {
         maximum = buf[x][y];
    }
          }
       }
        getImageDetail(height,width,maximum);
}
  break ;
  case 18: {
               int sum = 0 ;
               for(int x =0;x<width;x++)
   {
    for(int y = 0;y<height;y++)
    {
      sum = sum + buf[x][y];
        }
    }
    sum = sum/(height*width);
         meanGray(sum);
}
  break ;
    default:  ;
  }
     fclose(origianl_file);
}while(choice!=0) ;
    return 0;
}
void  imageBlur()
{
   FILE *fin2 =fopen("images/lena_color.bmp","rb");
     FILE *fout2 = fopen("images/lena_blur.bmp","wb");
     unsigned char imgHeader[54];
     unsigned char colorTable[1024];
     if(fin2 ==NULL)
     {
         printf("Unable to open file \n");
     }
     for(int i =0;i<54;i++)
     {
         imgHeader[i] = getc(fin2);
     }
     fwrite(imgHeader,sizeof(unsigned char),54,fout2);
     int height = *(int*)&imgHeader[22];
     int width  = *(int*)&imgHeader[18];
     int bitDepth = *(int*)&imgHeader[28];
     if(bitDepth <=8)
     {
         fread(colorTable,sizeof(unsigned char),1024,fin2);
         fwrite(colorTable, sizeof(unsigned char),1024,fout2);
    }
     int imgSize =  height * width;
     unsigned char buffer[imgSize][3];
     unsigned char output_buffer1[imgSize][3];
     for(int i =0;i<imgSize;i++)
     {
         buffer[i][2] = getc(fin2);
         buffer[i][1] = getc(fin2);
         buffer[i][0] = getc(fin2);
     }
     float kernel[3][3] = {{1.0/9.0, 1.0/9.0,1.0/9.0},
                           {1.0/9.0, 1.0/9.0,1.0/9.0},
                           {1.0/9.0, 1.0/9.0,1.0/9.0}
                            };
    for(int x =1 ;x<height-1;x++)
    {
        for(int y =1;y<width -1;y++)
        {
            float sum0 = 0.0;
            float sum1 = 0.0;
            float sum2 = 0.0;
            for(int i =-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    sum0  = sum0 + (float)kernel[i+1][j+1]*buffer[(x+i)*width+(y+j)][0];
                    sum1  = sum1 + (float)kernel[i+1][j+1]*buffer[(x+i)*width+(y+j)][1];
                    sum2  = sum2 + (float)kernel[i+1][j+1]*buffer[(x+i)*width+(y+j)][2];
                }
            }
            output_buffer1[(x)*width+(y)][0] =  sum0;
            output_buffer1[(x)*width+(y)][1] =  sum1;
            output_buffer1[(x)*width+(y)][2] =  sum2;
        }
    }
    for(int i =0;i<imgSize;i++)
    {
        putc(output_buffer1[i][2],fout2);
        putc(output_buffer1[i][1],fout2);
        putc(output_buffer1[i][0],fout2);
    }
    fclose(fout2);
    fclose(fin2);
}
void writeImage(const char *imgName,
                unsigned char *header,
                unsigned char *colorTable,
                unsigned char *buf,
                int bitDepth,
                int imgSize)
{
    FILE *write=fopen(imgName,"wb");
    fwrite(header,sizeof(unsigned char),54,write);
    if(bitDepth<=8)
    fwrite(colorTable,sizeof(unsigned char),1024,write);
    fwrite(buf,sizeof(unsigned char),imgSize,write);
    fclose(write);
}
void getImageDetail(height,width,maximum)
{
   printf("NUMBER OF ROWS =  %d\n",height);
   printf("NUMBER OF COLUMN =  %d\n",width);
   printf("MAX PIXEL VALUE IS  =  %d\n",maximum);
}
void imageSepia()
{
    FILE  *fIn =fopen("images/lena_color.bmp","rb");
    FILE  *fOut =fopen("images/lena_sepia.bmp","wb");
    unsigned char imgHeader[54];
    unsigned char colorTable[1024];
    if(fIn ==NULL)
    {
        printf("Unable to open file \n");
    }
    for(int i =0;i<54;i++)
    {
       imgHeader[i] = getc(fIn);
    }
    fwrite(imgHeader,sizeof(unsigned char),54,fOut);
    int height = *(int*)&imgHeader[22];
    int width  = *(int*)&imgHeader[18];
    int bitDepth = *(int*)&imgHeader[28];
    if(bitDepth <=8)
    {
        fread(colorTable,sizeof(unsigned char),1024,fIn);
        fwrite(colorTable,sizeof(unsigned char),1024,fOut);
    }
    int imgSize = height * width;
    int r,g,b;
    unsigned char buffer[imgSize][3];
    for(int i =0;i<imgSize;i++)
    {
        r=g=b=0;
        buffer[i][0] = getc(fIn);      //red
        buffer[i][1] = getc(fIn);      //green
        buffer[i][2] = getc(fIn);      //blue
        r = (buffer[i][0]*0.393) + (buffer[i][1]*0.769) + (buffer[i][2]*0.189);
        g = (buffer[i][0]*0.349) + (buffer[i][1]*0.686) + (buffer[i][2]*0.168);
        b = (buffer[i][0]*0.272) + (buffer[i][1]*0.534) + (buffer[i][2]*0.131);
        if(r>MAX_PIXEL){ r =MAX_PIXEL;}
        if(g>MAX_PIXEL){ g = MAX_PIXEL;}
        if(b>MAX_PIXEL){ b = MAX_PIXEL;}
        putc(b,fOut);
        putc(g,fOut);
        putc(r,fOut);
    }
    fclose(fOut);
    fclose(fIn);
}
void grayToBinary()
{
  FILE *original_file4 = fopen("images/cameraman.bmp","rb");
   FILE *duplicate_file = fopen("images/cameraman_black_and_white.bmp","wb");
   unsigned  char imgHeader[54];
   unsigned  char colorTable[1024];
   if(original_file4 == NULL)
   {
       printf("Unable to open image \n");
   }
   for(int i=0;i<54;i++)
   {
       imgHeader[i] = getc(original_file4);
   }
   fwrite(imgHeader,sizeof(unsigned char),54,duplicate_file);
   int height = *(int*)&imgHeader[22];
   int width  = *(int*)&imgHeader[18];
   int bitDepth = *(int *)&imgHeader[28];
   int imgSize = height * width;
   if(bitDepth<=8)
   {
       fread(colorTable, sizeof(unsigned char),1024,original_file4);
       fwrite(colorTable,sizeof(unsigned char),1024,duplicate_file);
   }
   unsigned char buffer[imgSize];
   fread(buffer,sizeof(unsigned char),imgSize,original_file4);
    //Black and White converter
    for(int i =0;i<imgSize;i++)
    {
        //buffer[i] = (buffer[i]>THRESHOLD)? WHITE : BLACK;
      if (buffer[i]>THRESHOLD)
      {
        buffer[i] = WHITE ;
      }      else
        buffer[i] = BLACK ;
    }
    fwrite(buffer,sizeof(unsigned char), imgSize,duplicate_file);
    fclose(original_file4);
    fclose(duplicate_file);
}
void colorToGray()
{
  FILE *original_file5 = fopen("images/lena_color.bmp","rb"); //  OPEN A FILE FOR READ OPERATION
    FILE *gray_file = fopen("images/lena_color_gray_copy.bmp","wb");
    unsigned char header[54]; // THE BITMAP HAS 54BYTES IMAGE HEADER
    unsigned char colorTable[1024]; // AND 1024BYTER COLOR TABLE
    for(int i =0;i<54;i++)
    {
        header[i] = fgetc(original_file5);  //COPYING THE INFO ABOUT IMAGE TO OUR HEADER FILE

    }
    int width = *(int *)&header[18];  // FIRSTLY IT IS TAKING ADDRESS OF WIDTH TYPECATING IT TO INTEGER AND THEN POINTING TO THE VALUE AT THAT ADDRESS
    int height = *(int *)&header[22]; //FIRSTLY IT IS TAKING ADDRESS OF HEIGHT TYPECATING IT TO INTEGER AND THEN POINTING TO THE VALUE AT THAT ADDRESS
    int bitDepth = *(int *)&header[28];// FIRSTLY IT IS TAKING ADDRESS OF BITDEPTH TYPECATING IT TO INTEGER AND THEN POINTING TO THE VALUE AT THAT ADDRESS
    fwrite(header,sizeof(unsigned char),54,gray_file);
    if(bitDepth<=8)
    {
      fread(colorTable,sizeof(unsigned char), 1024,original_file5); // READING VALUE FROM ORIGINAL_FILE AND COPYING IT TO COLOR TABLE
      fwrite(colorTable,sizeof(unsigned char),1024,gray_file);
    }
   unsigned char buf1[height * width];
  long int position = ftell(original_file5);
   fread(buf1,sizeof(unsigned char),(height*width), original_file5);// READING VALUE FROM ORIGINAL_FILE AND COPYING IT TO BUFF
   fseek(original_file5 , position ,SEEK_SET) ;
    int imgSize = height * width;
    unsigned char buffer[imgSize][3];
    for(int i =0;i<imgSize;i++)
    {
        buffer[i][0] = getc(original_file5);       //red
        buffer[i][1] = getc(original_file5);       //green
        buffer[i][2] = getc(original_file5);       //blue
        int temp =0;
        temp = (buffer[i][0]*0.3 )+(buffer[i][1]*0.59)+(buffer[i][2]*0.11);
       putc(temp,gray_file);
       putc(temp,gray_file);
       putc(temp,gray_file);
    }
   fclose(original_file5);
   fclose(gray_file);
}
void ChangeDetection()
{
  FILE * original_file2 = fopen("images/lighthouse.bmp","rb");
   FILE * original_file3 = fopen("images/lena512.bmp","rb");
   FILE * duplicate_file = fopen("images/subtraction.bmp","wb");
   FILE * duplicate_file2 = fopen("images/ltc.bmp","wb");
   unsigned char imgHeader[54];
   unsigned char colorTable[1024];
   unsigned char imgHeader2[54];
   unsigned char colorTable2[1024];
   for(int i =0;i<54;i++)
   {
       imgHeader[i] = getc(original_file2);
      imgHeader2[i] = getc(original_file3);
   }
   fwrite(imgHeader, sizeof(unsigned char),54,duplicate_file);
   fwrite(imgHeader2, sizeof(unsigned char),54,duplicate_file2);
   int height = *(int *)&imgHeader[22];
   int width =  *(int *)&imgHeader[18];
   int bitDepth = *(int *)&imgHeader[28];
   int imgSize = height * width;
   int height2 = *(int *)&imgHeader2[22];
   int width2 =  *(int *)&imgHeader2[18];
   int bitDepth2 = *(int *)&imgHeader2[28];
   int imgSize2 = height2 * width2 ;
   if(bitDepth <=8)
   {
       fread(colorTable,sizeof(unsigned char), 1024, original_file2);
       fwrite(colorTable,sizeof(unsigned char), 1024,duplicate_file);
       fread(colorTable2,sizeof(unsigned char), 1024, original_file3);
       fwrite(colorTable2,sizeof(unsigned char), 1024,duplicate_file2);
   }
   unsigned char buffer[imgSize];
     unsigned char buffer2[imgSize2];
   fread(buffer,sizeof(unsigned char),imgSize,original_file2);
   fread(buffer2,sizeof(unsigned char),imgSize2,original_file3);
   int temp ;
   int array[imgSize] ;
   for(int i =0;i<imgSize;i++)
   {
       temp = buffer[i] -  buffer2[i];
         if (temp < 0 )
         {
           temp = temp*(-1) ;
         }
         buffer[i] = temp ;
    }
    fwrite(buffer,sizeof(unsigned char), imgSize,duplicate_file);
   fwrite(buffer2,sizeof(unsigned char), imgSize2,duplicate_file2);
   fclose(original_file2);
   fclose(original_file3);
   fclose(duplicate_file);
   fclose(duplicate_file2);
   int del =  remove("images/ltc.bmp");

}
void ImageMorphing()
{
  FILE * original_file = fopen("images/cameraman.bmp","rb");
   FILE * original_file2 = fopen("images/lena512.bmp","rb");
   FILE * duplicate_file = fopen("images/addition.bmp","wb");
   FILE * duplicate_file2 = fopen("images/ltc.bmp","wb");
   unsigned char imgHeader[54];
   unsigned char colorTable[1024];
   unsigned char imgHeader2[54];
   unsigned char colorTable2[1024];
   for(int i =0;i<54;i++)
   {
       imgHeader[i] = getc(original_file);
      imgHeader2[i] = getc(original_file2);
   }
   fwrite(imgHeader, sizeof(unsigned char),54,duplicate_file);
   fwrite(imgHeader2, sizeof(unsigned char),54,duplicate_file2);
   int height = *(int *)&imgHeader[22];
   int width =  *(int *)&imgHeader[18];
   int bitDepth = *(int *)&imgHeader[28];
   int imgSize = height * width;
   int height2 = *(int *)&imgHeader2[22];
   int width2 =  *(int *)&imgHeader2[18];
   int bitDepth2 = *(int *)&imgHeader2[28];
   int imgSize2 = height2 * width2;
   if(bitDepth <=8)
   {
       fread(colorTable,sizeof(unsigned char), 1024, original_file);
       fwrite(colorTable,sizeof(unsigned char), 1024,duplicate_file);
       fread(colorTable2,sizeof(unsigned char), 1024, original_file2);
       fwrite(colorTable2,sizeof(unsigned char), 1024,duplicate_file2);
   }
   unsigned char buffer[imgSize];
     unsigned char buffer2[imgSize2];
   fread(buffer,sizeof(unsigned char),imgSize,original_file);
   fread(buffer2,sizeof(unsigned char),imgSize2,original_file2);
   int temp ;
   int array[imgSize] ;
   for(int i =0;i<imgSize;i++)
   {
       temp = buffer[i] + buffer2[i];
        array[i] = temp ;
   }
    int i, max, min, size;
    max = array[0];
    min = array[0];
    for(i=1; i<imgSize; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }

        if(array[i] < min)
        {
            min = array[i];
        }
    }
   int g ;
for(int i =0;i<imgSize;i++)
   {
         g = 255*(array[i] - min)/(max - min) ;
         buffer[i] = g ;
   }
  fwrite(buffer,sizeof(unsigned char), imgSize,duplicate_file);
  fwrite(buffer2,sizeof(unsigned char), imgSize2,duplicate_file2);
  fclose(original_file2);
  fclose(duplicate_file);
  fclose(duplicate_file2);
  int del =  remove("images/ltc.bmp");
}


void meanGray(sum)
{
     printf("%d\n",sum);
}
