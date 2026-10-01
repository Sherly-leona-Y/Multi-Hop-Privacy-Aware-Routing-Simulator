#ifndef PRIVACY_H
#define PRIVACY_H

#include <vector>

using namespace std;

class Privacy {
public:
    static int calculatePrivacyRisk(const vector<int>& path);

    static bool isPrivacySafe(
        const vector<int>& path,
        int maximumRisk
    );

    static void displayPrivacyReport(
        const vector<int>& path,
        int risk
    );
};

#endif