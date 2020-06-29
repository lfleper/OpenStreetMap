//
// Created by lfleper on 05.06.20.
//

#include <iostream>
#include "XMLController.h"
#include "../pugixml-1.10/src/pugixml.hpp"
#include "Structs.h"
#include "Relation.h"
#include <string>
#include "Osm.h"
using namespace std;
using namespace pugi;

XMLController::XMLController(const string &file) : file(file) {
    this->result = this->doc.load_string(file.c_str());
    if (!result) {
        cout << "[err] load xml string" << endl;
    }
}

Osm XMLController::parse() {
    Osm osmObj = Osm();
    bounds_t bounds_s;
    if (result) {
        xml_node elements = this->doc.child("osm");

        // get all osm tags
        xml_node osm = this->doc.first_child();

        // get bounds
        xml_node bounds = osm.child("bounds");
        bounds_s.minlat = bounds.attribute("minlat").as_double();
        bounds_s.minlon = bounds.attribute("minlon").as_double();
        bounds_s.maxlat = bounds.attribute("maxlat").as_double();
        bounds_s.maxlon = bounds.attribute("maxlon").as_double();
        osmObj.setBounds(bounds_s);

        // get ways
        vector<Way> ways;
        for (xml_node way = osm.child("way"); way; way = way.next_sibling("way")) {
            vector<tag_t> tags;
            bool hasHighway = false;
            for (xml_node t = way.child("tag"); t; t = t.next_sibling("tag")) {
                tag_t tmp_tag;
                tmp_tag.k = t.attribute("k").as_string();
                tmp_tag.v = t.attribute("v").as_string();
                if(strcmp(t.attribute("k").as_string(), "highway") == 0 && strcmp(t.attribute("v").as_string(), "residential") == 0){
                    hasHighway = true;
                }
                tags.push_back(tmp_tag);
            }

            //filtere alle wege die kein highway mit residential sind
            if(!hasHighway){
                continue;
            }
            vector<nd_t> nds;
            for (xml_node n = way.child("nd"); n; n = n.next_sibling("nd")) {
                nd_t tmp_ns;
                tmp_ns.ref = n.attribute("ref").as_llong();
                nds.push_back(tmp_ns);
            }
            ways.emplace_back(Way(
                    way.attribute("id").as_llong(),
                    way.attribute("visible").as_bool(),
                    way.attribute("version").as_int(),
                    way.attribute("changeset").as_int(),
                    way.attribute("timestamp").as_string(),
                    way.attribute("user").as_string(),
                    way.attribute("uid").as_int(),
                    nds,
                    tags
                    ));
        }
        osmObj.setWays(ways);

        // get nodes
        vector<Node> nodes;
        for (xml_node node = osm.child("node"); node; node = node.next_sibling("node")) {
            vector<tag_t> tags;

            //filtere alle nodes die in keinem weg vorkommen
            long nodeId = node.attribute("id").as_llong();
            bool skipNode = true;
            for(Way w : ways){
                for(nd_t nd : w.getNd()){
                    if(nd.ref == nodeId){
                        skipNode = false;
                    }
                }
            }
            if(skipNode)
                continue;

            //////////////////////////////

            for (xml_node t = node.child("tag"); t; t = t.next_sibling("tag")) {
                tag_t tmp_tag;
                tmp_tag.k = t.attribute("k").as_string();
                tmp_tag.v = t.attribute("v").as_string();
                tags.push_back(tmp_tag);
            }
            nodes.emplace_back(
                    node.attribute("id").as_llong(),
                    node.attribute("visible").as_bool(),
                    node.attribute("version").as_int(),
                    node.attribute("changeset").as_int(),
                    node.attribute("timestamp").as_string(),
                    node.attribute("user").as_string(),
                    node.attribute("uid").as_int(),
                    node.attribute("lat").as_double(),
                    node.attribute("lon").as_double(),
                    tags
            );
        }
        osmObj.setNodes(nodes);

        // get relations
        vector<Relation> relations;
        for (xml_node relation = osm.child("relation"); relation; relation = relation.next_sibling("relation")) {
            vector<member_t> members;
            for (xml_node m = relation.child("member"); m; m = m.next_sibling("member")) {
                member_t tmp_member;
                tmp_member.type = m.attribute("type").as_string();
                tmp_member.ref = m.attribute("ref").as_llong();
                tmp_member.role = m.attribute("role").as_string();
                members.push_back(tmp_member);
            }
            vector<tag_t> tags;
            for (xml_node t = relation.child("tag"); t; t = t.next_sibling("tag")) {
                tag_t tmp_tag;
                tmp_tag.k = t.attribute("k").as_string();
                tmp_tag.v = t.attribute("v").as_string();
                tags.push_back(tmp_tag);
            }
            relations.emplace_back(Relation(
                    relation.attribute("id").as_llong(),
                    relation.attribute("visible").as_bool(),
                    relation.attribute("version").as_int(),
                    relation.attribute("changeset").as_int(),
                    relation.attribute("timestamp").as_string(),
                    relation.attribute("user").as_string(),
                    relation.attribute("uid").as_int(),
                    members,
                    tags
                    ));
        }
        osmObj.setRelations(relations);
    }

    return osmObj;
}
