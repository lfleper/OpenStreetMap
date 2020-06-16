//
// Created by lfleper on 08.06.20.
//

#include "Node.h"

Node::Node(long id, bool visible, int version, int changeset, const string &timestamp, const string &user, int uid,
           double lat, double lon, const vector<tag_t> &tag) : id(id), visible(visible), version(version),
                                                               changeset(changeset), timestamp(timestamp), user(user),
                                                               uid(uid), lat(lat), lon(lon), tag(tag) {}

bool Node::isVisible() const {
    return visible;
}

void Node::setVisible(bool visible) {
    Node::visible = visible;
}

int Node::getVersion() const {
    return version;
}

void Node::setVersion(int version) {
    Node::version = version;
}

int Node::getChangeset() const {
    return changeset;
}

void Node::setChangeset(int changeset) {
    Node::changeset = changeset;
}

const string &Node::getTimestamp() const {
    return timestamp;
}

void Node::setTimestamp(const string &timestamp) {
    Node::timestamp = timestamp;
}

const string &Node::getUser() const {
    return user;
}

void Node::setUser(const string &user) {
    Node::user = user;
}

int Node::getUid() const {
    return uid;
}

void Node::setUid(int uid) {
    Node::uid = uid;
}

double Node::getLat() const {
    return lat;
}

void Node::setLat(double lat) {
    Node::lat = lat;
}

double Node::getLon() const {
    return lon;
}

void Node::setLon(double lon) {
    Node::lon = lon;
}

const vector<tag_t> &Node::getTag() const {
    return tag;
}

void Node::setTag(const vector<tag_t> &tag) {
    Node::tag = tag;
}

long Node::getId() const {
    return id;
}

void Node::setId(long id) {
    Node::id = id;
}
