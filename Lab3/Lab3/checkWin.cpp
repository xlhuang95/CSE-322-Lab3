/*
d is the dimention of the game
c is the number of continuse game pieces required to win
*/
bool win(vector <vector<string> > board, int d, int c) {
	for (size_t i = 0; i < d-c; i++)
	{
		for (size_t j = 0;  j < d - c;  j++)
		{
			int rowCt = 0;
			int colCt = 0;
			int lDCt = 0;
			int rDCt = 0;
			for (size_t k = 0;  k < c;  k++)
			{
				// check row
				if (board[i][j + k] == board[i][j])
				{
					rowCt++;
					if (rowCt == c)
					{
						return true;
					}
				}
				
				// check col
				if (board[i + k][j] == board[i][j])
				{
					colCt++;
					if (colCt == c)
					{
						return true;
					}
				}
				
				// check diagonal from the left  
				if (board[i+k][j+k] == board[i][j])
				{
					lDCt++;
					if (lDCt == c)
					{
						return true;
					}
				}

				// check diagonal from the right
				if (board[d - i - 1 - k][d - j - 1 - k] == board[d - i - 1][d - j - 1])
				{
					rDCt++;
					if (rDCt == c)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
