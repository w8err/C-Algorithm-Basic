double �ŵ�����(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)	
		return �ŵ�����(x * x, n / 2);
	else return x * �ŵ�����(x * x, (n - 1) / 2);
}