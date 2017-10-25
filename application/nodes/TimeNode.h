/*
 * TimeNode.h
 *
 *  Created on: 2017. okt. 25.
 *      Author: peti
 */

#ifndef NODES_TIMENODE_H_
#define NODES_TIMENODE_H_

#include <mprotocol-nodes/Node.h>

class TimeNode: public Node {
    DECLARE_PROP_STRING_RO(Time);
    DECLARE_PROP_STRING_RO(UpTime);
public:
    TimeNode();
    virtual ~TimeNode() {}
};

#endif /* NODES_TIMENODE_H_ */
