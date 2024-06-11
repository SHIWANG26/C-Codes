#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct SocialmediaPost
{
    string author, content, timestamp;
    int likes;
};
struct Influencers
{
    string username;
    int followers;
};
string analyse_sentiment(const string &content)
{
    return "Positive";
}
int main()
{
    vector<SocialmediaPost> socialmediaPost = {{"UserA", "Great day at the beach", "10:00:00", 100}, {"UserB", "Feeling sad today", "11:00:00", 50}};
    unordered_map<string, int> sentimentCount;
    unordered_map<string, int> trendCount;
    for (const SocialmediaPost &post : socialmediaPost)
    {
        string sentiment = analyse_sentiment(post.content);
        sentimentCount[sentiment]++;

        size_t pos = post.content.find('#');

        while (pos != string : npos)
        {
            string trend = post.content.substr(pos + 1, pos.content.find(' ', pos) - pos - 1);
            trendCount[trend]++;
            pos = pos.content.find('#', pos + 1);
        }
    }
    cout<<"Sentiment analysis\n";
    
}