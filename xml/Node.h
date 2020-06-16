//
// Created by lfleper on 08.06.20.
//

#ifndef OPENSTREETMAP_NODE_H
#define OPENSTREETMAP_NODE_H

#include "Structs.h"

class Node {
private:
    long id;
    bool visible;
    int version;
    int changeset;
    string timestamp;
    string user;
    int uid;
    double lat;
    double lon;
    vector<tag_t> tag;
public:
    Node(long id, bool visible, int version, int changeset, const string &timestamp, const string &user, int uid,
         double lat, double lon, const vector<tag_t> &tag);

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

    double getLat() const;

    void setLat(double lat);

    double getLon() const;

    void setLon(double lon);

    const vector<tag_t> &getTag() const;

    void setTag(const vector<tag_t> &tag);
};


#endif //OPENSTREETMAP_NODE_H
