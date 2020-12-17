#include "mandel.h"

mandel::mandel()
{

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define SIZE 800
#define ITERATIONS 100


    int values[SIZE][SIZE];
    int depth = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double ii = i * (3.0 / SIZE) - 2.3;
            double jj = j * (3.0 / SIZE) - 1.49;
            double zr = 0;
            double zi = 0;
            depth = 0;

            while ( (zr * zr + zi * zi <= 4.0) && depth < ITERATIONS) {
                depth += 1;
                double temp = zr * zr - zi * zi + ii;
                zi = zr * zi * 2 + jj;
                zr = temp;
            }
            values[j][i] = depth;
        }
    }

    Mat newImg(SIZE, SIZE, CV_8UC3);

    int r[50];
    int g[50];
    int b[50];

    for (int i = 0; i < 50; i++) {
        r[i] = i * 2;
        g[i] = i * 4;
        b[i] = i * 6;
    }

    for (int i = 0; i < newImg.rows; i++) {
        uchar* p = newImg.ptr<uchar>(i);
        int depth;
        for (int j = 0; j < newImg.cols * newImg.channels(); j++) {
            depth = values[i][j/3];
            p[j] = b[depth % 50];
            p[j+1] = g[depth % 50];
            p[j+2] = r[depth % 50];
            j += 2;
        }
    }

    imshow("Apple", newImg);
    waitKey(0);


    return 0;
}




}
