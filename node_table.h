//
// Created by lc201 on 2023/6/13.
//

#ifndef DELTA_WUZIQI_NODE_TABLE_H
#define DELTA_WUZIQI_NODE_TABLE_H


class GomokuNode {
    int status;
    int line_x,line_y,line_z;
public:
    void init_node(int x,int y,int z);
};

class NodeTable {
    int length;
    GomokuNode * node[15]{};
public:
    NodeTable(){
        length = 0;
        for (auto & i : this->node) {
            i = nullptr;
        }
    };
    void init_table(GomokuNode * node,int length);
    int find_same();
};


#endif //DELTA_WUZIQI_NODE_TABLE_H
