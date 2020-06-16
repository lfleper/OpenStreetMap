//
// Created by lfleper on 16.06.20.
//

#include "Relation.h"

bool Relation::isVisible() const {
    return visible;
}

void Relation::setVisible(bool visible) {
    Relation::visible = visible;
}

int Relation::getVersion() const {
    return version;
}

void Relation::setVersion(int version) {
    Relation::version = version;
}

int Relation::getChangeset() const {
    return changeset;
}

void Relation::setChangeset(int changeset) {
    Relation::changeset = changeset;
}

const std::string &Relation::getTimestamp() const {
    return timestamp;
}

void Relation::setTimestamp(const std::string &timestamp) {
    Relation::timestamp = timestamp;
}

const std::string &Relation::getUser() const {
    return user;
}

void Relation::setUser(const std::string &user) {
    Relation::user = user;
}

int Relation::getUid() const {
    return uid;
}

void Relation::setUid(int uid) {
    Relation::uid = uid;
}

long Relation::getId() const {
    return id;
}

void Relation::setId(long id) {
    Relation::id = id;
}

const vector<member_t> &Relation::getMembers() const {
    return members;
}

void Relation::setMembers(const vector<member_t> &members) {
    Relation::members = members;
}

const vector<tag_t> &Relation::getTags() const {
    return tags;
}

void Relation::setTags(const vector<tag_t> &tags) {
    Relation::tags = tags;
}

Relation::Relation(long id, bool visible, int version, int changeset, const string &timestamp, const string &user,
                   int uid, const vector<member_t> &members, const vector<tag_t> &tags) : id(id), visible(visible),
                                                                                          version(version),
                                                                                          changeset(changeset),
                                                                                          timestamp(timestamp),
                                                                                          user(user), uid(uid),
                                                                                          members(members),
                                                                                          tags(tags) {}

