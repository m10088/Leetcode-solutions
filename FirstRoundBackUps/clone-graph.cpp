/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if(node == NULL)
            return NULL;
        
        if(m.find(node) != m.end())   
            return m[node];
            
        UndirectedGraphNode *nodeClone = new UndirectedGraphNode(node->label);
        m[node] = nodeClone;
        UndirectedGraphNode *nodeClonenull = NULL;
        for(int st = 0; st < node->neighbors.size(); st ++)
        {
            UndirectedGraphNode *temp = cloneGraph(node->neighbors[st]);
            if(temp != NULL)
                nodeClone->neighbors.push_back(temp);
            else 
                nodeClone->neighbors.push_back(nodeClonenull);
        }
        return nodeClone;
    }
};