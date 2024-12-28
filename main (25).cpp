#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

// Helper function to check if two words differ by one letter
bool differByOne(const string& word1, const string& word2) {
    int count = 0;
    for (int i = 0; i < word1.size(); ++i) {
        if (word1[i] != word2[i]) {
            count++;
            if (count > 1) return false;
        }
    }
    return count == 1;
}

// BFS to build the graph (adjacency list)
void bfsBuildGraph(const string& beginWord, const string& endWord, unordered_set<string>& wordSet,
                   unordered_map<string, vector<string>>& graph, unordered_map<string, int>& distances) {
    queue<string> q;
    q.push(beginWord);
    distances[beginWord] = 0;

    while (!q.empty()) {
        string currentWord = q.front();
        q.pop();

        for (int i = 0; i < currentWord.size(); ++i) {
            string temp = currentWord;
            for (char c = 'a'; c <= 'z'; ++c) {
                temp[i] = c;

                if (wordSet.find(temp) != wordSet.end()) {
                    if (distances.find(temp) == distances.end()) { // New word
                        distances[temp] = distances[currentWord] + 1;
                        q.push(temp);
                    }

                    // Add edge if the word is part of the shortest path
                    if (distances[temp] == distances[currentWord] + 1) {
                        graph[currentWord].push_back(temp);
                    }
                }
            }
        }
    }
}

// DFS to find all shortest paths
void dfsPaths(const string& currentWord, const string& endWord, unordered_map<string, vector<string>>& graph,
              vector<string>& path, vector<vector<string>>& result) {
    path.push_back(currentWord);

    if (currentWord == endWord) {
        result.push_back(path);
    } else {
        for (const string& neighbor : graph[currentWord]) {
            dfsPaths(neighbor, endWord, graph, path, result);
        }
    }

    path.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return {};

    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> distances;

    bfsBuildGraph(beginWord, endWord, wordSet, graph, distances);

    vector<vector<string>> result;
    vector<string> path;
    dfsPaths(beginWord, endWord, graph, path, result);

    return result;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> result = findLadders(beginWord, endWord, wordList);

    cout << "All shortest transformation sequences:\n";
    for (const auto& sequence : result) {
        for (const string& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
