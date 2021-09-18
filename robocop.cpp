#include<iostream>
#include<vector>
#include<list>
using namespace std;
typedef pair<int, int> pii;

int pointDiff(const pii& p1, const pii& p2) {
	int xDiff = p1.first - p2.first;
	int yDiff = p1.second - p2.second;

	if (xDiff != 0) return xDiff;
	else return yDiff;
}

int calcLength(const vector<pii>& points){
	int len = 0;
	int size = points.size();

	for (int i = 0; i < size - 1; i++) 
		len += abs(pointDiff(points.at(i), points.at(i + 1)));
	return len;
}

bool toX(const pii& base, const pii& toGo) {
	int xDiff = base.first - toGo.first;

	if (xDiff != 0) return true;
	else return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numPoints;
	cin >> numPoints;
	vector<pii> points;
	for (int i = 0; i < numPoints; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	points.push_back(points.at(0));
	
	vector<int> diffs;
	for (int i = 1; i <= numPoints; i++) 
		diffs.push_back(pointDiff(points.at(i), points.at(i - 1)));

	int fullLength = calcLength(points);

	for (int i = 0; i < 5; i++) {
		int time; cin >> time;
		int idx = 0;

		time %= fullLength;
		
		while (time >= abs(diffs.at(idx))) {
			time -= abs(diffs.at(idx));
			idx++;
		}

		pii location = points.at(idx);
		pii nextPoint = points.at(idx + 1);

		if (toX(location, nextPoint)) {
			if (diffs.at(idx) > 0) location.first += time;
			else location.first -= time;
		}
		else {
			if (diffs.at(idx) > 0) location.second += time;
			else location.second -= time;
		}
		cout << location.first << " " << location.second << endl;
	}
	return 0;
}