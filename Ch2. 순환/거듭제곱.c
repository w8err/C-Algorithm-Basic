double °ÅµìÁ¦°ö(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)	
		return °ÅµìÁ¦°ö(x * x, n / 2);
	else return x * °ÅµìÁ¦°ö(x * x, (n - 1) / 2);
}