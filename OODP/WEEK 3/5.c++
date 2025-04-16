#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <iomanip>
#include <algorithm>

enum class VoteStatus {
    CAST,
    INVALID
};

class Candidate {
private:
    std::string candidateID;
    std::string name;
    std::string party;

public:
    Candidate(std::string id, std::string n, std::string p = "") : candidateID(id), name(n), party(p) {}

    std::string getName() const { return name; }
    std::string getParty() const { return party; }
    std::string getCandidateID() const { return candidateID; }

    void display() const {
        std::cout << "  Candidate ID: " << candidateID << std::endl;
        std::cout << "  Name: " << name << std::endl;
        if (!party.empty()) {
            std::cout << "  Party: " << party << std::endl;
        }
    }
};

class Election {
private:
    std::string electionID;
    std::string name;
    std::time_t startDate;
    std::time_t endDate;
    std::vector<Candidate> candidates;
    bool isOngoing;
    std::map<std::string, int> results; // CandidateID -> VoteCount

public:
    Election(std::string id, std::string n, std::time_t start, std::time_t end)
        : electionID(id), name(n), startDate(start), endDate(end), isOngoing(false) {}

    void addCandidate(const Candidate& candidate) {
        candidates.push_back(candidate);
        results[candidate.getCandidateID()] = 0; // Initialize vote count
    }

    void removeCandidate(const std::string& candidateID) {
        auto it = std::remove_if(candidates.begin(), candidates.end(),
                                [&](const Candidate& c){ return c.getCandidateID() == candidateID; });
        if (it != candidates.end()) {
            candidates.erase(it, candidates.end());
            results.erase(candidateID);
        }
    }

    void startElection() { isOngoing = true; }
    void endElection() { isOngoing = false; }
    bool getIsOngoing() const { return isOngoing; }
    std::string getElectionID() const { return electionID; }
    std::string getName() const { return name; }
    const std::vector<Candidate>& getCandidates() const { return candidates; }

    void recordVote(const std::string& candidateID) {
        if (results.count(candidateID)) {
            results[candidateID]++;
        }
    }

    std::map<std::string, int> getResults() const { return results; }

    void displayCandidates() const {
        std::cout << "  Candidates:" << std::endl;
        for (const auto& candidate : candidates) {
            candidate.display();
        }
    }

    void displayResults() const {
        std::cout << "\n--- Election Results for " << name << " ---" << std::endl;
        for (const auto& pair : results) {
            for (const auto& candidate : candidates) {
                if (candidate.getCandidateID() == pair.first) {
                    std::cout << "  " << candidate.getName() << ": " << pair.second << " votes" << std::endl;
                    break;
                }
            }
        }
    }
};

class Ballot {
private:
    std::string ballotID;
    std::string electionID;
    std::string voterID;
    std::string selectedCandidateID;
    std::time_t voteTime;
    VoteStatus status;

public:
    Ballot(std::string id, std::string eID, std::string vID)
        : ballotID(id), electionID(eID), voterID(vID), selectedCandidateID(""), voteTime(0), status(VoteStatus::INVALID) {}

    bool recordVote(const std::string& candidateID, std::time_t time) {
        selectedCandidateID = candidateID;
        voteTime = time;
        status = VoteStatus::CAST;
        return true; // Basic success
    }

    VoteStatus getStatus() const { return status; }
    std::string getVoterID() const { return voterID; }
    std::string getElectionID() const { return electionID; }
    std::string getSelectedCandidateID() const { return selectedCandidateID; }
    std::time_t getVoteTime() const { return voteTime; }

    void display() const {
        std::cout << "  Ballot ID: " << ballotID << std::endl;
        std::cout << "  Election ID: " << electionID << std::endl;
        std::cout << "  Voter ID: " << voterID << std::endl;
        std::cout << "  Selected Candidate ID: " << selectedCandidateID << std::endl;
        std::cout << "  Vote Time: " << std::ctime(&voteTime);
        std::cout << "  Status: ";
        if (status == VoteStatus::CAST) std::cout << "CAST" << std::endl;
        else std::cout << "INVALID" << std::endl;
    }
};

class Voter {
private:
    std::string voterID;
    std::string name;
    std::string address;
    std::map<std::string, bool> hasVotedInElection; // ElectionID -> hasVoted

public:
    Voter(std::string id, std::string n, std::string addr) : voterID(id), name(n), address(addr) {}

    std::string getVoterID() const { return voterID; }
    std::string getName() const { return name; }

    bool canVote(const std::string& electionID) const {
        return hasVotedInElection.find(electionID) == hasVotedInElection.end() || !hasVotedInElection.at(electionID);
    }

    void markAsVoted(const std::string& electionID) {
        hasVotedInElection[electionID] = true;
    }

    void display() const {
        std::cout << "Voter ID: " << voterID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Address: " << address << std::endl;
    }
};

class Administrator {
private:
    std::string adminID;
    std::string username;
    std::string password;

public:
    Administrator(std::string id, std::string user, std::string pass) : adminID(id), username(user), password(pass) {}

    bool login(const std::string& user, const std::string& pass) const {
        return username == user && password == pass;
    }

    void manageVoters() { std::cout << "Managing voters..." << std::endl; }
    void manageElections() { std::cout << "Managing elections..." << std::endl; }
    void manageCandidates() { std::cout << "Managing candidates..." << std::endl; }
    void viewAuditLog() { std::cout << "Viewing audit log..." << std::endl; }
};

class AuditLog {
private:
    struct LogEntry {
        std::string logID;
        std::time_t timestamp;
        std::string action;
        std::string performedBy;
        std::string details;
    };
    std::vector<LogEntry> logs;
    int nextLogID = 1;

public:
    void recordEvent(const std::string& action, const std::string& performedBy, const std::string& details) {
        LogEntry entry;
        entry.logID = std::to_string(nextLogID++);
        entry.timestamp = std::time(nullptr);
        entry.action = action;
        entry.performedBy = performedBy;
        entry.details = details;
        logs.push_back(entry);
    }

    void viewLogs(const std::string& filter = "") const {
        std::cout << "\n--- Audit Log ---" << std::endl;
        std::tm t{};
        for (const auto& log : logs) {
            std::cout << "Log ID: " << log.logID << std::endl;
            t = *std::localtime(&log.timestamp);
            std::cout << "Timestamp: " << std::put_time(&t, "%Y-%m-%d %H:%M:%S") << std::endl;
            std::cout << "Action: " << log.action << std::endl;
            std::cout << "Performed By: " << log.performedBy << std::endl;
            std::cout << "Details: " << log.details << std::endl;
            std::cout << "-------------" << std::endl;
        }
    }
};

int main() {
    // Example Usage
    Administrator admin("admin1", "admin", "password");
    if (admin.login("admin", "password")) {
        std::cout << "Admin logged in." << std::endl;
        admin.manageVoters();
    }

    Voter voter1("voter001", "Alice", "123 Main St");
    Voter voter2("voter002", "Bob", "456 Oak Ave");
    voter1.display();

    Election election1("elec2025-01", "Local Council Election", std::time(nullptr), std::time(nullptr) + 3600 * 24 * 7);
    Candidate cand1("cand001", "Charlie Brown", "Independent");
    Candidate cand2("cand002", "Lucy Van Pelt", "Progressive");
    election1.addCandidate(cand1);
    election1.addCandidate(cand2);
    election1.startElection();
    election1.displayCandidates();

    Ballot ballot1("ballot001", election1.getElectionID(), voter1.getVoterID());
    if (voter1.canVote(election1.getElectionID()) && election1.getIsOngoing()) {
        if (ballot1.recordVote(cand1.getCandidateID(), std::time(nullptr))) {
            election1.recordVote(cand1.getCandidateID());
            voter1.markAsVoted(election1.getElectionID());
            std::cout << voter1.getName() << " cast their vote." << std::endl;
        }
    }

    Ballot ballot2("ballot002", election1.getElectionID(), voter2.getVoterID());
    if (voter2.canVote(election1.getElectionID()) && election1.getIsOngoing()) {
        if (ballot2.recordVote(cand2.getCandidateID(), std::time(nullptr))) {
            election1.recordVote(cand2.getCandidateID());
            voter2.markAsVoted(election1.getElectionID());
            std::cout << voter2.getName() << " cast their vote." << std::endl;
        }
    }

    election1.endElection();
    election1.displayResults();

    AuditLog logger;
    logger.recordEvent("Voter Registered", voter1.getVoterID(), "Voter Alice registered.");
    logger.recordEvent("Vote Cast", voter1.getVoterID(), "Voter Alice voted for Charlie Brown in Local Council Election.");
    logger.viewLogs();

    return 0;
}