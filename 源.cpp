#include<stdio.h>
#include<math.h>
int n;
double minlen = 10000, x[1000], r[1000];//分别为最小圆排列长度，每个圆心横坐标，每个圆半径
double bestr[1000];//最小圆排列的半径顺序
double center(int t) {//圆心坐标
	double temp = 0;
	//由于后面一个圆不一定与前一个圆相切，可能与前面的任一圆相切
	for (int j = 1; j < t; j++) {
		double xvalue = x[j] + 2.0 * sqrt(r[t]*r[j]);
		if (xvalue > temp) {
			//对于排列的第t个圆，距离最远的便是排列第t的圆的横坐标
			temp = xvalue;
		}
	}
	return temp;
	//排列第一个的圆的圆心横坐标是0
}
void swap(double& a, double& b) {
	double t = a;
	a = b;
	b = t;
}
void compute() {
	double low = 0, high = 0;//表示矩阵框的左右边界
	for (int i = 1; i <= n; i++) {
		if (x[i] - r[i] < low) {
			low = x[i] - r[i];
		}
		if (x[i] + r[i] > high) {
			high = x[i] + r[i];
		}
	}
	if (high - low < minlen) {
		minlen = high - low;
		for (int i = 1; i <= n; i++) {
			bestr[i] = r[i];
		}
	}
}
void backtrack(int t) {
	if (t > n) {
		compute();
	}
	else {
		for (int j = t; j <= n; j++) {
			swap(r[t], r[j]);
			double centerx = center(t);//获取圆心横坐标
			//如果某个圆加起来的序列长度比当前最小序列的长度还要小，则继续进行，否则结束
			if (centerx + r[t] + r[1] < minlen) {
				x[t] = centerx;
				backtrack(t + 1);
			}
			swap(r[t],r[j]);
		}
	}
}
int main() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%lf", &r[i]);
	}
	printf("每个圆的半径分别为：\n");
	for (int i = 1; i <= n; i++) {
		printf("%.2f ", r[i]);
	}
	printf("\n");
	backtrack(1);
	printf("最小圆的排列长度为：%.2f\n",minlen);
	printf("排列的顺序对应的半径分别为:");
	for (int i = 1; i <= n; i++) {
		printf("%.2f ", bestr[i]);
	}
	printf("\n");
}