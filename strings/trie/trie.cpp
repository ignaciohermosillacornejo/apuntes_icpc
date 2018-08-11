#include "../../headers/headers/headers.h"

class Trie
{
  private:
    vector<unordered_map<char, int>> nodes;
    int next;

  public:
    Trie()
    {
        nodes.eb();
        next = 1;
    }

    bool build(string s)
    {
        int i = 0;
        int v = 0;
        while (i < s.size())
        {
            if (nodes[v].find(s[i]) == nodes[v].end())
            {
                nodes.eb();
                v = nodes[v][s[i]] = next;
                i++;
                next++;
            }
            else
            {
                v = nodes[v][s[i]];
                i++;
            }
        }
    }
};