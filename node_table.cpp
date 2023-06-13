//
// Created by lc201 on 2023/6/13.
//

#include "node_table.h"
GomokuNode node[169];
NodeTable table_x[15];
NodeTable table_y[15];
NodeTable table_z[15];
void GomokuNode::init_node(int x, int y, int z) {
    line_x = x;
    line_y = y;
    line_z = z;
}
void NodeTable::init_table(GomokuNode * node_input,int length) {
    for (int i=0;i<length;i++) {
        this->node[i] = &node_input[i];
    }
    this->length = length;
}
void init_board_data()
{
    int x,y,z;
    for (int i = 0; i < ; ++i) {
        node[i].init_node(i,i,i);
    }


}