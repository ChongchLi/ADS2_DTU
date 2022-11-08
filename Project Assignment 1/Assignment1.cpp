#include <iostream>
#include <vector>

#define print(x) std::cout << x << std::endl
#define max(X,Y) ((X) > (Y) ? (X) : (Y))

int main()
{
	// input line 1 (The integer n~[1,2000])
	int n;
	std::cin >> n;

	// input line 2 
	std::vector<int> Data;
	int input_d;
	for (int i = 0; i < n; i++)
	{
		std::cin >> input_d;
		Data.push_back(input_d);
	}
	//print(Data[0]);
	//Data.erase(Data.begin());
	//print(Data[0]);

	// output
	// DP initialize
	std::vector<std::vector<int> > first_dp(n);
	std::vector<std::vector<int> > second_dp(n);

	for (int i = 0; i < n; i++)
	{
		first_dp[i].resize(n);
		second_dp[i].resize(n);
		first_dp[i][i] = Data[i];
		second_dp[i][i] = 0;
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i+1; j < n; j++)
		{
			// first calculate first_dp, then second_dp
			first_dp[i][j] = max(Data[i] + second_dp[i + 1][j], Data[j] + second_dp[i][j - 1]);
			if (Data[i]>Data[j])
			{
				second_dp[i][j] = first_dp[i + 1][j];
			}
			else
			{
				second_dp[i][j] = first_dp[i][j - 1];
			}

		}
	}
	print(first_dp[0][n - 1]);
	

}