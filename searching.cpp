#include "searching.h"

void computeLPS(std::string pat, int* lps)
{
	int j = 0;

	lps[0] = 0; // lps[0] is always 0

	int i = 1;

	while (i < pat.size())
	{
		if (pat[i] == pat[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}


bool isKPeriodic(std::string& txt, int K)
{
	int* lps = new int[K];

	std::string pat;
	pat.resize(K);

	for (int i = 0; i < K; i++)
	{
		pat[i] = txt[i];
	}

	computeLPS(pat, lps);

	int i = 0, j = 0;

	int count = 0;

	while (i < txt.size())
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
		if (j == pat.size())
		{
			std::cout << "Found pattern at index" << i - j << std::endl;
			j = lps[j - 1];
			count++;
		}
		else if (i < txt.size() && pat[j] != txt[i])
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i = i + 1;
			}
		}
	}

	if (count == K - 1)
	{
		std::cout << "K is periodic of text";
		return 1;
	}
	else
	{
		std::cout << "K is not periodic of text";
		return 0;
	}

}
