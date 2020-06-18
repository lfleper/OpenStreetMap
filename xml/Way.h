//
// Created by lfleper on 08.06.20.
//

#ifndef OPENSTREETMAP_WAY_H
#define OPENSTREETMAP_WAY_H

#include "Structs.h"

class Way {
private:
    long id;
    bool visible;
    int version;
    int changeset;
    string timestamp;
    string user;
    int uid;
    vector<nd_t> nd;
    vector<tag_t> tag;
public:

    Way(long id, bool visible, int version, int changeset, const string &timestamp, const string &user, int uid,
        const vector<nd_t> &nd, const vector<tag_t> &tag);

    long getId() const;

    void setId(long id);

    bool isVisible() const;

    void setVisible(bool visible);

    int getVersion() const;

    void setVersion(int version);

    int getChangeset() const;

    void setChangeset(int changeset);

    const string &getTimestamp() const;

    void setTimestamp(const string &timestamp);

    const string &getUser() const;

    void setUser(const string &user);

    int getUid() const;

    void setUid(int uid);

    const vector<nd_t> &getNd() const;

    void setNd(const vector<nd_t> &nd);

    const vector<tag_t> &getTag() const;

    void setTag(const vector<tag_t> &tag);
};


#endif //OPENSTREETMAP_WAY_H
