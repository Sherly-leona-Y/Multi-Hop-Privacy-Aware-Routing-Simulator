#include "privacy.h"
#include <iostream>

using namespace std;

int Privacy::calculatePrivacyRisk(const vector<int>& path) {
    if (path.empty()) {
        return 100;
    }

    int risk = 0;

    /*
        Each intermediate node represents another
        point where routing information may be exposed.

        Source and destination are not counted.
    */
    int intermediateNodes = path.size() - 2;

    if (intermediateNodes > 0) {
        risk += intermediateNodes * 10;
    }

    /*
        Longer paths increase the number of nodes
        through which information travels.
    */
    if (path.size() > 5) {
        risk += 20;
    }

    /*
        Keep the privacy risk within 0-100.
    */
    if (risk > 100) {
        risk = 100;
    }

    return risk;
}

bool Privacy::isPrivacySafe(
    const vector<int>& path,
    int maximumRisk
) {
    int risk = calculatePrivacyRisk(path);

    return risk <= maximumRisk;
}

void Privacy::displayPrivacyReport(
    const vector<int>& path,
    int risk
) {
    cout << "\nPrivacy Analysis:\n";

    cout << "Privacy Risk Score: "
         << risk << "/100\n";

    if (risk <= 30) {
        cout << "Privacy Level: LOW\n";
    }
    else if (risk <= 60) {
        cout << "Privacy Level: MEDIUM\n";
    }
    else {
        cout << "Privacy Level: HIGH\n";
    }

    if (path.size() >= 2) {
        cout << "Intermediate Nodes: "
             << path.size() - 2 << '\n';
    }
}