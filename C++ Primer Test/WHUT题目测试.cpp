//#include <iostream>
//#include <stdio.h>
//#include <vector>
//using namespace std;
//
////int main()
////{
////	int m, n;
////	cin >> m >> n;
////	float *mat = new float[m*n];
////	for (int i = 0; i < m; i++)
////	{
////
////	}
//	//vector<float> save;
//	//float *mat = 0;
//	//while (cin >> *mat)
//	//	save.push_back(*mat);
//	//for (auto &s : save)
//	//	cout << s << endl;
////}
//
//void main1() //转置矩阵
//{
//	int M, N;
//	cin >> M >> N;
//	int a[3][3], b[3][3];
//	int i, j;
//	for (i = 0; i<M; i++)
//		for (j = 0; j<N; j++)
//		{
//			cin >> a[i][j];
//			b[j][i] = a[i][j];
//		}
//
//	for (i = 0; i<N; i++)
//	{
//		for (j = 0; j<M; j++)
//			printf("%d ", b[i][j]);
//		printf("\n");
//	}
//}
//
//class CTriangle 
//{
//private:
//	float a, b, c;
//public:
//	//默认构造函数
//	CTriangle() = default;
//	//一般构造函数
//	CTriangle(float a1, float b1, float c1) :a(a1), b(b1), c(c1) {}
//	//计算三角形的面积
//	float area()
//	{
//		return 0.5*(a + b + c);
//	}
//	//设置三角形的三条边长度
//	void change()
//	{
//		float t;
//		if (a>b)
//		{
//			t = a; a = b; b = t;
//		}
//		if (b>c)
//		{
//			t = b; b = c; c = t;
//		}
//		if (a>b)
//		{
//			t = a; a = b, b = t;
//		}
//	}
//	//得到三角形的三条边长度
//	void print()
//	{
//		cout << "三角形的三边从小到大依次为：" << a << b << c << endl;
//	}
//};
//
//void main2()
//{
//	CTriangle a(4, 2, 3);
//	cout << a.area() << endl;
//	a.print();
//	a.change();
//	a.print();
//}
//
//void main3()
//{
//	int score;
//	cin >> score;
//	switch (score/10)
//	{
//	case 10:
//		cout << "A" << endl;
//		break;
//	case 9:
//		cout << "A" << endl;
//		break;
//	case 8:
//		cout << "B" << endl;
//		break;
//	case 7:
//		cout << "C" << endl;
//		break;
//	case 6:
//		cout << "D" << endl;
//		break;
//	default:
//		cout << "E" << endl;
//		break;
//	}
//}
//
//void main4()
//{
//	int n;
//	vector<int> save;
//	while (cin >> n)
//		save.push_back(n);
//	int sum = 0;
//	while (sum != save.size())
//	{
//		for (int i = save.size() - 1; i > 0; i--)
//		{
//			int temp;
//			if (save[i] > save[i - 1])
//			{
//				temp = save[i];
//				save[i] = save[i - 1];
//				save[i - 1] = temp;
//			}
//		}
//		sum++;
//	}
//	for (auto &s : save)
//		cout << s << " ";
//	cout << endl;
//}
//
//class CBox
//{
//	double length, width, height;
//	//length（长）、width（宽）和height（高）
//public:
//	//默认构造函数
//	CBox() = default;
//	CBox(double a, double b, double c) :length(a), width(b), height(c) {};
//	//用函数SetSize设置盒子的长、宽、高
//	void SetSize(double a, double b, double c)
//	{
//		length = a;
//		width= b;
//		height = c;
//	}
//	//用函数GetSize获取盒子的长、宽、高
//	void GetSize()
//	{
//		cout << "长宽高分别为：" << length << " " << width << " " << height << endl;
//	}
//	//“+”运算符重载函数
//	CBox &operator +(const CBox& a)
//	{
//		length += a.length;
//		width += a.width;
//		height += a.height;
//		return *this;
//	}
//	//用函数CalVol 计算并输出盒子的体积
//	double CalVol()
//	{
//		return  length*width*height;
//	}
//};
//
//void main5()
//{
//	CBox a;
//	CBox b(3, 9, 10);
//	a.SetSize(3, 5, 8);
//	a.GetSize();
//	cout << a.CalVol() << endl;
//	a + b;
//	a.GetSize();
//	cout << a.CalVol() << endl;
//}
//


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int x = 0, n = 0;
//	cout << "请输入一个整数:" << endl;
//	cin >> x;
//	for (n = 0; x > 0; n++)
//	{
//		x /= 10;
//	}
//	cout << "位数是:" << n << endl;
//	return 0;
//}

//#pragma warning(disable:4996)
//
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//void stradd(char *S1, char *S2)
//{
//	while (*S1)  S1++;
//	while (*S2) { *S1 = *S2; S1++; S2++; }
//	*S1 = 0;
//}
//
//int main()
//{
//	char S1[80], S2[80];
//	printf("\nInput a string: ");   
//	gets(S1);
//	printf("\nInput a string: ");  
//	gets(S2);
//	cout << S1 << endl;
//	cout << S2 << endl;
//	stradd(S1, S2);
//	cout << S1 << endl;
//	cout << S2 << endl;
//}

//#include<iostream>
//using namespace std;
//
//class CMat
//{
//	double *m_pValue;
//	int m_nRow;
//	int m_nCol;
//public:
//	/*-----------------------------------------------------------*/
//	CMat() 
//	{ 
//		m_nCol = 0; m_nRow = 0; m_pValue = 0; 
//	}
//	/*-----------------------------------------------------------*/
//	CMat(int nRow, int nCol, double *pBuf)
//	{
//		m_nRow = nRow;
//		m_nCol = nCol;
//		int size = (nRow * nCol);
//		m_pValue = new double[size];
//		for (int i = 0; i < nRow; i++)
//		{
//			for (int j = 0; j < nCol; j++)
//			{
//				m_pValue[i*nRow + j] = pBuf[i*nRow + j];
//			}
//		}
//	}
//	/*-----------------------------------------------------------*/
//	~CMat()
//	{
//		delete []m_pValue;
//	}
//	/*-----------------------------------------------------------*/
//	CMat &operator=(const CMat &mat)
//	{
//		if (this == &mat)
//		{
//			return *this;
//		}
//		m_nCol = mat.m_nCol;
//		m_nRow = mat.m_nRow;
//		int size = m_nCol*m_nRow;
//		m_pValue = new double[size];
//		for (int i = 0; i < m_nRow; i++)
//		{
//			for (int j = 0; j < m_nCol; j++)
//			{
//				m_pValue[i*m_nRow + j] = mat.m_pValue[i*m_nRow + j];
//			}
//		}
//		return *this;
//	}
//	/*-----------------------------------------------------------*/
//	CMat operator+(const CMat &m)
//	{
//		CMat M = *this;
//		if (m_nCol == m.m_nCol && m_nRow == m.m_nRow)
//		{
//			for (int i = 0; i < M.m_nRow; i++)
//			{
//				for (int j = 0; j < M.m_nCol; j++)
//				{
//					M.m_pValue[i*m_nRow + j] = m_pValue[i*m_nRow + j] + m.m_pValue[i*m_nRow + j];
//				}
//			}
//			//for (int i = 0; i < m_nCol*m_nRow; i++)
//			//	M.m_pValue[i] = m.m_pValue[i] + m_pValue[i];
//			//return M;
//			return M;
//		}
//		else
//		{
//			cout << "矩阵行或列数不相等，不能相加" << endl;
//			return M;
//		}
//	}
///*-----------------------------------------------------------*/
//	void print()
//	{
//		for (int i = 0; i<m_nRow; i++) 
//		{
//			for (int j = 0; j<m_nCol; j++) {
//				cout << m_pValue[i*m_nRow + j] << ' ';
//			}
//			cout << endl;
//		}
//	}
//};
//
//void main()
//{
//	double *a = new double[40];
//	a[0] = 1.0;
//	a[1] = 2.0;
//	a[2] = 3;
//	a[3] = 4;
//	CMat s1(2, 2, a);
//	CMat s2(2, 2, a);
//	s1.print();
//	CMat s3 = s1 + s2;
//	s3.print();
//	s2 = s1;
//	s2.print();
//}