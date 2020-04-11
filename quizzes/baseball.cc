#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	vector<int> away,home;
	while (true) {
		int temp1 = 0,temp2 = 0;
		cin >> temp1 >> temp2;
		if (!cin or temp1 < 0 or temp2 < 0) break;
		away.push_back(temp1);
		home.push_back(temp2);
	}
	if (!home.size() or !away.size()) {
		cout << "Sum is 0, avg is 0, whatever, it's all zeroes.\n";
		exit(0);
	}
	//If we get to here, we know there is at least 1 inning in each
	//THIS IS CALLED AN INVARIANT

	//Sum up the vectors
	int away_sum = 0, home_sum = 0;
	for (int x : away) away_sum += x; //Option 1
	for (int x : home) home_sum += x; 
	//away_sum = accumulate(away.begin(),away.end(),0); //Option 2
	//home_sum = accumulate(home.begin(),home.end(),0); 
	cout << "Away: " << away_sum << " Home: " << home_sum << endl;
	if (away_sum > home_sum) cout << "Away team wins!\n";
	else if (home_sum > away_sum) cout << "Home team wins!\n";
	else cout << "Tie?? Is that possible?\n";
	cout << "Away team averaged: " << double(away_sum) / away.size() << endl;
	cout << "Home team averaged: " << double(home_sum) / home.size() << endl;
	cout << "Total inning score averaged: " << double(home_sum+away_sum) / (double(home.size()+away.size())/2) << endl;
	//Option 1
	int max_score = INT_MIN; //-2B ish
	int min_score = INT_MAX; //2B ish
	for (int x : away) {
		if (max_score < x) max_score = x;
		if (min_score > x) min_score = x;
	}
	for (int x : home) {
		if (max_score < x) max_score = x;
		if (min_score > x) min_score = x;
	}
	cout << "Min: " << min_score << " Max: " << max_score << endl;

	//Option 2 - Medium Difficulty, but less typing
	auto away_minmax = minmax_element(away.begin(),away.end());
	auto home_minmax = minmax_element(home.begin(),home.end());
	cout << "Away min: " << *away_minmax.first << " Away max: " << *away_minmax.second << endl;
	cout << "Home min: " << *home_minmax.first << " Home max: " << *home_minmax.second << endl;

	//Auto mean deduce the type of the variable from the right hand side
	//auto bob; //CANNOT DO THAT - WAIT, THAT'S ILLEGAL
	//cin >> bob;
}

















