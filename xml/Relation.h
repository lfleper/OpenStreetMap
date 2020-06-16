//
// Created by lfleper on 16.06.20.
//

#ifndef OPENSTREETMAP_RELATION_H
#define OPENSTREETMAP_RELATION_H

#include <iostream>
#include "Structs.h"

class Relation {
private:
    long id;
    bool visible;
    int version;
    int changeset;
    std::string timestamp;
    std::string user;
    int uid;
    std::vector<member_t> members;
    std::vector<tag_t> tags;
public:
    Relation(long id, bool visible, int version, int changeset, const string &timestamp, const string &user, int uid,
             const vector<member_t> &members, const vector<tag_t> &tags);

    const vector<tag_t> &getTags() const;

    void setTags(const vector<tag_t> &tags);

    const vector<member_t> &getMembers() const;

    void setMembers(const vector<member_t> &members);

    long getId() const;

    void setId(long id);

    bool isVisible() const;

    void setVisible(bool visible);

    int getVersion() const;

    void setVersion(int version);

    int getChangeset() const;

    void setChangeset(int changeset);

    const std::string &getTimestamp() const;

    void setTimestamp(const std::string &timestamp);

    const std::string &getUser() const;

    void setUser(const std::string &user);

    int getUid() const;

    void setUid(int uid);
};


#endif //OPENSTREETMAP_RELATION_H
