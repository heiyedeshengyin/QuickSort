#include<iostream>
using namespace std;

void quicksort(int left, int right, int *p);
int main()
{
	int i, j, n;
	cin >> n;
	int *a = new int[n];
	for (i = 0; i < n; i++)
		cin >> a[i];

	quicksort(0, n - 1, a);

	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	delete[] a;
	return 0;
}

void quicksort(int left, int right, int *p)
{
	int i, j, t, temp;
	if (left > right)
		return;

	temp = *(p + left);
	i = left;
	j = right;
	while (i != j)
	{
		while (*(p + j) >= temp && i < j)
			j--;
		while (*(p + i) <= temp && i < j)
			i++;

		if (i < j)
		{
			t = *(p + i);
			*(p + i) = *(p + j);
			*(p + j) = t;
		}
	}
	*(p + left) = *(p + i);
	*(p + i) = temp;

	quicksort(left, i - 1, p);
	quicksort(i + 1, right, p);
}