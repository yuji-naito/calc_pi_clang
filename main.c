#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

double calcPi(int testCount)
{
  double x, y = 0;
  double pi = 0;
  int hitCount = 0;

  srand((unsigned int)time(NULL));

  for (int j = 0; j < testCount; j++) {
    // x座標、y座標を0.0～1.0の間でランダムに取得
    x = rand() / (double)RAND_MAX;
    y = rand() / (double)RAND_MAX;

    // 原点からの距離(x^2 + y^2)が1未満であれば扇の中に入ったものとしてhitCountをインクリメント
    if ( (x*x + y*y) < 1 ) {
      hitCount++;
    }
  }

    // 4 * 円の扇の中に入った回数 / 全回数 = 円周率
    pi = (double)4 * hitCount / testCount;

    return pi;
}

// モンテカルロ法で円周率を計算するプログラム
void main()
{
  unsigned int testCount = 1000;
  unsigned int repeatCount = 6;
  clock_t startClock, endClock;
  double pi = 0;

  for (int i = 0; i < repeatCount; i++) {
    testCount *= 10;

    startClock = clock();

    pi = calcPi(testCount);

    endClock = clock();

    // 結果出力
    printf("count: %10d\tpi: %.10f\ttime: %.10f\n", testCount, pi, (double)(endClock - startClock) / CLOCKS_PER_SEC);
  }
}
