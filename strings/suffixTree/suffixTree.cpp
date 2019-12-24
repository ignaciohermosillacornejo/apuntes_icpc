#include "../../headers/headers.h"

struct Node{
    //map<int,int> children;
    vector<int> children;
    int suffix_link;
    int start;
    int end;
    
    Node(int start, int end):start(start),end(end){
        children.resize(27,-1);
        suffix_link = 0;
    }
    inline bool has_child(int i){
        //return children.find(i) != children.end();
        return children[i] != -1;
    }
};

struct SuffixTree{
    int size;
    int i;
    vector<int> suffix_array;
    vector<Node> tree;
    inline int length(int index){
        if(tree[index].end == -1)
            return i - tree[index].start + 1;
        return tree[index].end-tree[index].start+1;
    }
    //se puede usar string& s
    SuffixTree(vector<int>& s){
        size = s.size();
        tree.emplace_back(-1,-1);
        int remaining_suffix = 0;
        int active_node = 0;
        int active_edge = -1;
        int active_length = 0;
        for(i = 0; i < size; ++i){
            int last_new = -1;
            remaining_suffix++;
            while(remaining_suffix > 0){
                if(active_length == 0)
                    active_edge = i;
                if(!tree[active_node].has_child(s[active_edge])){
                    tree[active_node].children[s[active_edge]] = tree.size();
                    tree.emplace_back(i,-1);
                    if(last_new != -1){
                        tree[last_new].suffix_link = active_node;
                        last_new = -1;
                    }
                }
                else{
                    int next = tree[active_node].children[s[active_edge]];
                    if(active_length >= length(next)){
                        active_edge += length(next);
                        active_length -= length(next);
                        active_node = next;
                        continue;
                    }
                    if(s[tree[next].start + active_length] == s[i]){
                        if(last_new != -1 and active_node != 0){
                            tree[last_new].suffix_link = active_node;
                        }
                        active_length++;
                        break;
                    }
                    int split_end = tree[next].start + active_length - 1;
                    int split = tree.size();
                    tree.emplace_back(tree[next].start,split_end);
                    tree[active_node].children[s[active_edge]] = split;
                    int new_leaf = tree.size();
                    tree.emplace_back(i,-1);
                    tree[split].children[s[i]] = new_leaf;
                    tree[next].start += active_length;
                    tree[split].children[s[tree[next].start]] = next;
                    if(last_new != -1){
                        tree[last_new].suffix_link = split;
                    }
                    last_new = split;
                }
                remaining_suffix--;
                if(active_node == 0 and active_length > 0){
                    active_length--;
                    active_edge = i - remaining_suffix + 1;
                }
                else if(active_node != 0){
                    active_node = tree[active_node].suffix_link;
                }
            }
        }
        i = size - 1;
    }
    vector<int> lcp;
    //last for lcp
    void dfs(int node, int& index, int depth,int min_depth){
        if(tree[node].end == -1 and node != 0){
            suffix_array[index] = size - depth;
            if(index != 0){
                lcp[index-1] = min_depth;
            }
            index++;
        }
        for(auto it: tree[node].children){
            //if(i.second != -1){
            //    dfs(i.second,index,depth + length(i.second));
            //    min_depth = depth;
            //}
            if(it != -1){
                dfs(it,index,depth + length(it),min_depth);
                min_depth = depth;
            }
        }
    }
    void build_suffix_array(){
        suffix_array.resize(size,0);
        lcp.resize(size,0);
        int index = 0;
        int depth = 0;
        dfs(0,index,0,0);
    }
    
    // pensado para map<int,int>, pero puede modificarse para vector<int>
    bool match(string& a, string& base){
        int active_node = 0;
        int active_length = 0;
        int active_char = -1;
        for(int i = 0; i < a.size();){
            if(active_length == 0){
                if(!tree[active_node].has_child(a[i]))
                    return false;
                active_char = a[i];
                active_length++;
                i++;
                continue;
            }
            int next = tree[active_node].children[active_char];
            if(active_length == length(next)){
                active_node = next;
                active_length = 0;
                active_char = -1;
                continue;
            }
            if((base)[tree[next].start + active_length] != a[i])
                return false;
            active_length++;
            i++;
        }
        return true;
    }
};
