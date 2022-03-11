#include <fftw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define SIZE 1000000000

int Add(int a, int b)
{
    int c;
    return a + b;
}

int calc_fft()
{
    FILE *fp;
    int i;
    int N;
    double re, im, mag, ang;
    fftw_complex *in, *out;
    fftw_plan p;

    // N個のFFTW用の複素数配列を確保する
    in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);

    // 複素数配列に入力データをセット
    for (i = 0; i < N; i++)
    {                   // t=0〜1secのデータ
        in[i][0] = 1.0; // 実数部
        in[i][1] = 0.0; // 虚数部
    }

    // １次元のフーリエ変換を実行
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p);

    // 結果を出力する
    for (i = 0; i < N; i++)
    {                                  // f=0〜N（サンプリング周波数）のデータ
        re = out[i][0];                // 複素数の実数部
        im = out[i][1];                // 複素数の虚数部
        mag = sqrt(re * re + im * im); // 大きさを計算
        ang = atan2(im, re);           // 位相角を計算
        printf("%d \t %.5lf \t %.5lf \t %.5lf \t %.5lf \n", i, re, im, mag, ang);
    }

    // 後始末（使用した配列等を廃棄）
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return 0;
}