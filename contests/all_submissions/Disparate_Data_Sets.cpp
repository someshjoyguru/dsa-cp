#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define vll vector<ll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
// #define sort(v) sort(all(v));
#define pYES cout<<'YES'<<endl;
#define pNO cout<<'NO'<<endl;

struct Event {
    string event_id;
    string title;
    string acronym;
    string project_code;
    string project_code_3_digit;
    string record_type;
    string parent_id;
};

void parseInput(vector<Event>& events) {
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);
        Event event;
        string tmp;
        getline(ss, event.event_id, ',');
        getline(ss, tmp, '"');
        getline(ss, event.title, '"');
        // cout<<event.title<<endl;
        getline(ss, tmp, '"');
        getline(ss, event.acronym, '"');
        // cout<<event.acronym<<endl;
        getline(ss, tmp, ',');
        getline(ss, event.project_code, ',');
        // cout<<event.project_code<<endl;
        getline(ss, event.project_code_3_digit, ',');
        // cout<<event.project_code_3_digit<<endl;
        getline(ss, tmp, '"');
        getline(ss, event.record_type, '"');
        // cout<<event.record_type<<endl;
        events.push_back(event);
    }
}

void processEvents(const vector<Event>& events, vector<Event>& output) {
    unordered_map<string, Event> parents;
    unordered_map<string, vector<Event>> children;

    for (const auto& event : events) {
        if (event.acronym.empty()) continue;
        if (event.record_type == "Parent Event") {
            if (parents.count(event.acronym)) {
                parents[event.acronym].event_id = "";
            } else {
                parents[event.acronym] = event;
            }
        } else if (event.record_type == "IEEE Event") {
            children[event.acronym].push_back(event);
        }
    }

    for (auto& [acronym, parent] : parents) {
        if (parent.event_id.empty()) continue;
        auto& child_list = children[acronym];
        if (child_list.empty()) continue;

        unordered_set<string> unique_codes;
        for (const auto& child : child_list) {
            unique_codes.insert(child.project_code_3_digit);
        }
        parent.project_code_3_digit = (unique_codes.size() == 1) ? *unique_codes.begin() : "???";

        output.push_back(parent);
        sort(child_list.begin(), child_list.end(), [](const Event& a, const Event& b) {
            return a.title < b.title || (a.title == b.title && a.event_id < b.event_id);
        });
        for (auto& child : child_list) {
            child.parent_id = parent.event_id;
            output.push_back(child);
        }
    }
}

void printOutput(const vector<Event>& output) {
    for (const auto& event : output) {
        cout << event.event_id << ",\"" << event.title << "\",\"" << event.acronym << "\","
             << event.project_code << "," << event.project_code_3_digit << ",\"" << event.record_type << "\"";
        if (event.record_type == "IEEE Event") {
            cout << "," << event.parent_id;
        }
        cout << endl;
    }
}

int main() {
    vector<Event> events;
    vector<Event> output;

    parseInput(events);
    processEvents(events, output);
    printOutput(output);


    return 0;
}
