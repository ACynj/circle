#include<stdio.h>
#include<math.h>
int n;
double minlen = 10000, x[1000], r[1000];//�ֱ�Ϊ��СԲ���г��ȣ�ÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double bestr[1000];//��СԲ���еİ뾶˳��
double center(int t) {//Բ������
	double temp = 0;
	//���ں���һ��Բ��һ����ǰһ��Բ���У�������ǰ�����һԲ����
	for (int j = 1; j < t; j++) {
		double xvalue = x[j] + 2.0 * sqrt(r[t]*r[j]);
		if (xvalue > temp) {
			//�������еĵ�t��Բ��������Զ�ı������е�t��Բ�ĺ�����
			temp = xvalue;
		}
	}
	return temp;
	//���е�һ����Բ��Բ�ĺ�������0
}
void swap(double& a, double& b) {
	double t = a;
	a = b;
	b = t;
}
void compute() {
	double low = 0, high = 0;//��ʾ���������ұ߽�
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
			double centerx = center(t);//��ȡԲ�ĺ�����
			//���ĳ��Բ�����������г��ȱȵ�ǰ��С���еĳ��Ȼ�ҪС����������У��������
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
	printf("ÿ��Բ�İ뾶�ֱ�Ϊ��\n");
	for (int i = 1; i <= n; i++) {
		printf("%.2f ", r[i]);
	}
	printf("\n");
	backtrack(1);
	printf("��СԲ�����г���Ϊ��%.2f\n",minlen);
	printf("���е�˳���Ӧ�İ뾶�ֱ�Ϊ:");
	for (int i = 1; i <= n; i++) {
		printf("%.2f ", bestr[i]);
	}
	printf("\n");
}