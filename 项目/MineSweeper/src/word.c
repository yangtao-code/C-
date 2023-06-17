#include "word.h"

void display_words(int x0, int y0,
                   int w, int h,
                   char *wordbuf,
                   int wordnum,
                   unsigned int backcolor,
                   unsigned int wordcolor)
{
    for (int i = 0; i < wordnum; i++)
    {
        for (int j = 0; j < h * w / 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (*(wordbuf + i * h * w / 8 + j) << k & 0x80)
                {
                    display_ry_Point(x0 + i * w + (+j * 8 + k) % w, y0 + (j * 8) / w, wordcolor);
                }
                else
                {
                    display_ry_Point(x0 + i * w + (j * 8 + k) % w, y0 + (j * 8) / w, backcolor);
                }
            }
        }
    }
}
