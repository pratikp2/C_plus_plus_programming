#include <iostream>
#include <vector>
using namespace std;

void SortSampleInDescendingOrder(vector<string>& sample)
{
	// Sort the vector According to Size
	for (int i = 0; i < sample.size(); i++)
	{
		string temp = sample[i];

		int j = i - 1;
		while (j >= 0 && temp.length() < sample[j].length())
		{
			sample[j + 1] = sample[j];
			j--;
		}
		sample[j + 1] = temp;
	}

	// Reverse the vector to get words sorted by descending order of its length
	std::reverse(sample.begin(), sample.end());
}

vector<string> GetConcatinationList(vector<string> sample, int N)
{
	vector<string> result;

	// Sort sample in Descending order by size of strings
	SortSampleInDescendingOrder(sample);

	// Take the Biggest string and check in the sample vector for its possible concatenation.
	for (int i = 0; i < sample.size() - 2; i++)
	{
		// Check if size exceeds the parameter "N"
		if (sample[i].length() > N)
			continue;

		// Pick 1st word for possible concatenation
		for (int j = i + 1; j < sample.size() - 1; j++)
		{
			/*if (sample[i].length() == sample[j].length())		// Should be enabled if sample vectors do not have empty values.
				continue;*/

				// Pick the 2nd word for possible concatenation
			for (int k = j + 1; k < sample.size(); k++)
			{
				if (sample[i].length() == sample[j].length() + sample[k].length() &&
					(sample[i] == sample[j] + sample[k] || sample[i] == sample[k] + sample[j]))
				{
					result.push_back(sample[i]);

					// Push in vector only if sample string do not exist already in result vector 
					if (!std::count(result.begin(), result.end(), sample[j]))
						result.push_back(sample[j]);

					if (!std::count(result.begin(), result.end(), sample[k]))
						result.push_back(sample[k]);
				}
			}
		}
	}

	return result;
}

string isBalanced(string s)
{
	vector<char> holder;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '{')
			holder.push_back('}');
		else if (s[i] == '(')
			holder.push_back(')');
		else if (s[i] == '[')
			holder.push_back(']');
		else if (holder.size() != 0 && s[i] == holder[holder.size() - 1])
			holder.pop_back();
		else
		{
			cout << i << endl;
			return "NO";
		}
	}
	cout << -1 << endl;
	return "YES";
}


int main()
{
	cout << isBalanced("[(");
	vector<string> vec1{ "cat", "dog", "bird", "snow", "snowbird", "tail", "hot", "tailor", "or", "hotdog" };
	vector<string> concat = GetConcatinationList(vec1, 6);

	for (int i = 0; i < concat.size(); i++)
		cout << concat[i] << " ";

	return 0;
}