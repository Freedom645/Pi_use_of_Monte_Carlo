#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const unsigned N = 1e6;

string IntToStr(int i){stringstream ss;ss << i;return ss.str();}

int main(){
	//出力ファイルの指定
	ofstream in("res_" + IntToStr(N) + "_in.csv");
	ofstream out("res_" + IntToStr(N) + "_out.csv");

	//乱数初期化
	random_device seed_gen;
	default_random_engine engine(seed_gen());

	// 0.0以上1.0未満の値を等確率で発生させる
	uniform_real_distribution<> dist(0.0, 1.0);


	unsigned sum = 0;
	for(unsigned i = 0; i < N; i++){

		double x = dist(engine);
		double y = dist(engine);

		if(x*x + y*y < 1){
			in << x << "," << y << endl;
			++sum;
		}else{
			out << x << "," << y << endl;
		}
	}

	double pi = (double)sum/N*4.0;

	printf("%.10f\n", pi);

	//ファイルストリームの終了
	in.close();
	out.close();

	return 0;
}
