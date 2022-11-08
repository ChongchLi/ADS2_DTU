#include<bits/stdc++.h>

#define print(x) std::cout << x << std::endl

int main()
{
	int Delta = 1; // Penalty score
	int Penalty_Para = 1; // characters dismatch penalty
	std::string X, Y;
	std::getline(std::cin, X);
	std::getline(std::cin, Y);
	int nX = X.length();
	int nY = Y.length();
	std::vector<std::vector<int> > SA(nX + 1, std::vector<int>(nY + 1, 0)); // create dynamic matrix 
	std::vector<std::vector<int> > alpha(nX + 1, std::vector<int>(nY + 1, 0)); // create a(xi,yi)

	// initialization
	for (int i = 0; i <= nX; i++)
	{
		SA[i][0] = i * Delta;
	}
	for (int j = 0; j <= nY; j++)
	{
		SA[0][j] = j * Delta;
	}

	for (int i = 0; i < nX; i++)
	{
		for (int j = 0; j < nY; j++)
		{
			if (X[i] == Y[j])
			{
				alpha[i + 1][j + 1] = 0;
			}
			else alpha[i + 1][j + 1] = Penalty_Para;
		}
	}

	for (int i = 1; i <= nX; i++)
	{
		for (int j = 1; j <= nY; j++)
		{
			int SA_diag = SA[i - 1][j - 1];
			int SA_up = SA[i - 1][j]; 
			int SA_left = SA[i][j - 1];
			SA[i][j] = std::min({ alpha[i][j] + SA_diag, Delta + SA_up, Delta + SA_left });
		}
	}

	std::string X_out;
	std::string Y_out;
	int row = nX;
	int col = nY;

	while (row > 0 || col > 0)
	{
		if (row == 0)
		{
			X_out.push_back('-');
			Y_out.push_back(col > 0 ? Y[col - 1] : '-');
			col--;
			continue;
		}
		else if (col == 0)
		{
			X_out.push_back(row > 0 ? X[row - 1] : '-');
			Y_out.push_back('-');
			row--;
			continue;
		}
		int SA_min = std::min({ SA[row - 1][col - 1],SA[row][col - 1],SA[row - 1][col] });
		if (SA[row - 1][col - 1] == SA_min)
		{
			X_out.push_back(row > 0 ? X[row - 1] : '-');
			Y_out.push_back(col > 0 ? Y[col - 1] : '-');
			row--;
			col--;
		}
		else if (SA[row][col - 1] == SA_min)
		{
			X_out.push_back('-');
			Y_out.push_back(col > 0 ? Y[col - 1] : '-');
			col--;
		}
		else if (SA[row - 1][col] == SA_min)
		{
			X_out.push_back(row > 0 ? X[row - 1] : '-');
			Y_out.push_back('-');
			row--;
		}
	}

	std::reverse(X_out.begin(), X_out.end());
	std::reverse(Y_out.begin(), Y_out.end());

	print(X_out);
	print(Y_out);
	return 0;
}

