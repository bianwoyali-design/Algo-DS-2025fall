#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Station
{
    int distance;
    int fuel;
    Station(int d, int f) : distance(d), fuel(f) {}
};

class FuelTrip {
private:
    vector<Station> stations;
    int totalDistance;
    int initialFuel;
    int n;
public:
    FuelTrip() : totalDistance(0), initialFuel(0), n(0) {}

    void readInput() {
        cin >> n;
        stations.reserve(n);
        for (int i = 0; i < n; ++i) {
            int d, f;
            cin >> d >> f;
            stations.emplace_back(d, f);
        }
        cin >> totalDistance >> initialFuel;
    }

    int minRefuels() {
        sort(stations.begin(), stations.end(), [](const Station &a, const Station &b) {
            return a.distance > b.distance;
        });
        int ans = 0, fuel = initialFuel, i = 0;
        priority_queue<int> pq;
        while (fuel < totalDistance) {
            while (i < n && totalDistance - stations[i].distance <= fuel) {
                pq.push(stations[i].fuel);
                ++i;
            }
            if (pq.empty())
                return -1;
            fuel += pq.top();
            pq.pop();
            ++ans;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    FuelTrip trip;
    trip.readInput();
    cout << trip.minRefuels();
    return 0;
}