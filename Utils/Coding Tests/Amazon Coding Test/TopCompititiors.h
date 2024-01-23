#pragma once
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int calculateCount(vector<string> reviews, string company)
{
	int count = 0;

	for (int i = 0; i < reviews.size(); i++)
		if (reviews[i].find(company) != string::npos)
			count++;

	return count;
}

vector<string> topNCompititiors(int numCompititiors, int topNCompititiors, vector<string> compititiors,int numReviews, vector<string> reviews)
{
	map<string,int> count;
	vector<string> target;

	for (int i = 0; i < numCompititiors; i++)
		count.insert(pair <string, int> (compititiors[i],calculateCount(reviews,compititiors[i])));


	for (int i = 0; i < topNCompititiors; i++)
	{
		string tempstr = count.begin()->first;
		int tempint = count.begin()->second;

		for (auto var : count)
			if (var.second > tempint)
				tempstr = var.first;

		target.push_back(tempstr);
		count.erase(tempstr);
	}

	return target;
}
