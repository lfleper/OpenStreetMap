//
// Created by lfleper on 08.06.20.
//

#include "Way.h"

Way::Way(long id, bool visible, int version, int changeset, const string &timestamp, const string &user, int uid,
         const vector<nd_t> &nd, const vector<tag_t> &tag) : id(id), visible(visible), version(version),
                                                             changeset(changeset), timestamp(timestamp), user(user),
                                                             uid(uid), nd(nd), tag(tag) {}

bool Way::isVisible() const {
    return visible;
}

void Way::setVisible(bool visible) {
    Way::visible = visible;
}

int Way::getVersion() const {
    return version;
}

void Way::setVersion(int version) {
    Way::version = version;
}

int Way::getChangeset() const {
    return changeset;
}

void Way::setChangeset(int changeset) {
    Way::changeset = changeset;
}

const string &Way::getTimestamp() const {
    return timestamp;
}

void Way::setTimestamp(const string &timestamp) {
    Way::timestamp = timestamp;
}

const string &Way::getUser() const {
    return user;
}

void Way::setUser(const string &user) {
    Way::user = user;
}

int Way::getUid() const {
    return uid;
}

void Way::setUid(int uid) {
    Way::uid = uid;
}

const vector<nd_t> &Way::getNd() const {
    return nd;
}

void Way::setNd(const vector<nd_t> &nd) {
    Way::nd = nd;
}

const vector<tag_t> &Way::getTag() const {
    return tag;
}

void Way::setTag(const vector<tag_t> &tag) {
    Way::tag = tag;
}

long Way::getId() const {
    return id;
}

void Way::setId(long id) {
    Way::id = id;
}
